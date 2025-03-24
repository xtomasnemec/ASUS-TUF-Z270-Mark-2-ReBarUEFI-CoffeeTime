#ifndef MEMORY_ALLOCATION_LIB_H
#define MEMORY_ALLOCATION_LIB_H

#include <Uefi.h>

// Memory allocation functions
EFI_STATUS AllocatePool(IN UINTN Size, OUT VOID **Buffer);
EFI_STATUS FreePool(IN VOID *Buffer);

#endif // MEMORY_ALLOCATION_LIB_H