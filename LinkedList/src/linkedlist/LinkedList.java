package linkedlist;

public class LinkedList {
	private Node head;
	private int count;
	
	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}

	public Node getHead() {
		return head;
	}

	public void setHead(Node head) {
		this.head = head;
	}
	
	public LinkedList() {
		head = null;
		count = 0;
	}
	
	public void add(int keys, int pos) {
		Node new_node = new Node(keys);
		
		Node tmp = head;
		Node pre = null;
		if(pos > count) return;
		if(head == null) {
			head = new_node;
			count++;
		} else {
			while(pos>0) {
				pre = tmp;
				tmp = tmp.getNext();
				pos--;
			}
			
			pre.setNext(new_node);
			new_node.setNext(tmp);
			count++;
		}
	}
	
	public void del(int pos) {
		if(pos < 0 || pos >= count) return;
		
		Node tmp = head;
		while(pos > 0) {
			tmp = tmp.getNext();
			pos--;
		}
		
		tmp = tmp.getNext();
		count--;
	}
	
	public boolean check(int keys) {
		if(count == 0) return false;
		
		Node foo = head;
		while(foo != null) {
			if(foo.getKeys() == keys) return true;
			foo = foo.getNext();
		}
		return false;
		
	}
}
