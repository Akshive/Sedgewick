import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
/*package whatever //do not write package name here */


public class Main {
	public static void main (String[] args) throws Exception{
        Reader r = new Reader();
        int a[] = r.readInts();
        Transaction[] tr = new Transaction[a.length];
        for(int i = 0; i < a.length; i++){
            tr[i] = new Transaction(a[i]);
        }
        ins_sort(tr, a.length);
        for(int i = 0; i < a.length; i++){
            System.out.println(tr[i].getAmount());
        }
    }

    public static boolean isLess(Comparable a, Comparable b){
        return a.compareTo(b) < 0;
    }

    public static void ins_sort(Comparable[] items, int size){
        for(int i = 1; i < size; i++){
            for(int j = i; j > 0 && isLess(items[j], items[j-1]); j--){
                Comparable temp = items[j];
                items[j] = items[j-1];
                items[j-1] = temp;
            }
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
}

class Transaction implements Comparable<Transaction>{
    private int amount;
    public Transaction(int amt){
        amount = amt;
    }
    public int compareTo(Transaction that){
        return this.amount - that.amount;
    }
    public int getAmount(){
        return amount;
    }
}

