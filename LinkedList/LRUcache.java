import java.util.Deque;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * https://www.geeksforgeeks.org/lru-cache-implementation/
 */
public class LRUcache {

    // store the keys of cache
    private Deque<Integer> doublyQDeque;

    // store the references of cache
    private HashSet<Integer> hashSet;

    private final int CACHE_SIZE;

    public LRUcache(int cache_size) {
        this.CACHE_SIZE = cache_size;
        doublyQDeque = new LinkedList<>();
        hashSet = new HashSet<>();
    }

    public void refer(int page) {
        if (!hashSet.contains(page)) {
            if (doublyQDeque.size() == CACHE_SIZE) {
                int last = doublyQDeque.removeLast();
                hashSet.remove(last);
            }
        } else {
            doublyQDeque.remove(page);
        }
        doublyQDeque.push(page);
        hashSet.add(page);
    }

    public void display() {
        Iterator<Integer> iterator = doublyQDeque.iterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
    }

    public static void main(String[] args) {
        LRUcache cache = new LRUcache(4);
        cache.refer(1);
        cache.refer(2);
        cache.refer(3);
        cache.refer(1);
        cache.refer(4);
        cache.refer(5);
        cache.refer(2);
        cache.refer(2);
        cache.refer(1);
        cache.display();
    }
}