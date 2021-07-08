public class SortedInsertLinkedList {

    public static void main(String[] args) {
        LinkedListImplementation list = new LinkedListImplementation();
        list.insertBySort(2);
        list.insertBySort(81);
        list.insertBySort(41);
        list.insertBySort(16);
        list.insertBySort(32);
        list.insertBySort(-10);
        list.insertBySort(81);
        list.insertBySort(1);
        list.insertBySort(1);
        list.insertBySort(10);
        list.insertBySort(-81);
        list.insertBySort(41);
        list.insertBySort(-1);
        list.print();
    }
}
