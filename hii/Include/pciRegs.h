#ifndef PCI_REGS_H
#define PCI_REGS_H

// PCI Configuration Space Registers
#define PCI_CFG_SPACE_SIZE          256
#define PCI_CFG_SPACE_EXP_SIZE     4096

// PCI Extended Capability IDs
#define PCI_EXT_CAP_ID_REBAR       0x10

// Resizable BAR Control Register
#define PCI_REBAR_CTRL              0x40
#define PCI_REBAR_CTRL_NBAR_MASK    0xF
#define PCI_REBAR_CTRL_NBAR_SHIFT   0
#define PCI_REBAR_CTRL_BAR_IDX      0x1F
#define PCI_REBAR_CTRL_BAR_SIZE     0x3F
#define PCI_REBAR_CTRL_BAR_SHIFT    8

// Resizable BAR Capability Register
#define PCI_REBAR_CAP               0x44
#define PCI_REBAR_CAP_SIZES         0x3F0

// PCI Configuration Space Access Macros
#define PCI_EXT_CAP_ID(header)      ((header) & 0xFFFF)
#define PCI_EXT_CAP_NEXT(header)    (((header) >> 16) & 0xFFFF)

#endif // PCI_REGS_H