#include "cheats.h"

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