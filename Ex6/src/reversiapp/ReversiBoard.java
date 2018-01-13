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
	
	
	public ReversiBoard(Board board, String first, String second, Label label, Label scoreFirst, Label scoreSecond) {
		this.board = board;
		this.first = first;
		this.second = second;
		this.turn = 'X';
		this.logic = new GameLogic(this.getBoard());
		this.label = label;
		this.scoreFirst = scoreFirst;
		this.scoreSecond = scoreSecond;
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
							 

							 logic.updateBoard(new Position(row,column), 'X');
							 this.draw();
							 String firstscore = Integer.toString(this.board.score('X'));
							 String secondtscore = Integer.toString(this.board.score('O'));
							 scoreFirst.setText(first + " score:" + firstscore);
							 scoreSecond.setText(second + " score:" + secondtscore);
							 if (this.hasMove('O')){
								 this.setTurn('O');
								 String text = this.second  + "'s turn";
								 label.setText(text);
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
							 String firstscore = Integer.toString(this.board.score('X'));
							 String secondtscore = Integer.toString(this.board.score('O'));
							 scoreFirst.setText(first + " score:" + firstscore);
							 scoreSecond.setText(second + " score:" + secondtscore);
							if (this.hasMove('X')){
								this.setTurn('X');
								String text = this.first  + "'s turn";
								label.setText(text);
							}
						}
					}
				}
				event.consume();
			});
		} catch (IOException exception) {
			throw new RuntimeException(exception);
		}
	}
	public boolean hasMove(char player) {
		LinkedList<Position> moves = logic.calculateMoves(player);
		if(!moves.isEmpty()){
			return true;
		} else {
			if(player == 'X') {
				LinkedList<Position> moves1 = logic.calculateMoves('O');
				if(moves1.isEmpty()) {
					System.out.println("finish game no moves.....");
					int x = this.board.score('X');
					int y = this.board.score('O');
					if (x > y){
						FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),1,this.first,this.second);
						finish.display();
					} else if (x < y) {
						FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),2,this.first,this.second);
						finish.display();
					} else {
						FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),3,this.first,this.second);
						finish.display();
					}
				}
			} else {
				LinkedList<Position> moves1 = logic.calculateMoves('X');
				if (moves1.isEmpty()){
					System.out.println("finish game no moves.....");
					int x = this.board.score('X');
					int y = this.board.score('O');
					if (x > y){
						FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),1,this.first,this.second);
						finish.display();
					} else if (x < y) {
						FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),2,this.first,this.second);
						finish.display();
					} else {
						FinishGame finish = new FinishGame((Stage)this.getScene().getWindow(),3,this.first,this.second);
						finish.display();
					}
				}
			}
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
	}
}
