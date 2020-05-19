/*package whatever //do not write package name here */


public class Main {
	public static void main (String[] args) throws Exception{
        LinkedList<String> ll = new LinkedList<String>();
        ll.add("abc");
        ll.add("bcd");
        ll.add("cde");
        ll.printList();
        ll.reverse_iterative();
        ll.printList();
        ll.reverse_recursive();
        ll.printList();
    }
}

class Node <T>{
    public T item;
    public Node<T> next;
    public Node(T item){
        this.item = item;
        this.next = null;
    }
    public Node<T> reverse_recursive(){
        Node<T> current = this;
        Node<T> next = current.next;
        if(next == null)return current;
        Node<T> res = next.reverse_recursive();
        current.next = null;
        next.next = current;
        return res;
    }
}

class LinkedList <T>{
    private Node<T> first;
    public boolean isEmpty(){
        return first == null;
    }
    public void printList(){
        Node<T> current = first;
        while(current != null){
            System.out.println(current.item.toString());
            current = current.next;
        }
    }
    public void add(T item){
        Node<T> temp = new Node<T>(item);
        if(isEmpty()){
            first = temp;
            return;
        }
        Node<T> current = first;
        while(current.next != null){
            current = current.next;
        }
        current.next = temp;
    }
    public void reverse_iterative(){
        if(isEmpty())return;
        Node<T> current = first;
        Node<T> prev = null;
        if(current.next == null)return;
        Node<T> next = current.next;
        while(next != null){
            current.next = prev;
            prev = current;
            current = next;
            next = next.next;
        }
        current.next = prev;
        first = current;
    }
    public void reverse_recursive(){
        if(isEmpty())return;
        first = first.reverse_recursive();
    }
}
