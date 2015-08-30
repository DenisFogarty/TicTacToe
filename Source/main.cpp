/*
 * main.cpp
 *
 *  Created on: 6 Aug 2015
 *      Author: denis
 */

#include "../Headers/draw_grid.h"
#include "../Headers/play.h"
#include "../Headers/computer.h"

#include <stdio.h>

grid_layout grid;
play play_game;
computer play_computer;

int computer_player();
int two_player();

int main(int arcg, char **argv) {
	char play_choice[9];

	printf("%s", "Computer or Human");
	printf("\n");
	scanf("%s", play_choice);

	if(!(strcmp(play_choice, "Computer"))) {
		computer_player();
	}
	else {
		two_player();
	}

	return 0;
}

int computer_player() {
	int moves = 0;
	int player_won = 0;

	bool legal_move = false;

	int row;
	int col;
	int curr_player = 0;

	int move_x;
	int move_y;

	grid.draw_grid();

	play_computer.set_computer_player(2);

	while(moves < 9) {
		if(curr_player == 0) {
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
			play_computer.set_move(col, row, curr_player);

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

			curr_player = 1;

			moves++;

			legal_move = false;
		}

		else {
			play_computer.check_possible_moves();
			move_x = play_computer.get_x();
			move_y = play_computer.get_y();

			play_game.play_piece(move_x, move_y, curr_player);
			grid.fill_grid(move_x, move_y, curr_player);
			grid.draw_grid();

			player_won = play_game.check_grid();
			play_computer.set_move(move_x, move_y, curr_player);
			curr_player = 0;
		}
	}

	printf("%s", "Draw");
	printf("\n");

	return 0;

	return 0;
}

int two_player() {
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
