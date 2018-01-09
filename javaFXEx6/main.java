package javaFXEx6;

import java.io.IOException;
import java.util.Scanner;

// Noam shimshoviz 203565429 Sarit Zevin 313242588
public class main {
	public static void main(String[] args) throws IOException {
		// get the size of board from the user.
		int  size;
		boolean flag;
		do {
			System.out.println("Please enter even size of board: " );
			Scanner console = new Scanner(System.in); 
			size = console.nextInt();
			if (size > 0 && size%2 == 0){
				flag = false;
			} else {
				System.out.println("wrong input try again");
				flag = true;
			}
		} while (flag);
		// build the game with the choosen board and players and start the game.
		GameFlow game = new GameFlow(size, size);
		Player p1 = new HumanPlayer('X') ;
		Player p2 = new HumanPlayer('O');
		game.play(p1, p2);
	}

}
