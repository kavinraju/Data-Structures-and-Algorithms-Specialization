public class BinarySearchTree {

    public class Node {
        int value;
        Node left, right;

        Node(int value) {
            this.value = value;
            left = right = null;
        }
    }

    private Node root;

    BinarySearchTree(int value) {
        root = new Node(value);
    }

    // Insertion
    public void insert(int new_val) {
        insertItem(root, new_val);
    }

    private void insertItem(Node root, int new_val) {
        Node node = new Node(new_val);
        if (new_val > root.value) {

            if (root.right == null)
                root.right = node;
            else
                insertItem(root.right, new_val);

        } else if (new_val < root.value) {

            if (root.left == null)
                root.left = node;
            else
                insertItem(root.left, new_val);
        }
    }

    // Serach
    public boolean search(int find_val) {
        return searchItem(root, find_val);
    }

    private boolean searchItem(Node root, int find_val) {
        // This condition becomes true when find_val is not in the tree and root becomes
        // a None value
        if (root == null)
            return false;

        boolean elementSearchStatus = false;

        if (root.value == find_val)
            elementSearchStatus = true;
        else if (find_val > root.value)
            elementSearchStatus = searchItem(root.right, find_val);
        else if (find_val < root.value)
            elementSearchStatus = searchItem(root.left, find_val);

        return elementSearchStatus;
    }

    public static void main(String[] args) {

        BinarySearchTree tree = new BinarySearchTree(4);

        // Insert elements
        tree.insert(2);
        tree.insert(1);
        tree.insert(3);
        tree.insert(5);

        // Check search
        // Should be True
        System.out.println(tree.search(4));
        // Should be False
        System.out.println(tree.search(6));
    }
}