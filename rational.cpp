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

class Rational{
    private:
        int num, den;
        void simplify(){
            int gcd = __gcd(num, den);
            if(gcd != 1){
                num /= gcd;
                den /= gcd;
            }
        }
    public:
        Rational(int num, int den){
            this->num = num;
            this->den = den;
            simplify();
        }
        Rational plus(Rational b){
            int num = this->num*b.getDen() + this->den*b.getNum();
            int den = this->den*b.getDen();
            return Rational(num, den);
        }
        Rational times(Rational b){
            Rational rt1(this->num, b.getDen());
            Rational rt2(b.getNum(), this->den);
            return Rational(rt1.getNum()*rt2.getNum(), rt1.getDen()*rt2.getDen());
        }
        Rational divides(Rational b){
            return this->times(Rational(b.getDen(), b.getNum()));
        }
        int getNum(){return this->num;}
        int getDen(){return this->den;}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    
    Rational rt(3, 6);
    cout<<rt.getDen()<<" "<<rt.getNum()<<endl;
    Rational rt2(1, 6);
    cout<<rt2.getDen()<<" "<<rt2.getNum()<<endl;
    Rational res = rt.divides(rt2);
    cout<<res.getDen()<<" "<<res.getNum()<<endl;
    return 0;
}
