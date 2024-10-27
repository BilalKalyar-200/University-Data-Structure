//#include <iostream>
//using namespace std;
//
//class node {
//    string color;
//    int key;
//    node* next;
//public:
//    string getcolor() {
//        return color;
//    }
//    node* getnext() {
//        return next;
//    }
//    void setcolor(string color) {
//        this->color = color;
//    }
//    void setnext(node* next) {
//        this->next = next;
//    }
//    void setkey(int k) {
//        key = k;
//    }
//    int getkey() {
//        return key;
//    }
//};
//
//class circular_list {
//    node* head;
//public:
//    node* gethead() {
//        return head;
//    }
//    circular_list() {
//        head = nullptr;
//    }
//    void append(string color, int key) {
//        node* ptr = new node;
//        ptr->setkey(key);
//        ptr->setcolor(color);
//
//        if (head == NULL) {
//            head = ptr;
//            head->setnext(head);
//        }
//        else {
//            node* temp = head;
//            while (temp->getnext() != head) {
//                temp = temp->getnext();
//            }
//            temp->setnext(ptr);
//            ptr->setnext(head);
//        }
//    }
//
//
//    void display(int n)
//    {
//        if (!head) return;
//        node* temp = head;
//        int count = 0;
//        do {
//            cout << " color: " << temp->getcolor() << endl;
//            temp = temp->getnext();
//            count++;
//            if (count % 3 == 0)
//            {
//
//                n--;
//            }
//        } while (n != 0);
//    }
//};
//
//int main() {
//    circular_list obj;
//    obj.append("red", 1);
//    obj.append("yellow", 2);
//    obj.append("green", 3);
//    cout << "How many times you want to circle through the list of colors: ";
//    int n; cin >> n;
//    obj.display(n);
//
//
//
//}
