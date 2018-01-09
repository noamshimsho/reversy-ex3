package javaFXEx6;
//Noam shimshoviz 203565429 Sarit Zevin 313242588

public class Position {
	private int row;
	private int column;
	public Position(int r, int c){
		this.row = r;
		this.column = c;
	}
	
	public int getColumn() {
	    return column;
	}
	public int getRow() {
	    return row;
	}
	public boolean equal(Position other){
		if(this.getColumn()==other.getColumn() && this.getRow() == other.getRow()){
			return true;
		}
		return false;
	}
}
