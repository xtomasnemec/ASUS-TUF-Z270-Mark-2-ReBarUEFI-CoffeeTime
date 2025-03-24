# This file defines the driver package and its components for the BIOS driver project.

[Package]
  Name = BIOSDriver
  Version = 1.0.0
  GUID = {YOUR-GUID-HERE}
  Maintainer = xCuri0 <zkqri0@gmail.com>
  License = MIT

[Library]
  DebugLib
  MemoryAllocationLib

[Protocol]
  gEfiHiiConfigAccessProtocolGuid
  gEfiHiiDatabaseProtocolGuid

[Component]
  Hii/HiiConfigAccess.c
  Hii/HiiDatabase.c
  ReBarDxe/ReBar.c

[File]
  Hii/HiiStrings.uni
  Include/pciRegs.h
  Include/PciHostBridgeResourceAllocation.h
  ReBarDxe/ReBar.inf
  Library/DebugLib.c
  Library/MemoryAllocationLib.c

[BuildOptions]
  BuildType = DEBUG
  Compiler = GCC

[Output]
  OutputDirectory = ../Build/BIOSDriver

[Dependencies]
  gEfiHiiConfigAccessProtocolGuid
  gEfiHiiDatabaseProtocolGuid

[End]