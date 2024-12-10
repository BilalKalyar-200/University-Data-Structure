////Implement Prim’s Algorithm and Kruskal’s Algorithm using the array.Verify that both the shortest
////paths calculated from both algorithms are the same for the same graph.
//#include <iostream>
//
//const int MAX_VERTICES = 10;
//using namespace std;
//int graph[MAX_VERTICES][MAX_VERTICES];
//
//int parent[MAX_VERTICES];
//bool visited[MAX_VERTICES];
//
//int find(int parent[], int i) 
//{
//    if (parent[i] == i)
//        return i;
//    return find(parent, parent[i]);
//}
//
//
//void union_sets(int parent[], int x, int y) {
//    int x_root = find(parent, x);
//    int y_root = find(parent, y);
//    parent[x_root] = y_root;
//}
//
//void prims_algorithm(int vertices) 
//{
//    int min_cost = 0;
//    int edge_count = 0;
//    visited[0] = true;
//
//    while (edge_count < vertices - 1) 
//    {
//        int min_edge = INT_MAX;
//        int u = -1, v = -1;
//
//        for (int i = 0; i < vertices; i++)
//        {
//            if (visited[i]) {
//                for (int j = 0; j < vertices; j++)
//                {
//                    if (!visited[j] && graph[i][j] != 0 && graph[i][j] < min_edge) 
//                    {
//                        min_edge = graph[i][j];
//                        u = i;
//                        v = j;
//                    }
//                }
//            }
//        }
//
//        if (u != -1 && v != -1)
//        {
//            cout << "Edge: " << u << " - " << v << " with weight " << min_edge << endl;
//            min_cost += min_edge;
//            visited[v] = true;
//            edge_count++;
//        }
//    }
//    cout << "Total weight of MST (Prim's): " << min_cost << endl;
//}
//
//void kruskal_algorithm(int vertices)
//{
//    int edges[MAX_VERTICES * MAX_VERTICES][3];
//    int edge_count = 0;
//    int min_cost = 0;
//
//    for (int i = 0; i < vertices; i++) 
//    {
//        for (int j = i + 1; j < vertices; j++) 
//        {
//            if (graph[i][j] != 0) {
//                edges[edge_count][0] = i;
//                edges[edge_count][1] = j;
//                edges[edge_count][2] = graph[i][j];
//                edge_count++;
//            }
//        }
//    }
//
//    for (int i = 0; i < edge_count - 1; i++)
//    {
//        for (int j = 0; j < edge_count - i - 1; j++) {
//            if (edges[j][2] > edges[j + 1][2])
//            {
//                for (int k = 0; k < 3; k++) 
//                {
//                    int temp = edges[j][k];
//                    edges[j][k] = edges[j + 1][k];
//                    edges[j + 1][k] = temp;
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < vertices; i++) {
//        parent[i] = i;
//    }
//
//    int count = 0;
//    for (int i = 0; i < edge_count && count < vertices - 1; i++) 
//    {
//        int u = edges[i][0];
//        int v = edges[i][1];
//        int weight = edges[i][2];
//
//        int u_parent = find(parent, u);
//        int v_parent = find(parent, v);
//
//        if (u_parent != v_parent) {
//            cout << "Edge: " << u << " - " << v << " with weight " << weight << endl;
//            min_cost += weight;
//            union_sets(parent, u_parent, v_parent);
//            count++;
//        }
//    }
//
//    cout << "Total weight of MST (Kruskal's): " << min_cost << endl;
//}
//
//int main() {
//    int vertices;
//
//    cout << "Enter number of vertices: ";
//    cin >> vertices;
//
//    cout << "Enter adjacency matrix (0 for no edge):\n";
//    {
//    for (int i = 0; i < vertices; i++)
//        for (int j = 0; j < vertices; j++) {
//            cin >> graph[i][j];
//        }
//    }
//
//    cout << "\nPrim's Algorithm Result:\n";
//    for (int i = 0; i < vertices; i++) 
//    {
//        visited[i] = false;
//    }
//    prims_algorithm(vertices);
//
//    cout << "\nKruskal's Algorithm Result:\n";
//    kruskal_algorithm(vertices);
//
//    return 0;
//}
