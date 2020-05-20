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
class Node{
    public:
        T item;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node<T>(T item){
            this->item = item;
            this->next = NULL;
            this->prev = NULL;
        }
        T getItem(){return item;}
        Node<T>* getNext(){return next;}
        Node<T>* getprev(){return prev;}
        void setItem(T item){this->item = item;}
        void setNext(Node<T>* next){this->next = next;}
        void setPrev(Node<T>* prev){this->prev = prev;}
};

template <class T>
class DLL{
    private:
        Node<T>* head;
        int size;
    public:
        DLL(){
            head = NULL;
            size = 0;
        }
        bool isEmpty(){
            return size == 0;
        }
        void push(T item){
            Node<T>* node = new Node<T>(item);
            push(node);
        }
        void push(Node<T>* node){
            if(isEmpty()){
                head = node;
                size++;
                return;
            }
            Node<T>* current = head;
            while(current->getNext() != NULL){
                current = current->getNext();
            }
            current->setNext(node);
            node->setPrev(current);
            size++;
        }
        void remove(Node<T>* node){
            if(isEmpty())return;
            if(head == node){
                if(head->getNext() != NULL){
                    head->getNext()->setPrev(NULL);
                }
                head = head->getNext();
                size--;
                return;
            }
            Node<T>* current = head;
            while(current != NULL && current != node){
                current = current->getNext();
            }
            if(current == node){
                if(current->getprev() != NULL){
                    current->getprev()->setNext(current->getNext());
                }
                if(current->getNext() != NULL){
                    current->getNext()->setPrev(current->getprev());
                }
                size--;
            }
        }
        void printList(){
            Node<T>* current = head;
            while(current != NULL){
                cout<<current->getItem()<<endl;
                current = current->getNext();
            }
        }
};

template<typename T>
void insert_after(Node<T>* head, Node<T>* node, Node<T>* newNode){
    Node<T>* current = head;
    while(current != NULL && current != node){
        current = current->getNext();
    }
    if(current == node){
        if(current->getNext() != NULL){
            newNode->setNext(current->getNext());
            current->getNext()->setPrev(newNode);
        }
        current->setNext(newNode);
        newNode->setPrev(current);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    Node<int>* first = new Node<int>(1);
    Node<int>* second = new Node<int>(2);
    DLL<int>* dll = new DLL<int>();
    dll->push(first);
    dll->push(second);
    dll->printList();
    Node<int>* third = new Node<int>(3);
    insert_after(first, first, third);
    dll->printList();
    dll->remove(first);
    dll->printList();
    return 0;
}
