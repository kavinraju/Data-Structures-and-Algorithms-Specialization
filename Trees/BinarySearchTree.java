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

    BinarySearchTree() {
        root = null;
    }

    // Insertion
    public void insert(int new_val) {
        root = insertItem(root, new_val);
    }

    private Node insertItem(Node root, int new_val) {

        if (root == null) {
            root = new Node(new_val);
            return root;
        }

        if (new_val > root.value)
            root.right = insertItem(root.right, new_val);
        else if (new_val < root.value)
            root.left = insertItem(root.left, new_val);

        return root;
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

    boolean checkBST(Node root) {
        if (root.left != null && root.left.value < root.value) {
            checkBST(root.left);
        } else {
            return false;
        }

        if (root.right != null && root.right.value > root.value) {
            checkBST(root.right);
        } else {
            return false;
        }

        return true;
    }

    public void inOrder() {
        inOrder(root);
    }

    private void inOrder(Node root) {
        if (root != null) {
            inOrder(root.left);
            System.out.print(root.value + " ");
            inOrder(root.right);
        }
    }

    public static void main(String[] args) {

        BinarySearchTree tree = new BinarySearchTree();

        // Insert elements
        tree.insert(4);
        tree.insert(2);
        tree.insert(1);
        tree.insert(3);
        tree.insert(5);
        tree.insert(0);

        // Check search
        // Should be True
        System.out.println(tree.search(0));
        // Should be False
        System.out.println(tree.search(6));

        // Check if the Tree is BST
        System.out.println("Check if the Tree is BST:");
        System.out.println(tree.checkBST(tree.root));

        System.out.println("Priting in In-Order: ");
        tree.inOrder();
    }
}