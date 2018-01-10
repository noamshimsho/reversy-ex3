package reversiapp;
/*
 *      Author: Noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 */

public class Board {
	private int row;
	private int column;
	private char[][] board;
	public Board(int size){  // build the board as a array of pointers that each one of them point to another array
		this.row = size;
		this.column = size;
		this.board = new char[this.row][this.column];
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				board[i][j] = ' ';
			}
		}
		// build the opening board
		this.board [(this.row / 2) -1][(this.row / 2) -1] = 'O';
		this.board [(this.row / 2)][(this.row / 2)] = 'O';
		this.board [(this.row / 2) -1][(this.row / 2)] = 'X';
		this.board [(this.row / 2)][(this.row / 2) -1] = 'X';


	}
	public void print() {
		int i, j;
		for (i=0; i<row+1;i++) {
			for (j=0; j<column+1;j++) {
				//print the numbers
				if (j==0) {
					if(i==0) {
						System.out.print("  |");
					} else {
						System.out.print(i + " |");
					}
				} else if (i==0){
					if(j!=0){
						System.out.print( j + " |");
					}
					//print the rest of the board
				} else {
					System.out.print((char)board[i-1][j-1] +  " |");
				}
			}
			System.out.println("");
			for(j=0;j<row+1;j++) {
				System.out.print("...");
			}
			System.out.println("");
		}

	}

	public void update(int row, int column, char player) {
		this.board[row][column] = player;
	}

	public int getColumn()  {
		return this.column;
	}

	public int getRow() {
		return this.row;
	}

	public char[][] getBoard()  {
		return this.board;
	}

	public Board(Board oldboard) {
		char[][] old = oldboard.getBoard();
		for (int i = 0; i < this.getRow(); i++){
			for (int j = 0; j < this.getColumn(); j++){
				this.getBoard()[i][j] = old[i][j];
			}
		}
	}

	public int score(char player)  {
		int total = 0;
		for (int i = 0; i < this.getRow(); i++) {
			for (int j = 0; j < this.getColumn(); j++){
				if (this.getBoard()[i][j] == player) {
					total ++;
				}
			}
		}
		return total;
	}



}
