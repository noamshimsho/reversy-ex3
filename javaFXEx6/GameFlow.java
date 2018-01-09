package javaFXEx6;
/*
 * GameFlow.cpp
 *
 *  Created on: 7 бреб„ 2017
 *      Author: Noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 */

import java.io.IOException;

public class GameFlow {
	private Board board;
	private GameLogic logic;
	public GameFlow(int row, int column) {
		this.board = new Board(row, column);
		this.logic = new GameLogic(this.board);
	}

	public void play(Player playerX, Player player0) throws IOException  {
		board.print();
		int counter = 0;
		int fullBoard = ((board.getRow())*(board.getColumn()))-4;
		//check if either the board is full or there is no possible moves twice
		while((counter!=2) && (fullBoard!=0)) {
			//check if there is possible moves for the first player
			if(((HumanPlayer) playerX).playTurn(this.logic)){
			    counter = 0;
			    fullBoard--;
			//check the score of both players and print it
			    int x = this.board.score('X');
	            int o = this.board.score('O');
			    System.out.println(" there are: " + x + "  x ");
			    System.out.println(" there are: " + o + "  o ");
			} else {
				System.out.println("");
				System.out.println("player x: no possible moves for you, the turn pass to your opponent");
			    counter++;
			}
			if(fullBoard!=0){
			//check if there is possible moves for the second player
				if(((HumanPlayer) player0).playTurn(this.logic)){
				    counter = 0;
				    fullBoard--;
					//check the score of both players and print it
				    int x = this.board.score('X');
				    int o = this.board.score('O');
				    System.out.println( " there are: " + x + " x ");
				    System.out.println(" there are: " + o + " o ");
				} else {
					System.out.println("");
					System.out.println( "player o: no possible moves for you, the turn pass to your opponent");
				    counter++;
				}
			}
		}
	    endGame();
	}

	public void endGame()  {
	    this.board.print();
	    int x = this.board.score('X');
	    int o = this.board.score('O');

	    System.out.println( " the game is over!!! ");
	    System.out.println(" the x player score is: " + x);
	    System.out.println(" the o player score is: " + o);
		if (x > o) {
			System.out.println( " the winner is.... x!!! congratulations!!! ");
		}
		else if (o > x) {
			System.out.println(" the winner is.... o!!! congratulations!!! ");
		}
		else {
			System.out.println( " good game it is a draw!!!");
		}
	}

}
