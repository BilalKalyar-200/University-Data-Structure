////Implement a directed graph.Use dynamic memory allocation for vertex and edges.Implement
////Queue to store edges in displaying graph.Do the following tasks :
////1. addEdge
////2. addVertex
////3. DisplayGraph()
// 
//#include<iostream>
//#include<queue>
//#include<string>
//using namespace std;
//#define NULL_EDGE 0
//class graph {
//	string* vertex;
//	int** edge;
//	int max;
//	int count;
//public:
//	graph(int max)
//	{
//		count = 0;
//		this->max = max;
//		vertex = new string[max];
//		edge = new int* [max];
//		for (int i = 0; i < max; i++)
//		{
//			edge[i] = new int[max];
//			for (int j = 0; j < max; j++)
//			{
//				edge[i][j] = NULL_EDGE;
//			}
//		}
//	}
//
//	int isindex(string str)
//	{
//		for (int i = 0; i < count; i++)
//		{
//			if (vertex[i] == str)
//			{
//				return i;
//			}
//		}
//		return -1;	//not foound 
//	}
//	void add_vertex(string str)
//	{
//		if (count >= max)
//		{
//			cout << "graph is filled\n";
//			return;
//		}
//		vertex[count] = str;
//		for (int i = 0; i < count; i++)
//		{
//			edge[count][i] = NULL_EDGE;
//			edge[i][count] = NULL_EDGE;
//		}
//		count++;
//	}
//	void add_edge(string from, string to, int weight,queue<string>& qq)
//	{
//		int row = isindex(from);
//		int col = isindex(to);
//		if (row == -1 || col == -1)
//		{
//			cout << "There was error finding vertices\n";
//			return;
//		}
//		edge[row][col] = weight;
//		string weig = to_string(weight);
//		qq.push(from + " ---<" + weig + " >---" + to);
//	}
//	void disp(queue<string> edge_queue)
//	{
//		if (count == 0)
//		{
//			cout << "Nothing to display\n";
//			return;
//		}
//		//display using queue
//		cout << "\nEdges with Weights:\n";
//		while (!edge_queue.empty())
//		{
//			cout << edge_queue.front() << "\n";
//			edge_queue.pop();
//		}
//	}
//};
//int main()
//{
//	int max_vertices;
//	cout << "Enter the maximum number of vertices: ";
//	cin >> max_vertices;
//
//	graph g(max_vertices);
//
//	queue<string> edge_queue; //queue to store edges
//
//	while (true)
//	{
//		cout << "\n1.Add Vertex\n"
//			<< "2.Add Edge\n"
//			<< "3.Display Graph\n"
//			<< "4.Exit\n";
//		int choice;
//		cin >> choice;
//
//		if (choice == 1)
//		{
//			string vertex_name;
//			cout << "Enter vertex name: ";
//			cin >> vertex_name;
//			g.add_vertex(vertex_name);
//		}
//		else if (choice == 2)
//		{
//			string from, to;
//			int weight;
//			cout << "Enter FROM vertex name: ";
//			cin >> from;
//			cout << "Enter TO vertex name: ";
//			cin >> to;
//			cout << "Enter edge weight: ";
//			cin >> weight;
//			g.add_edge(from, to, weight, edge_queue);
//		}
//		else if (choice == 3)
//		{
//			g.disp(edge_queue);
//		}
//		else if (choice == 4)
//		{
//			break;
//		}
//		else
//		{
//			cout << "Invalid choice, please try again\n";
//		}
//	}
//
//	return 0;
//}