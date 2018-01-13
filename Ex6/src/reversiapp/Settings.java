package reversiapp;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;

import com.sun.glass.ui.Window;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class Settings {
	public Settings(){}

	public void disPlay() {
		Stage window = new Stage();
		window.initModality(Modality.APPLICATION_MODAL);
		window.setTitle("REVERSI.SETTINGS");
		
		GridPane layout = new GridPane();
		layout.setPadding(new Insets(10,10,10,10));
		layout.setVgap(12);
		layout.setHgap(12);
		
		
		//layout.setBackground(new Background(new BackgroundFill(Color.OLIVE,CornerRadii.EMPTY,Insets.EMPTY)));
		layout.setId("set");
		
		Label colorFirst = new Label("First player color:");
		GridPane.setConstraints(colorFirst, 0, 0);
		Label colorSecond = new Label("Second player color:");
		GridPane.setConstraints(colorSecond, 0, 1);
		Label boardSize = new Label("Board size:");
		GridPane.setConstraints(boardSize, 0, 2);
		
		ChoiceBox <String> firstPlayer = new ChoiceBox<>();
		GridPane.setConstraints(firstPlayer, 1, 0);
		ChoiceBox <String> secondPlayer = new ChoiceBox<>();
		GridPane.setConstraints(secondPlayer, 1, 1);
		ChoiceBox <String> size = new ChoiceBox<>();
		GridPane.setConstraints(size, 1, 2);
		
		firstPlayer.getItems().addAll("BLACK","WHITE","GREEN","RED","BLUE","PINK","BROWN","GRAY","CORAL");	
		secondPlayer.getItems().addAll("BLACK","WHITE","GREEN","RED","BLUE","PINK","BROWN","GRAY","CORAL");
		size.getItems().addAll("4","6","8","10","12","14","16","18","20");
		
		//firstPlayer.setValue("BLACK");
		//secondPlayer.setValue("WHITE");
		//size.setValue("8");
		
		Button confirm = new Button("confirm");
		GridPane.setConstraints(confirm, 1, 10);
		confirm.setOnAction(e-> getChoice(firstPlayer,secondPlayer,size,window));
		
		layout.getChildren().addAll(colorFirst, colorSecond, boardSize, firstPlayer, secondPlayer, size, confirm);
		Scene scene = new Scene(layout,400,320);
		scene.getStylesheets().addAll(this.getClass().getResource("application.css").toExternalForm());
		window.setScene(scene);
		window.showAndWait();
		
	}
	private void getChoice(ChoiceBox <String> firstPlayer,
			ChoiceBox <String> secondPlayer, ChoiceBox <String> size,Stage window) {
		String first = firstPlayer.getValue();
		String second = secondPlayer.getValue();
		String boardSize = size.getValue();
		
		File f1 = new File("settings.txt");

		FileOutputStream fos = null;
		try {
			fos = new FileOutputStream(f1);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		OutputStreamWriter osw = null;
		try {
			osw = new OutputStreamWriter(fos, "UTF8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}

		BufferedWriter writer = new BufferedWriter(osw);
		try {
			writer.write(first+"\n");
			writer.write(second+"\n");
			writer.write(boardSize+"\n");
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		window.close();
	}
}








