#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "io.h"
#include "terminal.h"
#include "keyboard.h"
#include "hu_scanmap.h"
#include "string.h"
#include "app.h"

#define MAX_COMMAND_LENGTH 32
char _command[MAX_COMMAND_LENGTH + 1];
int _commandPtr;

void clearCommand()
{
	_commandPtr = 0;
	for(int x = 0;x<MAX_COMMAND_LENGTH+1;x++)
	{
		_command[x] = 0x0;
	}
}

void kmain()
{
	_commandPtr = 0;
	
	//Setup terminal and the HU scanmap for the keyboard
	terminal_initialize();
	keyboard_setscanmap(getScanMapHU());

	//Basic os version and prompt
	terminal_fg(COLOR_LIGHT_GREEN);
	terminal_writeline("SajtOS v0.00000000000001");
	terminal_fg(COLOR_LIGHT_GREY);
	
Label_prompt:
	clearCommand();
	terminal_writestring("\n>");

	//Process keyboard events
	key_event event;
	event.code = 0;
	event.down = false;
	while(true)
	{
		if (keyboard_getkey(&event))
		{
			if (event.down)
			{
				if (event.chr != 0)
				{
					if (_commandPtr < MAX_COMMAND_LENGTH)
					{
						_command[_commandPtr] = event.chr;
						terminal_putchar(event.chr);
						_commandPtr++;
					}
				}
				else
				{
					switch(event.code)
					{
						case KEY_ENTER:
						{
							terminal_writestring("\n");
							shellExecute(_command);
							
							goto Label_prompt;
						}
						break;
						case KEY_BACKSPACE:
						{
							if (_commandPtr > 0)
							{
								_commandPtr--;
								_command[_commandPtr] = 0x0;
								terminal_backspace();
							}
						}
						break;
						default:
						{
							size_t saveRow = (size_t)getCursorRow();
							size_t saveCol = (size_t)getCursorColumn();
							
							set_cursor(0,VGA_WIDTH-2);
							terminal_printbyte(event.code);
							
							set_cursor(saveRow, saveCol);
						}
						break;
					}
				}
			}
		}
	}
}