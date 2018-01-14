package reversiapp;

import java.io.IOException;
import java.util.LinkedList;

import javafx.scene.paint.Color;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

/**
 * this class represent ReversiBoard
 * @author sarit zevin 313242588 and noam shimshoviz 203565429
 *
 */
public class ReversiBoard extends GridPane {
	@FXML
	private Board board;
	private Player turn;
	private Player otherTurn;
	private Player p1;
	private Player p2;
	private GameLogic logic;
	private Label label;
	private Label scoreFirst;
	private Label scoreSecond;
	
	/**
	 * construct ReversiBoard
	 * @param board the board of the reversi game
	 * @param first the name of the first player
	 * @param second the name of the second player
	 * @param label the label for the turn announcement
	 * @param scoreFirst the label to announce the score of the first player
	 * @param scoreSecond the label to announce the score of the second player
	 */
	public ReversiBoard(Board board, Player p1, Player p2, Label label, Label scoreFirst, Label scoreSecond) {
		this.board = board;
		this.p1 = p1;
		this.p2 = p2;
		this.turn = p1;
		this.otherTurn = p2;
		this.logic = new GameLogic(this.getBoard());
		this.label = label;
		this.scoreFirst = scoreFirst;
		this.scoreSecond = scoreSecond;
	}
	/**
	 * this method run the game in every click of the mouse
	 * the current player make his turn
	 */
	public void play(){
		FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("ReversiBoard.fxml"));
		fxmlLoader.setRoot(this);
		fxmlLoader.setController(this);
		try {
			fxmlLoader.load();
			this.setOnMouseClicked (event -> {
				//calculate the click into a position
				int height = (int)this.getPrefHeight();
				int width = (int)this.getPrefWidth();
				int cellHeight = height / this.getBoard().getRow();
				int cellWidth = width / this.getBoard().getColumn();
				int column = (int)event.getX()/cellWidth + 1;
				int row = (int)event.getY()/cellHeight + 1;
				System.out.println(row +" ++++++ " + column);
				//check if the current player has possible moves
				LinkedList<Position> moves = this.logic.calculateMoves(this.getTurn().getSymbol());
				System.out.print("player: " + this.getTurn()  + " your possible moves are: ");
				for (int i = 0; i < moves.size(); i++) {
					System.out.print("(" +  moves.get(i).getRow() + ", " + moves.get(i).getColumn() + ") ");
				}
				for (int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
					if (row == moves.get(i).getRow() && column == moves.get(i).getColumn()) {				 
						this.logic.updateBoard(new Position(row,column), this.getTurn().getSymbol());
						this.draw();
						//calculate the score for both of the players and print them
						String firstscore = Integer.toString(this.getBoard().score(this.p1.getSymbol()));
						String secondtscore = Integer.toString(this.getBoard().score(this.p2.getSymbol()));
						scoreFirst.setText(this.p1.getColor() + " score:" + firstscore);
						scoreSecond.setText(this.p2.getColor() + " score:" + secondtscore);
						if (this.hasMove(this.getOtherTurn(), this.getTurn())){
							//switch the turns
							Player temp = this.getTurn(); 
							 this.setTurn(this.getOtherTurn());
							 this.setOtherTurn(temp);
							 //write the next turn
							 String text;
							 text = this.getTurn().getColor()  + "'s turn";
							 this.label.setText(text);
						 }
					}
				}
				event.consume();
			});
		} catch (IOException exception) {
			throw new RuntimeException(exception);
		}
	}
	/**
	 * check if there is possible moves for the player
	 * of there isn't it check if the other player has any possible move
	 * if he also hasn't it means the game is over
	 * @param player the cuurent player to check if has move
	 * @param other the other player to check if has move in case the current player has no move
	 * @return true if the current player has possible move, false otherwise
	 */
	public boolean hasMove(Player player, Player other) {
		if(!(this.logic.calculateMoves(player.getSymbol())).isEmpty()){
			return true;
		} else {
			if(this.logic.calculateMoves(other.getSymbol()).isEmpty()) {
				System.out.println("finish game no moves.....");
				this.endGame();
			}
			return false;
		}
	}
	/**
	 * this method define which player won the game
	 * and create FinishGame according to the winner
	 */
	public void endGame(){
		int x = this.getBoard().score(this.getTurn().getSymbol());
		int y = this.getBoard().score(this.getOtherTurn().getSymbol());
		if (x > y){
			FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),1,this.getTurn().getColor());
			finish.display();
		} else if (x < y) {
			FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),2,this.getOtherTurn().getColor());
			finish.display();
		} else {
			FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),3, "");
			finish.display();
		}
	}
	/**
	 * @return the turn
	 */
	public Player getTurn() {
		return turn;
	}
	/**
	 * @return the other turn
	 */
	public Player getOtherTurn() {
		return otherTurn;
	}
	/**
	 * @param turn the turn to set
	 */
	public void setTurn(Player turn) {
		this.turn = turn;
	}
	/**
	 * @param otherTurn the other turn to set
	 */
	public void setOtherTurn(Player otherTurn) {
		this.otherTurn = otherTurn;
	}

	/**
	 * @return the board
	 */
	public Board getBoard() {
		return board;
	}

	/**
	 * this method draw the board
	 */
	public void draw() {
		this.getChildren().clear();
		int height = (int)this.getPrefHeight();
		int width = (int)this.getPrefWidth();
		int cellHeight = height / this.getBoard().getRow();
		int cellWidth = width / this.getBoard().getColumn();
		//draw the cells of the board
		for (int i = 0; i < this.getBoard().getRow(); i++){
			for (int j = 0; j < this.getBoard().getColumn(); j++){
				Rectangle rect = new Rectangle(cellWidth,cellHeight);
				rect.setFill(Color.GREEN);
				rect.setStroke(Color.BLACK);
			
				this.add(rect, j, i);
			}
		}
		//draw ellipse if there is 'x' or 'o' on the board
		for (int i = 0; i < this.getBoard().getRow(); i++){
			for (int j = 0; j < this.getBoard().getColumn(); j++){
				if (this.getBoard().getBoard()[i][j] == this.getTurn().getSymbol()) {
					Ellipse e = new Ellipse(cellWidth/2,cellHeight/2);
					e.setFill(Color.web(this.getTurn().getColor()));
					this.add(e, j, i);
				} else if (this.getBoard().getBoard()[i][j] == this.getOtherTurn().getSymbol()) {
					Ellipse e = new Ellipse(cellWidth/2,cellHeight/2);
					e.setFill(Color.web(this.getOtherTurn().getColor()));
					this.add(e, j, i);
				}
			}
		}
	}
}
