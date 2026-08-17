#Requires -Version 5.1
#
# Static build of Csound 7 + libsndfile + libsamplerate for Windows (x64),
# MSVC toolchain. The Windows counterpart to build_csound_static.sh
# (macOS/Linux, bash) - not a shared script on purpose, since MSVC's
# toolchain (cl.exe/link.exe, .lib instead of .a, the Visual Studio CMake
# generator, no lipo, no Homebrew/apt) is different enough that force-
# fitting it into the bash script wasn't realistic (see that script's own
# top comment for the same reasoning stated the other way around). Same
# script as ../../PD/scripts/build_csound_static.ps1, kept as a separate
# copy on purpose - same reasoning as the bash script's own duplication
# between MAX/ and PD/, keeps each side self-contained.
#
# UNVERIFIED - written without access to a Windows machine, meant to be
# run for real for the first time by GitHub Actions' windows-latest
# runner (or by you, if you have a Windows box - see the project README).
# Expect at least one round of real fixes after that first run, the same
# way the macOS and Linux branches of build_csound_static.sh both needed
# real build logs before they worked - that's the normal next step here,
# not a sign this was written carelessly. Two things flagged below as the
# most likely spots to need a fix are marked UNVERIFIED inline.
#
# x64 only - matches every other Windows target in this project.

$ErrorActionPreference = "Stop"

$CsoundRepo = "https://github.com/csound/csound.git"
$CsoundBranch = "develop"
$SndfileRepo = "https://github.com/libsndfile/libsndfile.git"
$SamplerateRepo = "https://github.com/libsndfile/libsamplerate.git"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectRoot = Split-Path -Parent $ScriptDir
$BuildRoot = Join-Path $ProjectRoot "build"
$InstallRoot = Join-Path $BuildRoot "csound-install"
$WinInstall = Join-Path $InstallRoot "windows-x64"

# ---------------------------------------------------------------------
# 0. toolchain check: bison/flex via winflexbison (the standard Windows
#    port of GNU bison/flex - `choco install winflexbison3`, already done
#    by the GitHub Actions workflow before this script runs). Its
#    executables are named win_bison.exe/win_flex.exe, not bison.exe/
#    flex.exe - passed straight to CMake's -DBISON_EXECUTABLE/
#    -DFLEX_EXECUTABLE (same mechanism the macOS/Linux script uses), no
#    renaming needed.
#
#    Generator: uses Ninja, not "Visual Studio 17 2022" as originally
#    written. First real GitHub Actions run of the PD side's copy of this
#    script failed at the very first cmake call with "Generator Visual
#    Studio 17 2022 could not find any instance of Visual Studio" - even
#    though windows-latest runners do have VS2022 installed, CMake's own
#    VS-instance auto-detection didn't find it in that environment. Ninja
#    sidesteps that detection path entirely: it just needs cl.exe/link.exe
#    on PATH, which the ilammy/msvc-dev-cmd@v1 GitHub Action step (added
#    to windows-build.yml right after checkout) sets up explicitly via
#    vcvarsall.bat, so CMake never has to auto-discover anything. Also
#    means Debug/Release is chosen at configure time via CMAKE_BUILD_TYPE
#    like the Linux/macOS branches, not via --config at build time like
#    the VS generator needed.
# ---------------------------------------------------------------------
function Find-Tool {
    param([string[]]$Names, [string]$InstallHint)
    foreach ($n in $Names) {
        $cmd = Get-Command $n -ErrorAction SilentlyContinue
        if ($cmd) { return $cmd.Source }
    }
    Write-Error "$($Names -join ' or ') not found on PATH. $InstallHint"
    exit 1
}

$BisonExe = Find-Tool -Names @("win_bison.exe", "win_bison", "bison.exe", "bison") `
    -InstallHint "Install with: choco install winflexbison3"
$FlexExe = Find-Tool -Names @("win_flex.exe", "win_flex", "flex.exe", "flex") `
    -InstallHint "Install with: choco install winflexbison3"

Write-Host "==> using bison: $BisonExe"
Write-Host "==> using flex:   $FlexExe"

function Clone-Once {
    param([string]$Repo, [string]$Branch, [string]$Dest)
    if (-not (Test-Path (Join-Path $Dest ".git"))) {
        Write-Host "==> cloning $Repo ($Branch)"
        git clone --branch $Branch --depth 1 $Repo $Dest
    }
}

# ---------------------------------------------------------------------
# 1. libsndfile, static - same flags/reasoning as the macOS/Linux script,
#    this part is genuinely OS-agnostic CMake. Ninja is single-config
#    (Release chosen at configure time via CMAKE_BUILD_TYPE), like the
#    Unix Makefiles generator the other two branches use.
# ---------------------------------------------------------------------
$SndfileSrc = Join-Path $BuildRoot "sndfile-static\src"
Clone-Once -Repo $SndfileRepo -Branch "master" -Dest $SndfileSrc
$SndfileBuild = Join-Path $BuildRoot "sndfile-static\build-windows"
$SndfileInstall = Join-Path $InstallRoot "windows-x64-deps\sndfile"

# -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded..." (here and on the other
# two cmake configure calls below, plus the outer external build in
# windows-build.yml) forces the static CRT (/MT, /MTd for Debug) - found
# necessary via a real CI failure: max-sdk-base's own max-pretarget.cmake
# forces this same /MT for us automatically, but ONLY
# `if (CMAKE_GENERATOR MATCHES "Visual Studio")` - since we build with
# Ninja instead (to sidestep the earlier "could not find any instance of
# Visual Studio" issue), that block is skipped entirely, everything here
# falls back to CMake's own default (dynamic CRT, /MD in Release), and the
# final link against Cycling'74's prebuilt MaxAPI.lib/MaxAudio.lib (built
# expecting /MT) fails with dozens of unresolved CRT symbols (rand,
# access, write, ...) - a classic CRT-mismatch symptom, not missing code.
# Setting this explicitly, generator-independent, restores what
# max-pretarget.cmake would have done for the Visual Studio generator.
Write-Host "==> building static libsndfile for Windows (x64)"
cmake -S $SndfileSrc -B $SndfileBuild -G Ninja `
    -DCMAKE_BUILD_TYPE=Release `
    -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded`$<`$<CONFIG:Debug>:Debug>" `
    -DCMAKE_INSTALL_PREFIX="$SndfileInstall" `
    -DBUILD_SHARED_LIBS=OFF `
    -DBUILD_PROGRAMS=OFF `
    -DBUILD_EXAMPLES=OFF `
    -DBUILD_TESTING=OFF `
    -DENABLE_EXTERNAL_LIBS=OFF `
    -DENABLE_MPEG=OFF `
    -DENABLE_CPACK=OFF
if ($LASTEXITCODE -ne 0) { throw "libsndfile configure failed" }
cmake --build $SndfileBuild
if ($LASTEXITCODE -ne 0) { throw "libsndfile build failed" }
cmake --install $SndfileBuild
if ($LASTEXITCODE -ne 0) { throw "libsndfile install failed" }

# ---------------------------------------------------------------------
# 2. libsamplerate, static
# ---------------------------------------------------------------------
$SamplerateSrc = Join-Path $BuildRoot "samplerate-static\src"
Clone-Once -Repo $SamplerateRepo -Branch "master" -Dest $SamplerateSrc
$SamplerateBuild = Join-Path $BuildRoot "samplerate-static\build-windows"
$SamplerateInstall = Join-Path $InstallRoot "windows-x64-deps\samplerate"

Write-Host "==> building static libsamplerate for Windows (x64)"
cmake -S $SamplerateSrc -B $SamplerateBuild -G Ninja `
    -DCMAKE_BUILD_TYPE=Release `
    -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded`$<`$<CONFIG:Debug>:Debug>" `
    -DCMAKE_INSTALL_PREFIX="$SamplerateInstall" `
    -DBUILD_SHARED_LIBS=OFF `
    -DBUILD_TESTING=OFF `
    -DLIBSAMPLERATE_EXAMPLES=OFF `
    -DLIBSAMPLERATE_INSTALL=ON
if ($LASTEXITCODE -ne 0) { throw "libsamplerate configure failed" }
cmake --build $SamplerateBuild
if ($LASTEXITCODE -ne 0) { throw "libsamplerate build failed" }
cmake --install $SamplerateBuild
if ($LASTEXITCODE -ne 0) { throw "libsamplerate install failed" }

# find_library-style lookup rather than a single hardcoded name - CMake's
# default static-lib naming on MSVC does NOT add a "lib" prefix the way it
# does on Unix, but it wasn't confirmed whether libsndfile's/libsamplerate's
# own CMakeLists.txt force one anyway (Csound's own does, unconditionally -
# see source/csound7_tilde/CMakeLists.txt's comment on this). UNVERIFIED:
# whichever of these two names is wrong will show up as a "not found"
# error below, with both candidates and their real directory listing
# printed, rather than a cryptic linker failure later.
function Find-StaticLib {
    param([string]$Dir, [string]$BaseName)
    foreach ($candidate in @("lib$BaseName.lib", "$BaseName.lib")) {
        $full = Join-Path $Dir $candidate
        if (Test-Path $full) { return $full }
    }
    Write-Error "expected static $BaseName at $Dir\lib$BaseName.lib or $Dir\$BaseName.lib, neither found."
    Write-Host "Contents of ${Dir}:"
    Get-ChildItem $Dir -ErrorAction SilentlyContinue
    exit 1
}

$SndfileLibDir = Join-Path $SndfileInstall "lib"
$SamplerateLibDir = Join-Path $SamplerateInstall "lib"
$SndfileLib = Find-StaticLib -Dir $SndfileLibDir -BaseName "sndfile"
$SamplerateLib = Find-StaticLib -Dir $SamplerateLibDir -BaseName "samplerate"

# ---------------------------------------------------------------------
# 3. Csound 7, static, pointed at our own static sndfile/samplerate.
#    UNVERIFIED (the two spots most likely to need a real fix after the
#    first CI run, flagged here rather than guessed silently):
#      - whether Csound's codebase compiles clean under MSVC at all
#        without patches (it's a large, long-lived C/C++ codebase with
#        real Linux/macOS-first history; the CMakeLists.txt does have
#        WIN32-specific branches throughout, suggesting Windows support is
#        real and maintained, but that's not the same as "compiles clean
#        with zero fixes on the first try").
#      - whether winflexbison's bison/flex are close enough behaviorally
#        to GNU bison/flex for Csound's grammar files - they're built
#        from the same upstream GNU sources, ported rather than
#        reimplemented, so this is a reasonable bet, not a blind guess,
#        but still unconfirmed here.
#    USE_ALSA=OFF (present in the Linux branch of the bash script) is
#    intentionally NOT passed here - Csound's own InOut/CMakeLists.txt
#    only triggers that REQUIRED ALSA search `if(USE_ALSA AND LINUX)`,
#    which is never true on Windows regardless of this flag.
#
#    dirent.h: MSVC doesn't ship this POSIX header at all - confirmed by a
#    real CI failure on the PD side (identical Csound build here): Csound's
#    own CMakeLists.txt does find_file(DIRENT_H "dirent.h") around line
#    770 and, on MSVC, hard FATAL_ERRORs the whole configure step if it's
#    not found ("Csound will not be able to load dynamic plugins"; this is
#    a build-time need, not just a runtime one - BUILD_PLUGINS=OFF above
#    doesn't help, it only skips building Csound's own bundled plugin
#    targets). Fixed by fetching the well-known tronkko/dirent
#    single-header MSVC shim (MIT licensed, the standard fix for exactly
#    this) and pointing CMAKE_INCLUDE_PATH at it, which is one of the
#    locations find_file() searches by default.
# ---------------------------------------------------------------------
$DirentDir = Join-Path $BuildRoot "win-compat\include"
$DirentHeader = Join-Path $DirentDir "dirent.h"
if (-not (Test-Path $DirentHeader)) {
    New-Item -ItemType Directory -Force -Path $DirentDir | Out-Null
    Write-Host "==> fetching dirent.h shim (tronkko/dirent, MIT) for MSVC"
    Invoke-WebRequest -Uri "https://raw.githubusercontent.com/tronkko/dirent/master/include/dirent.h" -OutFile $DirentHeader
}

# CMAKE_INCLUDE_PATH above only affects CMake's own find_file()/find_path()
# lookups (that's what makes the configure-time check pass) - it does NOT
# add this directory to the real compiler's include search path used when
# actually building Csound's .c files, which is a separate mechanism.
# Confirmed by a real CI failure one step further than the configure-time
# one (identical build on the PD side): "fatal error C1083: Cannot open
# include file: 'dirent.h'" while compiling Top/getstring.c, even though
# HAVE_DIRENT_H was already defined. Fix: prepend to the %INCLUDE%
# environment variable, which is what cl.exe itself reads for every
# compile invocation regardless of how it was started (this is the same
# mechanism vcvarsall.bat/ilammy/msvc-dev-cmd already used to expose the
# standard MSVC/Windows SDK headers) - more reliable here than passing
# -DCMAKE_C_FLAGS/-DCMAKE_CXX_FLAGS by hand.
$env:INCLUDE = "$DirentDir;$env:INCLUDE"

$CsoundSrc = Join-Path $BuildRoot "csound-static\src"
Clone-Once -Repo $CsoundRepo -Branch $CsoundBranch -Dest $CsoundSrc
$CsoundBuild = Join-Path $BuildRoot "csound-static\build-windows"

Write-Host "==> building static Csound for Windows (x64)"
Write-Host "    using SndFile:    $SndfileLib"
Write-Host "    using SampleRate: $SamplerateLib"
Write-Host "    using dirent.h:   $DirentHeader"

cmake -S $CsoundSrc -B $CsoundBuild -G Ninja `
    -DCMAKE_BUILD_TYPE=Release `
    -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded`$<`$<CONFIG:Debug>:Debug>" `
    -DCMAKE_INSTALL_PREFIX="$WinInstall" `
    -DCMAKE_INCLUDE_PATH="$DirentDir" `
    -DBISON_EXECUTABLE="$BisonExe" `
    -DFLEX_EXECUTABLE="$FlexExe" `
    -DSndFile_LIBRARY="$SndfileLib" `
    -DSndFile_INCLUDE_DIR="$SndfileInstall\include" `
    -DSampleRate_LIBRARY="$SamplerateLib" `
    -DSampleRate_INCLUDE_DIR="$SamplerateInstall\include" `
    -DBUILD_STATIC_LIBRARY=ON `
    -DBUILD_PLUGINS=OFF `
    -DUSE_LIBSNDFILE=ON `
    -DUSE_LIBSAMPLERATE=ON `
    -DUSE_CURL=OFF `
    -DUSE_GETTEXT=OFF `
    -DBUILD_UTILITIES=OFF `
    -DBUILD_TESTS=OFF `
    -DBUILD_INSTALLER=OFF `
    -DBUILD_DOCS=OFF `
    -DUSE_DOUBLE=ON `
    -DFAIL_MISSING=OFF `
    -DUSE_PORTAUDIO=OFF `
    -DUSE_PORTMIDI=OFF `
    -DUSE_JACK=OFF `
    -DUSE_COREMIDI=OFF `
    -DUSE_AUDIOUNIT=OFF `
    -DUSE_IPMIDI=OFF `
    -DUSE_PULSEAUDIO=OFF `
    -DUSE_PIPEWIRE=OFF `
    -DBUILD_OSC_OPCODES=OFF `
    -DBUILD_CSBEATS=OFF `
    -DBUILD_DSSI_OPCODES=OFF `
    -DINSTALL_PYTHON_INTERFACE=OFF
if ($LASTEXITCODE -ne 0) { throw "Csound configure failed" }
cmake --build $CsoundBuild
if ($LASTEXITCODE -ne 0) { throw "Csound build failed" }
cmake --install $CsoundBuild
if ($LASTEXITCODE -ne 0) { throw "Csound install failed" }

# Bring the static sndfile/samplerate libs+headers into the same install
# root as Csound's own, same idea as the Linux branch of the bash script -
# one self-contained CSOUND_STATIC_ROOT directory.
New-Item -ItemType Directory -Force -Path "$WinInstall\lib" | Out-Null
New-Item -ItemType Directory -Force -Path "$WinInstall\include" | Out-Null
Copy-Item $SndfileLib "$WinInstall\lib\"
Copy-Item $SamplerateLib "$WinInstall\lib\"
Copy-Item "$SndfileInstall\include\*" "$WinInstall\include\" -Recurse -Force
Copy-Item "$SamplerateInstall\include\*" "$WinInstall\include\" -Recurse -Force

Write-Host ""
Write-Host "Done. Static libraries in: $WinInstall\lib"
Write-Host "Headers in: $WinInstall\include"
Write-Host ""
Write-Host "Real lib file names:"
Get-ChildItem "$WinInstall\lib"
Write-Host ""
Write-Host "If source/csound7_tilde/CMakeLists.txt's find_library() calls didn't"
Write-Host "find the right files, the names above are the real ones to fix"
Write-Host "them to point at."
