# BIOS Driver Project

This project implements a BIOS driver with support for Human Interface Infrastructure (HII). The driver provides functionality for managing resizable BARs and includes a user-friendly interface for configuration access.

## Project Structure

- **Hii**: Contains files related to the Human Interface Infrastructure.
  - `HiiStrings.uni`: Unicode strings for user-visible messages.
  - `HiiConfigAccess.c`: Implementation of the configuration access protocol.
  - `HiiConfigAccess.h`: Header file for configuration access functions.
  - `HiiDatabase.c`: Manages the HII database for storing and retrieving data.
  - `HiiDatabase.h`: Header file for HII database management functions.

- **Include**: Header files for various components.
  - `pciRegs.h`: Definitions for PCI register mappings.
  - `PciHostBridgeResourceAllocation.h`: Protocol definitions for PCI host bridge resource allocation.

- **ReBarDxe**: Main implementation of the BIOS driver.
  - `ReBar.c`: Handles resizable BAR functionality.
  - `ReBar.inf`: INF file providing metadata for the driver.
  - `ReBar.h`: Header file for functions and data structures used in ReBar.c.

- **Library**: Contains library files for debugging and memory allocation.
  - `DebugLib.c`: Implements debugging functions.
  - `DebugLib.h`: Header file for debugging functions.
  - `MemoryAllocationLib.c`: Implements memory allocation functions.
  - `MemoryAllocationLib.h`: Header file for memory allocation functions.

- **Package**: Contains package definition files.
  - `BIOSDriver.dsc`: DSC file defining the driver package.
  - `BIOSDriver.fdf`: FDF file specifying build configuration.

- **Tools**: Contains build scripts.
  - `BuildScripts/build.sh`: Shell script to automate the build process.

## Features

- **Resizable BAR Support**: The driver allows for the configuration of resizable BARs, enhancing memory access for devices.
- **User Interface**: The integration of HII provides a user-friendly interface for configuration management.
- **Configuration Access**: The driver implements functions to retrieve and set configuration data through the HII protocols.

## Getting Started

1. Clone the repository.
2. Navigate to the project directory.
3. Run the build script: `./Tools/BuildScripts/build.sh`.
4. Follow the instructions for flashing the BIOS driver to your system.

## Testing

Ensure to validate the HII functionality by testing the configuration access and ensuring that the user interface behaves as expected.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.