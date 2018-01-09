package java_ex2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
/**
 * this class read from a given input
 * and create board according to the input 
 * @author sarit zevin
 */
public class ReadFile {
	private String[] args;
	/**
	 * construct ReadFile from given string[]
	 * @param args holds the name of the input file if it was given
	 */
	public ReadFile(String[] args){
		this.args = args;
	}
	/**
	 * read the input from the file and return board
	 * @return board according to the file
	 */
	public Board readFile(int size) {
		// Open the file
    	File f1;
    	if(this.getArgs().length != 0){
    		f1 = new File(this.getArgs()[0]);
    	}else{
    		f1 = new File("input.txt");
    	}
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
		String line;
		//read from the input file and set the board according the reading
		Board board = new Board(new char[size][size], size);
		int i,j;
        try {
	    	for(i=0; i<size;i++) {
	        	line = reader.readLine();
	        	for(j=0; j<size;j++) {
	        		board.setBoard(i, j, line.charAt(j));
	        	}
	    	}
		} catch (IOException e) {
			e.printStackTrace();
		}
        try {
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
        return board;
	}
	/**
	 * @return string of the file's name
	 */
	public String[] getArgs() {
		return args;
	}
}