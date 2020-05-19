/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main (String[] args) throws Exception{
        Queue<String> q = new Queue<String>();
        q.push("abc");
        System.out.println(q.front());
        q.pop();
        System.out.println(q.front());
    }
}

class Node <T>{
    public T item;
    public Node<T> next;
}

class Queue <T>{
    private Node<T> last;
    boolean isEmpty(){
        return last == null;
    }
    public void push(T item){
        Node<T> temp = new Node<T>();
        temp.item = item;
        if(isEmpty()){
            last = temp;
        }
        else{
            temp.next = last.next;
        }
        last.next = temp;
    }
    public T front() throws Exception{
        if(isEmpty()){
            throw new Exception("Empty Queue");
        }
        T temp = last.next.item;
        return temp;
    }
    public void pop(){
        if(isEmpty())return;
        if(last.next == last){
            last = null; return;
        }
        last.next = last.next.next;
    }
}
