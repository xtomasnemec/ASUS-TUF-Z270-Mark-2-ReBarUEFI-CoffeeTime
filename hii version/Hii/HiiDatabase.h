#ifndef HII_DATABASE_H
#define HII_DATABASE_H

#include <Uefi.h>
#include <Library/HiiLib.h>
#include <Protocol/HiiDatabase.h>

// Function declarations for HII database management
EFI_STATUS HiiDatabaseAddString(
    IN EFI_HII_DATABASE_PROTOCOL *This,
    IN CONST CHAR16 *String,
    OUT EFI_HANDLE *Handle
);

EFI_STATUS HiiDatabaseRemoveString(
    IN EFI_HII_DATABASE_PROTOCOL *This,
    IN EFI_HANDLE Handle
);

EFI_STATUS HiiDatabaseGetString(
    IN EFI_HII_DATABASE_PROTOCOL *This,
    IN EFI_HANDLE Handle,
    OUT CHAR16 **String
);

#endif // HII_DATABASE_H