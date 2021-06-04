import java.util.*;

class GraphBFS {

    private int numOfVertices;
    private LinkedList<Integer> adj[];

    GraphBFS(int numOfVertices) {
        this.numOfVertices = numOfVertices;
        adj = new LinkedList[numOfVertices];
        for (int i = 0; i < numOfVertices; i++)
            adj[i] = new LinkedList<>();
    }

    void addEdge(int v, int w) {
        adj[v].add(w);
    }

    void BFS(int s) {

        // By default add the vertices are not visited, hence all are false
        boolean visited[] = new boolean[numOfVertices];

        // Create a queue for BFS
        LinkedList<Integer> queue = new LinkedList<>();

        // Mark the current node,s, as visisted and enqueue into queue
        visited[s] = true;
        queue.add(s);

        while (queue.size() != 0) {
            // dequeue from the queue and print it
            s = queue.poll();
            System.out.print(s + " ");

            // Get all the adjacent vertices of the dequeued vector s
            // If the adj has not been visited mark it as visited and enqueue it
            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

    public static void main(String[] args) {
        GraphBFS bfs = new GraphBFS(4);

        bfs.addEdge(0, 1);
        bfs.addEdge(0, 2);
        bfs.addEdge(1, 2);
        bfs.addEdge(2, 0);
        bfs.addEdge(2, 3);
        bfs.addEdge(3, 3);

        int x = 2;
        System.out.println("BFS of " + x);
        bfs.BFS(x);
    }
}