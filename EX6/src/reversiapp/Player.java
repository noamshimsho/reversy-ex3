package reversiapp;

import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;

public class Player {
	private GridPane grid;
	private int row;
	private int col;
	private ImageView iv;
	
	public Player(GridPane grid, int row, int col){
		this.grid = grid;
		this.row = row;
		this.col = col;
		iv = new ImageView(getClass().getResource("tag.png").toExternalForm());
	}
  public void draw(int cellWidth, int cellHeight) {
	  grid.add(iv, col, row);
	  iv.setFitWidth(cellWidth);
	  iv.setFitHeight(cellHeight);
	  grid.getChildren().remove(iv);
	  grid.add(iv, col, row);
  }
}
