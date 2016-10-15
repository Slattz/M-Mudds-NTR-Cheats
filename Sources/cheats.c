#include "cheats.h"

void	infLives(void)
{
	WRITEU8(0x147E2C44, 0x4);
}
