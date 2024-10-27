//#include<iostream>
//using namespace std;
//class node {
//public:
//	char ch;
//	node* next, * pre;
//	node()
//	{
//		ch = '\0';
//		next = NULL;
//		pre = NULL;
//	}
//
//};
//bool is_vowel(char ch)
//{
//	switch (ch)//as asked treating y as vowel also
//	{
//	case 'a': case 'e': case 'i': case 'o': case 'u':
//	case 'A': case 'E': case 'I': case 'O': case 'U': case'y': case'Y':
//		return true;
//	default:
//		return false;
//	}
//}
//class linked {
//	node* head;
//
//public:
//	linked()
//	{
//		head = NULL;
//	}
//
//	void append(char ch)
//	{
//		node* ptr = new node;
//		ptr->ch = ch;
//		if (head == NULL)
//		{
//			head = ptr;
//			head->next = head;
//			head->pre = head;
//			return;
//		}
//		else {
//			node* temp = head;
//			while (temp->next != head)
//			{
//				temp = temp->next;
//			}
//			temp->next = ptr;
//			ptr->next = head;
//		}
//	}
//	void  reverse()
//	{
//		if (head == NULL)
//		{
//			cout << "Nothing to change\n";
//			return;
//		}
//		bool vowel3 = false;
//		node* temp2 = head;
//		while (temp2->next != head)
//		{
//			if (is_vowel(temp2->ch))		//checking if there is any vowel in string
//			{
//				vowel3 = true;
//				break;
//			}
//			temp2 = temp2->next;
//		}
//		bool isvowel = false, isvowel2 = false;
//		if (vowel3)
//		{
//			node* temp = head;
//			while (temp->next != head)
//			{
//				if ((is_vowel(head->ch)))		//if we found vowel at head
//				{
//					isvowel = true;
//					break;
//				}
//				else {
//					append('-');
//
//					head = head->next;
//					if ((is_vowel(head->ch)))	//checking if we finds vowel at head after moving
//					{
//						isvowel2 = true;
//
//						break;
//					}
//				}
//
//			}
//		}
//		if (!vowel3) {
//			append('-');
//			append('w');
//			append('a');
//			append('y');
//			return;
//		}
//		if (isvowel)
//		{
//			append('-');
//			append('w');
//			append('a');
//			append('y');
//			return;
//		}
//		if (isvowel2)
//		{
//			append('a');
//			append('y');
//			return;
//		}
//
//	}
//	void display()
//	{
//		node* temp = head;
//		do {
//			cout << temp->ch;
//			temp = temp->next;
//		} while (temp != head);
//		cout << endl;
//	}
//};
//int main()
//{
//	linked obj;
//	cout << "Enter string: ";
//	string str; cin >> str;
//
//	int s = str.length();
//	for (int i = 0; i < s; i++)
//	{
//		obj.append(str[i]);
//	}
//	obj.reverse();
//	obj.display();
//}