#ifndef DEBUG_LIB_H
#define DEBUG_LIB_H

#include <Uefi.h>

VOID
EFIAPI
DebugPrint (
    IN UINTN DebugLevel,
    IN CONST CHAR8 *Format,
    ...
);

#endif // DEBUG_LIB_H