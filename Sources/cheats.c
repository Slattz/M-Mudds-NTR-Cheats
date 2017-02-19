#include "cheats.h"

u32		g_Hearts;
u32		g_GBullets;
u32		g_Time;

void    assign_region(u32 region)
{
    g_Hearts = HEARTS_ADDR;
    g_GBullets = GBULLETS_ADDR;
    g_Time = TIME_ADDR;

    // applying offset or particular address
    switch (region)
    {
        case JAP:
			g_Hearts = HEARTS_JAP_ADDR;
			g_GBullets = GBULLETS_JAP_ADDR;
			g_Time = TIME_JAP_ADDR;
        break;
    }
}

void	infHearts(void)
{
	WRITEU8(g_Hearts, 0x4);
}

void	infGBullets(void)
{
		WRITEU8(g_GBullets, 0xA);
}

void	infTime(void)
{
	WRITEU16(g_Time, 0x3880);
}