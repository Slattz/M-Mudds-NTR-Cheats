#include "cheats.h"
#include "notes.h"
#include <string.h>

static const char * const infheart = "Enable this cheat to\nhave infinite Hearts.";

char	*builder_name = "Slattz";

void	my_menus(void)
{
	int index;
	int i;
	
		new_unselectable_entry("M-Mudds NTR Cheats Ver. 1.0");
	index =	new_entry("Infinite Hearts", infLives);
			set_note(infheart, index);
	
	for (i = 2; i <= index; i++)
		set_note(notes[i - 2], i);
}



