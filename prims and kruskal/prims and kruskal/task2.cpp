////Create a map of 6 vertices.The First Vertex should be your house, last vertex should be your
////university.The remaining vertices should be the famous places between the first and last vertex.
////The map contains many paths to reach the university but there is only one source which is your
////house.Implement Dijkstra’s Algorithm to find the shortest path.
//
////using array
//
//#include <iostream>
//using namespace std;
//const int MAX_VERTICES = 6;
//int graph[MAX_VERTICES][MAX_VERTICES];
//int distances[MAX_VERTICES]; 
//bool visited[MAX_VERTICES]; 
//
//void dijkstra_array(int source) 
//{
//    for (int i = 0; i < MAX_VERTICES; i++) 
//    {
//        distances[i] = INT_MAX;
//        visited[i] = false;
//    }
//    distances[source] = 0;
//
//    for (int i = 0; i < MAX_VERTICES - 1; i++) {
//        int min_distance = INT_MAX;
//        int u = -1;
//        for (int j = 0; j < MAX_VERTICES; j++) 
//        {
//            if (!visited[j] && distances[j] < min_distance) 
//            {
//                min_distance = distances[j];
//                u = j;
//            }
//        }
//
//        visited[u] = true;
//
//        for (int v = 0; v < MAX_VERTICES; v++) 
//        {
//            if (!visited[v] && graph[u][v] != 0 && distances[u] + graph[u][v] < distances[v]) 
//            {
//                distances[v] = distances[u] + graph[u][v];
//            }
//        }
//    }
//
//    cout << "Shortest path from house to university:\n";
//    for (int i = 0; i < MAX_VERTICES; i++) {
//        cout << "Distance to vertex " << i << ": " << distances[i] << endl;
//    }
//}
//
//int main() 
//{
//    int graph_input[MAX_VERTICES][MAX_VERTICES] = {
//        {0, 10, 0, 0, 0, 0}, // house=0
//        {10, 0, 5, 0, 0, 0}, //place1 =1
//        {0, 5, 0, 15, 0, 0}, //place 2 =2
//        {0, 0, 15, 0, 10, 0}, //place 3 =3
//        {0, 0, 0, 10, 0, 5}, //place 4 =4
//        {0, 0, 0, 0, 5, 0}  //university (5)
//    };
//
//    for (int i = 0; i < MAX_VERTICES; i++)
//    {
//        for (int j = 0; j < MAX_VERTICES; j++) {
//            graph[i][j] = graph_input[i][j];
//        }
//    }
//
//    dijkstra_array(0); //start from house
//
//    return 0;
//}
