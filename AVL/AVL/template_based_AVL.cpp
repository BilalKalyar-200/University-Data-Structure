//You should consider the data of published research papers in a journal.The data in a node include
//the title, authors name, publication date, publication id.The primary data to create BST in this case
//is the publication id(integer data).
//TEMPLATE BASED AVL IMPLEMENTATION
#include<iostream>
using namespace std;

template<class T>
class node {
public:
    node<T>* left, * right;
    T ID;

    node()
    {
        ID = 0;
        left = right = NULL;
    }

    node(T id) : ID(id)
    {
        left = right = NULL;
    }
};

template<class T>
class AVL {
public:
    node<T>* root;
    AVL() {
        root = NULL;
    }

    int height(node<T>* ptr)
    {
        if (ptr == NULL) {
            return -1;
        }
        else {
            int left_height = height(ptr->left);
            int right_height = height(ptr->right);
            if (left_height > right_height)
            {
                return 1 + left_height;
            }
            else return 1 + right_height;
        }
    }

    int get_balance(node<T>* ptr)
    {
            if (ptr == NULL) {
                return -1;
            }
            return height(ptr->left) - height(ptr->right);
    }

    node<T>* right_rot(node<T>* ptr)
    {
        node<T>* temp = ptr->left;
        node<T>* temp2 = temp->right;
        temp->right = ptr;
        ptr->left = temp2;
        return temp;
    }

    node<T>* left_rot(node<T>* ptr)
    {
        node<T>* temp = ptr->right;
        node<T>* temp2 = temp->left;
        ptr->right = temp2;
        temp->left = ptr;
        return temp;
    }

    bool isempty()
    {
        return root == NULL;
    }
    void get_min_right(node<T>*& ptr, T& d)
    {
        if (ptr->left == NULL)
        {
            d = ptr->ID;
            node<T>* temp = ptr;
            ptr = ptr->right;
            delete temp;
        }
        else {
            get_min_right(ptr->left, d);
        }
    }
    node<T>* delete_node(node<T>*& ptr, T d)		//d is that is to be deleted
    {
        if ((ptr==NULL))
        {
            cout << "Nothing to delete\n";
            return NULL;
        }
        if (ptr->ID > d) {
            ptr->left = delete_node(ptr->left, d);
        }
        else if (ptr->ID < d)
        {
            ptr->right = delete_node(ptr->right, d);
        }
        else {
            //means ptr->data==data
            //case1:
            if (ptr->left == NULL && ptr->right == NULL)
            {
                delete ptr;
                ptr = NULL;
                return root;    //sending something to check wheather we found the ID or not
            }
            //case2:
            if (ptr->left == NULL)
            {
                node<T>* temp = ptr->right;
                delete ptr;
                return temp;
            }
            if (ptr->right == NULL)
            {
                node<T>* temp = ptr->left;
                delete ptr;
                return temp;
            }
            //case3:
            get_min_right(ptr->right, d);
            ptr->ID = d;

            //now checking balance factore after deletion
            int balance = get_balance(ptr);
            if (balance == 2 && get_balance(ptr->left) >= 0)
            {
                return right_rot(ptr);
            }
            else if (balance == 2 && get_balance(ptr->left) == -1)
            {
                ptr->left = left_rot(ptr->left);
                return right_rot(ptr);
            }

            else if (balance == -2 && get_balance(ptr->right) <= 0)
            {
                return left_rot(ptr);
            }
            else if (balance == -2 && get_balance(ptr->right) == 1)
            {
                ptr->right = right_rot(ptr->right);
                return left_rot(ptr);
            }
        }
        return ptr;
    }

    node<T>* insert(node<T>* rr, node<T>* ptr)
    {
        if (rr == nullptr) {    
            return ptr;
        }
        if (ptr->ID < rr->ID)
        {
            rr->left = insert(rr->left, ptr);
        }
        else if (ptr->ID > rr->ID)
        {
            rr->right = insert(rr->right, ptr);
        }
        else {
            cout << "NO duplicates are allowed\n";
            return rr;
        }

        int balance = get_balance(rr);
        if (balance > 1 && ptr->ID < rr->left->ID) {
            return right_rot(rr);
        }
        if (balance < -1 && ptr->ID > rr->right->ID)
        {
            return left_rot(rr);
        }
        if (balance > 1 && ptr->ID > rr->left->ID) {
            rr->left = left_rot(rr->left);
            return right_rot(rr);
        }
        if (balance < -1 && ptr->ID < rr->right->ID) {
            rr->right = right_rot(rr->right);
            return left_rot(rr);
        }

        return rr;
    }

    node<T>* search(node<T>* ptr, T val)
    {
        if (ptr == NULL) {
            return NULL;
        }
        if (ptr->ID == val) {
            return ptr;
        }
        if (val < ptr->ID)
        {
            return search(ptr->left, val);
        }
        return search(ptr->right, val);
    }

    bool is_AVL(node<T>* ptr) {
        if (ptr == NULL) {
            return true;
        }
        int balance = get_balance(ptr);
        if (balance > 1 || balance < -1)
        {
            return false;
        }
        return is_AVL(ptr->left) && is_AVL(ptr->right);
    }

    void inorder(node<T>* ptr) {
        if (ptr != NULL) {
            inorder(ptr->left);
            cout << ptr->ID << endl; // Only displaying ID
            inorder(ptr->right);
        }
    }

    void preorder(node<T>* ptr) {
        if (ptr != NULL) {
            cout << ptr->ID << endl; // Only displaying ID
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(node<T>* ptr)
    {
        if (ptr != NULL) {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->ID << endl; // Only displaying ID
        }
    }
    //this function Join(T1, T2) returns an AVL tree containing the union of the elements
    //in T1 and T2
    AVL<T> combine(AVL<T>& T1, AVL<T>& T2)
    {
        AVL<T> result;
        //inserting all nodes in a new tree
        inorder_insert(result.root, T1.root);
        inorder_insert(result.root, T2.root);

        return result;
    }

    void inorder_insert(node<T>*& resultRoot, node<T>* ptr)
    {
        if (ptr != nullptr)
        {
            inorder_insert(resultRoot, ptr->left);
            resultRoot = insert(resultRoot, new node<T>(ptr->ID)); // Use new node with ID
            inorder_insert(resultRoot, ptr->right);
        }
    }
};

int main() {
    AVL<int> obj;
    while (true)
    {
        cout << "1.Insert\n2.Delete\n3.Search\n4.check AVL\n5.Isempty\n6.inorder\n7.Preorder\n8.Postorder\n9.Combine\n10.Exit\n";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int ID;
            cout << "Enter ID: ";
            cin >> ID;

            node<int>* ptr = new node<int>(ID); // Create new node with ID
            obj.root = obj.insert(obj.root, ptr);
            obj.inorder(obj.root); //it was asked to print after each insert
            cout << endl;
        }
        else if (ch == 2)
        {
            cout << "Enter value to delete: ";
            int val; cin >> val;
            node<int>* temp = obj.delete_node(obj.root, val);
            if (temp) {
                cout << "Node with " << val << " ID deleted\n";
            }
            else cout << "Node was not found\n";
        }
        else if (ch == 3)
        {
            cout << "Enter id to search: ";
            int id;
            cin >> id;
            node<int>* found = obj.search(obj.root, id);
            if (found)
            {
                cout << "Found: " << found->ID << endl; // Only displaying ID
            }
            else
            {
                cout << "not Found\n";
            }
        }
        else if (ch == 4)
        {
            if (obj.is_AVL(obj.root))
            {
                cout << "Tree is AVL\n";
            }
            else {
                cout << "not AVL\n";
            }
        }
        else if (ch == 5)
        {
            if (obj.isempty())
            {

                cout << "Tree is empty\n";
            }
            else {
                cout << "not empty\n";
            }
        }
        else if (ch == 6)
        {
            obj.inorder(obj.root);
            cout << endl;
        }
        else if (ch == 7) 
        {
            obj.preorder(obj.root);
            cout << endl;
        }
        else if (ch == 8)
        {
            obj.postorder(obj.root);
            cout << endl;
        }
        else if (ch == 9)
        {
            AVL<int> obj2;
            node<int>* ptr = new node<int>(209);
            obj2.root = obj2.insert(obj2.root, ptr);
            ptr = new node<int>(250);

            obj2.root = obj2.insert(obj2.root, ptr);
            ptr = new node<int>(300);
            obj2.root = obj2.insert(obj2.root, ptr);
            AVL<int> result = obj.combine(obj, obj2);
            result.inorder(result.root);
        }
        else if (ch == 10)
        {
            break;
        }
        else cout << "Enter valid choice\n";
    }
}
