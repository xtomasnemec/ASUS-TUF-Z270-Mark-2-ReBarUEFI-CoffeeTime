#ifndef REBAR_H
#define REBAR_H

#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/HiiConfigAccess.h>
#include <Protocol/HiiDatabase.h>

// Function declarations for ReBar.c
EFI_STATUS ReBarInitialize(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable);
EFI_STATUS ReBarSetConfiguration(IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL *This, IN CONST EFI_STRING Configuration, OUT EFI_STRING *Progress);
EFI_STATUS ReBarGetConfiguration(IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL *This, OUT EFI_STRING *Configuration, OUT EFI_STRING *Progress);
EFI_STATUS ReBarRouteConfig(IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL *This, IN CONST EFI_STRING Configuration, OUT EFI_STRING *Progress);

#endif // REBAR_H