/*******************************************************************************
* Copyright 2010 Broadcom Corporation.  All rights reserved.
*
* 	@file	drivers/video/broadcom/displays/lcd_s6d05a1x01.h
*
* Unless you and Broadcom execute a separate DISPCTRL_WRitten software license agreement
* governing use of this software, this software is licensed to you under the
* terms of the GNU General Public License version 2, available at
* http://www.gnu.org/copyleft/gpl.html (the "GPL").
*
* Notwithstanding the above, under no circumstances may you combine this
* software in any way with any other Broadcom software provided under a license
* other than the GPL, without Broadcom's express prior DISPCTRL_WRitten consent.
*******************************************************************************/

/****************************************************************************
*
*  lcd_NT35512.h
*
*  PURPOSE:
*    This is the LCD-specific code for a NT35510 module.
*
*****************************************************************************/

/* ---- Include Files ---------------------------------------------------- */
#ifndef __BCM_LCD_NT35512_H
#define __BCM_LCD_NT35512_H

//  LCD command definitions
#define PIXEL_FORMAT_RGB565  0x05   // for 16 bits
#define PIXEL_FORMAT_RGB666  0x06   // for 18 bits
#define PIXEL_FORMAT_RGB888  0x07   // for 24 bits

typedef enum {
	NT35512_CMD_NOP	= 0x00,
	NT35512_CMD_SWRESET	= 0x01,
	NT35512_CMD_RDDID	= 0x04,
	NT35512_CMD_RDNUMED	= 0x05,
	NT35512_CMD_RDDPM	= 0x0A,
	NT35512_CMD_RDDMADCTL	= 0x0B,
	NT35512_CMD_RDDCOLMOD	= 0x0C,
	NT35512_CMD_RDDIM	= 0x0D,
	NT35512_CMD_RDDSM	= 0x0E,
	NT35512_CMD_RDDSDR	= 0x0F,
	NT35512_CMD_SLPIN	= 0x10,
	NT35512_CMD_SLPOUT	= 0x11,
	NT35512_CMD_PTLON	= 0x12,
	NT35512_CMD_NORON	= 0x13,
	NT35512_CMD_INVOFF	= 0x20,
	NT35512_CMD_INVON	= 0x21,
	NT35512_CMD_ALLPOFF	= 0x22,
	NT35512_CMD_ALLPON	= 0x23,
	NT35512_CMD_GAMSET	= 0x26,
	NT35512_CMD_DISPOFF	= 0x28,
	NT35512_CMD_DISPON	= 0x29,
	NT35512_CMD_CASET	= 0x2A,
	NT35512_CMD_RASET	= 0x2B,
	NT35512_CMD_RAMWR	= 0x2C,
	NT35512_CMD_RAMRD	= 0x2E,
	NT35512_CMD_PTLAR	= 0x30,
	NT35512_CMD_TEOFF	= 0x34,
	NT35512_CMD_TEON	= 0x35,
	NT35512_CMD_MADCTL	= 0x36,
	NT35512_CMD_IDMOFF	= 0x38,
	NT35512_CMD_IDMON	= 0x39,
	NT35512_CMD_COLMOD	= 0x3A,
	NT35512_CMD_RAMWRC	= 0x3C,
	NT35512_CMD_RAMRDC	= 0x3E,
	NT35512_CMD_STESL	= 0x44,
	NT35512_CMD_GSL	= 0x45,
	NT35512_CMD_DSTBON	= 0x4F,
	NT35512_CMD_WRPFD	= 0x50,
	NT35512_CMD_WRGAMMSET	= 0x58,
	NT35512_CMD_RDFCS	= 0xAA,
	NT35512_CMD_RDCCS	= 0xAF,
	NT35512_CMD_DOPCTR      = 0xB1,
	NT35512_CMD_RDID1	= 0xDA,
	NT35512_CMD_RDID2	= 0xDB,
	NT35512_CMD_RDID3	= 0xDC,
	NT35512_CMD_MAUCCTR     = 0xF0,
} NT35512_CMD_T;


//Based on data in a xlsx provided by vendor
//ax- made change based on apps note. Power setting using page 1 command set
DISPCTRL_REC_T power_setting_seq_cmdlist[] =
{	
	{DISPCTRL_WR_CMND, NT35512_CMD_SLPOUT, 0},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x01},
	{DISPCTRL_WR_CMND, 0xB0, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_CMND, 0xB6, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x34},
	{DISPCTRL_WR_DATA, 0, 0x34},
	{DISPCTRL_WR_DATA, 0, 0x34},
	{DISPCTRL_WR_CMND, 0xB1, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_CMND, 0xB7, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_CMND, 0xB3, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x05},
	{DISPCTRL_WR_DATA, 0, 0x05},
	{DISPCTRL_WR_DATA, 0, 0x05},
	{DISPCTRL_WR_CMND, 0xB9, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_CMND_DATA, 0xBF, 0x01},
	//{DISPCTRL_WR_DATA, 0, 0x01},
	{DISPCTRL_WR_CMND, 0xB5, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x0B},
	{DISPCTRL_WR_DATA, 0, 0x0B},
	{DISPCTRL_WR_DATA, 0, 0x0B},
	{DISPCTRL_WR_CMND, 0xBA, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_DATA, 0, 0x24},
	{DISPCTRL_WR_CMND_DATA, 0xC2, 0x01},
	{DISPCTRL_WR_CMND, 0xBC, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_CMND, 0xBD, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x09},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T initializing_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_CMND_DATA, 0xB6, 0x0A},
	{DISPCTRL_WR_CMND, 0xB7, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_CMND, 0xB8, 0x01},
	{DISPCTRL_WR_DATA, 0, 0x01},
	{DISPCTRL_WR_DATA, 0, 0x05},
	{DISPCTRL_WR_DATA, 0, 0x05},
	{DISPCTRL_WR_DATA, 0, 0x05},
	{DISPCTRL_WR_CMND_DATA, 0xBA, 0x1},
	{DISPCTRL_WR_CMND, 0xBC, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_CMND, 0xCC, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x03},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_CMND, 0xB1, 0x0},
	{DISPCTRL_WR_DATA, 0, 0xFC},
	{DISPCTRL_WR_DATA, 0, 0x06},
	{DISPCTRL_WR_CMND_DATA, 0x35, 0x00},
	{DISPCTRL_WR_CMND_DATA, 0x36, 0xC2},
	//{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T test_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_CMND, 0xB1, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x08},
	//{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T disable_CMD2_seq_cmdlist[] =
{
	//{DISPCTRL_WR_CMND_DATA, NT35512_CMD_MAUCCTR, 0x55},
	{DISPCTRL_WR_CMND, 0xF0, 0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_WR_DATA, 0, 0x00},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T gama_R_plus_setting_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_SLPOUT, 0},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x01},
	//{DISPCTRL_WR_CMND_DATA, 0xD1, 0x00}, 	// 1;
	{DISPCTRL_WR_CMND, 0xD1, 0},
	{DISPCTRL_WR_DATA, 0, 0x00},			// 1
	{DISPCTRL_WR_DATA, 0, 0x01},			// 2;
	{DISPCTRL_WR_DATA, 0, 0x00},			// 3
	{DISPCTRL_WR_DATA, 0, 0x1D},			// 4
	{DISPCTRL_WR_DATA, 0, 0x00},  			// 5
	{DISPCTRL_WR_DATA, 0, 0x48},			// 6
	{DISPCTRL_WR_DATA, 0, 0x00},			// 7
	{DISPCTRL_WR_DATA, 0, 0x64},			// 8
	{DISPCTRL_WR_DATA, 0, 0x00},			// 9
	{DISPCTRL_WR_DATA, 0, 0x7E},			// 10
	{DISPCTRL_WR_DATA, 0, 0x00},			// 11
	{DISPCTRL_WR_DATA, 0, 0xB1},			// 12
	{DISPCTRL_WR_DATA, 0, 0x00},			// 13
	{DISPCTRL_WR_DATA, 0, 0xD3},			// 14
	
	{DISPCTRL_WR_DATA, 0, 0x01},			// 15
	{DISPCTRL_WR_DATA, 0, 0x07},			// 16
	{DISPCTRL_WR_DATA, 0, 0x01},			// 17
	{DISPCTRL_WR_DATA, 0, 0x35},			// 18
	{DISPCTRL_WR_DATA, 0, 0x01},			// 19
	{DISPCTRL_WR_DATA, 0, 0x7B},			// 20
	{DISPCTRL_WR_DATA, 0, 0x01},			// 21
	{DISPCTRL_WR_DATA, 0, 0xB3},			// 22
	
	{DISPCTRL_WR_DATA, 0, 0x02},			// 23
	{DISPCTRL_WR_DATA, 0, 0x03},			// 24
	{DISPCTRL_WR_DATA, 0, 0x02},			// 25
	{DISPCTRL_WR_DATA, 0, 0x48},			// 26
	{DISPCTRL_WR_DATA, 0, 0x02},			// 27
	{DISPCTRL_WR_DATA, 0, 0x49},			// 28
	{DISPCTRL_WR_DATA, 0, 0x02},			// 29
	{DISPCTRL_WR_DATA, 0, 0x88},			// 30
	{DISPCTRL_WR_DATA, 0, 0x02},			// 31
	{DISPCTRL_WR_DATA, 0, 0xC7},			// 32
	{DISPCTRL_WR_DATA, 0, 0x02},			// 33
	{DISPCTRL_WR_DATA, 0, 0xF3},			// 34

	{DISPCTRL_WR_DATA, 0, 0x03},			// 35
	{DISPCTRL_WR_DATA, 0, 0x21},			// 35
	{DISPCTRL_WR_DATA, 0, 0x03},			// 37
	{DISPCTRL_WR_DATA, 0, 0x46},			// 38
	{DISPCTRL_WR_DATA, 0, 0x03},			// 39
	{DISPCTRL_WR_DATA, 0, 0x74},			// 40
	{DISPCTRL_WR_DATA, 0, 0x03},			// 41
	{DISPCTRL_WR_DATA, 0, 0x8F},			// 42
	{DISPCTRL_WR_DATA, 0, 0x03},			// 43
	{DISPCTRL_WR_DATA, 0, 0xA3},			// 44
	{DISPCTRL_WR_DATA, 0, 0x03},			// 45
	{DISPCTRL_WR_DATA, 0, 0xAC},			// 46
	{DISPCTRL_WR_DATA, 0, 0x03},			// 47
	{DISPCTRL_WR_DATA, 0, 0xB7},			// 48
	{DISPCTRL_WR_DATA, 0, 0x03},			// 49
	{DISPCTRL_WR_DATA, 0, 0xBF},			// 50
	{DISPCTRL_WR_DATA, 0, 0x03},			// 51
	{DISPCTRL_WR_DATA, 0, 0xFE},			// 52
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T gama_G_plus_setting_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_SLPOUT, 0},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x01},
	//{DISPCTRL_WR_CMND_DATA, 0xD1, 0x00}, 	// 1;
	{DISPCTRL_WR_CMND, 0xD2, 0},
	{DISPCTRL_WR_DATA, 0, 0x00},			// 1
	{DISPCTRL_WR_DATA, 0, 0x01},			// 2;
	{DISPCTRL_WR_DATA, 0, 0x00},			// 3
	{DISPCTRL_WR_DATA, 0, 0x1D},			// 4
	{DISPCTRL_WR_DATA, 0, 0x00},  			// 5
	{DISPCTRL_WR_DATA, 0, 0x48},			// 6
	{DISPCTRL_WR_DATA, 0, 0x00},			// 7
	{DISPCTRL_WR_DATA, 0, 0x64},			// 8
	{DISPCTRL_WR_DATA, 0, 0x00},			// 9
	{DISPCTRL_WR_DATA, 0, 0x7E},			// 10
	{DISPCTRL_WR_DATA, 0, 0x00},			// 11
	{DISPCTRL_WR_DATA, 0, 0xB1},			// 12
	{DISPCTRL_WR_DATA, 0, 0x00},			// 13
	{DISPCTRL_WR_DATA, 0, 0xD3},			// 14
	
	{DISPCTRL_WR_DATA, 0, 0x01},			// 15
	{DISPCTRL_WR_DATA, 0, 0x07},			// 16
	{DISPCTRL_WR_DATA, 0, 0x01},			// 17
	{DISPCTRL_WR_DATA, 0, 0x35},			// 18
	{DISPCTRL_WR_DATA, 0, 0x01},			// 19
	{DISPCTRL_WR_DATA, 0, 0x7B},			// 20
	{DISPCTRL_WR_DATA, 0, 0x01},			// 21
	{DISPCTRL_WR_DATA, 0, 0xB3},			// 22
	
	{DISPCTRL_WR_DATA, 0, 0x02},			// 23
	{DISPCTRL_WR_DATA, 0, 0x03},			// 24
	{DISPCTRL_WR_DATA, 0, 0x02},			// 25
	{DISPCTRL_WR_DATA, 0, 0x48},			// 26
	{DISPCTRL_WR_DATA, 0, 0x02},			// 27
	{DISPCTRL_WR_DATA, 0, 0x49},			// 28
	{DISPCTRL_WR_DATA, 0, 0x02},			// 29
	{DISPCTRL_WR_DATA, 0, 0x88},			// 30
	{DISPCTRL_WR_DATA, 0, 0x02},			// 31
	{DISPCTRL_WR_DATA, 0, 0xC7},			// 32
	{DISPCTRL_WR_DATA, 0, 0x02},			// 33
	{DISPCTRL_WR_DATA, 0, 0xF3},			// 34

	{DISPCTRL_WR_DATA, 0, 0x03},			// 35
	{DISPCTRL_WR_DATA, 0, 0x21},			// 35
	{DISPCTRL_WR_DATA, 0, 0x03},			// 37
	{DISPCTRL_WR_DATA, 0, 0x46},			// 38
	{DISPCTRL_WR_DATA, 0, 0x03},			// 39
	{DISPCTRL_WR_DATA, 0, 0x74},			// 40
	{DISPCTRL_WR_DATA, 0, 0x03},			// 41
	{DISPCTRL_WR_DATA, 0, 0x8F},			// 42
	{DISPCTRL_WR_DATA, 0, 0x03},			// 43
	{DISPCTRL_WR_DATA, 0, 0xA3},			// 44
	{DISPCTRL_WR_DATA, 0, 0x03},			// 45
	{DISPCTRL_WR_DATA, 0, 0xAC},			// 46
	{DISPCTRL_WR_DATA, 0, 0x03},			// 47
	{DISPCTRL_WR_DATA, 0, 0xB7},			// 48
	{DISPCTRL_WR_DATA, 0, 0x03},			// 49
	{DISPCTRL_WR_DATA, 0, 0xBF},			// 50
	{DISPCTRL_WR_DATA, 0, 0x03},			// 51
	{DISPCTRL_WR_DATA, 0, 0xFE},			// 52
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T gama_B_plus_setting_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_SLPOUT, 0},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x01},
	//{DISPCTRL_WR_CMND_DATA, 0xD1, 0x00}, 	// 1;
	{DISPCTRL_WR_CMND, 0xD3, 0},
	{DISPCTRL_WR_DATA, 0, 0x00},			// 1
	{DISPCTRL_WR_DATA, 0, 0x01},			// 2;
	{DISPCTRL_WR_DATA, 0, 0x00},			// 3
	{DISPCTRL_WR_DATA, 0, 0x1D},			// 4
	{DISPCTRL_WR_DATA, 0, 0x00},  			// 5
	{DISPCTRL_WR_DATA, 0, 0x48},			// 6
	{DISPCTRL_WR_DATA, 0, 0x00},			// 7
	{DISPCTRL_WR_DATA, 0, 0x64},			// 8
	{DISPCTRL_WR_DATA, 0, 0x00},			// 9
	{DISPCTRL_WR_DATA, 0, 0x7E},			// 10
	{DISPCTRL_WR_DATA, 0, 0x00},			// 11
	{DISPCTRL_WR_DATA, 0, 0xB1},			// 12
	{DISPCTRL_WR_DATA, 0, 0x00},			// 13
	{DISPCTRL_WR_DATA, 0, 0xD3},			// 14
	
	{DISPCTRL_WR_DATA, 0, 0x01},			// 15
	{DISPCTRL_WR_DATA, 0, 0x07},			// 16
	{DISPCTRL_WR_DATA, 0, 0x01},			// 17
	{DISPCTRL_WR_DATA, 0, 0x35},			// 18
	{DISPCTRL_WR_DATA, 0, 0x01},			// 19
	{DISPCTRL_WR_DATA, 0, 0x7B},			// 20
	{DISPCTRL_WR_DATA, 0, 0x01},			// 21
	{DISPCTRL_WR_DATA, 0, 0xB3},			// 22
	
	{DISPCTRL_WR_DATA, 0, 0x02},			// 23
	{DISPCTRL_WR_DATA, 0, 0x03},			// 24
	{DISPCTRL_WR_DATA, 0, 0x02},			// 25
	{DISPCTRL_WR_DATA, 0, 0x48},			// 26
	{DISPCTRL_WR_DATA, 0, 0x02},			// 27
	{DISPCTRL_WR_DATA, 0, 0x49},			// 28
	{DISPCTRL_WR_DATA, 0, 0x02},			// 29
	{DISPCTRL_WR_DATA, 0, 0x88},			// 30
	{DISPCTRL_WR_DATA, 0, 0x02},			// 31
	{DISPCTRL_WR_DATA, 0, 0xC7},			// 32
	{DISPCTRL_WR_DATA, 0, 0x02},			// 33
	{DISPCTRL_WR_DATA, 0, 0xF3},			// 34

	{DISPCTRL_WR_DATA, 0, 0x03},			// 35
	{DISPCTRL_WR_DATA, 0, 0x21},			// 35
	{DISPCTRL_WR_DATA, 0, 0x03},			// 37
	{DISPCTRL_WR_DATA, 0, 0x46},			// 38
	{DISPCTRL_WR_DATA, 0, 0x03},			// 39
	{DISPCTRL_WR_DATA, 0, 0x74},			// 40
	{DISPCTRL_WR_DATA, 0, 0x03},			// 41
	{DISPCTRL_WR_DATA, 0, 0x8F},			// 42
	{DISPCTRL_WR_DATA, 0, 0x03},			// 43
	{DISPCTRL_WR_DATA, 0, 0xA3},			// 44
	{DISPCTRL_WR_DATA, 0, 0x03},			// 45
	{DISPCTRL_WR_DATA, 0, 0xAC},			// 46
	{DISPCTRL_WR_DATA, 0, 0x03},			// 47
	{DISPCTRL_WR_DATA, 0, 0xB7},			// 48
	{DISPCTRL_WR_DATA, 0, 0x03},			// 49
	{DISPCTRL_WR_DATA, 0, 0xBF},			// 50
	{DISPCTRL_WR_DATA, 0, 0x03},			// 51
	{DISPCTRL_WR_DATA, 0, 0xFE},			// 52
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T gama_R_neg_setting_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_SLPOUT, 0},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x01},
	//{DISPCTRL_WR_CMND_DATA, 0xD1, 0x00}, 	// 1;
	{DISPCTRL_WR_CMND, 0xD4, 0},
	{DISPCTRL_WR_DATA, 0, 0x00},			// 1
	{DISPCTRL_WR_DATA, 0, 0x01},			// 2;
	{DISPCTRL_WR_DATA, 0, 0x00},			// 3
	{DISPCTRL_WR_DATA, 0, 0x1D},			// 4
	{DISPCTRL_WR_DATA, 0, 0x00},  			// 5
	{DISPCTRL_WR_DATA, 0, 0x48},			// 6
	{DISPCTRL_WR_DATA, 0, 0x00},			// 7
	{DISPCTRL_WR_DATA, 0, 0x64},			// 8
	{DISPCTRL_WR_DATA, 0, 0x00},			// 9
	{DISPCTRL_WR_DATA, 0, 0x7E},			// 10
	{DISPCTRL_WR_DATA, 0, 0x00},			// 11
	{DISPCTRL_WR_DATA, 0, 0xB1},			// 12
	{DISPCTRL_WR_DATA, 0, 0x00},			// 13
	{DISPCTRL_WR_DATA, 0, 0xD3},			// 14
	
	{DISPCTRL_WR_DATA, 0, 0x01},			// 15
	{DISPCTRL_WR_DATA, 0, 0x07},			// 16
	{DISPCTRL_WR_DATA, 0, 0x01},			// 17
	{DISPCTRL_WR_DATA, 0, 0x35},			// 18
	{DISPCTRL_WR_DATA, 0, 0x01},			// 19
	{DISPCTRL_WR_DATA, 0, 0x7B},			// 20
	{DISPCTRL_WR_DATA, 0, 0x01},			// 21
	{DISPCTRL_WR_DATA, 0, 0xB3},			// 22
	
	{DISPCTRL_WR_DATA, 0, 0x02},			// 23
	{DISPCTRL_WR_DATA, 0, 0x03},			// 24
	{DISPCTRL_WR_DATA, 0, 0x02},			// 25
	{DISPCTRL_WR_DATA, 0, 0x48},			// 26
	{DISPCTRL_WR_DATA, 0, 0x02},			// 27
	{DISPCTRL_WR_DATA, 0, 0x49},			// 28
	{DISPCTRL_WR_DATA, 0, 0x02},			// 29
	{DISPCTRL_WR_DATA, 0, 0x88},			// 30
	{DISPCTRL_WR_DATA, 0, 0x02},			// 31
	{DISPCTRL_WR_DATA, 0, 0xC7},			// 32
	{DISPCTRL_WR_DATA, 0, 0x02},			// 33
	{DISPCTRL_WR_DATA, 0, 0xF3},			// 34

	{DISPCTRL_WR_DATA, 0, 0x03},			// 35
	{DISPCTRL_WR_DATA, 0, 0x21},			// 35
	{DISPCTRL_WR_DATA, 0, 0x03},			// 37
	{DISPCTRL_WR_DATA, 0, 0x46},			// 38
	{DISPCTRL_WR_DATA, 0, 0x03},			// 39
	{DISPCTRL_WR_DATA, 0, 0x74},			// 40
	{DISPCTRL_WR_DATA, 0, 0x03},			// 41
	{DISPCTRL_WR_DATA, 0, 0x8F},			// 42
	{DISPCTRL_WR_DATA, 0, 0x03},			// 43
	{DISPCTRL_WR_DATA, 0, 0xA3},			// 44
	{DISPCTRL_WR_DATA, 0, 0x03},			// 45
	{DISPCTRL_WR_DATA, 0, 0xAC},			// 46
	{DISPCTRL_WR_DATA, 0, 0x03},			// 47
	{DISPCTRL_WR_DATA, 0, 0xB7},			// 48
	{DISPCTRL_WR_DATA, 0, 0x03},			// 49
	{DISPCTRL_WR_DATA, 0, 0xBF},			// 50
	{DISPCTRL_WR_DATA, 0, 0x03},			// 51
	{DISPCTRL_WR_DATA, 0, 0xFE},			// 52
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T gama_G_neg_setting_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_SLPOUT, 0},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x01},
	//{DISPCTRL_WR_CMND_DATA, 0xD1, 0x00}, 	// 1;
	{DISPCTRL_WR_CMND, 0xD5, 0},
	{DISPCTRL_WR_DATA, 0, 0x00},			// 1
	{DISPCTRL_WR_DATA, 0, 0x01},			// 2;
	{DISPCTRL_WR_DATA, 0, 0x00},			// 3
	{DISPCTRL_WR_DATA, 0, 0x1D},			// 4
	{DISPCTRL_WR_DATA, 0, 0x00},  			// 5
	{DISPCTRL_WR_DATA, 0, 0x48},			// 6
	{DISPCTRL_WR_DATA, 0, 0x00},			// 7
	{DISPCTRL_WR_DATA, 0, 0x64},			// 8
	{DISPCTRL_WR_DATA, 0, 0x00},			// 9
	{DISPCTRL_WR_DATA, 0, 0x7E},			// 10
	{DISPCTRL_WR_DATA, 0, 0x00},			// 11
	{DISPCTRL_WR_DATA, 0, 0xB1},			// 12
	{DISPCTRL_WR_DATA, 0, 0x00},			// 13
	{DISPCTRL_WR_DATA, 0, 0xD3},			// 14
	
	{DISPCTRL_WR_DATA, 0, 0x01},			// 15
	{DISPCTRL_WR_DATA, 0, 0x07},			// 16
	{DISPCTRL_WR_DATA, 0, 0x01},			// 17
	{DISPCTRL_WR_DATA, 0, 0x35},			// 18
	{DISPCTRL_WR_DATA, 0, 0x01},			// 19
	{DISPCTRL_WR_DATA, 0, 0x7B},			// 20
	{DISPCTRL_WR_DATA, 0, 0x01},			// 21
	{DISPCTRL_WR_DATA, 0, 0xB3},			// 22
	
	{DISPCTRL_WR_DATA, 0, 0x02},			// 23
	{DISPCTRL_WR_DATA, 0, 0x03},			// 24
	{DISPCTRL_WR_DATA, 0, 0x02},			// 25
	{DISPCTRL_WR_DATA, 0, 0x48},			// 26
	{DISPCTRL_WR_DATA, 0, 0x02},			// 27
	{DISPCTRL_WR_DATA, 0, 0x49},			// 28
	{DISPCTRL_WR_DATA, 0, 0x02},			// 29
	{DISPCTRL_WR_DATA, 0, 0x88},			// 30
	{DISPCTRL_WR_DATA, 0, 0x02},			// 31
	{DISPCTRL_WR_DATA, 0, 0xC7},			// 32
	{DISPCTRL_WR_DATA, 0, 0x02},			// 33
	{DISPCTRL_WR_DATA, 0, 0xF3},			// 34

	{DISPCTRL_WR_DATA, 0, 0x03},			// 35
	{DISPCTRL_WR_DATA, 0, 0x21},			// 35
	{DISPCTRL_WR_DATA, 0, 0x03},			// 37
	{DISPCTRL_WR_DATA, 0, 0x46},			// 38
	{DISPCTRL_WR_DATA, 0, 0x03},			// 39
	{DISPCTRL_WR_DATA, 0, 0x74},			// 40
	{DISPCTRL_WR_DATA, 0, 0x03},			// 41
	{DISPCTRL_WR_DATA, 0, 0x8F},			// 42
	{DISPCTRL_WR_DATA, 0, 0x03},			// 43
	{DISPCTRL_WR_DATA, 0, 0xA3},			// 44
	{DISPCTRL_WR_DATA, 0, 0x03},			// 45
	{DISPCTRL_WR_DATA, 0, 0xAC},			// 46
	{DISPCTRL_WR_DATA, 0, 0x03},			// 47
	{DISPCTRL_WR_DATA, 0, 0xB7},			// 48
	{DISPCTRL_WR_DATA, 0, 0x03},			// 49
	{DISPCTRL_WR_DATA, 0, 0xBF},			// 50
	{DISPCTRL_WR_DATA, 0, 0x03},			// 51
	{DISPCTRL_WR_DATA, 0, 0xFE},			// 52
	{DISPCTRL_LIST_END, 0, 0},
};

DISPCTRL_REC_T gama_B_neg_setting_seq_cmdlist[] =
{
	{DISPCTRL_WR_CMND, NT35512_CMD_SLPOUT, 0},
	{DISPCTRL_SLEEP_MS, 0, 120},
	{DISPCTRL_WR_CMND, NT35512_CMD_MAUCCTR, 0x0},
	{DISPCTRL_WR_DATA, 0, 0x55},
	{DISPCTRL_WR_DATA, 0, 0xAA},
	{DISPCTRL_WR_DATA, 0, 0x52},
	{DISPCTRL_WR_DATA, 0, 0x08},
	{DISPCTRL_WR_DATA, 0, 0x01},
	//{DISPCTRL_WR_CMND_DATA, 0xD1, 0x00}, 	// 1;
	{DISPCTRL_WR_CMND, 0xD6, 0},
	{DISPCTRL_WR_DATA, 0, 0x00},			// 1
	{DISPCTRL_WR_DATA, 0, 0x01},			// 2;
	{DISPCTRL_WR_DATA, 0, 0x00},			// 3
	{DISPCTRL_WR_DATA, 0, 0x1D},			// 4
	{DISPCTRL_WR_DATA, 0, 0x00},  			// 5
	{DISPCTRL_WR_DATA, 0, 0x48},			// 6
	{DISPCTRL_WR_DATA, 0, 0x00},			// 7
	{DISPCTRL_WR_DATA, 0, 0x64},			// 8
	{DISPCTRL_WR_DATA, 0, 0x00},			// 9
	{DISPCTRL_WR_DATA, 0, 0x7E},			// 10
	{DISPCTRL_WR_DATA, 0, 0x00},			// 11
	{DISPCTRL_WR_DATA, 0, 0xB1},			// 12
	{DISPCTRL_WR_DATA, 0, 0x00},			// 13
	{DISPCTRL_WR_DATA, 0, 0xD3},			// 14
	
	{DISPCTRL_WR_DATA, 0, 0x01},			// 15
	{DISPCTRL_WR_DATA, 0, 0x07},			// 16
	{DISPCTRL_WR_DATA, 0, 0x01},			// 17
	{DISPCTRL_WR_DATA, 0, 0x35},			// 18
	{DISPCTRL_WR_DATA, 0, 0x01},			// 19
	{DISPCTRL_WR_DATA, 0, 0x7B},			// 20
	{DISPCTRL_WR_DATA, 0, 0x01},			// 21
	{DISPCTRL_WR_DATA, 0, 0xB3},			// 22
	
	{DISPCTRL_WR_DATA, 0, 0x02},			// 23
	{DISPCTRL_WR_DATA, 0, 0x03},			// 24
	{DISPCTRL_WR_DATA, 0, 0x02},			// 25
	{DISPCTRL_WR_DATA, 0, 0x48},			// 26
	{DISPCTRL_WR_DATA, 0, 0x02},			// 27
	{DISPCTRL_WR_DATA, 0, 0x49},			// 28
	{DISPCTRL_WR_DATA, 0, 0x02},			// 29
	{DISPCTRL_WR_DATA, 0, 0x88},			// 30
	{DISPCTRL_WR_DATA, 0, 0x02},			// 31
	{DISPCTRL_WR_DATA, 0, 0xC7},			// 32
	{DISPCTRL_WR_DATA, 0, 0x02},			// 33
	{DISPCTRL_WR_DATA, 0, 0xF3},			// 34

	{DISPCTRL_WR_DATA, 0, 0x03},			// 35
	{DISPCTRL_WR_DATA, 0, 0x21},			// 35
	{DISPCTRL_WR_DATA, 0, 0x03},			// 37
	{DISPCTRL_WR_DATA, 0, 0x46},			// 38
	{DISPCTRL_WR_DATA, 0, 0x03},			// 39
	{DISPCTRL_WR_DATA, 0, 0x74},			// 40
	{DISPCTRL_WR_DATA, 0, 0x03},			// 41
	{DISPCTRL_WR_DATA, 0, 0x8F},			// 42
	{DISPCTRL_WR_DATA, 0, 0x03},			// 43
	{DISPCTRL_WR_DATA, 0, 0xA3},			// 44
	{DISPCTRL_WR_DATA, 0, 0x03},			// 45
	{DISPCTRL_WR_DATA, 0, 0xAC},			// 46
	{DISPCTRL_WR_DATA, 0, 0x03},			// 47
	{DISPCTRL_WR_DATA, 0, 0xB7},			// 48
	{DISPCTRL_WR_DATA, 0, 0x03},			// 49
	{DISPCTRL_WR_DATA, 0, 0xBF},			// 50
	{DISPCTRL_WR_DATA, 0, 0x03},			// 51
	{DISPCTRL_WR_DATA, 0, 0xFE},			// 52
	{DISPCTRL_LIST_END, 0, 0},
};

#endif /* __BCM_LCD_NT35512_H */
