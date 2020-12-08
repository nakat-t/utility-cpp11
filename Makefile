project_name := utility_cpp11

STDCXX    := 11
DEBUG     := 0
TOOLCHAIN := gcc

OUT_DIR   := _out

ifeq ($(OS),Windows_NT)
	rm_rf := rd /s /q
else
	rm_rf := rm -rf
endif

makefile_root_dir := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
target_dir := $(OUT_DIR)/std$(STDCXX)-$(TOOLCHAIN)$(if $(findstring 0,$(DEBUG)),,-debug)
ext_exe := $(if $(findstring Windows_NT,$(OS)),.exe)

cmake_options += -DCMAKE_CXX_STANDARD=$(STDCXX)

ifeq ($(DEBUG),0)
	cmake_config = Release
else
	cmake_config = Debug
endif

ifeq ($(findstring msvc,$(TOOLCHAIN)),msvc)
	catch2_test_exe_path := $(target_dir)/$(cmake_config)/catch2_test_$(project_name)$(ext_exe)
else
	catch2_test_exe_path := $(target_dir)/catch2_test_$(project_name)$(ext_exe)
endif

cmake_options += -DCMAKE_BUILD_TYPE=$(cmake_config)

ifeq ($(TOOLCHAIN),gcc)
    cmake_options += -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
else ifeq ($(TOOLCHAIN),clang)
	cmake_options += -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS=-stdlib=libc++ -DCMAKE_EXE_LINKER_FLAGS=-stdlib=libc++
else ifeq ($(TOOLCHAIN),msvc14)
	cmake_options += -G "Visual Studio 14 2015" -A x64
else ifeq ($(TOOLCHAIN),msvc141)
	cmake_options += -G "Visual Studio 15 2017" -A x64
else ifeq ($(TOOLCHAIN),msvc142)
	cmake_options += -G "Visual Studio 16 2019" -A x64
endif

.DEFAULT_GOAL := all

.PHONY: all
all: test

.PHONY: build
build:
	cmake -S $(makefile_root_dir) -B $(target_dir) $(cmake_options)
	cmake --build $(target_dir) --config $(cmake_config)

.PHONY: test
test: build
	cd $(target_dir) && ctest -C $(cmake_config)
	$(catch2_test_exe_path)

.PHONY: clean
clean:
	$(rm_rf) $(OUT_DIR)
