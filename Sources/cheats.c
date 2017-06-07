#include "cheats.h"

u32		g_Hearts;
u32		g_GBullets;
u32		g_Time;
u32     g_pos_x1;
u32     g_pos_y1;
u32     g_pos_x2;
u32     g_pos_y2;

void    assign_region(u32 region)
{
    g_Hearts = HEARTS_ADDR;
    g_GBullets = GBULLETS_ADDR;
    g_Time = TIME_ADDR;
	g_pos_x1 = X_POS_ADDR1;
	g_pos_y1 = Y_POS_ADDR1;
	g_pos_x2 = X_POS_ADDR2;
	g_pos_y2 = Y_POS_ADDR2;

    // applying offset or particular address
    switch (region)
    {
        case JAP:
			g_Hearts = HEARTS_JAP_ADDR;
			g_GBullets = GBULLETS_JAP_ADDR;
			g_Time = TIME_JAP_ADDR;
			g_pos_x1 = X_POS_JAP_ADDR1;
			g_pos_y1 = Y_POS_JAP_ADDR1;
			g_pos_x2 = X_POS_JAP_ADDR2;
			g_pos_y2 = Y_POS_JAP_ADDR2;
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

void	coord(void)
{
	if ((READU8(g_pos_x1) != 0) && (READU8(g_pos_y1) != 0))
		{
			if (is_pressed(BUTTON_DU))
				ADDTOFLOAT(g_pos_y1, 0.1);
			if (is_pressed(BUTTON_DD))
				SUBTOFLOAT(g_pos_y1, 0.1);
			if (is_pressed(BUTTON_DL))
				SUBTOFLOAT(g_pos_x1, 0.1);
			if (is_pressed(BUTTON_DR))
				ADDTOFLOAT(g_pos_x1, 0.1);
		}
		
	if ((READU8(g_pos_x2) != 0) && (READU8(g_pos_y2) != 0))
		{
			if (is_pressed(BUTTON_DU))
				ADDTOFLOAT(g_pos_y2, 0.2);
			if (is_pressed(BUTTON_DD))
				SUBTOFLOAT(g_pos_y2, 0.2);
			if (is_pressed(BUTTON_DL))
				SUBTOFLOAT(g_pos_x2, 0.2);
			if (is_pressed(BUTTON_DR))
				ADDTOFLOAT(g_pos_x2, 0.2);
		}
}