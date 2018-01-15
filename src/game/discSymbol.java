package game;
/**
 * this documents discSymbol
 * @author noam shimshoviz 203565429 and sarit zevin, ID: 313242588
 *
 */
public enum discSymbol {
	//space
	S,
	//'X'
	X,
	//'O'
	O;
	/**
	 * @return the value of each enum
	 */
	char symbol(){
		switch(this){
			case S:
				return ' ';
			case X:
				return 'X';
			case O:
				return 'O';
			default:
                throw new AssertionError("Unknown symbol " + this);
		}
	}
}
