/*
 * draw_grid.h
 *
 *  Created on: 6 Aug 2015
 *      Author: denis
 */

#ifndef HEADERS_DRAW_GRID_H_
#define HEADERS_DRAW_GRID_H_

#include <iostream>
#include <stdio.h>
#include <string.h>

class grid_layout {
private:
	char full_grid[17][24];

	char row_1[24];
	char row_2[24];

	char x_marker[5][7];

	char o_marker[5][7];

public:
	grid_layout();
	virtual ~grid_layout();

	int fill_grid(int x_pos, int y_pos, int player);
	int draw_grid();

};

#endif /* HEADERS_DRAW_GRID_H_ */
