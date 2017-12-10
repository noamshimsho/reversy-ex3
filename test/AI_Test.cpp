/*
 *
 */

#include "gtest/gtest.h"
#include "AIplayer.h"
#include "Player.h"

TEST (AI_move, smart_move) {

	Board b(8,8);
	b.update(5,3,X);
	b.update(7,3,X);
	GameLogic logic(b);
	Player *p = new AIplayer(O);

	b.print();
	vector <Position> moves = p->hasMove(logic);
	Position position = p->playTurn(logic, moves);

	cout << position << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1";
	EXPECT_TRUE(position == Position (3,5));
	EXPECT_TRUE(b.getBoard()[6][3] != O);

	delete p;
	}
	TEST (AI_move, no_moves) {
		Board b(8,8);
			b.update(3,3,X);
			b.update(4,4,X);
			GameLogic logic(b);
			Player *p = new AIplayer(O);
			vector <Position> moves = p->hasMove(logic);
			Position position = p->playTurn(logic, moves);
			EXPECT_TRUE(moves.size() == 0);
			EXPECT_TRUE(position == Position (0,0));
			delete p;
	}



