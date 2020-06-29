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

void Print(int a[], int size){
    REP(i, 0, size-1){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void dequeue_sort_sim(int a[], int size){
    bool check;
    while(1){
        check = true;
        for(int i = 1; i < size; i++){
            if(a[i] < a[i-1]){swap(a[i], a[i-1]); check=false;}
        }
        if(check)return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int a[4] = {1, 4, 3, 2};
    dequeue_sort_sim(a, 4);
    Print(a, 4);
    return 0;
}
