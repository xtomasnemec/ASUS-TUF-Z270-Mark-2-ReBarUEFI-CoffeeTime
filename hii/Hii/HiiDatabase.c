#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Protocol/HiiDatabase.h>
#include <Protocol/HiiConfigAccess.h>
#include "HiiDatabase.h"

// HII Database structure
typedef struct {
    EFI_HII_DATABASE_PROTOCOL *HiiDatabase;
    EFI_HANDLE DriverHandle;
} HII_DATABASE_INSTANCE;

static HII_DATABASE_INSTANCE *mHiiDatabaseInstance = NULL;

// Function to initialize the HII database
EFI_STATUS InitializeHiiDatabase(EFI_HANDLE ImageHandle) {
    EFI_STATUS Status;

    mHiiDatabaseInstance = AllocateZeroPool(sizeof(HII_DATABASE_INSTANCE));
    if (mHiiDatabaseInstance == NULL) {
        return EFI_OUT_OF_RESOURCES;
    }

    mHiiDatabaseInstance->DriverHandle = ImageHandle;

    // Locate the HII Database Protocol
    Status = gBS->LocateProtocol(&gEfiHiiDatabaseProtocolGuid, NULL, (VOID **)&mHiiDatabaseInstance->HiiDatabase);
    if (EFI_ERROR(Status)) {
        FreePool(mHiiDatabaseInstance);
        return Status;
    }

    return EFI_SUCCESS;
}

// Function to add a new HII package
EFI_STATUS AddHiiPackage(EFI_STRING_ID StringId, EFI_HII_PACKAGE_HEADER *PackageHeader) {
    EFI_STATUS Status;

    if (mHiiDatabaseInstance == NULL || mHiiDatabaseInstance->HiiDatabase == NULL) {
        return EFI_NOT_READY;
    }

    Status = mHiiDatabaseInstance->HiiDatabase->NewPackageList(mHiiDatabaseInstance->HiiDatabase, PackageHeader, NULL);
    if (EFI_ERROR(Status)) {
        return Status;
    }

    return EFI_SUCCESS;
}

// Function to remove a HII package
EFI_STATUS RemoveHiiPackage(EFI_STRING_ID StringId) {
    EFI_STATUS Status;

    if (mHiiDatabaseInstance == NULL || mHiiDatabaseInstance->HiiDatabase == NULL) {
        return EFI_NOT_READY;
    }

    Status = mHiiDatabaseInstance->HiiDatabase->RemovePackageList(mHiiDatabaseInstance->HiiDatabase, StringId);
    if (EFI_ERROR(Status)) {
        return Status;
    }

    return EFI_SUCCESS;
}

// Function to cleanup the HII database instance
VOID CleanupHiiDatabase() {
    if (mHiiDatabaseInstance != NULL) {
        FreePool(mHiiDatabaseInstance);
        mHiiDatabaseInstance = NULL;
    }
}