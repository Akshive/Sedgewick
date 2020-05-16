//use only for integers//


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

class Evaluator{
    private:
        string str;
        bool isOperand(char c){
            if(c >= '0' && c <= '9'){
                return true;
            }
            return false;
        }
        int charToInt(char c){
            return (int)((int)c - (int)'0');
        }
        double operation(double operand1, double operand2, char op){
            switch(op){
                case '*': return operand1*operand2;
                case '/': return operand1/operand2;
                case '-': return operand1-operand2;
                default : return operand1+operand2;
            }
        }
        double compute(string s){
            int size = s.size();
            stack<double> operand_st;
            stack<char> operator_st;

            for(int i = 0; i < size; i++){
                if(isOperand(s[i])){
                    double temp = 0;
                    while(i < size && isOperand(s[i])){
                        temp = temp*10 + charToInt(s[i]);
                        i++;
                    }
                    i--;
                    operand_st.push(temp);
                }
                else{
                    if(!operator_st.empty() && (operator_st.top() == '*' || operator_st.top() == '/')){
                        double op2 = operand_st.top(); operand_st.pop();
                        double op1 = operand_st.top(); operand_st.pop();
                        operand_st.push(operation(op1, op2, operator_st.top()));
                        operator_st.pop();
                        operator_st.push(s[i]);
                    }
                    else{
                        operator_st.push(s[i]);
                    }
                }
            }
            while(!operator_st.empty()){
                double op2 = operand_st.top(); operand_st.pop();
                double op1 = operand_st.top(); operand_st.pop();
                operand_st.push(operation(op1, op2, operator_st.top()));
                operator_st.pop();
            }
            
            return operand_st.top();
        }
    public:
        Evaluator(string str){
            this->str = str;
        }
        int evaluate(){
            string s = this->str;
            int size = s.size();
            stack<char> st;

            for(int i = 0; i < size; i++){
                if(s[i] == ')'){
                    string temp;
                    while(!st.empty() && st.top() != '('){
                        temp.push_back(st.top());
                        st.pop();
                    }
                    if(!st.empty())st.pop();
                    reverse(temp.begin(), temp.end());
                    int var = compute(temp);
                    temp = to_string(var);
                    for(int i = 0; i < temp.size(); i++){st.push(temp[i]);}
                }
                else st.push(s[i]);
            }
            string temp;
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            return compute(temp);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string str;
    getline(cin, str);
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    Evaluator xyz(str);
    cout<<xyz.evaluate()<<endl;
    return 0;
}
