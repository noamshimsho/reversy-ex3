/*
 *
 */

#include "Board.h"
#include "GameLogic.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "Position.h"

TEST(FindMoves, Start) {

Board b(8,8);
GameLogic logic(b);
vector<Position> moves;
moves = logic.calculateMoves('x');

	EXPECT_TRUE(moves[0] == Position(3,4));
	EXPECT_TRUE(moves[1] == Position(4,3));
	EXPECT_TRUE(moves[2] == Position(5,6));
	EXPECT_TRUE(moves[3] == Position(6,5));
	EXPECT_TRUE(moves.size() == 4);

}

TEST(FindMoves, allDirections) {
	Board b(8,8);
	b.update(4,3,'0');
	b.update(2,3,'0');
	b.update(2,4,'0');
	b.update(2,5,'0');
	b.update(3,5,'0');
	b.update(4,5,'0');
	GameLogic logic(b);
	vector<Position> moves;
	moves = logic.calculateMoves('x');
	EXPECT_TRUE(moves[0] == Position(2,3));
	EXPECT_TRUE(moves[1] == Position(2,5));
	EXPECT_TRUE(moves[2] == Position(2,7));
	EXPECT_TRUE(moves[3] == Position(4,3));
	EXPECT_TRUE(moves[4] == Position(4,7));
	EXPECT_TRUE(moves[5] == Position(6,3));
	EXPECT_TRUE(moves[6] == Position(6,5));
	EXPECT_TRUE(moves[7] == Position(6,7));
	EXPECT_TRUE(moves.size() == 8);
}


TEST(FindMoves, noMoves) {
	Board b(8,8);
	b.update(3,3,'x');
	b.update(4,4,'x');
	GameLogic logic(b);
	vector<Position> moves;
	moves = logic.calculateMoves('x');
	EXPECT_TRUE(moves.size() == 0);
}

TEST(FindMoves, fullBoard) {
	Board b(2,2);
	GameLogic logic(b);
	vector<Position> moves;
	moves = logic.calculateMoves('x');
	EXPECT_TRUE(moves.size() == 0);
}

TEST(UpddateBoard, allDirections) {
	Board b(8,8);
	b.update(4,3,'0');
	b.update(2,3,'0');
	b.update(2,4,'0');
	b.update(2,5,'0');
	b.update(3,5,'0');
	b.update(4,5,'0');
	GameLogic logic(b);
	logic.updateBoard(Position(2,3),'x');
	EXPECT_TRUE(b.getBoard()[2][3] == 'x');   // angle left up
	logic.updateBoard(Position(2,5),'x');
	EXPECT_TRUE(b.getBoard()[2][4] == 'x');  // up
	logic.updateBoard(Position(2,7),'x');
	EXPECT_TRUE(b.getBoard()[2][5] == 'x');  // angle right up
	logic.updateBoard(Position(4,3),'x');
	EXPECT_TRUE(b.getBoard()[3][3] == 'x');  // left
	logic.updateBoard(Position(4,7),'x');
	EXPECT_TRUE(b.getBoard()[3][5] == 'x');   // right
	logic.updateBoard(Position(6,3),'x');
	EXPECT_TRUE(b.getBoard()[4][3] == 'x');    // angle left down
	logic.updateBoard(Position(6,5),'x');
	EXPECT_TRUE(b.getBoard()[4][4] == 'x');    // down
	logic.updateBoard(Position(6,7),'x');
	EXPECT_TRUE(b.getBoard()[4][5] == 'x');    // angle right down


}










