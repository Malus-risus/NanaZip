﻿/*
 * PROJECT:   NanaZip
 * FILE:      NanaZip.Codecs.MultiThreadWrapper.LZ4.h
 * PURPOSE:   Definition for LZ4 Multi Thread Wrapper
 *
 * LICENSE:   The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#ifndef NANAZIP_CODECS_MULTI_THREAD_WRAPPER_LZ4
#define NANAZIP_CODECS_MULTI_THREAD_WRAPPER_LZ4

#include "NanaZip.Codecs.MultiThreadWrapper.Common.h"

#include <stdint.h>
#include <lz4-mt.h>

EXTERN_C int NanaZipCodecsLz4Read(
    void* Context,
    LZ4MT_Buffer* Input);

EXTERN_C int NanaZipCodecsLz4Write(
    void* Context,
    LZ4MT_Buffer* Output);

#endif // !NANAZIP_CODECS_MULTI_THREAD_WRAPPER_LZ4
