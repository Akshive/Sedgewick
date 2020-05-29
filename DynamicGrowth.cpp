#include <bits/stdc++.h>
using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define IREP(i, a, b)\
for(int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 1000000000
#define CLR(a) memset(a, 0, sizeof(a))
#define RESET(a) memset(a, -1, sizeof(a))
#define MP(a,b) make_pair((int)a, (int)b)
#define MP2(a,b,c) make_pair((int)a, make_pair((int)b, (int)c))
#define EPS 1e-6
#define char_to_int(c)((int)c-(int)'A')

class WeightedUnionUF{
    private:
        int* parent;
        int* rank;
        int size;
        void resize(int newSize){
            int* temp_parent = new int[newSize];
            int* temp_rank = new int[newSize];
            for(int i = 0; i < size; i++){
                temp_parent[i] = parent[i];
                temp_rank[i] = rank[i];
            }
            for(int i = size; i < newSize; i++){
                temp_parent[i] = i;
                temp_rank[i] = 1;
            }
            delete[] parent;
            delete[] rank;
            parent = temp_parent;
            rank = temp_rank;
            size = newSize;
        }
    public:
        WeightedUnionUF(){
            parent = new int[1];
            rank = new int[1];
            size = 1;
        }
        int find(int p){
            if(p >= size)resize(2*p);
            if(p == parent[p])return p;
            return parent[p] = find(parent[p]);
        }
        void Union(int p, int q){
            if(p >= size || q >= size)resize(2*max(p, q));
            int root_p = find(p);
            int root_q = find(q);

            if(root_p == root_q)return;

            if(rank[root_p] >= rank[root_q]){
                parent[root_q] = root_p;
                if(rank[root_p] == rank[root_q]){
                    rank[root_p] += 1;
                }
            }
            else{
                parent[root_p] = root_q;
            }
        }
        int getSize(){
            return size;
        }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    WeightedUnionUF* uf = new WeightedUnionUF();
    int x = 4, t1, t2;
    while(x--){
        cin>>t1>>t2;
        uf->Union(t1, t2);
        cout<<uf->getSize()<<endl;
    }
    return 0;
}
