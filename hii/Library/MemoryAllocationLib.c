#include <Uefi.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>

// Memory allocation functions for the BIOS driver project

VOID* AllocatePool(IN UINTN Size) {
    VOID* Buffer;

    if (Size == 0) {
        return NULL;
    }

    Buffer = AllocateZeroPool(Size);
    if (Buffer == NULL) {
        DEBUG((DEBUG_ERROR, "Memory allocation failed for size: %d\n", Size));
    }

    return Buffer;
}

VOID FreePool(IN VOID* Buffer) {
    if (Buffer != NULL) {
        FreePool(Buffer);
    }
}