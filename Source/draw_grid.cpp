/*
 * draw_grid.cpp
 *
 *  Created on: 6 Aug 2015
 *      Author: denis
 */

#include "../Headers/draw_grid.h"

grid_layout::grid_layout() {
	strcpy(row_1, "       |       |       \0");
	strcpy(row_2, "-----------------------\0");

	int row_offset = 0;
	int i, j;

	//Drawing the board
	for(i = 0; i < 3; i++) {

		for(j = row_offset; j < row_offset + 5; j++) {
			strcpy(full_grid[j], row_1);
		}

		if(i < 2) {
			strcpy(full_grid[j], row_2);
		}

		row_offset += 6;
	}

	strcpy(x_marker[0], " \\   / \0");
	strcpy(x_marker[1], "  \\ /  \0");
	strcpy(x_marker[2], "   x    \0");
	strcpy(x_marker[3], "  / \\  \0");
	strcpy(x_marker[4], " /   \\ \0");

	strcpy(o_marker[0], "  ---  \0");
	strcpy(o_marker[1], " |   | \0");
	strcpy(o_marker[2], " |   | \0");
	strcpy(o_marker[3], " |   | \0");
	strcpy(o_marker[4], "  ---  \0");
}

int grid_layout::fill_grid(int x_pos, int y_pos, int player) {
	int y_grid_offset = (y_pos - 1) * 6;
	int x_grid_offset = (x_pos - 1) * 8;
	int i, j;

	if(player == 0) {
		for(i = 0; i < 7; i++) {
			for(j = 0; j < 5; j++) {
				full_grid[y_grid_offset + j][x_grid_offset + i] = x_marker[j][i];
			}
		}
	}
	else {
		for(i = 0; i < 7; i++) {
			for(j = 0; j < 5; j++) {
				full_grid[y_grid_offset + j][x_grid_offset + i] = o_marker[j][i];
			}
		}
	}

	return 0;
}

int grid_layout::draw_grid() {
	int row_offset = 0;
	int i, j;

	for(i = 0; i < 3; i++) {

		for(j = row_offset; j < row_offset + 5; j++) {
			printf("%s", full_grid[j]);
			printf("\n");
		}

		if(i < 2) {
			printf("%s", full_grid[j]);
			printf("\n");
		}

		row_offset += 6;
	}

	return 0;
}

int grid_layout::clear_grid() {
    strcpy(row_1, "       |       |       \0");
	strcpy(row_2, "-----------------------\0");

	int row_offset = 0;
	int i, j;

	//Drawing the board
	for(i = 0; i < 3; i++) {

		for(j = row_offset; j < row_offset + 5; j++) {
			strcpy(full_grid[j], row_1);
		}

		if(i < 2) {
			strcpy(full_grid[j], row_2);
		}

		row_offset += 6;
	}

	return 0;
}

grid_layout::~grid_layout() {

}
