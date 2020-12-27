package linkedlist;

public class Node {
	private int keys;
	private Node next;
	
	public int getKeys() {
		return keys;
	}
	
	public void setKeys(int keys) {
		this.keys = keys;
	}
	
	public Node getNext() {
		return next;
	}
	
	public void setNext(Node next) {
		this.next = next;
	}
	
	public Node(int keys) {
		this.keys = keys;
		this.next = null;
	}
}
