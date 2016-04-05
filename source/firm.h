/*
*   firm.h
*       by Reisyukaku / Aurora Wright
*   Copyright (c) 2016 All Rights Reserved
*/

#pragma once

#include "types.h"

#define PDN_MPCORE_CFG (*(vu32 *)0x10140FFC)
#define PDN_SPI_CNT    (*(vu32 *)0x101401C0)

//FIRM Header layout
typedef struct firmSectionHeader {
    u32 offset;
    u8 *address;
    u32 size;
    u32 procType;
    u8 hash[0x20];
} firmSectionHeader;

typedef struct firmHeader {
    u32 magic;
    u32 reserved1;
    u8 *arm11Entry;
    u8 *arm9Entry;
    u8 reserved2[0x30];
    firmSectionHeader section[4];
} firmHeader;

typedef struct patchData {
    u32 offset[2];
    union {
        u8 type0[8];
        u16 type1;
    } patch;
    u32 type;
} patchData;

void setupCFW(void);
void loadFirm(void);
void patchFirm(void);
void launchFirm(void);