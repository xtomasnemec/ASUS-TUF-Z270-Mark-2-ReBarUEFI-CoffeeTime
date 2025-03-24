#ifndef PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_H
#define PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_H

#include <Uefi.h>
#include <Protocol/PciRootBridgeIo.h>

// Define the PCI Host Bridge Resource Allocation Protocol GUID
#define EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GUID \
    { 0x8b3b7c3e, 0x3c4d, 0x4c3c, { 0x8f, 0x3e, 0x5d, 0x4c, 0x8e, 0x3b, 0x2f, 0x1e } }

// Forward declaration of the protocol structure
typedef struct _EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL;

// Define the function prototypes for the protocol
typedef EFI_STATUS (EFIAPI *EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_PREPROCESS_CONTROLLER)(
    IN EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL *This,
    IN EFI_HANDLE RootBridgeHandle,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS PciAddress,
    IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE Phase
);

// Define the protocol structure
struct _EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL {
    EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_PREPROCESS_CONTROLLER PreprocessController;
    // Additional function pointers can be added here
};

#endif // PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_H