
/*
    Create a Graph 
*/
class Graph{

    /*
        Create a Edge
        It consists of src - source
                       dest - destination
                       weight - weight of the edge 
    */
    class Edge{
        int src, dest, weight;
        Edge(){
            src = dest = weight = 0;
        }
    }

    int V, E;
    Edge edge[];

    Graph(int v, int e){

        this.V = v;
        this.E = e;

        edge = new Edge[e];
        // Initialize the edges
        for(int i=0; i<e; ++i)
            edge[i] = new Edge();
    }


    void bellmanFord(Graph graph, int src){

        int vertices = graph.V, edges = graph.E;
        // Initailize the distance array and assign Integer.MAX_VALUE to all the positions.
        int dist[] = new int[vertices];

        for(int i=0; i<vertices; i++)
            dist[i] = Integer.MAX_VALUE;
        
        dist[src] = 0;  // Assign 0 to source vertex

        /*
            Iterate (vertices - 1) times over all the edges and do the relaxation on each vertex.
        */
        for(int i=1; i<vertices; i++){
            for(int j=0; j<edges; j++){
                int u = graph.edge[j].src;
                int v = graph.edge[j].dest;
                int weight = graph.edge[j].weight;
                // relaxation condition
                if( dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + graph.edge[j].weight;

            }
        }

        // Check for negative weighted cycle
        for(int j=0; j<edges; j++){
            int u = graph.edge[j].src;
            int v = graph.edge[j].dest;
            int weight = graph.edge[j].weight;
            if( dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]){
                System.out.println("Graph contains negative weighted cycle."); 
                return;
            }
        }

        printArr(dist, vertices, src);
    }

    void printArr(int dist[], int vertices, int src){
        System.out.println("Shortest distance in the graph from the vertex " + src);
        for(int i=0;i<vertices; i++)
            System.out.println(i + "\t\t" + dist[i]);
    }
}


class Belmann_Ford_Algorithm{
    
    public static void main(String[] args) {
        int V = 5; // Number of vertices in graph 
        int E = 8; // Number of edges in graph 
  
        Graph graph = new Graph(V, E); 
  
        // add edge 0-1 (or A-B in above figure) 
        graph.edge[0].src = 0; 
        graph.edge[0].dest = 1; 
        graph.edge[0].weight = -1; 
  
        // add edge 0-2 (or A-C in above figure) 
        graph.edge[1].src = 0; 
        graph.edge[1].dest = 2; 
        graph.edge[1].weight = 4; 
  
        // add edge 1-2 (or B-C in above figure) 
        graph.edge[2].src = 1; 
        graph.edge[2].dest = 2; 
        graph.edge[2].weight = 3; 
  
        // add edge 1-3 (or B-D in above figure) 
        graph.edge[3].src = 1; 
        graph.edge[3].dest = 3; 
        graph.edge[3].weight = 2; 
  
        // add edge 1-4 (or A-E in above figure) 
        graph.edge[4].src = 1; 
        graph.edge[4].dest = 4; 
        graph.edge[4].weight = 2; 
  
        // add edge 3-2 (or D-C in above figure) 
        graph.edge[5].src = 3; 
        graph.edge[5].dest = 2; 
        graph.edge[5].weight = 5; 
  
        // add edge 3-1 (or D-B in above figure) 
        graph.edge[6].src = 3; 
        graph.edge[6].dest = 1; 
        graph.edge[6].weight = 1; 
  
        // add edge 4-3 (or E-D in above figure) 
        graph.edge[7].src = 4; 
        graph.edge[7].dest = 3; 
        graph.edge[7].weight = -3; 
  
        graph.bellmanFord(graph, 0); 
    }
}