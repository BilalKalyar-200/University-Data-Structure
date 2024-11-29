#include <iostream>
#include <queue>
#include <stack>
#include<conio.h>
using namespace std;

class Node {
public:
    int data;   // Index of the vertex in the adjacency list
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Graph {
public:
    string* vertices;   
    Node** adjList;     
    string* color;      
    int count;          //current number of vertices
    int maxVertices;

    Graph(int size)
    {
        maxVertices = size;
        count = 0;
        vertices = new string[maxVertices];
        adjList = new Node * [maxVertices];
        color = new string[maxVertices];

        for (int i = 0; i < maxVertices; i++) {
            adjList[i] = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i < maxVertices; i++) {
            Node* current = adjList[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] vertices;
        delete[] adjList;
        delete[] color;
    }

    void addVertex(string s)
    {
        if (count < maxVertices)
        {
            vertices[count] = s;
            adjList[count] = NULL;
            count++;
        }
        else {
            cout << "can't add limmit reached\n";
        }
    }

    void addEdge(string from, string to)
    {
        int from_ind = vertex_ind(from);
        int to_ind = vertex_ind(to);

        if (from_ind == -1 || to_ind == -1) 
        {
            cout << "index not found\n";
            return;
        }

        Node* newNode = new Node(to_ind);       //directed
        newNode->next = adjList[from_ind];
        adjList[from_ind] = newNode;
    }

    int vertex_ind(string s) 
    {
        for (int i = 0; i < count; i++)
        {
            if (vertices[i] == s)
                return i;
        }
        return -1;
    }

    void display() 
    {
        cout << "Adjacency List:\n";
        for (int i = 0; i < count; i++)
        {
            cout << vertices[i] << " -> ";
            Node* temp = adjList[i];
            while (temp != NULL)
            {
                cout << vertices[temp->data] << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void BFS(string start)
    {
        int start_ind = vertex_ind(start);
        if (start_ind == -1)
        {
            cout << "nothing in graph\n";
            return;
        }

        queue<int> q;
        for (int i = 0; i < count; i++) 
        {
            color[i] = "white";     //un visited
        }

        q.push(start_ind);
        color[start_ind] = "gray";

        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int u = q.front();      //u is current index
            q.pop();
            cout << vertices[u] << " ";

            Node* temp = adjList[u];
            while (temp != NULL)
            {
                int v = temp->data;         //neighbours of u
                if (color[v] == "white") 
                {
                    q.push(v);
                    color[v] = "gray";
                }
                temp = temp->next;
            }
            color[u] = "black";
        }
        cout << endl;
    }

    void DFS(string start) 
    {
        int start_ind = vertex_ind(start);
        if (start_ind == -1) {
            cout << "nothing in graph\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            color[i] = "white";
        }

        cout << "DFS Traversal: ";
        DFSRecursive(start_ind);
        cout << endl;
    }

    void DFSRecursive(int index) 
    {
        color[index] = "gray";
        cout << vertices[index] << " ";

        Node* temp = adjList[index];
        while (temp != NULL)
        {
            int v = temp->data;
            if (color[v] == "white") 
            {
                DFSRecursive(v);
            }
            temp = temp->next;
        }
        color[index] = "black";
    }
    string get_vertex(int index)
    {
        if (index >= 0 && index < count)
        {
            return vertices[index];
        }
        return "";
    }
};

int main()
{
    int num;
    cout << "Enter maximum size of graph: ";
    cin >> num;

    Graph g(num);

    int ch;
    while (true) 
    {
        cout << "1.Add Vertex\n";
        cout << "2.Add Edge\n";
        cout << "3.Display Graph\n";
        cout << "4.Perform BFS\n";
        cout << "5.Perform DFS\n";
        cout << "0.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1)
        {
            string vertex;
            cout << "Enter vertex name: ";
            cin >> vertex;
            g.addVertex(vertex);
        }
        else if (ch == 2) 
        {
            string from, to;
            cout << "Add edge..... ";
            cout << "Enter from vertex: ";
            cin >> from;
            cout << "Enter TO vertex: ";
            cin >> to;
            g.addEdge(from, to);
        }
        else if (ch == 3) 
        {
            g.display();
        }
        else if (ch == 4) 
        {
            string start = g.get_vertex(0);
            g.BFS(start);
        }
        else if (ch == 5)
        {
            string start = g.get_vertex(0);
            g.DFS(start);
        }
        else if (ch == 0) {
            break;
        }
        else {
            cout << "enter valid choice\n";
        }
        cout << "press any key to clear screen and continue....\n";
        _getch();
        system("cls");
    }

    return 0;
}
