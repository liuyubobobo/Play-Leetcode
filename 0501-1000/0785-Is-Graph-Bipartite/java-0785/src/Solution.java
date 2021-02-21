import java.util.Arrays;
import java.util.TreeSet;

public class Solution {

    public class Graph {

        private int V;
        private int E;
        private TreeSet<Integer>[] adj;

        public Graph(int V){

            this.V = V;
            adj = new TreeSet[V];
            for(int i = 0; i < V
                    ; i ++)
                adj[i] = new TreeSet<Integer>();
        }

        public void addEdge(int a, int b){

            if(a == b) throw new IllegalArgumentException();

            adj[a].add(b);
            adj[b].add(a);
            this.E ++;
        }

        public void validateVertex(int v){
            if(v < 0 || v >= V)
                throw new IllegalArgumentException("vertex " + v + "is invalid");
        }

        public int V(){
            return V;
        }

        public int E(){
            return E;
        }

        public boolean hasEdge(int v, int w){
            validateVertex(v);
            validateVertex(w);
            return adj[v].contains(w);
        }

        public Iterable<Integer> adj(int v){
            validateVertex(v);
            return adj[v];
        }

        public int degree(int v){
            validateVertex(v);
            return adj[v].size();
        }

        @Override
        public String toString(){
            StringBuilder sb = new StringBuilder();

            sb.append(String.format("V = %d, E = %d\n", V, E));
            for(int v = 0; v < V; v ++){
                sb.append(String.format("%d : ", v));
                for(int w : adj[v])
                    sb.append(String.format("%d ", w));
                sb.append('\n');
            }
            return sb.toString();
        }
    }

    public class BipartitionDetection {

        private Graph G;

        private boolean[] visited;
        private int[] colors;
        private boolean isBipartite = true;

        public BipartitionDetection(Graph G){

            this.G = G;
            visited = new boolean[G.V()];
            colors = new int[G.V()];
            for(int i = 0; i < G.V(); i ++)
                colors[i] = -1;

            for(int v = 0; v < G.V(); v ++)
                if(!visited[v])
                    if(!dfs(v, 0)){
                        isBipartite = false;
                        break;
                    }
        }

        private boolean dfs(int v, int color){

            visited[v] = true;
            colors[v] = color;
            for(int w: G.adj(v))
                if(!visited[w]){
                    if(!dfs(w, 1 - color)) return false;
                }
                else if(colors[w] == colors[v])
                    return false;
            return true;
        }

        public boolean isBipartite(){
            return isBipartite;
        }
    }

    public boolean isBipartite(int[][] graph){

        int n = graph.length;
        Graph g = new Graph(n);
        for(int i = 0; i < n; i ++)
            for(int j: graph[i]) g.addEdge(i, j);

        return new BipartitionDetection(g).isBipartite();
    }
}