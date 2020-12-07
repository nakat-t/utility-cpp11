project_name := utility_cpp11

STDCXX    := 11
DEBUG     := 0
TOOLCHAIN := gcc

OUT_DIR   := _out

makefile_root_dir := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
target_dir := $(OUT_DIR)/std$(STDCXX)-$(TOOLCHAIN)$(if $(findstring 0,$(DEBUG)),,-debug)
ext_exe := $(if $(findstring Windows_NT,$(DEBOSUG)),.exe)

cmake_options += -DCMAKE_CXX_STANDARD=$(STDCXX)

ifeq ($(DEBUG),0)
	cmake_options += -DCMAKE_BUILD_TYPE=Release
else
	cmake_options += -DCMAKE_BUILD_TYPE=Debug
endif

ifeq ($(TOOLCHAIN),gcc)
    cmake_options += -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
else ifeq ($(TOOLCHAIN),clang)
	cmake_options += -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS=-stdlib=libc++ -DCMAKE_EXE_LINKER_FLAGS=-stdlib=libc++
endif

.DEFAULT_GOAL := all

.PHONY: all
all: test

.PHONY: build
build:
	cmake -S $(makefile_root_dir) -B $(target_dir) $(cmake_options)
	cmake --build $(target_dir)

.PHONY: test
test: build
	cd $(target_dir) && ctest
	$(target_dir)/catch2_test_$(project_name)$(ext_exe)

.PHONY: clean
clean:
	rm -rf $(OUT_DIR)
