/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_
#include "Board.h"
#include <vector>
#include "Position.h"
class GameLogic {
public:
	/**
	 * constructor of GameLogic
	 * @ parm board, pass by reference to the game logic for his calculations
	 */
	GameLogic(Board& board);
	/**
	 *  calculate the possible moves of the player on the main board
	 * @ parm player, which player is it's turn
	 *  @ return vector of possible position to play
	 */
	vector<Position> calculateMoves(discSymbol player) const;
	/**
	 *  calculate the possible moves of the player on a given board 
	 * @ parm player, which player is it's turn parm m the given board
	 *  @ return vector of possible position to play
	 */
	vector<Position> calculateMoves(discSymbol player, Board& m) const;
	/**
	 * repair the main board after a player move
	 * @ parm p, the position of the new tag, tag is it 'x'/'0'
	 */
	void updateBoard (Position p, discSymbol player);
	/**
	 * repair a given board after a player move
	 * @ parm p, the position of the new tag, tag is it 'x'/'0', parameter m the given board
	 */
	void updateBoard (Position p, discSymbol player, Board& m);
       /**
       * @ return the main board
       */
	Board& getBoard() const;

private:
	 Board& board;
};

#endif /* GAMELOGIC_H_ */
