package reversiapp;

import java.io.IOException;
import javafx.scene.paint.Color;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Rectangle;


public class ReversiBoard extends GridPane {
	@FXML
	public int[][] board;
	private Player player;
	
	public ReversiBoard(int [][] board) {
		this.board = board;
		FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("ReversiBoard.fxml"));
		fxmlLoader.setRoot(this);
		fxmlLoader.setController(this);
		try {
			fxmlLoader.load();
			System.out.println("q!!!!!!!!!!!!!!!!!!!!" );
			this.setOnMouseClicked (event -> {
				System.out.println("here!!!!!!!!!!!!!!!!!!!!" );
				event.getX();
				
				System.out.println(event.getX() +"!!!!!!" + event.getY());
				System.out.println(event.getScreenY() +"@@@@@" + event.getScreenY());
				System.out.println(event.getSceneX() +"#####" + event.getSceneY());
				/*switch (event.getCode()) {
				case DOWN:
					System.out.println("downnnnn");
					break;
				case UP:
					System.out.println("UPPPPP");
					break;
				case LEFT:
					System.out.println("LEFTTTTT");
					break;
				case RIGHT:
					System.out.println("RIGHTTTTTT");
					break;
				}*/
				event.consume();
			});
		} catch (IOException exception) {
			throw new RuntimeException(exception);
		}
		player = new Player(this,7,7);
		
	}
	
	public void draw() {
		this.getChildren().clear();
		int height = (int)this.getPrefHeight();
		int width = (int)this.getPrefWidth();
		
		int cellHeight = height / board.length;
		int cellWidth = width / board[0].length;
		System.out.println(cellHeight +"%%%%%" + cellWidth);
		
		for (int i = 0; i < board.length; i++){
			for (int j = 0; j < board[i].length; j++){
				Rectangle rect = new Rectangle(cellWidth,cellHeight);
				rect.setFill(Color.GOLD);
				rect.setStroke(Color.BLACK);
			
				this.add(rect, j, i);
			}
		}
		player.draw(cellWidth, cellHeight);
	}

}
