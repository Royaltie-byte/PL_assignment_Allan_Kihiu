
public class Main {

    static final int MAX_SIZE = 100;

    static class ArrayList {
        int[] data = new int[MAX_SIZE];
        int size = 0;
    }

    // insert value at index
    static void insertAt(ArrayList list, int index, int value) {
        // check if full
        if (list.size == MAX_SIZE) {
            System.out.println("The list is full!!");
            return;
        }

        // check index
        if (index > list.size || index < 0) {
            System.out.println("The input index is invalid.");
            return;
        }

        // shift elements right
        for (int i = list.size; i >= index; i--) {
            list.data[i + 1] = list.data[i];
        }

        list.data[index] = value;
        list.size++;
    }

    // print all elements
    static void traverse(ArrayList list) {
        if (list.size == 0) {
            System.out.println("The list is empty");
            return;
        }

        for (int i = 0; i < list.size; i++) {
            System.out.println("The data at " + i + " is " + list.data[i]);
        }
    }

    // delete element at index
    static void deleteAt(ArrayList list, int index) {
        if (list.size == 0) {
            System.out.println("The list is empty!");
            return;
        }

        if (index < 0 || index >= list.size) {
            System.out.println("Invalid index");
            return;
        }

        // shift elements left
        for (int i = index; i < list.size - 1; i++) {
            list.data[i] = list.data[i + 1];
        }

        list.size--;
    }

    public static void main(String[] args) {
        ArrayList list = new ArrayList();

        insertAt(list, 0, 12);
        insertAt(list, 0, 20);
        insertAt(list, 0, 90);
        insertAt(list, 0, 120);
        insertAt(list, 4, 1000);

        traverse(list);
        System.out.println("The size of the new array after insertions is : " + list.size);

        // testing delete
        deleteAt(list, 0);
        deleteAt(list, 3);

        System.out.println("Array after deletion");
        traverse(list);
        System.out.println("Size of array after two deletions is : " + list.size);
    }
}
