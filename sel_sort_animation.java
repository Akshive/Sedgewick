import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
/*package whatever //do not write package name here */


public class Main {
	public static void main (String[] args) throws Exception{
        Reader r = new Reader();
        double a[] = r.readDoubles();
        StdDraw.setXscale(0, a.length+10);
        StdDraw.setYscale(0, 20);
        show(a, a.length);
        sel_sort(a, a.length);
    }

    private static boolean isLess(Comparable a, Comparable b){
        return a.compareTo(b) < 0;
    }

    private static void show(double[] a, int size){
        if(size < 0)return;
        StdDraw.clear();
        for(int i = 0; i < size; i++){
            StdDraw.rectangle(i+0.5, a[i]/2, 0.5, a[i]/2);
        }
        System.out.printf("\n");
    }

    private static void sel_sort(double[] a, int size) throws InterruptedException {
        double temp_min = 0;
        int temp_id = 0;
        for(int i = 0; i < size; i++){
            temp_min = a[i];
            temp_id = i;
            for(int j = i+1; j < size; j++){
                if(a[j] < temp_min){
                    temp_min = a[j]; temp_id = j;
                }
            }
            a[temp_id] = a[i];
            a[i] = temp_min;  
            show(a, a.length);
            Thread.sleep(250);
        }
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
    public int readInt() throws Exception{
        s = br.readLine();
        return Integer.parseInt(s);
    }
    public double readDouble() throws Exception{
        s = br.readLine();
        return Double.parseDouble(s);
    }
    public double[] readDoubles() throws Exception {
        s = br.readLine();
        String[] words = s.split("\\s+");
        double[] doubles = new double[words.length];
        for(int i = 0; i < words.length; i++){
            doubles[i] = Double.parseDouble(words[i]);
        }
        return doubles;
    }
}



