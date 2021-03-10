import java.io.*;
import java.util.*;

public class DFS {
    private int numOfVertices;
    private LinkedList<Integer> adj[];

    DFS(int numOfVertices) {
        this.numOfVertices = numOfVertices;
        adj = new LinkedList[numOfVertices];
        for (int i = 0; i < numOfVertices; i++)
            adj[i] = new LinkedList<>();
    }

    public void addEdge(int v, int w) {
        adj[v].add(w);
    }

    void DFSUtil(int v, boolean visited[]) {

        // Create a stack for DFS
        Stack<Integer> stack = new Stack<>();

        // Push current vertex into stack
        stack.push(v);

        // Iterate until the stack gets empty
        while (!stack.empty()) {

            int x = stack.peek();
            stack.pop();

            // Stack may contain same vertex twice. So
            // we need to print the popped item only
            // if it is not visited.
            if (!visited[x]) {
                // Mark the current node as visited and print
                System.out.print(x + " ");
                visited[x] = true;
            }

            // Get all adjacent vertices of the popped vertex x
            // If a adjacent has not been visited, then push it
            // to the stack.
            Iterator<Integer> itr = adj[x].listIterator();
            while (itr.hasNext()) {
                int y = itr.next();
                if (!visited[y]) {
                    stack.push(y);
                }
            }
        }
    }

    public void DFS() {
        boolean visited[] = new boolean[numOfVertices];

        // For Disjoint graph
        for (int i = 0; i < numOfVertices; i++)
            if (visited[i] == false)
                DFSUtil(i, visited);
    }

    public static void main(String[] args) {
        DFS dfs = new DFS(5);
        dfs.addEdge(0, 1);
        dfs.addEdge(0, 2);
        dfs.addEdge(0, 4);
        dfs.addEdge(1, 2);
        dfs.addEdge(2, 0);
        dfs.addEdge(2, 3);
        dfs.addEdge(3, 3);

        System.out.println("Depth First Traversal:");

        dfs.DFS();
    }
}
