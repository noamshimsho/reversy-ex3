package game;
/**
 * this class represent a board
 * @author noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 *
 */
public class Board {
	private int row;
	private int column;
	private discSymbol[][] board;
	/**
	 * construct a board from a given integer
	 * @param size the size of the rows and the columns of the board
	 */
	public Board(int size){
		this.row = size;
		this.column = size;
		this.board = new discSymbol[this.row][this.column];
		//initialize the board with space
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				board[i][j] = discSymbol.S;
			}
		}
		// build the opening board
		this.board [(this.row / 2) -1][(this.row / 2) -1] = discSymbol.O;
		this.board [(this.row / 2)][(this.row / 2)] = discSymbol.O;
		this.board [(this.row / 2) -1][(this.row / 2)] = discSymbol.X;
		this.board [(this.row / 2)][(this.row / 2) -1] = discSymbol.X;
	}
	/**
	 * print the console board (not relevant for ex 6)
	 */
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
					System.out.print((discSymbol)board[i-1][j-1] +  " |");
				}
			}
			System.out.println("");
			for(j=0;j<row+1;j++) {
				System.out.print("...");
			}
			System.out.println("");
		}
	}
	/**
	 * update the board according to a two given integers and given discSymbol
	 * @param row the row of the position to update
	 * @param column the column of the position to update
	 * @param player the symbol to put on the board
	 */
	public void update(int row, int column, discSymbol player) {
		this.board[row][column] = player;
	}
	/**
	 * @return the number of columns in the board
	 */
	public int getColumn()  {
		return this.column;
	}
	/**
	 * @return the number of rows in the board
	 */
	public int getRow() {
		return this.row;
	}
	/**
	 * @return the board
	 */
	public discSymbol[][] getBoard()  {
		return this.board;
	}
	/**
	 * copy construct the board
	 * @param oldboard the board to copy from
	 */
	public Board(Board oldboard) {
		discSymbol[][] old = oldboard.getBoard();
		for (int i = 0; i < this.getRow(); i++){
			for (int j = 0; j < this.getColumn(); j++){
				this.getBoard()[i][j] = old[i][j];
			}
		}
	}
	/**
	 * compute the how many discs of a given discSymbol there are on the board
	 * @param player the discSymbol of the discs
	 * @return the number of the given discSymbol on the board
	 */
	public int score(discSymbol player)  {
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
