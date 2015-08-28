/*
 * main.cpp
 *
 *  Created on: 6 Aug 2015
 *      Author: denis
 */

#include "../Headers/draw_grid.h"
#include "../Headers/play.h"

#include <stdio.h>

int main(int arcg, char **argv) {
	grid_layout grid;
	play play_game;

	int moves = 0;
	int player_won = 0;

	bool legal_move = false;

	int row;
	int col;
	int curr_player = 0;

	grid.draw_grid();

	while(moves < 9) {
		while(!legal_move) {
			printf("%s", "Enter row: ");
			scanf("%d", &row);

			printf("%s", "Enter col: ");
			scanf("%d", &col);

			if(play_game.check_legal(col, row)) {
				legal_move = true;
			}
		}

		play_game.play_piece(col, row, curr_player);
		player_won = play_game.check_grid();

		grid.fill_grid(col, row, curr_player);
		grid.draw_grid();

		if(player_won) {
			printf("%s", "Player ");
			if(curr_player == 0) {
				printf("%s", "1 wins");
			}
			else {
				printf("%s", "2 wins");
			}
			printf("\n");
			return 0;
		}

		if(curr_player == 0) {
			curr_player = 1;
		}
		else {
			curr_player = 0;
		}

		moves++;

		legal_move = false;
	}

	printf("%s", "Draw");
	printf("\n");

	return 0;
}

int human_move() {

	return 0;
}
