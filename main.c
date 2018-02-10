#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

	screen s;
	color c;

	clear_screen(s);

	c.red = MAX_COLOR;
	c.green = MAX_COLOR;
	c.blue = MAX_COLOR / 2;

	float x, y;
	int pixels = 500;
	const float INTERVAL = 0.1;
	for(x = -2; x <= 2; x += INTERVAL){
		for(y = -2; y <= 2; y += INTERVAL){
			if(x * x * x * x / 16 + y * y * y * y / 8 < 1){
				float z = -3 * (x * x - y * y) / 4;
				float partial_x = -3 * x / 2;
				float partial_y = 3 * y / 2;

				//finding the position in the 2D picture given 3D coordinates.
				//Slightly rotated counterclockwise for a better view.

				if((x + INTERVAL) * (x + INTERVAL) * (x + INTERVAL) * (x + INTERVAL) / 16 + y * y * y * y / 8 < 1){
					int col = (int)(pixels / 2 - y * 4 * pixels / 48 + x * 8 * pixels / 48);
					int dest_col = (int)(pixels / 2 - y * 4 * pixels / 48 + (x + INTERVAL) * 8 * pixels / 48);
					int row = (int)(pixels / 2 - z * pixels / 20 + y * pixels / 16 + x * pixels / 16);
					int dest_row = (int)(pixels / 2 - (z + partial_x * INTERVAL) * pixels / 20 + y * pixels / 16 + (x + INTERVAL) * pixels / 16);
					draw_line(col, row, dest_col, dest_row, s, c);
				}

				if(x * x * x * x / 16 + (y + INTERVAL) * (y + INTERVAL) * (y + INTERVAL) * (y + INTERVAL) / 8 < 1){
					int col = (int)(pixels / 2 - y * 4 * pixels / 48 + x * 8 * pixels / 48);
					int dest_col = (int)(pixels / 2 - (y + INTERVAL) * 4 * pixels / 48 + x * 8 * pixels / 48);
					int row = (int)(pixels / 2 - z * pixels / 20 + y * pixels / 16 + x * pixels / 16);
					int dest_row = (int)(pixels / 2 - (z + partial_y * INTERVAL) * pixels / 20 + (y + INTERVAL) * pixels / 16 + x * pixels / 16);
					draw_line(col, row, dest_col, dest_row, s, c);
				}
			}
		}
	}

	display(s);
	save_extension(s, "lines.png");
}
