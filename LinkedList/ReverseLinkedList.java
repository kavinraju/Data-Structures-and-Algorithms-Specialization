
public class ReverseLinkedList {

    static void reverseLinkedList(LinkedListImplementation list) {
        LinkedListImplementation.Node prev = null, current = list.head, next = null;

        // 5 -> 6 -> 8
        while (current != null) {
            // Point the Node's next node to the next variable
            // 1. next = 6
            // 2. next = 8
            // 3. next = null
            next = current.next;

            // Update the Node's next node to prev variable
            // 1. current.next = null
            // 2. current.next = 5
            // 3. current.next = 6
            current.next = prev;

            // Update the prev variable to current Node
            // 1. prev = 5
            // 2. prev = 6
            // 3. prev = 8
            prev = current;

            // Update the current Node to next variable
            // 1. current = 6
            // 2. current = 8
            // 3. current = null
            current = next;
        }
        // Update the head of the LinkedList
        // list.head = 8
        list.head = prev;
    }

    public static void main(String[] args) {
        LinkedListImplementation list = new LinkedListImplementation();
        list.insert(2);
        list.insert(80);
        list.insert(4);
        list.insert(6);
        list.insert(3);
        list.insert(10);
        list.print();

        ReverseLinkedList.reverseLinkedList(list);
        System.out.println("After reversing:");
        list.print();

    }
}
