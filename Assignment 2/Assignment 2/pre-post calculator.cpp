#include<iostream>
#include<string>
using namespace std;
class node {
public:
	node* next;
	string data;
	node()
	{
		next = NULL;
		data = "";
	}
};
bool check_alphanum(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
	{
		return true;
	}
	else return false;
}
bool isoper(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ' ^ ')
	{
		return true;
	}
	else return false;
}
int checkprec(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}
	else if (ch == '^') return 3;
	else return 0;
}
class Stack {
	node* top;
public:
	Stack()
	{
		top = NULL;
	}
	char see_top()
	{
		return top->data[0];
	}
	void push(string d)
	{
		node* ptr = new node;
		ptr->data = d;
		ptr->next = top;
		top = ptr;
	}
	string pop()
	{
		if (!isempty())
		{
			string str = top->data;
			node* temp = top;
			top = top->next;
			delete temp;
			return str;
		}
		cout << "Nothing to pop\n";
		return "";
	}
	void reversestr(string& str)
	{
		int len = str.length();
		for (int i = 0; i < len / 2; i++)
		{
			char temp = str[i];
			str[i] = str[len - i - 1];
			str[len - 1 - i] = temp;
		}
	}
	bool isempty()
	{
		if (top == NULL)
			return true;
		else return false;
	}

};
string inf_to_post(string str)
{
	Stack st;
	string postfix = "";
	for (int i = 0; i < str.length(); i++)
	{
		char curr = str[i];
		if (check_alphanum(curr))
		{
			string num = ""; //to handile two or more digit number
			while (i < str.length() && check_alphanum(str[i]))
			{
				num += str[i];
				i++;
			}
			i--;
			postfix += num + " ";
			cout << "->" << postfix << endl;
		}
		else if (curr == '(')
		{
			st.push(string(1, curr));
			cout << "->" << st.see_top() << endl;
		}
		else if (curr == ')')
		{
			while (!st.isempty() && st.see_top() != '(')
			{
				postfix += st.pop() + " ";
			}
			st.pop(); // Removing "("
			cout << "->" << postfix << endl;
		}
		else if (isoper(curr))
		{
			while (!st.isempty() && checkprec(st.see_top()) >= checkprec(curr))
			{
				postfix += st.pop() + " ";
			}
			st.push(string(1, curr));
			cout << "->" << st.see_top() << endl;
		}
		else if (curr == ' ')
		{
			continue;
		}
	}
	while (!st.isempty())
	{
		postfix += st.pop() + " ";
	}
	return postfix;
}

string inf_to_pre(string infix)
{
	Stack st;
	string prefix = "";
	int length = infix.length();
	st.reversestr(infix);

	for (int i = 0; i < length; i++)
	{
		if (infix[i] == ')')
		{
			infix[i] = '(';
		}
		else if (infix[i] == '(')
		{
			infix[i] = ')';
		}
	}

	for (int i = 0; i < length; i++)
	{
		char curr = infix[i];
		if (check_alphanum(curr))
		{
			string num = "";
			while (i < length && check_alphanum(infix[i])) //if the number is more than one digit number
			{
				num += infix[i];
				i++;
			}
			i--;
			prefix += num + " ";
			cout << "->" << prefix << endl;
		}
		else if (curr == '(')
		{
			st.push(string(1, curr));
			cout << "->" << st.see_top() << endl;
		}
		else if (curr == ')')
		{
			while (!st.isempty() && st.see_top() != ')')
			{
				prefix += st.pop() + " ";
			}
			st.pop();
			cout << "->" << prefix << endl;
		}
		else if (isoper(curr))
		{
			while (!st.isempty() && checkprec(st.see_top()) >= checkprec(curr))
			{
				prefix += st.pop() + " ";
			}
			st.push(string(1, curr));
			cout << "->" << st.see_top() << endl;
		}
		else if (curr == ' ')
		{
			continue;
		}
	}
	while (!st.isempty())
	{
		prefix += st.pop() + " ";
	}
	st.reversestr(prefix);
	return prefix;
}

int applyoperator(int op1, int op2, char curr)
{
	if (curr == '+')
	{
		return op1 + op2;
	}
	else if (curr == '-')
	{
		return op1 - op2;
	}
	else if (curr == '*')
	{
		return op1 * op2;
	}
	else if (curr == '/' && op2 != 0)
	{
		return op1 / op2;
	}
	else if (curr == '^')
	{
		return op1 ^ op2;
	}
	else cout << "There is something wrong\n";
	return 0;
}
int evaluate_post(string str)
{
	Stack st;

	for (int i = 0; i < str.length(); i++)
	{
		char curr = str[i];

		if (curr == ' ')
		{
			continue;
		}

		if (check_alphanum(curr))
		{
			string num = "";
			while (i < str.length() && check_alphanum(str[i])) //if the number is more than one digit number
			{
				num += str[i];
				i++;
			}
			i--;
			st.push(num);	//pushing that number onto stack
			cout << "->" << st.see_top() << endl;
		}
		else if (isoper(curr))
		{
			cout << "->" << curr << endl;
			if (st.isempty())
			{
				cout << "need two operands\n";
				return -1;
			}
			int op1 = stoi(st.pop());
			if (st.isempty())
			{
				cout << "need two operands\n";
				return -1;
			}
			int op2 = stoi(st.pop());
			int exp = applyoperator(op2, op1, curr);
			st.push(to_string(exp));
			cout << "->" << st.see_top() << endl;
		}
	}

	if (!st.isempty())
	{
		return stoi(st.pop());
	}
	return -1;
}

int evaluate_prefix(string pref) {
	Stack st;
	for (int i = pref.length() - 1; i >= 0; i--) 
	{
		char curr = pref[i];
		if (curr == ' ')
			continue;

		if (check_alphanum(curr)) 
		{
			string num = "";
			while (i >= 0 && check_alphanum(pref[i])) 
			{
				num = pref[i] + num;
				i--;
			}
			i++;
			st.push(num);
			cout << "->" << st.see_top() << endl;
		}
		else if (isoper(curr)) 
		{
			int op1 = stoi(st.pop());
			int op2 = stoi(st.pop());
			int result = applyoperator(op1, op2, curr);
			st.push(to_string(result));
			cout << "->" << st.see_top() << endl;
		}
	}
	return stoi(st.pop());
}


int main()
{
	Stack obj;
	string infix, postfix, prefix;
	while (true)
	{
		cout << "Welcome\n1.Enter infix\n2.To postfix\n3.To prefix\n4.Evaluate postfix\n5.Evalute prefix\n\n6.Exit\n";
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			cin.ignore();
			getline(cin, infix);
		}
		else if (ch == 2)
		{
			postfix = inf_to_post(infix);
			cout << "FINAL:" << postfix << endl;
		}
		else if (ch == 3)
		{
			prefix = inf_to_pre(infix);
			cout << "FINAL:" << prefix << endl;
		}
		else if (ch == 4)
		{
			int evaltute = evaluate_post(postfix);
			cout << "FINAL:" << evaltute << endl;
		}
		else if (ch == 5)
		{
			int evaltute = evaluate_prefix(prefix);
			cout << "FINAL:" << evaltute << endl;
		}
		else if (ch == 6)
		{
			break;
		}
		else continue;
	}
}