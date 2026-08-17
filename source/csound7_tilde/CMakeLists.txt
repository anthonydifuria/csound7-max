set_property(DIRECTORY PROPERTY max::external YES)
set_property(DIRECTORY PROPERTY max::glob ON)
project(csound7_tilde)

# --- Static Csound 7 (built by scripts/build_csound_static.sh) ---
target_include_directories(csound7_tilde PRIVATE
  "${CSOUND_STATIC_ROOT}/include"
  "${CSOUND_STATIC_ROOT}/include/csound"
)

# Core static lib + its static deps (libsndfile, libsamplerate). Confirmed
# from a real build log: the target is CsoundLib64-static, output file is
# libCsoundLib64.a (not libcsound64.a as first guessed) - on Apple only.
# Everywhere else, including Windows, Csound's own CMakeLists.txt names it
# "csound64" instead (its CSOUNDLIB variable is only ever "CsoundLib64"
# inside an if(APPLE) branch) - confirmed by reading that file directly,
# and separately verified correct on Linux with a real build (see
# ../../../PD/source/csound7_pd/CMakeLists.txt for that side's copy of
# this same fix - both externals link against the same static Csound).
if(APPLE)
  set(CSOUND_STATIC_LIB "${CSOUND_STATIC_ROOT}/lib/libCsoundLib64.a")
  set(SNDFILE_STATIC_LIB "${CSOUND_STATIC_ROOT}/lib/libsndfile.a")
  set(SAMPLERATE_STATIC_LIB "${CSOUND_STATIC_ROOT}/lib/libsamplerate.a")
elseif(WIN32)
  # Csound's CMakeLists.txt also unconditionally forces a "lib" prefix on
  # the static target's OUTPUT_NAME regardless of platform, so
  # "libcsound64.lib" is the well-grounded prediction here (same reasoning
  # as the Linux name, just not yet confirmed by an actual Windows build -
  # that confirmation is what the first real CI run of this project's
  # Windows workflow is for). libsndfile/libsamplerate's own CMake projects
  # weren't read closely enough to know whether they force the same "lib"
  # prefix on Windows (CMake's own MSVC default does NOT add one, unlike
  # its Unix default) - find_library() tries both spellings so this
  # doesn't depend on guessing the one true answer up front.
  find_library(CSOUND_STATIC_LIB_WIN NAMES libcsound64 csound64
    PATHS "${CSOUND_STATIC_ROOT}/lib" NO_DEFAULT_PATH)
  find_library(SNDFILE_STATIC_LIB_WIN NAMES libsndfile sndfile
    PATHS "${CSOUND_STATIC_ROOT}/lib" NO_DEFAULT_PATH)
  find_library(SAMPLERATE_STATIC_LIB_WIN NAMES libsamplerate samplerate
    PATHS "${CSOUND_STATIC_ROOT}/lib" NO_DEFAULT_PATH)
  set(CSOUND_STATIC_LIB "${CSOUND_STATIC_LIB_WIN}")
  set(SNDFILE_STATIC_LIB "${SNDFILE_STATIC_LIB_WIN}")
  set(SAMPLERATE_STATIC_LIB "${SAMPLERATE_STATIC_LIB_WIN}")
endif()

foreach(lib IN ITEMS CSOUND_STATIC_LIB SNDFILE_STATIC_LIB SAMPLERATE_STATIC_LIB)
  if(NOT EXISTS "${${lib}}")
    message(WARNING "${lib} not found at ${${lib}} — run scripts/build_csound_static.sh first, or fix the path/filename here.")
  endif()
endforeach()

# CoreFoundation/Accelerate/-lc++/-lpthread are macOS-specific - confirmed
# unconditional before this fix, which would have broken Windows's linker
# outright the same way it already did on Linux ("-framework" isn't
# something any non-Apple linker understands). Nothing Windows-specific
# needed here in return: unlike the Pd side, the Max SDK itself ships real,
# prebuilt Windows import libraries directly inside max-sdk-base
# (c74support/max-includes/x64/MaxAPI.lib, c74support/msp-includes/x64/
# MaxAudio.lib - confirmed by actually fetching max-sdk-base and looking,
# not assumed) and FindMaxSDK.cmake / max-posttarget.cmake (both part of
# max-sdk-base, fetched by ../../CMakeLists.txt) already wire these up
# automatically via the max::external/max::glob directory properties set
# at the top of this file - including the .mxe64 Windows output suffix,
# also confirmed directly in max-posttarget.cmake. Nothing extra to add
# here for that part.
target_link_libraries(csound7_tilde PRIVATE
  "${CSOUND_STATIC_LIB}"
  "${SNDFILE_STATIC_LIB}"
  "${SAMPLERATE_STATIC_LIB}"
)
if(APPLE)
  target_link_libraries(csound7_tilde PRIVATE
    "-framework CoreFoundation"
    "-framework Accelerate"
    "-lpthread"
    "-lc++"
  )
endif()

# The static Csound lib bundles several C++ opcodes (mixer, ftsamplebank,
# signalflowgraph, etc. — with BUILD_PLUGINS=OFF these got compiled straight
# into the core static lib instead of as separate plugin modules). Our
# external's own source is plain C, so CMake would otherwise pick the C
# linker for the final link step, which doesn't pull in the C++ runtime's
# exception handling/RTTI support those C++ object files need — hence the
# wall of "Undefined symbols ... std::__1::..." errors on macOS (MSVC would
# show its own equivalent). Forcing the linker language to CXX makes CMake
# invoke the platform's C++ driver for the link step instead (clang++ on
# macOS, link.exe via the C++ toolchain on Windows), which pulls the C++
# runtime in automatically (the explicit "-lc++" above, on Apple only, is
# belt-and-suspenders).
set_target_properties(csound7_tilde PROPERTIES LINKER_LANGUAGE CXX)
