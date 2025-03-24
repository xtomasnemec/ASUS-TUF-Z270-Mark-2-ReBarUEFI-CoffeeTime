#ifndef HII_CONFIG_ACCESS_H
#define HII_CONFIG_ACCESS_H

#include <Uefi.h>
#include <Protocol/HiiConfigAccess.h>

// Function prototypes for HII Configuration Access Protocol
EFI_STATUS
EFIAPI
HiiConfigAccessGetVariable (
    IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL *This,
    IN CHAR8 *VariableName,
    OUT UINTN *VariableSize,
    OUT VOID *VariableValue
);

EFI_STATUS
EFIAPI
HiiConfigAccessSetVariable (
    IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL *This,
    IN CHAR8 *VariableName,
    IN UINTN VariableSize,
    IN VOID *VariableValue
);

EFI_STATUS
EFIAPI
HiiConfigAccessRouteConfig (
    IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL *This,
    IN CONST CHAR8 *Configuration,
    OUT CHAR8 **Progress
);

#endif // HII_CONFIG_ACCESS_H