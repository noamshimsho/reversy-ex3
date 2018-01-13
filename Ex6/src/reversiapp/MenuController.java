package reversiapp;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class MenuController {
	//@FXML
	//private Button startButton;
	//@FXML
	//private Button settingButoon;
	@FXML
	private Button exitButoon;
	
	@FXML
	protected void startClicked() {
		System .out.println("start");
		HBox root;
		try {
			root = (HBox)FXMLLoader.load(getClass().getResource("ReversiGame.fxml"));
			Scene scene = new Scene(root,650,500);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			Stage primaryStage = new Stage();
			primaryStage.setTitle("REVERSI");
			primaryStage.setScene(scene);
			primaryStage.show();
			Stage s = (Stage)exitButoon.getScene().getWindow();
			s.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	@FXML
	protected void settingsClicked() {
		System .out.println("settings");
		Settings setting = new Settings();
		setting.disPlay();
	}
	@FXML
	protected void exitClicked() {
		System .out.println("exit");
		Stage s = (Stage)exitButoon.getScene().getWindow();
		s.close();
		
	}
}
