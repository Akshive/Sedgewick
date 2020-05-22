import java.util.*;

/*package whatever //do not write package name here */


public class Main {
	public static void main (String[] args) throws Exception{
        Stack<Integer> st = new Stack<Integer>();
        for(int i = 0; i < 10; i++){
            st.push(i);
        }
        Iterator<Integer> it = st.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
            st.pop();
        }
    }
}

class Node<T>{
    private T item;
    private Node<T> next;

    public Node(T item){
        this.item = item;
        this.next = null;
    }
    public T getItem(){
        return item;
    }
    public Node<T> getNext(){
        return next;
    }
    public void setNext(Node<T> next){
        this.next = next;
    }
}

class Stack<T> implements Iterable<T>{
    private Node<T> head;
    private int push_count, pop_count;
    public Stack(){
        head = null;
        push_count = pop_count = 0;
    }
    public boolean isEmpty(){
        return head == null;
    }
    void push(T item){
        push_count += 1;
        if(isEmpty()){
            head = new Node<T>(item);
            return;
        }
        Node<T> newNode = new Node<T>(item);
        newNode.setNext(head);
        head = newNode;
    }
    T top(){
        return head.getItem();
    }
    void pop(){
        pop_count += 1;
        if(!isEmpty()){
            head = head.getNext();
        }
    }
    public Iterator<T> iterator(){
        return new StackIterator();
    }
    private class StackIterator implements Iterator<T>{
        private int push_cnt = push_count;
        private int pop_cnt = pop_count;
        private Node<T> current = head;
        public boolean hasNext(){
            if(push_cnt != push_count || pop_cnt != pop_count){
                throw new ConcurrentModificationException();
            }
            return current != null;
        }
        public T next(){
            if(push_cnt != push_count || pop_cnt != pop_count){
                throw new ConcurrentModificationException();
            }
            T res = current.getItem();
            current = current.getNext();
            return res;
        }
    } 
}

