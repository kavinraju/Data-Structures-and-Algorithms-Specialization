import java.util.HashSet;

public class LinkedListImplementation {

    public Node head;

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // This method inserts the data at the end of the LinkedList
    public void insert(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
        } else {
            Node last = head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = newNode;
        }
    }

    // This method inserts the data at the front/head of the
    public void pushFront(int data) {
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }

    /**
     * Sorted insert in the LinkedList
     * 
     * @param headNode
     */
    public void insertBySort(int data) {
        Node new_node = new Node(data);

        if (head == null) {
            head = new_node;
        } else {

            if (head.next == null) {
                if (data < head.data) {
                    Node next_node = head;
                    head = new_node;
                    head.next = next_node;
                } else {
                    head.next = new_node;
                }
            } else {
                Node node = head; // to iterate over the nodes
                Node prev = null; // to keep hold of the prev node so that we can insert the new node

                // Iterate to the position where the current node.data is less than data.
                // If the data is greater than all the elements in the list then prev node will
                // be the last-node and `node` will be equal to null.
                while (node.data < data) {
                    prev = node;
                    node = node.next;
                    if (node == null)
                        break;
                }

                // condition for values in b/w the list
                if (node != null && prev != null && data <= node.data) {
                    prev.next = new_node;
                    new_node.next = node;
                }
                // condition for values at 0th postion of the list and that's why we change the
                // head value
                else if (prev == null && node.data >= data) {
                    Node next_node = head;
                    head = new_node;
                    new_node.next = next_node;
                }
                // condition for values at the end of the list, that is when prev node will
                // be last-node and `node` will be equal to null.
                else {
                    prev.next = new_node;
                }

            }
        }

    }

    /**
     * https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
     * 
     * Hashing approach: Time Complexity: O(n) Space Complexity: O(n)
     * 
     * @param headNode
     * @return
     */
    public void detectLoopMethodHashing(Node headNode) {
        HashSet<Node> set = new HashSet<>();
        boolean is_loop_available = false;

        while (headNode != null) {

            if (set.contains(headNode)) {
                is_loop_available = true;
                break;
            }

            set.add(headNode);
            headNode = headNode.next;
        }

        if (is_loop_available)
            System.out.println("Loop Detected.");
        else
            System.out.println("Loop Not Detected.");
    }

    /**
     * Floyds Cycle method: Time Complexity: O(n) Space Complexity: O(1)
     * 
     * __Another approach__ is to declare a temp node and while iterating mark the
     * current node's next to the temp Node object, so if we encounter the current
     * Node's next to temp object again then it means there excists a loop.
     * 
     * @param headNode
     * @return
     */
    public void detectLoopMethodFloydCycle(Node headNode) {
        Node slow_p = headNode, fast_p = headNode;
        boolean is_loop_available = false;

        while (slow_p != null && fast_p != null && fast_p.next != null) {
            slow_p = slow_p.next;
            fast_p = fast_p.next.next;

            if (slow_p == fast_p) {
                is_loop_available = true;
                break;
            }
        }

        if (is_loop_available)
            System.out.println("Loop Detected.");
        else
            System.out.println("Loop Not Detected.");
    }

    public void print() {
        Node head = this.head;
        System.out.println("LinkedList: ");
        while (head != null) {
            System.out.print(head.data + ", ");
            head = head.next;
        }
        System.out.println();
    }

    public void printLoopedLinkedList() {

        HashSet<LinkedListImplementation.Node> set = new HashSet<>();
        Node head = this.head;
        System.out.println("LinkedList: ");
        while (head != null) {
            if (set.contains(head))
                break;
            System.out.print(head.data + ", ");
            set.add(head);
            head = head.next;
        }

        set = null;
        System.out.println();
    }

    public void deleteNodeWithoutHead(Node node) {
        if (node == null) {
            return;
        }

        if (node.next == null) {
            System.out.println("This is the last node. Can't delete without having the head pointer.");
            return;
        }

        // Copy the next Node's data to current Node
        Node next_node = node.next;
        node.data = node.next.data;
        // Then point the current Node to the Next Node's Next Node
        node.next = node.next.next;

        // Make the Node to be deleted as null and call the garbage collecter.
        next_node = null;
        System.gc();

    }

}