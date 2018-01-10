package reversiapp;
	
import java.util.concurrent.TimeUnit;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.fxml.FXMLLoader;

public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			HBox root = (HBox)FXMLLoader.load(getClass().getResource("ReversiGame.fxml"));
			Scene scene = new Scene(root,520,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			
			primaryStage.setTitle("REVERSI");
			primaryStage.setScene(scene);
			primaryStage.show();
			
			
			/*try {
				TimeUnit.SECONDS.sleep(60);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			*/
		//	ReversiBoard b = (ReversiBoard)root.getChildren().get(0);
			
			
		//	GameFlow game = new GameFlow(b.board);
		//	Player p1 = new HumanPlayer('X');
		//	Player p2 = new HumanPlayer('O');
		//	game.play(p1, p2);
		//	System.out.println("im herererererererererererere");
			
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
