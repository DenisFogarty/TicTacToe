/*
 * play.h
 *
 *  Created on: 11 Aug 2015
 *      Author: denis
 */

#ifndef PLAY_H_
#define PLAY_H_

class play {
public:
	play();
	virtual ~play();

	int play_piece(int x_pos, int y_pos, int player);
	int check_legal(int x_pos, int y_pos);
	int check_grid();
	int reset_play();

private:
	int filled_blocks[3][3];
};

#endif /* PLAY_H_ */
