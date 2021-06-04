/*
    Time Complexity: O(V^2)
*/
public class Djikstra_Algorithm_Matrix_Method {

    class Graph{
       int vertices;

        Graph(int vertices){
            this.vertices = vertices;
        }

        int minimumDistance(int dist[], Boolean sptSet[]){
            int min = Integer.MAX_VALUE, min_index = -1;
            
            for(int i=0; i< vertices; i++)
                // if not already visited and distance to the vertex i is less the min
                if(!sptSet[i] && dist[i] < min){
                    min = dist[i];
                    min_index = i;
                }
            return min_index;
        }
    
        void dijkstra(int graph[][], int src){

            // Initialize distance array and a set to store the visted vertex
            int dist[] = new int[vertices];

            Boolean sptSet[] = new Boolean[vertices];

            for(int i=0; i<vertices; i++){
                dist[i] = Integer.MAX_VALUE;
                sptSet[i] = false;
            }

            dist[src] = 0; // Set the source vertex distance to 0

            // Iterate over vertices - 1 times to find the shortest distance of all the vertices
            for(int i=0; i<vertices-1; i++){

                // Find the minimumDistance of the unvisited vertex
                int u = minimumDistance(dist, sptSet);

                // set it as visited
                sptSet[u] = true;

                // Update the dist of the adjacent vertices of picked vertex 'u'
                for(int vertex=0; vertex<vertices; vertex++)
                    /*
                        Update the adjacent vertex distance only if
                            - it is not visited
                            - it's an actual edge, as in matrix representation 0 is not an edge
                            - total distance from u to v is small than the current distance
                    */
                    if(!sptSet[vertex] && graph[u][vertex] != 0 && dist[u] != Integer.MAX_VALUE && 
                            dist[u] + graph[u][vertex] < dist[vertex])
                            dist[vertex] = dist[u] + graph[u][vertex];
            }
            
            // Print the shortest distance calculated
            printArr(dist, vertices, src);
        }

        void printArr(int dist[], int vertices, int src){
            System.out.println("Shortest distance in the graph from the vertex " + src);
            for(int i=0;i<vertices; i++)
                System.out.println(i + "\t\t" + dist[i]);
        }
    
    }

    public static void main(String[] args) {
        int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

        Djikstra_Algorithm_Matrix_Method d = new Djikstra_Algorithm_Matrix_Method();
        Graph g = d.new Graph(9);
        g.dijkstra(graph, 0);
    }
}
