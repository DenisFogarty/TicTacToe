/*
 * computer.h
 *
 *  Created on: 11 Aug 2015
 *      Author: denis
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

class computer {
public:
	computer(int computer_player);
	virtual ~computer();

	int set_move(int x, int y, int player);
	int check_possible_moves();
	int set_move();
	int get_x();
	int get_y();

private:
	int filled_blocks[3][3];
	bool move_decided;
	int move_score[3][3];
	int move_x;
	int move_y;

	int comp;
	int player;
};

#endif /* COMPUTER_H_ */
