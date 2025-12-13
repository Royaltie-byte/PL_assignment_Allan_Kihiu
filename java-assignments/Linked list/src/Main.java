public class Main {

    // Node structure
    static class Node {
        int data;
        Node next;

        Node(int value) {
            data = value;
            next = null;
        }
    }

    // Linked list
    static class LinkedList {
        Node head;
        int size;

        LinkedList() {
            head = null;
            size = 0;
        }
    }

    // insert at index
    static void insertAt(LinkedList list, int index, int value) {
        if (index < 0 || index > list.size) {
            System.out.println("Error: Invalid index.");
            return;
        }

        Node newNode = new Node(value);

        if (index == 0) { // insert at start
            newNode.next = list.head;
            list.head = newNode;
        } else { // insert at middle/end
            Node current = list.head;
            for (int i = 0; i < index - 1; i++) {
                current = current.next;
            }
            newNode.next = current.next;
            current.next = newNode;
        }

        list.size++;
    }

    // delete at index
    static void deleteAt(LinkedList list, int index) {
        if (list.size == 0) {
            System.out.println("Error: List is empty.");
            return;
        }

        if (index < 0 || index >= list.size) {
            System.out.println("Error: Invalid index.");
            return;
        }

        Node temp;

        if (index == 0) { // delete first
            temp = list.head;
            list.head = list.head.next;
        } else { // delete middle/end
            Node current = list.head;
            for (int i = 0; i < index - 1; i++) {
                current = current.next;
            }
            temp = current.next;
            current.next = temp.next;
        }

        temp.next = null; // optional, clean reference
        list.size--;
    }

    // traverse and print list
    static void traverse(LinkedList list) {
        Node current = list.head;

        if (current == null) {
            System.out.println("[empty]");
            return;
        }

        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        insertAt(list, 0, 10);
        insertAt(list, 1, 20);
        insertAt(list, 1, 15);
        insertAt(list, 3, 25);

        System.out.print("List after insertions: ");
        traverse(list);

        deleteAt(list, 1);
        System.out.print("List after deleting index 1: ");
        traverse(list);

        deleteAt(list, 0);
        System.out.print("List after deleting index 0: ");
        traverse(list);
    }
}
