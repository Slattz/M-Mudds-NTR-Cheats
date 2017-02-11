#include "cheats.h"

void	infHearts(void)
{
	WRITEU8(g_Hearts, 0x4);
}
