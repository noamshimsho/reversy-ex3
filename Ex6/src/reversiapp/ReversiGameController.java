package reversiapp;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.concurrent.TimeUnit;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;

public class ReversiGameController implements Initializable {
	@FXML
	private HBox root;
	@FXML
	private Label label;
	@FXML
	private Label scoreFirst;
	@FXML
	private Label scoreSecond;

	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		
		File f1 = new File("settings.txt");
    
		// Open a file reader obfather.getY()ect
		FileInputStream fis = null;
		try {
			fis = new FileInputStream(f1);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		// Wrap the file reader with InputStreamReader with UTF8 encoding
		InputStreamReader isr = null;
		try {
			isr = new InputStreamReader(fis, "UTF8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
		// Wrap it with buffered reader
		BufferedReader reader = new BufferedReader(isr);
		String line,first = "",second = "";
		int size = 0;
		try {
			first = reader.readLine();
			second = reader.readLine();
			line = reader.readLine();
			size = Integer.parseInt(line);
		} catch (IOException e) {
			e.printStackTrace();
		}
		Board b = new Board(size);
		ReversiBoard rb = new ReversiBoard(b, first, second, this.label, this.scoreFirst, this.scoreSecond);
		rb.setPrefHeight(400);
		rb.setPrefWidth(400);
		root.getChildren().add(0,rb);
		rb.draw();
		label.setText(first  + "'s turn");
		scoreFirst.setText(first + " score: 2");
		scoreSecond.setText(second + " score: 2");

		
		root.widthProperty().addListener((observable, oldValue, newValue) -> {
			double boardNewWidth = newValue.doubleValue() - 120;
			rb.setPrefWidth(boardNewWidth);
			rb.draw();		
		});
		root.heightProperty().addListener((observable, oldValue, newValue) -> {
			double boardNewWidth = newValue.doubleValue() - 120;
			rb.setPrefHeight(newValue.doubleValue());
			rb.draw();		
		});
		
	}
	
	
	
	
	
	
	
}






