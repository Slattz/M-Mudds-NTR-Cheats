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

/*
JAP Addresses
*/

#define		HEARTS_JAP_ADDR			0x309FD3CC
#define		GBULLETS_JAP_ADDR		0x001AB68C
#define		TIME_JAP_ADDR			0x001AB690


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

#endif
