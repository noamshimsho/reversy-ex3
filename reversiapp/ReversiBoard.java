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
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;


public class ReversiBoard extends GridPane {
	@FXML
	private Board board;
	private String first;
	private String second;
	private char turn;
	private GameLogic logic;
	private Label label;
	private Label scoreFirst;
	private Label scoreSecond;
	private Label endGame;
	public int counter=0;
	public int fullBoard=4;
	
	public ReversiBoard(Board board, String first, String second, Label label, Label scoreFirst, Label scoreSecond, Label endGame) {
		this.label = label;
		this.scoreFirst = scoreFirst;
		this.scoreSecond = scoreSecond;
		this.endGame = endGame;
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
				int height = (int)this.getPrefHeight();
				int width = (int)this.getPrefWidth();
				int cellHeight = height / this.board.getRow();
				int cellWidth = width / this.board.getColumn();
				int column = (int)event.getX()/cellWidth + 1;
				int row = (int)event.getY()/cellHeight + 1;
				System.out.println(row +" ++++++ " + column);
				System.out.println("counter: " + counter);
				System.out.println("fullBoard: " + fullBoard);

				if (this.getTurn() == 'X'){
					LinkedList<Position> moves = logic.calculateMoves('X');
					if(!moves.isEmpty()){
						System.out.print("player: X "  + " your possible moves are: ");
						for (int i = 0; i < moves.size(); i++) {
							System.out.print("(" +  moves.get(i).getRow() + ", " + moves.get(i).getColumn() + ") ");
						}
						for (int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
							if (row == moves.get(i).getRow() && column == moves.get(i).getColumn()) {
								 logic.updateBoard(new Position(row,column), 'X');
								 String xscore = Integer.toString(this.board.score('X'));
								 String oscore = Integer.toString(this.board.score('O'));
								 this.scoreFirst.setText(this.first + "'s score: " + xscore);
								 this.scoreSecond.setText(this.second + "'s score: " + oscore);
								 counter=0;
								 fullBoard++;
							 	 if(fullBoard == (this.board.getRow()*this.board.getColumn())){
							 		 System.out.println("full board!!!!!!!!!!!!!!!!!");
									this.board.endGame(this.endGame, this.first, this.second);
								 }
							 	String text =  this.second + "'s turn";
								this.label.setText(text);
								this.setTurn('O');
								 this.draw();
							}
						}
						
					} else{
						 counter++;
						 if(counter==2){
							 System.out.println("counter!!!!!!!!!!!!!!!!!");
							this.board.endGame(this.endGame, this.first, this.second);
						}
						String text =  this.second + "'s turn";
						this.label.setText(text);
						this.setTurn('O');
					}
					
				} else {
					LinkedList<Position> moves = logic.calculateMoves('O');
					if(!moves.isEmpty()){
						System.out.print("player: O "  + " your possible moves are: ");
						for (int i = 0; i < moves.size(); i++) {
							System.out.print("(" +  moves.get(i).getRow() + ", " + moves.get(i).getColumn() + ") ");
						}
						for (int i = 0; i < moves.size(); i++) {  // check that this position is equal to one of his options
							if (row == moves.get(i).getRow() && column == moves.get(i).getColumn()) {
								logic.updateBoard(new Position(row,column), 'O');
								String xscore = Integer.toString(this.board.score('X'));
								String oscore = Integer.toString(this.board.score('O'));
								this.scoreFirst.setText(this.first + "'s score: " + xscore);
								this.scoreSecond.setText(this.second + "'s score: " + oscore);
								counter=0;
								fullBoard++;
								if(fullBoard == (this.board.getRow()*this.board.getColumn())){
									System.out.println("full board!!!!!!!!!!!!!!!!!");
									this.board.endGame(this.endGame, this.first, this.second);
								}
								String text =  this.first + "'s turn";
								this.label.setText(text);
								this.setTurn('X');
								this.draw();
							}
						}
						
					} else{
						counter++;
						if(counter==2){
							System.out.println("counter!!!!!!!!!!!!!!!!!");
							this.board.endGame(this.endGame, this.first, this.second);
						}
						String text =  this.first + "'s turn";
						this.label.setText(text);
						this.setTurn('X');
					}
					
				}
				event.consume();
			});
		} catch (IOException exception) {
			throw new RuntimeException(exception);
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
