/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main (String[] args) throws Exception{
        Reader r = new Reader();
        int[] a = r.readInts();
        System.out.println(a[0]);
    }
}

class Reader{
    private String s;
    private BufferedReader br;

    public Reader(){
        br = new BufferedReader(new InputStreamReader(System.in));
    } 
    public int[] readInts() throws Exception {
        s = br.readLine();
        String[] words = s.split("\\s+");
        int[] ints = new int[words.length];
        for(int i = 0; i < words.length; i++){
            ints[i] = Integer.parseInt(words[i]);
        }
        return ints;
    }
}
