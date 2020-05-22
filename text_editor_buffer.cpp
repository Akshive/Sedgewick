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

template <class T>
class Buffer{
    private:
     int size;
     stack<T> st1, st2;
    public:
     void insert(T c){
         st1.push(c);
     }
     T del(){
         T res = st1.top();
         st1.pop();
         return res;
     }
     void left(int k){
         while(k--){
             if(st1.empty())throw -1;
             st2.push(st1.top()); st1.pop();
         }
     }
     void right(int k){
         while(k--){
             if(st2.empty())throw -1;
             st1.push(st2.top()); st2.pop();
         }
     }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    Buffer<char>* buffer = new Buffer<char>();
    for(char c = 'a'; c <= 'z'; c++){
        buffer->insert(c);
    }
    cout<<buffer->del()<<endl;
    buffer->left(24);
    cout<<buffer->del()<<endl;
    buffer->right(5);
    cout<<buffer->del()<<endl;
    return 0;
}
