/** @file
Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <Uefi.h>

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseCryptLib.h>

#define TOTAL_SIZE (512 * 1024)


UINTN
EFIAPI
GetMaxBufferSize (
  VOID
  )
{
  return TOTAL_SIZE;
}

VOID
EFIAPI
TestBigNumRShiftCase1(
  IN VOID  *TestBuffer,
  IN UINTN TestBufferSize
  )
{
  UINTN N = 0;
  UINT8 BnRes[TOTAL_SIZE];

  BigNumRShift(TestBuffer, N, BnRes);
}

VOID
EFIAPI
TestBigNumRShiftCase2(
  IN VOID  *TestBuffer,
  IN UINTN TestBufferSize
  )
{
  UINTN N = 0xFFFFFFFF;
  UINT8 BnRes[TOTAL_SIZE];

  BigNumRShift(TestBuffer, N, BnRes);
}

VOID
EFIAPI
TestBigNumRShiftCase3(
  IN VOID  *TestBuffer,
  IN UINTN TestBufferSize
  )
{
  UINTN N = *(UINTN *)TestBuffer;
  UINT8 BnRes[TOTAL_SIZE];

  BigNumRShift(TestBuffer, N, BnRes);
}

VOID
EFIAPI
RunTestHarness(
  IN VOID  *TestBuffer,
  IN UINTN TestBufferSize
  )
{
  TestBigNumRShiftCase1(TestBuffer, TestBufferSize);
  TestBigNumRShiftCase2(TestBuffer, TestBufferSize);
  TestBigNumRShiftCase3(TestBuffer, TestBufferSize);
}
