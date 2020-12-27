package linkedlist;

public class Test {
	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		list.add(9, 0);
		System.out.println(list.getCount());
		if(list.check(9)) System.out.println("true");
		else System.out.println("false");
	}
}
