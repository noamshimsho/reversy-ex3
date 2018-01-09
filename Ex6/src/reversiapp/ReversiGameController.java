package reversiapp;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.layout.HBox;

public class ReversiGameController implements Initializable {
	@FXML
	private HBox root;
	private static final int FIRST = 0;
	private static final int SECOND = 1;
	private int [][]board;

	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		int size = 8;
		board = new int [size][size];
		board [(size / 2) -1][(size / 2) -1] = SECOND;
		board [(size / 2)][(size / 2)] = SECOND;
		board [(size / 2) -1][(size / 2)] = FIRST;
		board [(size / 2)][(size / 2) -1] = FIRST;
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
