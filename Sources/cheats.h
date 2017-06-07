#ifndef CHEATS_H
#define CHEATS_H

#include "../Includes/plugin.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define     ADD32(addr, value)         			*(u32 *)addr += value
#define     SUB32(addr, value)         			*(u32 *)addr -= value
#define     ADD64(addr, value)                  *(vs64 *)addr += value
#define     SUB64(addr, value)                  *(vs64 *)addr -= value
#define		ADD16(addr, value)					*(u16 *)addr += value
#define		SUB16(addr, value)					*(u16 *)addr -= value
#define     ADDTOFLOAT(addr, add_value)         *(float *)addr += (float)add_value
#define     SUBTOFLOAT(addr, sub_value)         *(float *)addr -= (float)sub_value

/*
 EUR/USA Addresses
*/

#define		HEARTS_ADDR				0x147E2C44
#define		GBULLETS_ADDR			0x001BCD14
#define		TIME_ADDR				0x001BCD18
#define		X_POS_ADDR1				0x147E2BD0 //ADDR1= offset after initial level selection
#define		Y_POS_ADDR1				0x147E2BD5
#define		X_POS_ADDR2				0x147E2BD8 //ADDR2= offset before initial level selection
#define		Y_POS_ADDR2				0x147E2BDD

/*
JAP Addresses
*/

#define		HEARTS_JAP_ADDR			0x309FD3CC
#define		GBULLETS_JAP_ADDR		0x001AB68C
#define		TIME_JAP_ADDR			0x001AB690
#define		X_POS_JAP_ADDR1			0x309FD358
#define		Y_POS_JAP_ADDR1			0x309FD35D
#define		X_POS_JAP_ADDR2			0x309FD360
#define		Y_POS_JAP_ADDR2			0x309FD365


enum
{
	USA = 0,
	EUR,
	JAP
};
 
/*
Cheats
*/
void    assign_region(u32 region);

void	infHearts(void);
void	infGBullets(void);
void	infTime(void);
void	coord(void);

#endif
