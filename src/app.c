#include "app.h"

#include "terminal.h"
#include "string.h"
#include "keyboard.h"

//Apps
//==Print==
void app_print()
{
	terminal_writeline("Text");
}

void app_scan()
{
	terminal_writeline("Press escape to exit.");
	terminal_writeline("Raw keyboard events:");
	
	//Process keyboard events
	key_event event;
	while(true)
	{
		if (keyboard_getkey(&event))
		{
			if (event.down && event.code == KEY_ESCAPE)
			{
				return;
			}
			else
			{
				terminal_writestring(event.down ? "Down" : "  Up");
				terminal_writestring(" Scancode: 0x");
				terminal_printbyte(event.code);
				if(event.chr != 0){
					terminal_writestring(" as '");
					terminal_putchar(event.chr);
					terminal_putchar('\'');
				}
				terminal_writestring("\n");
			}
		}
	}
}
//End of Apps

#define APP_COUNT 2
static app_info _apps[] = {
	{ .command = "print", .entry = app_print },
	{ .command = "scan", .entry = app_scan },
};

void shellExecute(const char* app)
{
	for (int x = 0; x<APP_COUNT; x++)
	{
		if (strcomp(app, _apps[x].command))
		{
			_apps[x].entry();
			return;
		}
	}
	
	terminal_fg(COLOR_RED);
	terminal_writeline("Unknown command!\n");
	terminal_fg(COLOR_LIGHT_GREY);
	
	return;
}