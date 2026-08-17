cmake_minimum_required(VERSION 3.25)

# Universal binary by default: arm64 + x86_64, buildable from a single
# Apple Silicon Mac (Xcode cross-compiles both slices, no Intel Mac needed).
if(NOT CMAKE_OSX_ARCHITECTURES)
  set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "macOS architectures")
endif()

if(NOT DEFINED CACHE{CMAKE_OSX_DEPLOYMENT_TARGET})
  # Matches Csound's own forced minimum (its CMake sets 11 regardless of
  # what we ask for) - keeps them aligned so the linker stops warning
  # about mismatched deployment targets.
  set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE STRING "Minimum macOS deployment version")
endif()

include(FetchContent)

message(STATUS "Fetching max-sdk-base (Cycling'74 headers + CMake scripts)")
FetchContent_Declare(
  max-sdk-base
  GIT_REPOSITORY https://github.com/Cycling74/max-sdk-base.git
  GIT_TAG main
)
FetchContent_MakeAvailable(max-sdk-base)

project(csound7_tilde_package)

# Where the static Csound build drops its libs/headers - macOS gets a
# universal (arm64+x86_64) folder from scripts/build_csound_static.sh
# (bash); Windows gets a fixed "windows-x64" folder from the separate
# scripts/build_csound_static.ps1 (PowerShell - MSVC's toolchain is
# different enough that reusing the bash script isn't realistic, see that
# script's own top comment; same split as the PD side, see
# ../PD/CMakeLists.txt's copy of this same comment). Override with
# -DCSOUND_STATIC_ROOT=... if you built it somewhere else.
if(NOT DEFINED CSOUND_STATIC_ROOT)
  if(APPLE)
    set(CSOUND_STATIC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/build/csound-install/universal")
  elseif(WIN32)
    set(CSOUND_STATIC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/build/csound-install/windows-x64")
  endif()
endif()

add_subdirectory(source/csound7_tilde)
