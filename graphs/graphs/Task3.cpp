//Implement an undirected graph using templates.Use dynamic memory allocation for vertex and
//edges.Implement Queue to store edges in displaying graph.Do the following tasks :
//1. addEdge
//2. addVertex
//3. DisplayGraph()
#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define NULL_EDGE 0
template<class T>
class graph {
	T* vertex;
	int max;
	int count;
	int** edge;
public:
	graph(int max)
	{
		this->max = max;
		count = 0;
		vertex = new T[max];
		edge = new int* [max];
		for (int i = 0; i < max; i++)
		{
			edge[i] = new int[max];
			for (int j = 0; j < max; j++)
			{
				edge[i][j] = NULL_EDGE;
			}
		}
	}
	int indexis(T);
	void add_vertex(T);
	void add_edge(T, T, int,queue<T>&);
	void display(queue<T>);
};
template<class T>
int graph<T>::indexis(T data)
{
	for (int i = 0; i < count; i++)
	{
		if (vertex[i] == data)
		{
			return i;
		}
	}
	return -1;//not found
}
template<class T>
void graph<T>::add_vertex(T data)
{
	if (count >= max)
	{
		cout << "Graph is full\n";
		return;
	}
	vertex[count] = data;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			edge[count][i] = NULL_EDGE;
			edge[i][count] = NULL_EDGE;
		}
	}
	count++;
}

template<class T>
void graph<T>::add_edge(T from, T to, int weight, queue<T>& q)
{
	int FROM = indexis(from);
	int TO = indexis(to);
	if (FROM == -1 || TO == -1)
	{
		cout << "error finding vertices\n";
		return;
	}
	q.push(from + "(---" + to_string(weight) + "---)" + to);
	edge[FROM][TO] = weight;
	edge[TO][FROM] = weight;
}

template<class T>
void graph<T>::display(queue<T> edge_queue)
{
	if (count == 0)
	{
		cout << "Nothing to display\n";
		return;
	}
	//display using queue
	cout << "\nEdges with Weights:\n";
	while (!edge_queue.empty())
	{
		cout << edge_queue.front() << "\n";
		edge_queue.pop();
	}
}
int main()
{
	int max_vertices;
	cout << "Enter the maximum number of vertices: ";
	cin >> max_vertices;

	graph<string> g(max_vertices);

	queue<string> edge_queue; //queue to store edges

	while (true)
	{
		cout << "\n1.Add Vertex\n"
			<< "2.Add Edge\n"
			<< "3.Display Graph\n"
			<< "4.Exit\n";
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			string vertex_name;
			cout << "Enter vertex name: ";
			cin >> vertex_name;
			g.add_vertex(vertex_name);
		}
		else if (choice == 2)
		{
			string from, to;
			int weight;
			cout << "Enter FROM vertex name: ";
			cin >> from;
			cout << "Enter TO vertex name: ";
			cin >> to;
			cout << "Enter edge weight: ";
			cin >> weight;
			g.add_edge(from, to, weight, edge_queue);
		}
		else if (choice == 3)
		{
			g.display(edge_queue);
		}
		else if (choice == 4)
		{
			break;
		}
		else
		{
			cout << "Choose valid option\n";
		}
	}

	return 0;
}