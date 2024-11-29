////THIS PROGRAM SHOWS BASIC WORK OF DIRECTED GRAPH
////IT HAS MULTIPLE FUNCTIONS THAT SHOWS HOW A DIRECTED GRAPH WORKS
////THIS CAN BE USED TO SHOW MANY REAL LIFE SCENARIOS LIKE SHOWING DISTANCE BETWEEN MULTIPLE CITIES AND MANY MORE
//
//
//#include <iostream>
//#include <queue>
//#include <conio.h>
//
//using namespace std;
//
//#define NULL_EDGE 0
//
//class graph_type
//{
//private:
//    string* vertices;       //array for vertices
//    int** edges;            //adjacency matrix
//    int num_vertices;       //current number of vertices
//    int max_vertices;
//
//    int index_is(string vertex)
//    {
//        for (int i = 0; i < num_vertices; i++)
//        {
//            if (vertices[i] == vertex)
//            {
//                return i;
//            }
//        }
//        return -1; //vertex not found
//    }
//
//public:
//    graph_type(int size)
//    {
//        max_vertices = size;
//        num_vertices = 0;
//        vertices = new string[max_vertices];
//        edges = new int* [max_vertices];
//        for (int i = 0; i < max_vertices; i++)
//        {
//            edges[i] = new int[max_vertices];
//            for (int j = 0; j < max_vertices; j++)
//            {
//                edges[i][j] = NULL_EDGE;
//            }
//        }
//    }
//
//    ~graph_type()
//    {
//        delete[] vertices;
//        for (int i = 0; i < max_vertices; i++)
//        {
//            delete[] edges[i];
//        }
//        delete[] edges;
//    }
//
//    void add_vertex(string vertex)
//    {
//        if (num_vertices >= max_vertices)
//        {
//            cout << "Graph is full. Cannot add more vertices\n";
//            return;
//        }
//        vertices[num_vertices] = vertex;
//        for (int i = 0; i <= num_vertices; i++)
//        {
//            edges[num_vertices][i] = NULL_EDGE;
//            edges[i][num_vertices] = NULL_EDGE;
//        }
//        num_vertices++;
//    }
//
//    void add_edge(string from_vertex, string to_vertex, int weight)
//    {
//        int row = index_is(from_vertex);
//        int col = index_is(to_vertex);
//        if (row == -1 || col == -1)
//        {
//            cout << "error finding vertices\n";
//            return;
//        }
//        edges[row][col] = weight;
//    }
//
//    int weight_is(string from_vertex, string to_vertex)
//    {
//        int row = index_is(from_vertex);
//        int col = index_is(to_vertex);
//        if (row == -1 || col == -1)
//        {
//            cout << "vertice(s) not found\n";
//            return NULL_EDGE;
//        }
//        return edges[row][col];
//    }
//
//    void get_to_vertices(string vertex, queue<string>& adj_vertices)
//    {
//        int from_index = index_is(vertex);
//        if (from_index == -1)
//        {
//            cout << "vertex not found\n";
//            return;
//        }
//        for (int to_index = 0; to_index < num_vertices; to_index++)
//        {
//            if (edges[from_index][to_index] != NULL_EDGE)
//            {
//                adj_vertices.push(vertices[to_index]);
//            }
//        }
//    }
//
//    void display()
//    {
//        cout << "Adjacency Matrix:\n";
//        for (int i = 0; i < num_vertices; i++)
//        {
//            for (int j = 0; j < num_vertices; j++)
//            {
//                cout << edges[i][j] << " ";
//            }
//            cout << "\n";
//        }
//    }
//};
//
//int main()
//{
//    int size;
//    cout << "Enter number of vertices for the graph: ";
//    cin >> size;
//    string verrr;
//    graph_type graph(size);
//    while (true)
//    {
//        cout << "1.Add vertex\n"
//            << "2.add edge\n"
//            << "3.get weight\n"
//            << "4.get adjacent vertice\n"
//            << "5.Display\n"
//            << "6.Exit\n";
//        int ch; cin >> ch;
//        if (ch == 1)
//        {
//            cout << "Enter vertex name: ";
//            cin >> verrr;
//            graph.add_vertex(verrr);
//        }
//        else if (ch == 2)
//        {
//            cout << "Enter FROM vertex name: ";
//            string from; cin >> from;
//            cout << "Enter TO vertex name: ";
//            string to; cin >> to;
//            cout << "Enter weight: ";
//            int weight; cin >> weight;
//            graph.add_edge(from, to, weight);
//
//        }
//        else if (ch == 3)
//        {
//            cout << "Enter FROM vertex name: ";
//            string from; cin >> from;
//            cout << "Enter TO vertex name: ";
//            string to; cin >> to;
//            cout << "Weight from " << from << " to " << to << " is:" << graph.weight_is(from, to) << "\n";
//        }
//        else if (ch == 4)
//        {
//            queue<string> adj_vertices;
//            cout << "Enter name of vertex to get adjacent vertices of: ";
//            cin >> verrr;
//            graph.get_to_vertices(verrr, adj_vertices);
//            cout << "Vertices adjacent to A: ";
//            while (!adj_vertices.empty())
//            {
//                cout << adj_vertices.front() << " ";
//                adj_vertices.pop();
//            }
//            cout << "\n";
//        }
//        else if (ch == 5)
//        {
//            graph.display();
//        }
//        else if (ch == 6)
//        {
//            break;
//        }
//        else cout << "Enter valid choice\n";
//        cout << "\nPress any key to continue...";
//        _getch();
//
//        system("cls");
//    }  
//    return 0;
//}
