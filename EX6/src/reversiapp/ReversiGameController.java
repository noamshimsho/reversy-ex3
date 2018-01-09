package reversiapp;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.layout.HBox;

public class ReversiGameController implements Initializable {
	@FXML
	private HBox root;
	private int [][]board = new int [8][8];

	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		ReversiBoard rb = new ReversiBoard(board);
		rb.setPrefHeight(400);
		rb.setPrefWidth(400);
		root.getChildren().add(0,rb);
		rb.draw();
		
		root.widthProperty().addListener((observable, oldValue, newValue) -> {
			double boardNewWidth = newValue.doubleValue() - 120;
			rb.setPrefWidth(boardNewWidth);
			rb.draw();		
		});
		root.heightProperty().addListener((observable, oldValue, newValue) -> {
			//double boardNewWidth = newValue.doubleValue() - 120;
			rb.setPrefHeight(newValue.doubleValue());
			rb.draw();		
		});
		
	}
	
}
