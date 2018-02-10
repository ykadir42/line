#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	if(x0 > x1){
		int temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}
	int x = x0;
	int y = y0;
	int a = y1 - y0;
	int b = x0 - x1;

	if(a >= 0){
		if(a + b <= 0){
			int d = 2 * a + b;
			while (x <= x1){
				plot(s, c, x, y);
				if(d > 0){
					y++;
					d += 2 * b;
				}
				x++;
				d += 2 * a;
			}
		}
		else{
			int d = a + 2 * b;
			while (y <= y1){
				plot(s, c, x, y);
				if(d < 0){
					x++;
					d += 2 * a;
				}
				y++;
				d += 2 * b;
			}
		}
	}

	else{
		if(b - a <= 0){
			int d = 2 * a - b;
			while (x <= x1){
				plot(s, c, x, y);
				if(d < 0){
					y--;
					d -= 2 * b;
				}
				x++;
				d += 2 * a;
			}
		}
		else{
			int d = a - 2 * b;
			while (y >= y1){
				plot(s, c, x, y);
				if(d > 0){
					x++;
					d += 2 * a;
				}
				y--;
				d -= 2 * b;
			}
		}
	}


}
