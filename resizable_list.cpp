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
class List{
    private:
        T* items = new T[1];
        int n, size = 1;
    public:
        int getSize(){return size;}
        bool isEmpty(){return n == 0;}
        void resize(int newSize){
            T* temp = new T[newSize];
            for(int i = 0; i < n; i++){
                temp[i] = items[i];
            }
            delete[] items;
            items = temp;
            size = newSize;
        }
        void push_back(T item){
            if(n == size){resize(2*size);}
            items[n++] = item;
        }
        T pop_back(){
            if(isEmpty())return NULL;
            T temp = items[--n];
            if(n == size/4)resize(size/2);
            return temp;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    List<int>* ls = new List<int>();
    for(int i = 0; i < 10; i++){
        ls->push_back(i);
        cout<<ls->getSize()<<endl;
    }
    for(int i = 0; i < 10; i++){
        cout<<ls->pop_back()<<" "<<ls->getSize()<<endl;
    }
    return 0;
}
