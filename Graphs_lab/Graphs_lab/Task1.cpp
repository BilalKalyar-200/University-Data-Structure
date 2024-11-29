////Implement an directed graph.Use dynamic memory allocation for vertex and edges.Use Queue
////built - in library in Breadth First Traversal.Your task is to find the shortest path from source to each
////vertex.Use integer data in graph nodes.Do the following tasks :
////1. addEdge()
////2. add vertex()
////3. BFS()
////4. findLength()
////Note : You can also implement other necessary functions of class “Graph”.
//
//#include <iostream>
//#include <string>
//#include<conio.h>
//#include <queue>
//using namespace std;
//
//class Graph 
//{
//    string* vertices;      //vertex names
//    int** adj_mat;       //edges
//    string* color;         //color bcz of BFS
//    int* distance;         //distance of each node from top
//    int max_vertices;
//    int count;       //current number of nodes in graph
//
//public:
//    Graph(int max_vertices)
//    {
//        this->max_vertices = max_vertices;
//        count = 0;
//
//        vertices = new string[max_vertices];        //allocating memory to our dynamic arrays
//        adj_mat = new int* [max_vertices];
//        for (int i = 0; i < max_vertices; i++) 
//        {
//            adj_mat[i] = new int[max_vertices]();
//        }
//        color = new string[max_vertices];
//        distance = new int[max_vertices];
//    }
//
//    ~Graph()
//    {
//        delete[] vertices;          ///deallocating memory taken by our dynamic arrays
//        for (int i = 0; i < max_vertices; i++) 
//        {
//            delete[] adj_mat[i];
//        }
//        delete[] adj_mat;
//        delete[] color;
//        delete[] distance;
//    }
//
//    void add_vertex(string vertex)
//    {
//        if (count >= max_vertices) 
//        {
//            cout << "can't add capacity reached\n";
//            return;
//        }
//        vertices[count] = vertex;
//
//        for (int i = 0; i <= count; i++)
//        {
//            adj_mat[count][i] = 0;
//            adj_mat[i][count] = 0;
//        }
//        count++;
//    }
//
//    void add_edge(string from,string to)
//    {
//        int from_ind = vertex_ind(from);
//        int to_ind = vertex_ind(to);
//
//        if (from_ind == -1 || to_ind == -1)
//        {
//            cout << "there was error finding vertices\n";
//            return;
//        }
//        adj_mat[from_ind][to_ind] = 1; //directed graph
//    }
//
//    void BFS(string startVertex)
//    {
//        int start_ind = vertex_ind(startVertex);
//        if (start_ind == -1) 
//        {
//            cout << "error find vertex\n";
//            return;
//        }
//
//        //initilalizing with defaults for BFS traversal
//        for (int i = 0; i < count; i++)
//        {
//            color[i] = "white"; //white for not visited
//            distance[i] = -1; //-1 for no link
//        }
//        queue<int> q;
//        color[start_ind] = "gray";
//        distance[start_ind] = 0;
//        q.push(start_ind);
//
//        while (!q.empty())
//        {
//            int u = q.front();
//            q.pop();
//
//            //visiting neigbours of u
//            for (int v = 0; v < count; v++) 
//            {
//                if (adj_mat[u][v] == 1 && color[v] == "white")
//                {
//                    color[v] = "gray";          //means visited
//                    distance[v] = distance[u] + 1;  //if distance = 0 mean top node
//                                                    //if distance= 1 mean it has 1 distance from top
//                                                    //if distance= 2 mean it has 2 distance from top and so on......
//                    q.push(v);
//                }
//            }
//            color[u] = "black"; //completely visited
//            cout << vertices[u] << " ";
//        }
//        cout << endl;
//
//        cout << "Shortest distances from " << startVertex << ":\n"; //printing shortest distance
//        for (int i = 0; i < count; i++) 
//        {
//            cout << vertices[i] << ": ";
//            if (distance[i] == -1)
//                cout << "not reachable";
//            else
//                cout << distance[i];
//            cout << endl;
//        }
//    }
//    int vertex_ind(string vertex)
//    {
//        for (int i = 0; i < count; i++) 
//        {
//            if (vertices[i] == vertex) {
//                return i;
//            }
//        }
//        return -1;
//    }
//    string get_vertex(int index) 
//    {
//        if (index >= 0 && index < count)
//        {
//            return vertices[index];
//        }
//        return "";
//    }
//
//};
//int main() 
//{
//    int n;
//    string vertex;
//
//    cout << "Enter the number of vertices: ";
//    cin >> n;
//
//    Graph g(n);
//
//    for (int i = 0; i < n; i++)
//    {
//        cout << "Enter vertex " << i + 1 << ": ";
//        cin >> vertex;
//        g.add_vertex(vertex);
//    }
//
//    while (true)
//    {
//        cout << "1.Add edge\n";
//        cout << "2.BFS traversal of graph\n";
//        cout << "3.Exit\n";
//        int ch;  cin >> ch;
//        if (ch == 1) 
//        {
//            string from, to;
//            cout << "Enter edge....\n";
//            cout << "Enter 'FROM' vertex name: ";
//            cin >> from;
//            cout << "Enter 'TO' vertex name: ";
//            cin >> to;
//            g.add_edge(from, to);
//        }
//        else if (ch == 2) 
//        {
//            if (n > 0)
//            {
//                vertex = g.get_vertex(0); //first node (starting from top)
//                g.BFS(vertex);
//            }
//            else {
//                cout << "graph is empty...\n";
//            }
//        }
//        else if (ch == 3)
//        {
//            break;
//        }
//        else {
//            cout << "Enter valid choice\n";
//        }
//        cout << "Press any key to clear screen\n";
//        _getch();
//        system("cls");
//    }
//
//    return 0;
//}