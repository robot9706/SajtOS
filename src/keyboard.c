#include "keyboard.h"
#include "terminal.h"

#include "io.h"

scanmap* _scanmap;
bool _shifted = false;

void keyboard_setscanmap(scanmap* map)
{
	_scanmap = map;
}

uint8_t keyboard_getScancode()
{
	uint8_t c = 0;
    if(inb(0x60)!=c) 
	{
		c = inb(0x60);
        if(c>0)
			return c;
    }
	
	return 0;
}

bool keyboard_getkey(key_event* event)
{
	uint8_t code = keyboard_getScancode(); 
	if (code == 0 || event->scan == code){
		event->code = 0;
		return false;
	}
	
	event->scan = code;
	event->code = (code & 0x7F);
	event->down = !(code & 0x80);
	
	if(event->code == KEY_SHIFT){
		_shifted = event->down;
	}
	
	if(_shifted){
		event->chr = _scanmap->shifted[event->code];
	}else{
		event->chr = _scanmap->normal[event->code];
	}
	
	return true;
}