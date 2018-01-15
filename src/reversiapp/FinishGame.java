package reversiapp;

import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
/**
 * this class represent finishGame
 * @author sarit zevin 313242588 and noam shimshoviz 203565429
 *
 */
public class FinishGame {
	private Stage window;
	private String winner;
	private int win;
	/**
	 * construct FinishGame from a given Stage and integer and String
	 * @param stage the stage of the game
	 * @param x define whether there is a winner or it is a draw 
	 * @param w the name of the winner
	 */
	public FinishGame(Stage stage, int x, String w) {
		this.window = stage;
		this.winner = w;
		this.win = x;
	}
	/**
	 * display the wining announcement on the screen
	 */
	public void display() {
		//creating the layout
		StackPane layout = new StackPane();
		//add the background photo
		layout.setId("finish");
		Label label = new Label();
		label.setId("labelFinish");
		if (win != 3){ //means there is a winner
			label.setText( " The game is over!!! \n the winner is...." + this.winner + "!!! congratulations!!!");
		} else { //a draw
			label.setText( " The game is over!!! \n good game it is a draw!!!");
		}
		//add the text
		layout.getChildren().add(label);
		//define the screen size
		Scene scene = new Scene(layout,500,420);
		scene.getStylesheets().addAll(this.getClass().getResource("application.css").toExternalForm());
		window.setScene(scene);
		window.show();
	}

}