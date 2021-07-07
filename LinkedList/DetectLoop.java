/**
 * https://www.geeksforgeeks.org/implementing-a-linked-list-in-java-using-class/
 */
public class DetectLoop {
    public static void main(String[] args) {

        LinkedListImplementation list = new LinkedListImplementation();
        list.insert(2);
        list.insert(80);
        list.insert(4);
        list.insert(6);
        list.insert(3);
        list.insert(10);
        list.print();

        System.out.println("Delete Last Node without head: ");
        list.deleteNodeWithoutHead(list.head.next.next.next.next.next);
        list.print();

        System.out.println("Delete Node without head: ");
        list.deleteNodeWithoutHead(list.head.next.next);
        list.print();

        System.out.println("Detect loop before introducing a looping mannually: ");
        list.detectLoopMethodHashing(list.head);

        // Now add some looping
        // that is connecting the 10 to 6
        list.head.next.next.next = list.head.next;

        System.out.println("Detect loop after introducing a looping mannually: ");
        list.detectLoopMethodHashing(list.head);
    }
}
