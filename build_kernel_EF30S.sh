#!/bin/bash
#######################################################
#  PANTECH defined Environment                        #
#######################################################
# export TARGET_BUILD_SKY_MODEL_NAME=IM-A750K
# export TARGET_BUILD_SKY_MODEL_ID=MODEL_EF32K
# export TARGET_BUILD_SKY_BOARD_VER=EF32K_ES20
# export TARGET_BUILD_SKY_FIRMWARE_VER=S0832143
# export TARGET_BUILD_SKY_CUST_INCLUDE=$PWD/include/CUST_SKY.h
# export TARGET_BUILD_SKY_CUST_INCLUDE_DIR=$PWD/include
#######################################################
export ARCH=arm
export PATH=~/toolchain/arm-eabi-4.4.3/bin:$PATH
export PANTECH_ANDROID_FLAGS="-DFEATURE_AARM_RELEASE_MODE -DT_EF30S -include $PWD/include/CUST_PANTECH.h -DFIRM_VER=\\\"S000000\\\" -DSYS_MODEL_NAME=\\\"EF30S\\\" -DPANTECH_MODEL_NAME=\\\"IM-A730S\\\""
# Define KERNEL Configuration (depending on the SKY MODEL)
KERNEL_DEFCONFIG=msm7630-perf_ef30s_ws20_defconfig

# Build LINUX KERNEL
mkdir -p ./obj/KERNEL_OBJ/
make O=./obj/KERNEL_OBJ ARCH=arm CROSS_COMPILE=arm-eabi- $KERNEL_DEFCONFIG
#make O=./obj/KERNEL_OBJ ARCH=arm CROSS_COMPILE=arm-eabi- menuconfig
#cp ./obj/KERNEL_OBJ/.config ./kernel/$KERNEL_DECONFIG
make -j4 O=./obj/KERNEL_OBJ ARCH=arm CROSS_COMPILE=arm-eabi-

