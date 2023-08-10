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

#include "AeadAesGcmDecrypt.h"

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
RunTestHarness(
  IN VOID  *TestBuffer,
  IN UINTN TestBufferSize
  )
{
  UINT8    OutBuffer[1024];
  UINTN    OutBufferSize;

  OutBufferSize = sizeof (OutBuffer);
  ZeroMem (OutBuffer, sizeof (OutBuffer));

  //Test parameter Kye
  AeadAesGcmDecrypt (
              TestBuffer,
              TestBufferSize,
              gcm_iv,
              sizeof (gcm_iv),
              gcm_aad,
              sizeof (gcm_aad),
              gcm_ct,
              sizeof (gcm_ct),
              gcm_tag,
              sizeof (gcm_tag),
              OutBuffer,
              &OutBufferSize
              );
             
}
