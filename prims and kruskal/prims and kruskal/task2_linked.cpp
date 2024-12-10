#include <iostream>
#include <climits>

class Node {
public:
    int vertex;
    int weight;
    Node* next;
    
};

class Graph {
    int vertices;
    Node** adjacency_list;
public:
    Graph(int vertices) : vertices(vertices) 
    {
        adjacency_list = new Node * [vertices];
        for (int i = 0; i < vertices; i++) 
        {
            adjacency_list[i] = nullptr;
        }
    }

    void addEdge(int u, int v, int weight) 
    {
        Node* new_node = new Node{ v, weight, adjacency_list[u] };
        adjacency_list[u] = new_node;
    }

    void dijkstra(int source) 
    {
        int* distances = new int[vertices];
        bool* visited = new bool[vertices];

        for (int i = 0; i < vertices; i++) 
        {
            distances[i] = INT_MAX;
            visited[i] = false;
        }
        distances[source] = 0;

        for (int i = 0; i < vertices - 1; i++) 
        {
            int min_distance = INT_MAX;
            int u = -1;
            for (int j = 0; j < vertices; j++) 
            {
                if (!visited[j] && distances[j] < min_distance) 
                {
                    min_distance = distances[j];
                    u = j;
                }
            }

            visited[u] = true;

            Node* current = adjacency_list[u];
            while (current != nullptr) {
                int v = current->vertex;
                int weight = current->weight;
                if (!visited[v] && distances[u] + weight < distances[v]) 
                {
                    distances[v] = distances[u] + weight;
                }
                current = current->next;
            }
        }

        std::cout << "Shortest path from house to university:\n";
        for (int i = 0; i < vertices; i++) {
            std::cout << "Distance to vertex " << i << ": " << distances[i] << std::endl;
        }

        delete[] distances;
        delete[] visited;
    }


};

int main() 
{
    Graph graph(6);

    graph.addEdge(0, 1, 10); //house to Place 1
    graph.addEdge(1, 2, 5);  //place 1 to Place 2
    graph.addEdge(2, 3, 15); //place 2 to Place 3
    graph.addEdge(3, 4, 10); //place 3 to Place 4
    graph.addEdge(4, 5, 5);  //place 4 to University

    graph.dijkstra(0); // Start from the house (vertex 0)

    return 0;
}
