package javaFXEx6;
/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */
public class Player {
	private char player;
	private char other;
	public Player(char p) {
		this.player = p;
		if(player == 'X') {
			this.other = 'O';
		}
		else {
			this.other = 'X';
		}
	}

	public char getOther() {
		return other;
	}

	public char getPlayer() {
		return player;
	}


}
