/*
 * play.cpp
 *
 *  Created on: 11 Aug 2015
 *      Author: denis
 */

#include "../Headers/play.h"

play::play() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			filled_blocks[j][i] = 0;
		}
	}
}

int play::play_piece(int x_pos, int y_pos, int player) {
	if(player == 0) {
		filled_blocks[y_pos - 1][x_pos - 1] = 1;
	}
	else {
		filled_blocks[y_pos - 1][x_pos - 1] = 2;
	}

	return 0;
}

int play::check_legal(int x_pos, int y_pos) {
	if(filled_blocks[y_pos - 1][x_pos - 1] != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int play::check_grid() {
	int i;

	//Checking all vertical and horizontal lines
	for(i = 0; i < 3; i++) {
		if(filled_blocks[i][0] == filled_blocks[i][1] && filled_blocks[i][1] == filled_blocks[i][2] && filled_blocks[i][2] != 0) {
			return 1;
		}
		if(filled_blocks[0][i] == filled_blocks[1][i] && filled_blocks[1][i] == filled_blocks[2][i] && filled_blocks[2][i] != 0) {
			return 1;
		}
	}

	//Checking diagonals
	if(filled_blocks[0][0] == filled_blocks[1][1] && filled_blocks[1][1] == filled_blocks[2][2] && filled_blocks[2][2] != 0) {
		return 1;
	}
	if(filled_blocks[0][2] == filled_blocks[1][1] && filled_blocks[1][1] == filled_blocks[2][0] && filled_blocks[2][0] != 0) {
		return 1;
	}

	return 0;
}

play::~play() {

}
