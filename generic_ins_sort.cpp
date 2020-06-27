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

//override '>'/'<' operators for wrapper classes 
template <typename T>
void ins_sort(T a[], int size){
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0 && a[j] > a[j-1]; j--){
            swap(a[j], a[j-1]);
        }
    }
}

class Integer{
    private:
        int val;
    public:
        Integer(){val = 0;}
        Integer(int val){this->val = val;}
        bool operator > (const Integer& obj){
            return val > obj.val;
        }
        void setValue(int val){
            this->val = val;
        }
        int getValue(){return val;}

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    Integer a[4];
    int temp;
    REP(i, 0, 3){cin>>temp; a[i].setValue(temp);}
    ins_sort(a, 4);
    REP(i, 0, 3)cout<<a[i].getValue()<<" ";
    return 0;
}
