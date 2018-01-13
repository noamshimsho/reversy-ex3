package reversiapp;
	
import java.util.concurrent.TimeUnit;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.fxml.FXMLLoader;


public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			//HBox root = (HBox)FXMLLoader.load(getClass().getResource("ReversiGame.fxml"));
			VBox root = (VBox)FXMLLoader.load(getClass().getResource("Menu.fxml"));
			Scene scene = new Scene(root,350,300);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			
			primaryStage.setTitle("REVERSI");
			primaryStage.setScene(scene);
			primaryStage.show();
			
			System.out.println("hsjkdfkjshdfkjshfjkshdkjfhsjkdfhsjkd");
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
