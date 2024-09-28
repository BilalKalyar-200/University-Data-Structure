//THIS TASK ALLOWS THE USER TO PLAY THE GAME SIMILAR TO TOWER OF HANOI
//IN THIS GAME YOU HAVE TO MOVE THE FIRST STACK TO THIRD IN SAME ORDER BY MAKING DIFFERENT MOVES
//YOU CANNOT PUT LARGER OVER SMALLER
//ONLY TOP CONTAINER(VALUE) CAN BE MOVED
#include<iostream>
using namespace std;
class node {
public:
	node* next;
	int data;
	node()
	{
		next = NULL;
		data = 0;
	}
};
class Stack
{
public:
	node* top;
	Stack()
	{
		top = NULL;
	}
	void push(int d)
	{
		node* ptr = new node;
		ptr->data = d;
		ptr->next = top;
		top = ptr;
	}
	int pop()
	{
		if (isempty())
		{
			cout << "Nothing to pop\n";
			return 0;
		}
		node* temp = top;
		int temp2 = top->data;
		top = top->next;
		delete temp;
		return temp2;
	}
	bool isempty()
	{
		if (top == NULL)
			return true;
		else return false;
	}
	int seetop()
	{
		return top->data;
	}
	void display()
	{
		if (top == NULL)
		{
			cout << "------";
			return;
		}
		node* temp = top;
		int arr[100];
		int index = 0;

		while (temp)
		{
			arr[index++] = temp->data;
			temp = temp->next;
		}

		for (int i = index - 1; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
	}


};
void showstack(Stack s1, Stack s2, Stack s3)
{
	cout << "Stack1: ";
	s1.display();
	cout << endl;
	cout << "Stack2: ";
	s2.display();
	cout << endl;
	cout << "Stack3: ";
	s3.display();
	cout << endl;
}
int main()
{
	Stack st;
	Stack st2, st3;
	int size = 4;	//number of containers
	int temp;
	Stack temp_st;
	for (int i = 0; i < size; i++)
	{
		st.push(4 - i);
		temp_st.push(4 - i);  //creating this to keep track of winning

	}

	int moves = 0;
	bool done = false;
	while (true)
	{
		showstack(st, st2, st3);
		node* temp1 = temp_st.top;
		node* temp2 = st3.top;
		int count = 0;
		while (temp2 && temp1)		//checking if the user was able to move in same order as original stack in 3rd stack
		{
			if (temp1->data == temp2->data)
			{
				count++;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (count == size)
		{
			done = true;
			break;
		}
		bool placed = false;
		cout << "Enter stack number to move from ----->1 or 2 or 3\n";
		int ch; cin >> ch;
		if (ch == 1)
		{
			temp = st.pop();
		}
		else if (ch == 2)
		{
			temp = st2.pop();
		}
		else if (ch == 3)
		{
			temp = st3.pop();
		}
		else {
			cout << "Enter valie choice\n";
			continue;
		}
		cout << "Enter stack number to place at----->1 or 2 or 3    (moves:" << moves << ")\n";
		int ch1; cin >> ch1;
		if (ch1 == 1)
		{
			if (st.isempty() || st.seetop() > temp)
			{
				st.push(temp);
				placed = true;
				moves++;
			}
			else
			{
				cout << "cannot put larger over smaller\n";
			}
		}
		else if (ch1 == 2)
		{
			if (st2.isempty() || st2.seetop() > temp)
			{
				st2.push(temp);
				placed = true;
				moves++;

			}
			else
			{
				cout << "cannot put larger over smaller\n";
			}
		}
		else if (ch1 == 3)
		{
			if (st3.isempty() || st3.seetop() > temp)
			{
				st3.push(temp);
				placed = true;
				moves++;
			}
			else {
				cout << "cannot put larger over smaller\n";
			}
		}
		else {
			cout << "Enter valie choice\n";
			continue;
		}
		if (!placed)	//if user tries to put larger over smaller then place back
		{
			if (ch == 1) {
				st.push(temp);
			}
			else if (ch == 2)
			{
				st2.push(temp);
			}
			else if (ch == 3)
			{
				st3.push(temp);
			}
		}
	}
	if (done)
	{
		cout << "Congargulation you won!!!!!!\n";
	}
	return 0;
}