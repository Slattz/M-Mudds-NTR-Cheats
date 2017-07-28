#include "cheats.h"
#include "notes.h"

#define ENTRY_COUNT 300

typedef struct s_menu
{
    int         count;
    int         status;
    u32         f[ENTRY_COUNT];
    u32         s[ENTRY_COUNT];
    int         a[ENTRY_COUNT];
    const char  *t[ENTRY_COUNT];
    const char  *n[ENTRY_COUNT];
    void        (*fp[ENTRY_COUNT])();
}             t_menu;


typedef void    (*FuncPointer)(void);
extern t_menu menu;



void    new_super_unselectable_entry(char *str, FuncPointer function)
{
    int index;

    index = menu.count;
    if (index >= 300)
        return;
    new_unselectable_entry(str);
    menu.f[index] |= BIT(0) | BIT(1);
    menu.fp[index] = function;
}

char    *builder_name = "Slattz";

void with_note_common(const char *name, const char *note, void (*cheatfunction)(void), int type)
{
    int     index;

    if (type == 0)
        index = new_entry((char *)name, cheatfunction);
    else if (type == 1)
        index = new_radio_entry((char *)name, cheatfunction);
    else if (type == 2)
        index = new_spoiler((char *)name);
    else return;
    set_note(note, index);
}

void new_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 0);
}

void new_radio_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 1);
}

void new_spoiler_with_note(const char *name, const char *note)
{
    with_note_common(name, note, NULL, 2);
}

static inline void  smenu(void)
{
    new_entry_with_note("Infinite Hearts", infheartnote, infHearts);
    new_entry_with_note("Infinite Ghost Bullets", infGBnote, infGBullets);
    new_entry_with_note("Infinite Time", infTimenote, infTime);
    /*
    ** Coord Modifier is broken, never fixed it.
    ** new_entry_with_note("Coordinates Modifier", cmnote, coord);
    */


}

void    my_menus(void)
{
    u32 tid;
    
    set_hid_address(0x10002000); //This is in order to unlock the advanced HID capabilities such as Touchscreen and the stick (No N3DS hid for the moment)
    tid = get_tid_low();
    
    if (tid == 0x0A5400)
    {
        assign_region(BOTH);
		new_unselectable_entry("M-Mudds NTR Cheats v1.3.1 EUR");
    }
	
	else if (tid == 0x086600)
    {
        assign_region(BOTH);
		new_unselectable_entry("M-Mudds NTR Cheats v1.3.1 USA");
    }
	
	else if (tid == 0x16FD00)
    {
		assign_region(JAP);
		new_unselectable_entry("M-Mudds NTR Cheats v1.3.1 JAP");
    }
    
    
    else
    {
        new_unselectable_entry("You're Using An Incorrect TitleID!");            
		new_unselectable_entry("This plugin only supports the");
		new_unselectable_entry("Following TitleIDs:");
		new_unselectable_entry("00040000000A5400 (EUR)");
		new_unselectable_entry("0004000000086600 (USA)");
		new_unselectable_entry("000400000016FD00 (JAP)");
        
        return;
    }
    smenu();
}