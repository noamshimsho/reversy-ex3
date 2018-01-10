package reversiapp;

import java.io.IOException;
import java.util.LinkedList;

import javafx.scene.paint.Color;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;


public class ReversiBoard extends GridPane {
	@FXML
	private Board board;
	private String first;
	private String second;
	private char turn;
	private GameLogic logic;

	
	public ReversiBoard(Board board, String first, String second) {
		this.board = board;
		this.first = first;
		this.second = second;
		this.turn = 'X';
		this.logic = new GameLogic(this.getBoard());
		FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("ReversiBoard.fxml"));
		fxmlLoader.setRoot(this);
		fxmlLoader.setController(this);
		try {
			fxmlLoader.load();
			
			this.setOnMouseClicked (event -> {
				System.out.println("here!!!!!!!!!!!!!!!!!!!!" );

				int height = (int)this.getPrefHeight();
				int width = (int)this.getPrefWidth();
				int cellHeight = height / this.board.getRow();
				int cellWidth = width / this.board.getColumn();
				int column = (int)event.getX()/cellWidth + 1;
				int row = (int)event.getY()/cellHeight + 1;
				System.out.println(row +"++++++" + column);
							
				
				if (this.getTurn() == 'X'){
					LinkedList<Position> moves = logic.calculateMoves('X');

					System.out.print("player: X "  + " your possible moves are: ");
					for (int i = 0; i < moves.size(); i++) {
						System.out.print("(" +  moves.get(i).getRow() + ", " + moves.get(i).getColumn() + ") ");
					}
					
					for (int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
						if (row == moves.get(i).getRow() && column == moves.get(i).getColumn()) {
							//System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1");
							 //this.board.getBoard()[row - 1][column - 1] = this.getTurn();
							 logic.updateBoard(new Position(row,column), 'X');
							 this.draw();
							 if (this.hasMove('O')){
								 this.setTurn('O'); 
							 }
						}
					}
				} else { 
					
					LinkedList<Position> moves = logic.calculateMoves('O');
					System.out.print("player: O "  + " your possible moves are: ");
					for (int i = 0; i < moves.size(); i++) {
						System.out.print("(" +  moves.get(i).getRow() + ", " + moves.get(i).getColumn() + ") ");
					}
					for (int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
						if (row == moves.get(i).getRow() && column == moves.get(i).getColumn()) {
							logic.updateBoard(new Position(row,column), 'O');
							//this.board.getBoard()[row - 1][column - 1] = this.getTurn();
							this.draw();
							if (this.hasMove('X')){
								this.setTurn('X');
							}
						}
					}
				}
				event.consume();
			});
		} catch (IOException exception) {
			throw new RuntimeException(exception);
		}
		//playerTest = new PlayerTest(this,7,7);
	}
	public boolean hasMove(char player) {
		LinkedList<Position> moves = logic.calculateMoves(player);
		if(!moves.isEmpty()){
			return true;
		} else {
			return false;
		}
	}
	/**
	 * @return the turn
	 */
	public char getTurn() {
		return turn;
	}

	/**
	 * @param turn the turn to set
	 */
	public void setTurn(char turn) {
		this.turn = turn;
	}

	/**
	 * @return the board
	 */
	public Board getBoard() {
		return board;
	}


	public void draw() {
		this.getChildren().clear();
		int height = (int)this.getPrefHeight();
		int width = (int)this.getPrefWidth();
		
		int cellHeight = height / this.board.getRow();
		int cellWidth = width / this.board.getColumn();
		System.out.println(cellHeight +"%%%%%" + cellWidth);
		
		for (int i = 0; i < this.board.getRow(); i++){
			for (int j = 0; j < this.board.getColumn(); j++){
				Rectangle rect = new Rectangle(cellWidth,cellHeight);
				rect.setFill(Color.GOLD);
				rect.setStroke(Color.BLACK);
			
				this.add(rect, j, i);
			}
		}
		for (int i = 0; i < this.board.getRow(); i++){
			for (int j = 0; j < this.board.getColumn(); j++){
				if (this.board.getBoard()[i][j] == 'X') {
					Ellipse e = new Ellipse(cellWidth/2,cellHeight/2);
					
					e.setFill(Color.web(first));
					this.add(e, j, i);
				} else if (this.board.getBoard()[i][j] == 'O') {
					Ellipse e = new Ellipse(cellWidth/2,cellHeight/2);
					e.setFill(Color.web(second));
					this.add(e, j, i);
			}
		 }
		}
		//playerTest.draw(cellWidth, cellHeight);
	}
	
}
