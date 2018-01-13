package reversiapp;

import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class FinishGame {
	private Stage window;
	private int winner;
	private String first;
	private String second;
	
	public FinishGame(Stage stage, int x, String first, String second) {
		this.window = stage;
		this.winner = x;
		this.first = first;
		this.second = second;
	}
	
	public void display() {
		StackPane layout = new StackPane();
		layout.setId("finish");
		Label label = new Label();
		label.setId("labelFinish");
		if (winner == 1){
			label.setText( " The game is over!!! \n the winner is...." + this.first + "!!! congratulations!!!");
		} else if (winner == 2) {
			label.setText( " The game is over!!! \n the winner is...." + this.second + "!!! congratulations!!!");
		} else {
			label.setText( " The game is over!!! \n good game it is a draw!!!");
		}
		layout.getChildren().add(label);
		Scene scene = new Scene(layout,500,420);
		scene.getStylesheets().addAll(this.getClass().getResource("application.css").toExternalForm());
		window.setScene(scene);
		window.show();
	}

}

	
	
	
	
	