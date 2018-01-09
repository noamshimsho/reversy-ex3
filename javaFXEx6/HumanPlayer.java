package javaFXEx6;

import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */
public class HumanPlayer extends Player{
	private char player;
	public HumanPlayer(char name) {
		super(name);
	}
	public boolean playTurn(GameLogic logic) throws IOException {
		LinkedList<Position> moves = logic.calculateMoves(this.getPlayer());  // find the moves of the player
		if (!moves.isEmpty()) {  // check the player has moves
			System.out.println("");
			System.out.print("player: " + this.getPlayer() + " your possible moves are: ");
			for (int i = 0; i < moves.size(); i++) {
				System.out.print("(" +  moves.get(i).getRow() + ", " + moves.get(i).getColumn() + ") ");
			}
			System.out.print("");
			// checking the input and convert it to integers
			int row, column;
			boolean flag = true;
			do {
				System.out.print( "\nplease enter row number: ");
				Scanner console = new Scanner(System.in); 
				row = console.nextInt();
				System.out.print( "please enter column number: ");
				column = console.nextInt();
				Position p = new Position(row,column); // the position the player enter
				for (int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
					if (p.equal(moves.get(i))) {
						flag =false;
						break;
					}
				}
				if (flag){
					System.out.println("wrong input try again!! ");
				}
			} while (flag);
				Position p = new Position(row,column);
				logic.updateBoard(p,this.getPlayer());     // end of turn the main board is update and print
				logic.getBoard().print();
				return true;
		} else {
			return false;
		}
	}

}