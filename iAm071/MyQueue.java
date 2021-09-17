package MyQueue;

public class MyQueue {
	private Node head;
	private Node tail;
	private int size = 0;
	
	MyQueue() {
		this.head = null;
		this.tail = null;
	}
	
	public String offer(String data) {
		Node newNode = new Node(data);
		
		if(head == null && tail == null)
			head = tail = newNode;
		else {
			tail.setNextNode(newNode);
			tail = newNode;
		}
		size++;
		
		return data;
	}
	
	public String poll() {
		if(head == null && tail == null) {
			System.out.println("Queue is empty");
			return null;
		}
		String temp = head.getData();
		head = head.getNextNode();
		size--;
		return temp;
	}
	
	public String peek() {
		if(head == null && tail == null) {
			System.out.println("Queue is empty");
			return null;
		}
		
		return head.getData();
	}
	
	public boolean isEmpty() {
		return size==0;
	}
}

class Node {
	private String data;
	private Node nextNode;
	
	Node(String data) {
		this.data = data;
	}
	
	public String getData() {
		return data;
	}
	
	public Node getNextNode() {
		return nextNode;
	}
	
	public void setNextNode(Node newNode) {
		this.nextNode = newNode;
	}
}