#!/bin/bash
#/******************************************************************************
# * # License
# * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
# ******************************************************************************
# * The licensor of this software is Silicon Laboratories Inc. Your use of this
# * software is governed by the terms of Silicon Labs Master Software License
# * Agreement (MSLA) available at
# * www.silabs.com/about-us/legal/master-software-license-agreement. This
# * software is distributed to you in Source Code format and is governed by the
# * sections of the MSLA applicable to Source Code.
# *
# *****************************************************************************/

# Rust links native static libraries as public. This means, if we want to link the produced library into a binary,
# we would have 'duplicate symbols' linking errors.
# This script removes all the o files that where linked in at this point. 
# Because we know that our native libraries are c/c++ sources. 
# we simply glob all c/c++ symbols in the produced library and remove them.
ofiles=`${CMAKE_AR} -t $1 | grep -E '.cpp.o$$|.c.o$$'`
if [ ! -z "$ofiles" ]; then
    ${CMAKE_AR} -d $1 $ofiles
fi

# In consecutive runs, cargo decides to update the archive index back to before stripping.
# As workaround, run ranlib explicitly to make sure the archive index is up to date with the archive content.
${CMAKE_RANLIB} $1