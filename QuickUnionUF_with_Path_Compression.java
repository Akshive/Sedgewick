import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
/*package whatever //do not write package name here */


public class Main {
	public static void main (String[] args) throws Exception{
        Reader r = new Reader();
        int n = r.readInt();
        QuickUnionUF qu = new QuickUnionUF(n);
        System.out.printf("%d\n", n);
        int[] a;
        StdDraw.setPenRadius(0.005);
        StdDraw.setXscale(0, n+10);
        StdDraw.setYscale(0, 1000);
        for(int i = 1; i <= n; i++){
            a = r.readInts();
            qu.union(a[0], a[1]);
            StdDraw.setPenColor(StdDraw.DARK_GRAY);
            StdDraw.point(i, qu.getCount());
            StdDraw.setPenColor(StdDraw.RED);
            StdDraw.point(i, qu.getTotalCount()/i);
            System.out.printf("%d %d\n", i, qu.getCount());
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

class QuickUnionUF{
    private int[] parent;
    private int total_count;
    private int count;

    public QuickUnionUF(int n){
        total_count = 0;
        parent = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    public int find(int p){
        while(parent[p] != p){
            p = parent[p];
            count += 2;
        }
        count += 1;
        return p;
    }

    public void union(int p, int q){
        count = 0;
        int root_p = find(p);
        int root_q = find(q);

        if(root_p == root_q)return;
        
        parent[root_q] = root_p;
        count += 1;

        int temp_p = p;
        int temp;
        while(temp_p != root_p){
            temp = temp_p;
            temp_p = parent[temp_p];
            parent[temp] = root_p;
            count += 2;
        }
        temp_p = q;
        while(temp_p != root_p){
            temp = temp_p;
            temp_p = parent[temp_p];
            parent[temp] = root_p;
            count += 2;
        }
    }

    public int getTotalCount(){
        total_count += count;
        return total_count;
    }

    public int getCount(){
        return count;
    }
}

class QuickFindUF{
    private int[] parent;
    private int total_count;
    private int count;
    private int n;

    public QuickFindUF(int n){
        this.n = n;
        total_count = 0;
        parent = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    public int find(int p){
        count += 1;
        return parent[p];
    }

    public void union(int p, int q){
        count = 0;
        int root_p = find(p);
        int root_q = find(q);

        if(root_p == root_q)return;

        for(int i = 0; i < n; i++){
            if(parent[i] == root_q){
                parent[i] = root_p;
                count += 2;
            }
            else{
                count += 1;
            }
        }
    }

    public int getTotalCount(){
        total_count += count;
        return total_count;
    }

    public int getCount(){
        return count;
    }
}

class WeightedQuickUnionUF{
    private int[] parent;
    private int[] rank;
    private int total_count;
    private int count;

    public WeightedQuickUnionUF(int n){
        total_count = 0;
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    public int find(int p){
        while(parent[p] != p){
            p = parent[p];
            count += 2;
        }
        count += 1;
        return p;
    }

    public void union(int p, int q){
        count = 0;
        int root_p = find(p);
        int root_q = find(q);

        if(root_p == root_q)return;

        if(rank[root_p] >= rank[root_q]){
            parent[root_q] = root_p;
            if(rank[root_p] == rank[root_q]){
                rank[root_p] += 1;
                count += 3;
            }
            count += 3;
        }
        else{
            parent[root_p] = root_q;
            count += 1;
        }
    }

    public int getTotalCount(){
        total_count += count;
        return total_count;
    }

    public int getCount(){
        return count;
    }
}