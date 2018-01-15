package reversiapp;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
/**
 * this class represent MenuController
 * @author Noam shimshoviz 203565429 Sarit Zevin 313242588
 *
 */
public class MenuController {
	@FXML
	private Button exitButoon;
	/**
	 * this method represent the start button
	 */
	@FXML
	protected void startClicked() {
		HBox root;
		try {
			//preparing the game screen
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
	/**
	 * this method represent the settings button
	 */
	@FXML
	protected void settingsClicked() {
		Settings setting = new Settings();
		setting.display();
	}
	/**
	 * this method represent the exit button
	 */
	@FXML
	protected void exitClicked() {
		Stage s = (Stage)exitButoon.getScene().getWindow();
		s.close();
		
	}
}