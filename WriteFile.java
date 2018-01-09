package java_ex2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
/**
 * write the given result
 * into a text file
 * @author sarit zevin
 */
public class WriteFile {
	/**
	 * defualt constructor
	 */
	public WriteFile(){}
	/**
	 * this method write the results to a text file
	 */
	public void writeFile(char win) {
		// Open the file
		File out = new File("output.txt");
	    FileOutputStream fos = null;
		try {
			fos = new FileOutputStream(out);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	     // Wrap the file writer with OutputStreamWriter with UTF8 encoding
	     OutputStreamWriter osw = null;
		try {
			osw = new OutputStreamWriter(fos, "UTF8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	     // Wrap it with buffered writer
	     BufferedWriter writer = new BufferedWriter(osw);
	     // Try block: Most stream operations may throw IO exception
	     try {
	    	 writer.write(win);
	         // Close the streams
	         writer.close();
	     } catch (IOException e) {
	         e.printStackTrace();
	         System.exit(0);
	     }  
	
	}
}
