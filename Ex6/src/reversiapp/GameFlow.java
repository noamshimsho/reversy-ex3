package reversiapp;
/*
 * GameFlow.cpp
 *
 *  Created on: 7 ����� 2017
 *      Author: Noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 */

import java.io.IOException;
import java.util.LinkedList;

public class GameFlow {
	//private Board board;
	private GameLogic logic;
	private ReversiBoard board;
	/*
	public GameFlow(Board b) {
		this.board = b;
		this.logic = new GameLogic(this.board);
	}*/
	public GameFlow(ReversiBoard board) {
		this.board = board;
		this.logic = new GameLogic(this.board.getBoard());
	}

	public void play(Player playerX, Player player0)  {
		//board.print();
		int counter = 0;
		int fullBoard = ((board.getBoard().getRow())*(board.getBoard().getColumn()))-4;
		//check if either the board is full or there is no possible moves twice
		
		
		while((counter!=2) && (fullBoard!=0)) {
			//check if there is possible moves for the first player
			try {
				LinkedList<Position> moves = logic.calculateMoves(playerX.getPlayer());  // find the moves of the player
				if (!moves.isEmpty()) {
				((HumanPlayer) playerX).playTurn(this.logic,board,moves);
					  System.out.println(" in game flow after play turn finish ");
				    counter = 0;
				    fullBoard--;
				//check the score of both players and print it
				    int x = this.board.getBoard().score('X');
				    int o = this.board.getBoard().score('O');
				    System.out.println(" there are: " + x + "  x ");
				    System.out.println(" there are: " + o + "  o ");
				} else {
					System.out.println("");
					System.out.println("player x: no possible moves for you, the turn pass to your opponent");
				    counter++;
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			if(fullBoard!=0){
			//check if there is possible moves for the second player
				try {
					LinkedList<Position> moves = logic.calculateMoves(player0.getPlayer()); 
					if (!moves.isEmpty()) {
					((HumanPlayer) player0).playTurn(this.logic, this.board,moves);
					    counter = 0;
					    fullBoard--;
						//check the score of both players and print it
					    int x = this.board.getBoard().score('X');
					    int o = this.board.getBoard().score('O');
					    System.out.println( " there are: " + x + " x ");
					    System.out.println(" there are: " + o + " o ");
					} else {
						System.out.println("");
						System.out.println( "player o: no possible moves for you, the turn pass to your opponent");
					    counter++;
					}
				} catch (IOException e) {
					
					e.printStackTrace();
				}
			}
		}
	    endGame();
	}

	public void endGame()  {
	    this.board.getBoard().print();
	    int x = this.board.getBoard().score('X');
	    int o = this.board.getBoard().score('O');

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
