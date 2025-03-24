#include <Uefi.h>
#include <Library/DebugLib.h>

// Debugging functions for the BIOS driver project

VOID
EFIAPI
DebugPrint (
    IN UINTN DebugLevel,
    IN CONST CHAR8 *Format,
    ...
    )
{
    VA_LIST Args;

    VA_START(Args, Format);
    // Implement the actual debug print functionality here
    // This could involve sending output to a serial port, console, etc.
    // For now, we will just use the UEFI DebugLib's DEBUG macro
    DEBUG((DebugLevel, Format, Args));
    VA_END(Args);
}

VOID
EFIAPI
DebugAssert (
    IN BOOLEAN Condition,
    IN CONST CHAR8 *FileName,
    IN UINTN LineNumber
    )
{
    if (!Condition) {
        // Handle the assertion failure, e.g., log the error and halt
        DEBUG((DEBUG_ERROR, "Assertion failed in %a at line %d\n", FileName, LineNumber));
        // Optionally, you could invoke a breakpoint or halt the system
    }
}