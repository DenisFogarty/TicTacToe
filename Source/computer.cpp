/*
 * computer.cpp
 *
 *  Created on: 11 Aug 2015
 *      Author: denis
 */

#include "../Headers/computer.h"

computer::computer() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			filled_blocks[j][i] = 0;
			move_score[j][i] = 0;
		}
	}

	move_x = 0;
	move_y = 0;

	move_decided = false;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			move_score[j][i] = 0;
		}
	}

	comp = 1;
	player = 2;
}

int computer::set_move(int x, int y, int player) {
	if(player == 0) {
		filled_blocks[y-1][x-1] = 1;
	}
	else {
		filled_blocks[y-1][x-1] = 2;
	}

	return 0;
}

int computer::set_computer_player(int computer_player) {
	comp = computer_player;

	if(comp == 1) {
		player = 2;
	}
	else {
		player = 1;
	}

	return 0;
}

int computer::check_possible_moves() {
	int i, j;
	int row, col;
	int fillable_spaces;
	int score;

	i = 0;
	j = 0;

	row = 0;
	col = 0;

	fillable_spaces = 0;

	score = 0;

	while(i < 3 && !move_decided) {
		while(j < 3 && !move_decided) {

			if(filled_blocks[j][i] == 0) {
				filled_blocks[j][i] = comp;

				//Checking if move is winning move
				{
					//Checking all vertical and horizontal lines
					if(filled_blocks[j][0] == filled_blocks[j][1] && filled_blocks[j][1] == filled_blocks[j][2] && filled_blocks[j][2] != 0) {
						move_x = i;
						move_y = j;
						move_decided = true;
					}
					if(filled_blocks[0][i] == filled_blocks[1][i] && filled_blocks[1][i] == filled_blocks[2][i] && filled_blocks[2][i] != 0) {
						move_x = i;
						move_y = j;
						move_decided = true;
					}

					//Checking diagonals
					if(filled_blocks[0][0] == filled_blocks[1][1] && filled_blocks[1][1] == filled_blocks[2][2] && filled_blocks[2][2] != 0) {
						move_x = i;
						move_y = j;
						move_decided = true;
					}
					if(filled_blocks[0][2] == filled_blocks[1][1] && filled_blocks[1][1] == filled_blocks[2][0] && filled_blocks[2][0] != 0) {
						move_x = i;
						move_y = j;
						move_decided = true;
					}
				}

				//Checking if opponents next move is winning move
				{
					if(!move_decided) {
						filled_blocks[j][i] = player;

						//Checking if move is winning move
						{
							//Checking all vertical and horizontal lines
							if(filled_blocks[j][0] == filled_blocks[j][1] && filled_blocks[j][1] == filled_blocks[j][2] && filled_blocks[j][2] != 0) {
								move_x = i;
								move_y = j;
								move_decided = true;
							}
							if(filled_blocks[0][i] == filled_blocks[1][i] && filled_blocks[1][i] == filled_blocks[2][i] && filled_blocks[2][i] != 0) {
								move_x = i;
								move_y = j;
								move_decided = true;
							}

							//Checking diagonals
							if(filled_blocks[0][0] == filled_blocks[1][1] && filled_blocks[1][1] == filled_blocks[2][2] && filled_blocks[2][2] != 0) {
								move_x = i;
								move_y = j;
								move_decided = true;
							}
							if(filled_blocks[0][2] == filled_blocks[1][1] && filled_blocks[1][1] == filled_blocks[2][0] && filled_blocks[2][0] != 0) {
								move_x = i;
								move_y = j;
								move_decided = true;
							}
						}
					}
				}
				filled_blocks[j][i] = 0;

				//Checking for best move to make
				{
					if(!move_decided) {
						col = i;
						row = j;

						//Checking column if possible to win
						while((col - 1) >= 0) {
							//Goes to previous block in column and checks if filled
							col--;
							if(filled_blocks[row][col] == 0 || filled_blocks[row][col] == comp) {
								fillable_spaces++;
							}
						}
						col = i;

						while((col + 1) <= 2) {
							//Goes to next block in column and checks if filled
							col++;
							if(filled_blocks[row][col] == 0 || filled_blocks[row][col] == comp) {
								fillable_spaces++;
							}
						}
						col = i;

						if(fillable_spaces == 2) {
							move_score[j][i] = (move_score[j][i]) + 1;
						}
						fillable_spaces = 0;

						//Checking row if possible to win
						while((row - 1) >= 0) {
							//Goes to previous block in row and checks if filled
							row--;
							if(filled_blocks[row][col] == 0 || filled_blocks[row][col] == comp) {
								fillable_spaces++;
							}
						}
						row = j;

						while((row + 1) <= 2) {
							//Goes to previous block in row and checks if filled
							row++;
							if(filled_blocks[row][col] == 0 || filled_blocks[row][col] == comp) {
								fillable_spaces++;
							}
						}
						row = j;

						if(fillable_spaces == 2) {
							move_score[j][i] = (move_score[j][i]) + 1;
						}
						fillable_spaces = 0;

						//Checking diagonals if possible to win
						while((row - 1) >= 0 && (col - 1) >= 0) {
							col--;
							row--;

							if(filled_blocks[row][col] == 0 || filled_blocks[row][col] == comp) {
								fillable_spaces++;
							}
						}
						col = i;
						row = j;

						while((row + 1) >= 2 && (col + 1) >= 2) {
							col++;
							row++;

							if(filled_blocks[row][col] == 0 || filled_blocks[row][col] == comp) {
								fillable_spaces++;
							}
						}
						col = i;
						row = j;

						if(fillable_spaces == 2) {
							move_score[j][i] = (move_score[j][i]) + 1;
						}
						fillable_spaces = 0;
					}
				}
			}

			j++;
		}

		i++;
	}

	if(!move_decided) {
		for(i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
				if(move_score[j][i] > score) {
					score = move_score[j][i];
					move_x = i + 1;
					move_y = j + 1;
				}
			}
		}
	}

	move_decided = false;
	return 0;
}

int computer::get_x() {
	return move_x;
}

int computer::get_y() {
	return move_y;
}

computer::~computer() {

}
