#include "terminal.h"

#include "io.h"
#include "string.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
uint8_t _fgColor;
uint8_t _bgColor;

static char _hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

uint8_t make_color(uint8_t fg, uint8_t bg)
{
	return fg | bg << 4;
}

uint16_t make_vgaentry(char c, uint8_t color)
{
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

void set_cursor(int row, int col)
{
	terminal_row = (size_t)row;
	terminal_column = (size_t)col;
	
	update_cursor();
}

void update_cursor()
{
	unsigned short position = (terminal_row * VGA_WIDTH) + terminal_column;
 
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(position&0xFF));

    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char )((position>>8)&0xFF));
}

void terminal_initialize()
{
	_fgColor = COLOR_LIGHT_GREY;
	_bgColor = COLOR_BLACK;
	
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(_fgColor, _bgColor);
	terminal_buffer = (uint16_t*) 0xB8000;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
}

void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c)
{
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH )
	{
		terminal_column = 0;
		terminal_nextline();
	}
	update_cursor();
}

void terminal_backspace()
{
	if(terminal_column == 0)
	{
		terminal_column = VGA_WIDTH - 1;
		if (terminal_row > 0)
		{
			terminal_row--;
		}
	}
	else
	{
		terminal_column--;
	}
	
	terminal_putentryat(' ', terminal_color, terminal_column, terminal_row);
	update_cursor();
}

void terminal_writestring(const char* data)
{
	size_t datalen = strlen(data);
	for (size_t i = 0; i < datalen; i++){
		char chr = data[i];
		if(chr == '\n'){
			terminal_nextline();
			terminal_column = 0;
			continue;
		}
		
		terminal_putchar(chr);
	}
	update_cursor();
}

void terminal_writeline(const char* data){
	int l = strlen(data);
	char newString[l + 2];
	for(int x = 0;x<l;x++)
		newString[x] = data[x];
	newString[l] = '\n';
	newString[l+1] = (char)0x0;
	
	char* ptr = &newString[0];
	
	terminal_writestring((const char*)ptr);
	
	update_cursor();
}

void terminal_nextline()
{
	terminal_row++;
	if(terminal_row >= VGA_HEIGHT)
	{
		for (size_t y = 1;y<VGA_HEIGHT;y++)
		{
			for(size_t x = 0;x<VGA_WIDTH;x++)
			{
				terminal_buffer[(y - 1) * VGA_WIDTH + x] = terminal_buffer[y * VGA_WIDTH + x];
			}
		}
		
		for(size_t x = 0;x<VGA_WIDTH;x++)
		{
			terminal_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = make_vgaentry(' ', terminal_color);
		}
		
		terminal_row = VGA_HEIGHT - 1;
	}
}

void terminal_printbyte(uint8_t byte)
{
	terminal_putchar(_hex[(byte & 0xF0) >> 4]);
	terminal_putchar(_hex[byte & 0x0F]);
}

void terminal_printint32(uint32_t i)
{
	terminal_printbyte((uint8_t)(i & 0x000000FF) << 24);
	terminal_printbyte((uint8_t)(i & 0x0000FF) << 16);
	terminal_printbyte((uint8_t)(i & 0x00FF) << 8);
	terminal_printbyte((uint8_t)(i & 0xFF));
}

size_t getCursorRow()
{
	return terminal_row;
}

size_t getCursorColumn()
{
	return terminal_column;
}

void terminal_fg(uint8_t color)
{
	_fgColor = color;
	terminal_color = make_color(_fgColor, _bgColor);
}

void terminal_bg(uint8_t color)
{
	_bgColor = color;
	terminal_color = make_color(_fgColor, _bgColor);
}