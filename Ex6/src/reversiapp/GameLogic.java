package reversiapp;
import java.util.ArrayList;
import java.util.LinkedList;

/*
 * Noam shimshoviz 203565429 Sarit Zevin 313242588
 */

public class GameLogic {
	private Board board;
	
	public GameLogic (Board board){
		this.board = board;
	}
	
	public Board getBoard() {
		return board;
	}
	
	public LinkedList<Position> calculateMoves(char player, Board m){
		
		char[][] b = m.getBoard();
		int row = m.getRow();
		int size;
		int column = m.getColumn();
		LinkedList<Position> moves = new LinkedList<Position>();
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				if ( b[i][j] == ' '){  // check that it's an empty cell
					if (j - 1 > 0 && b[i][j-1] != ' ' && b[i][j-1] != player) {   // left
						for (int t = 2; j-t >= 0; t++){
							if (b[i][j-t] == player) {
								boolean flag = true;
								Position candidate = new Position(i+1,j+1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if  (b[i][j-t] == ' '){
								break;
							}
						}
					}
					if (j - 1 > 0 && i-1 > 0 && b[i-1][j-1] != ' ' && b[i-1][j-1] != player) { // left oblique line
						for (int t = 2; j-t >= 0 && i - t >= 0; t++) {
							if (b[i-t][j-t] == player) {
								boolean flag = true;
								Position candidate = new Position(i+1,j+1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if (b[i-t][j-t] == ' '){
								break;
							}
						}
					}
					if (i - 1 > 0  && b[i-1][j] != ' ' &&  b[i-1][j] != player) { // up
						for (int t = 2; i-t >= 0; t++) {
							if (b[i-t][j] == player) {
								boolean flag = true;
								Position candidate = new Position(i+1,j+1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if (b[i-t][j] == ' '){
								break;
							}
						}
					}
					if(j + 1 < column  && i-1 > 0 && b[i-1][j+1] != ' ' && b[i-1][j+1] != player) {
						for (int t = 2; j+t < column && i-t >= 0 ; t++) {
							if (b[i-t][j+t] == player) {
								boolean flag = true;
								Position candidate = new Position(i + 1, j + 1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if (b[i-t][j+t] == ' '){
								break;
							}
						}
					}
					if (j + 1 < column  && b[i][j+1] != ' ' && b[i][j+1] != player) { // right
						for (int t = 2; j+t < column; t++) {
							if (b[i][j+t] == player) {
								boolean flag = true;
								Position candidate = new Position(i+1, j + 1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if (b[i][j+t] == ' '){
								break;
							}
						}
					}
					if (j + 1 < column && i+1 < row && b[i+1][j+1] != ' ' && b[i+1][j+1] != player) {
						for (int t = 2; j + t < column && i + t < row; t++) {
							if (b[i+t][j+t] == player) {
								boolean flag = true;
								Position candidate = new Position(i + 1, j + 1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if (b[i+t][j+t] == ' '){
								break;
							}
						}
					}
					if ( i+1 < row && b[i+1][j] != ' ' && b[i+1][j] != player) { // down
						for (int t = 2; i+t < row; t++) {
							if (b[i+t][j] == player) {
								boolean flag = true;
								Position candidate = new Position(i + 1, j+1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if (b[i+t][j] == ' '){
								break;
							}
						}
					}
					if (j - 1 > 0 && i+1 < row && b[i+1][j-1] != ' ' && b[i+1][j-1] != player){
						for (int t = 2; j-t >= 0 && i + t < row; t++) {
							if (b[i+t][j-t] == player) {
								boolean flag = true;
								Position candidate = new Position(i+1,j+1);
								for (int a = 0; a < moves.size(); a++) {
									if (candidate.equal(moves.get(a))){
										flag = false;
									}
								}
								if (flag){
									moves.add(new Position(i+1,j+1));
									break;
								}
							} else if (b[i+t][j-t] == ' '){
								break;
							}
						}
					}
				}
			}
		}
		return moves;
	}
	public LinkedList<Position> calculateMoves(char player) {
		return this.calculateMoves(player, this.board);
	}

	public void updateBoard(Position p, char player) {
		this.updateBoard(p,player,board);

	}
	public void updateBoard(Position p, char player, Board m) {
		int i = p.getRow() - 1;
		int j = p.getColumn() - 1;
		int row = m.getRow();
		int column = m.getColumn();
		char[][] b = m.getBoard();
		if (j - 1 > 0 && b[i][j-1] != ' ' && b[i][j-1] != player) {   // check the left beside cell that is oposite player
			for (int t = 2; j-t >= 0; t++){   //chek the rest left side if there is the same tag
				if (b[i][j-t] == player) {
					for (int a = j-1; a > j-t; a--) {
						b[i][a] = player;
					}
					break;
				} else if  (b[i][j-t] == ' '){
					break;
				}
			}
		}
		if (j - 1 > 0 && i - 1 > 0 && b[i-1][j-1] != ' ' && b[i-1][j-1] != player) {
			for (int t = 2; j-t >= 0 && i-t >= 0; t++){
				if (b[i-t][j-t] == player) {
					for (int a = 1; a < t; a++) {
						b[i-a][j-a] = player;
					}
					break;
				} else if  (b[i-t][j-t] == ' '){
					break;
				}
			}
		}
		if ( i - 1 > 0 && b[i-1][j] != ' ' && b[i-1][j] != player) {   // up
			for (int t = 2; i-t >= 0; t++){
				if (b[i-t][j] == player) {
					for (int a = 1; a < t; a++) {
						b[i-a][j] = player;
					}
					break;
				}else if  (b[i-t][j] == ' '){
					break;
				}
			}
		}
		if(j + 1 < column  && i-1 > 0 && b[i-1][j+1] != ' ' && b[i-1][j+1] != player) {
			for (int t = 2; j+t < column && i-t >= 0 ; t++) {
				if (b[i-t][j+t] == player) {
					for (int a = 1; a < t; a++) {
						b[i-a][j+a] = player;
					}
					break;
				} else if (b[i-t][j+t] == ' '){
					break;
				}
			}
		}
		if (j + 1 < column  && b[i][j+1] != ' ' && b[i][j+1] != player) { // right
			for (int t = 2; j+t < column; t++) {
				if (b[i][j+t] == player) {
					for (int a = 1; a < t; a++) {
						b[i][j+a] = player;
					}
					break;
				} else if (b[i][j+t] == ' '){
					break;
				}
			}
		}
		if (j + 1 < column && i+1 < row && b[i+1][j+1] != ' ' && b[i+1][j+1] != player) {
			for (int t = 2; j + t < column && i + t < row; t++) {
				if (b[i+t][j+t] == player) {
					for (int a = 1; a < t; a++) {
						b[i+a][j+a] = player;
					}
					break;
				} else if (b[i+t][j+t] == ' '){
					break;
				}
			}
		}
		if ( i+1 < row && b[i+1][j] != ' ' && b[i+1][j] != player) { // down
			for (int t = 2; i+t < row; t++) {
				if (b[i+t][j] == player) {
					for (int a = 1; a < t; a++) {
						b[i+a][j] = player;
					}
					break;
				} else if (b[i+t][j] == ' '){
				 	break;
				}
			}
		}
		if (j - 1 > 0 && i+1 < row && b[i+1][j-1] != ' ' && b[i+1][j-1] != player) { //  down
			for (int t = 2; j-t >= 0 && i + t < row; t++) {
				if (b[i+t][j-t] == player) {
					for (int a = 1; a < t; a++) {
						b[i+a][j-a] = player;
					}
					break;
				} else if (b[i+t][j-t] == ' '){
					break;
				}
			}
		}
		b[i][j] = player;
	}
}
