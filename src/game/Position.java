package game;
/**
 * this class represent Position
 * @author Noam shimshoviz 203565429 Sarit Zevin 313242588
 *
 */
public class Position {
	private int row;
	private int column;
	/**
	 * construct Position from two given integers 
	 * @param r the first coordinate of the position
	 * @param c the second coordinate of the position
	 */
	public Position(int r, int c){
		this.row = r;
		this.column = c;
	}
	/**
	 * @return the column coordinate
	 */
	public int getColumn() {
	    return column;
	}
	/**
	 * @return the row coordinate
	 */
	public int getRow() {
	    return row;
	}
	/**
	 * check if two positions are equal
	 * @param other, one of the position to check if equal
	 * @return true if the positions are equal, false otherwise
	 */
	public boolean equal(Position other){
		if(this.getColumn()==other.getColumn() && this.getRow() == other.getRow()){
			return true;
		}
		return false;
	}
}