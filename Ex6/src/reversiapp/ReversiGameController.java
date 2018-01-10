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
import javafx.scene.layout.HBox;

public class ReversiGameController implements Initializable {
	@FXML
	private HBox root;

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
			line = reader.readLine();
			size = Integer.parseInt(line);
			first = reader.readLine();
			second = reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		Board b = new Board(size);
		ReversiBoard rb = new ReversiBoard(b, first, second);
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






