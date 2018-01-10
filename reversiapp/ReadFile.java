package reversiapp;

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
	private String args;
	/**
	 * construct ReadFile from given string[]
	 * @param args holds the name of the input file if it was given
	 */
	public ReadFile(String args){
		this.args = args;
	}
	/**
	 * read the input from the file and return board
	 * @return board according to the file
	 */
	
	/**
	 * @return string of the file's name
	 */
	public String getArgs() {
		return args;
	}
}