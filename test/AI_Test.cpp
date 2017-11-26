/*
 *
 */

#include "gtest/gtest.h"
#include "AIplayer.h"
#include "Player.h"

TEST (AI_move, smart_move) {

	Board b(8,8);
	b.update(5,3,'x');
	b.update(7,3,'x');
	GameLogic logic(b);
	Player *p = new AIplayer('0');
	bool flag;
	flag = p->playTurn(logic);
	EXPECT_TRUE(flag);
	EXPECT_TRUE(b.getBoard()[2][4] == '0');
	EXPECT_TRUE(b.getBoard()[6][3] != '0');



	delete p;
	}
	TEST (AI_move, no_moves) {
		Board b(8,8);
			b.update(3,3,'x');
			b.update(4,4,'x');
			GameLogic logic(b);
			Player *p = new AIplayer('0');
			bool flag;
			flag = p->playTurn(logic);
			EXPECT_FALSE(flag);

	}



