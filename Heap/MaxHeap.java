public class MaxHeap {

    private int[] heap;
    private int size;
    private int max_size;

    MaxHeap(int max_size) {
        this.max_size = max_size;
        this.size = -1;
        heap = new int[this.max_size];
    }

    // Returns the position of the parent for the give position i
    private int parent(int i) {
        return (i - 1) / 2;
    }

    // Returns the position of the left child for the give position i
    private int leftChild(int i) {
        return (2 * i) + 1;
    }

    // Returns the position of the right child for the give position i
    private int rightChild(int i) {
        return (2 * i) + 2;
    }

    // Helper method to swap two postions
    private void swap(int a, int b) {
        int temp;
        temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }

    // Method to insert elements into the array as a Max Heap
    public void insert(int element) {
        heap[++size] = element;

        int current = size;
        while (heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    // Helper method to print the Heap array
    public void print() {
        for (int i = 0; i < size / 2; i++) {
            if (i == 0)
                System.out.print(" PARENT : " + heap[0]);
            else
                System.out.print(" PARENT : " + heap[(i - 1) / 2]);

            System.out.print(" LEFT CHILD : " + heap[2 * i + 1] + " RIGHT CHILD :" + heap[2 * i + 2]);
            System.out.println();
        }
    }

    // Method to remove an element from max heap
    public int extractMax() {
        int popped = heap[0];
        heap[0] = heap[size--];
        maxHeapify(0);
        return popped;
    }

    // A recursive function to max heapify the given
    // subtree. This function assumes that the left and
    // right subtrees are already heapified, we only need
    // to fix the root.
    private void maxHeapify(int pos) {
        if (isLeaf(pos))
            return;

        if (heap[pos] < heap[leftChild(pos)] || heap[pos] < heap[rightChild(pos)]) {
            if (heap[leftChild(pos)] > heap[rightChild(pos)]) {
                swap(pos, leftChild(pos));
                maxHeapify(leftChild(pos));
            } else {
                swap(pos, rightChild(pos));
                maxHeapify(rightChild(pos));
            }
        }
    }

    // Returns true of given node is leaf
    private boolean isLeaf(int pos) {

        if (pos > (size / 2) && pos <= size)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        System.out.println("The Max Heap is ");
        MaxHeap maxHeap = new MaxHeap(15);
        maxHeap.insert(5);
        maxHeap.insert(3);
        maxHeap.insert(17);
        maxHeap.insert(10);
        maxHeap.insert(84);
        maxHeap.insert(19);
        maxHeap.insert(6);
        maxHeap.insert(22);
        maxHeap.insert(9);

        maxHeap.print();

        int max = maxHeap.heap[0];
        System.out.println("The max val is " + max);

        maxHeap.extractMax();
        System.out.println("After calling extractMax method:");
        maxHeap.print();
    }
}