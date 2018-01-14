package reversiapp;
/**
 * this class represent Player
 * @author Noam shimshoviz 203565429 Sarit Zevin 313242588
 *
 */
public class Player {
	private discSymbol symbol;
	private String color;
	/**
	 * construct Player from given discSymbol and String
	 * @param s the symbol of the player
	 * @param c the color of the player
	 */
	public Player(discSymbol s, String c){
		this.symbol = s;
		this.color = c;
	}
	/**
	 * @return the symbol of the player
	 */
	public discSymbol getSymbol(){
		return this.symbol;
	}
	/**
	 * @return the color of the player
	 */
	public String getColor(){
		return this.color;
	}
}