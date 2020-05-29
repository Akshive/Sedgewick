import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
/*package whatever //do not write package name here */


public class Main {
	public static void main (String[] args) throws Exception{
        
        Reader r = new Reader();
        int n = r.readInt();
        WeightedQuickUnionUF qu = new WeightedQuickUnionUF(n);
        Random random = new Random();
        while(qu.getConnectedComponents() != 1){
            int rand1 = random.nextInt(n);
            int rand2 = random.nextInt(n);
            if(!qu.connected(rand1, rand2)){
                qu.union(rand1, rand2);
            }
            System.out.printf("%d\n", count(qu));
        }
    }

    public static int count(WeightedQuickUnionUF qu){
        return qu.getConnections();
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

class WeightedQuickUnionUF{
    private int[] parent;
    private int[] rank;
    private int total_count;
    private int count;
    private int connected_components;
    private int connections;

    public WeightedQuickUnionUF(int n){
        total_count = 0;
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        connected_components = n;
        connections = 0;
    }
    
    public boolean connected(int p, int q){
        return find(p) == find(q);
    }

    public int find(int p){
        count += 1;
        if(parent[p] == p)return p;
        count += 2;
        return parent[p] = find(parent[p]);
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

        connected_components -= 1;
        connections += 1;
    }

    public int getTotalCount(){
        total_count += count;
        return total_count;
    }

    public int getCount(){
        return count;
    }

    public int getConnectedComponents(){
        return connected_components;
    }

    public int getConnections(){
        return connections;
    }
}
