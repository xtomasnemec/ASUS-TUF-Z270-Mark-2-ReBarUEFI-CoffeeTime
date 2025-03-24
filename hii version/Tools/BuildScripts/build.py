#!/usr/bin/env python3
#
# Copyright (c) 2022 xCuri0 <zkqri0@gmail.com>
# SPDX-License-Identifier: MIT
#
import os
import sys
import glob
import shutil
import subprocess
from pefile import PE

name = "ReBarDxe"
version = "2.0"
GUID = "a8ee1777-a4f5-4345-9da4-13742084d31e"
shell = sys.platform == "win32"
buildtype = "RELEASE"

def filesub(filep, f, r):
    """Replace a string in a file."""
    with open(filep, 'r') as file:
        filedata = file.read()
    filedata = filedata.replace(f, r)
    with open(filep, 'w') as file:
        file.write(filedata)

def set_bit(data, bit):
    """Sets a specific bit."""
    return data | (1 << bit)

def set_nx_compat_flag(pe):
    """Sets the nx_compat flag to 1 in the PE/COFF file."""
    dllchar = pe.OPTIONAL_HEADER.DllCharacteristics
    dllchar = set_bit(dllchar, 8)  # 8th bit is the nx_compat_flag
    pe.OPTIONAL_HEADER.DllCharacteristics = dllchar
    pe.merge_modified_section_data()
    return pe

if len(sys.argv) > 1:
    buildtype = sys.argv[1].upper()

# Handle GitHub Actions environment
if len(sys.argv) == 3:
    print("TARGET: ", os.environ['TARGET'])
    print("TARGET_ARCH: ", os.environ['TARGET_ARCH'])
    print("TOOL_CHAIN_TAG: ", os.environ['TOOL_CHAIN_TAG'])

    # Update Conf/target.txt
    filesub("./Conf/target.txt", "DEBUG", os.environ['TARGET'])
    filesub("./Conf/target.txt", "IA32", os.environ['TARGET_ARCH'])
    filesub("./Conf/target.txt", "VS2015x86", os.environ['TOOL_CHAIN_TAG'])
else:
    os.chdir("../..")

# Set the working directory to the project root
project_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
os.chdir(project_dir)

# Define build output directory
output_dir = "BuildOutput"

# Create output directory if it doesn't exist
os.makedirs(output_dir, exist_ok=True)

# Clean previous builds
print("Cleaning previous builds...")
for root, dirs, files in os.walk(output_dir):
    for file in files:
        os.remove(os.path.join(root, file))
    for dir in dirs:
        shutil.rmtree(os.path.join(root, dir))

# Run the build command
subprocess.run(["build", "--platform=ReBarUEFI/ReBarDxe/ReBar.dsc"], shell=shell, env=os.environ, stderr=sys.stderr, stdout=sys.stdout)

# Locate the built EFI file
ReBarDXE = glob.glob(f"./Build/ReBarUEFI/{buildtype}_*/X64/ReBarDxe.efi")

if len(ReBarDXE) != 1:
    print("Build failed")
    sys.exit(1)

# Set NX_COMPAT flag
pe = PE(ReBarDXE[0])
set_nx_compat_flag(pe)

os.remove(ReBarDXE[0])
pe.write(ReBarDXE[0])

print(ReBarDXE[0])
print("Building FFS")
os.chdir(os.path.dirname(ReBarDXE[0]))

# Clean up old files
try:
    os.remove("pe32.sec")
    os.remove("name.sec")
    os.remove("ReBarDxe.ffs")
except FileNotFoundError:
    pass

# Generate sections and FFS file
subprocess.run(["GenSec", "-o", "pe32.sec", "ReBarDxe.efi", "-S", "EFI_SECTION_PE32"], shell=shell, env=os.environ, stderr=sys.stderr, stdout=sys.stdout)
subprocess.run(["GenSec", "-o", "name.sec", "-S", "EFI_SECTION_USER_INTERFACE", "-n", name], shell=shell, env=os.environ, stderr=sys.stderr, stdout=sys.stdout)
subprocess.run(["GenFfs", "-g", GUID, "-o", "ReBarDxe.ffs", "-i", "pe32.sec", "-i", "name.sec", "-t", "EFI_FV_FILETYPE_DRIVER", "--checksum"], shell=shell, env=os.environ, stderr=sys.stderr, stdout=sys.stdout)

# Clean up temporary files
try:
    os.remove("pe32.sec")
    os.remove("name.sec")
except FileNotFoundError:
    pass

subprocess.run(["nmake", "/f", "Makefile"], shell=shell, env=os.environ, stderr=sys.stderr, stdout=sys.stdout)

print("Finished")