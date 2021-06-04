import java.util.*;

public class DFS_Recursive {
    private int numOfVertices;
    private LinkedList<Integer> adj[];

    DFS_Recursive(int numOfVertices) {
        this.numOfVertices = numOfVertices;
        adj = new LinkedList[numOfVertices];
        for (int i = 0; i < numOfVertices; i++)
            adj[i] = new LinkedList<>();
    }

    public void addEdge(int v, int w) {
        adj[v].add(w);
    }

    void DFSUtil(int v, boolean visited[]) {
        // Mark the current node as visited and print
        visited[v] = true;
        System.out.print(v + " ");

        // Iterate over the adjacent vertices
        Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) {
            int x = i.next();
            if (!visited[x])
                DFSUtil(x, visited);
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
        DFS_Recursive dfs = new DFS_Recursive(5);
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
