package reversiapp;
	
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.fxml.FXMLLoader;

/**
 * this class is the main class
 * this class extend Application
 * @author Noam shimshoviz 203565429 Sarit Zevin 313242588
 *
 */
public class Main extends Application {
	@Override
	/**
	 * start the game
	 */
	public void start(Stage primaryStage) {
		try {
			//create VBox
			VBox root = (VBox)FXMLLoader.load(getClass().getResource("Menu.fxml"));
			root.setId("menu");
			//create Scene 
			Scene scene = new Scene(root,630,630);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setTitle("REVERSI");
			primaryStage.setScene(scene);
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	/**
	 * the main method that launch the game
	 * @param args in case there is given argument
	 */
	public static void main(String[] args) {
		launch(args);
	}
}
