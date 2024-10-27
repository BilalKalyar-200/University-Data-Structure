//IT IS MORE PREFERABLE AND IDEAL TO CREATE AVL TREE USING LINKED LIST NOT ARRAY
//BUT THIS PROGRAM IS JUST TO DEMONSTRATE THAT IT CAN BE DONE

//#include <iostream>
//using namespace std;
//
//const int CAP = 100;
//
//class node {
//public:
//    int id; 
//
//    node() {
//        id = 0;
//    }
//};
//
//class AVL_array {
//private:
//    int tree[CAP];
//    node node_data[CAP];
//    int size;
//
//public:
//    AVL_array() : size(0) {
//        for (int i = 0; i < CAP; ++i) 
//        {
//            tree[i] = 0;
//        }
//    }
//
//    bool is_empty()
//    {
//        return size == 0;
//    }
//
//    int left_child(int idx)
//    {
//        return 2 * idx;
//    }
//
//    int right_child(int idx) 
//    {
//        return 2 * idx + 1;
//    }
//
//    int height(int idx)
//    {
//        if (idx >= CAP || tree[idx] == 0) 
//        {
//            return -1; 
//        }
//        int left_height = height(left_child(idx));
//
//        int right_height = height(right_child(idx));
//
//        return max(left_height, right_height) + 1;
//    }
//
//    int balance_factor(int idx) 
//    {
//        if (idx >= CAP || tree[idx] == 0) {
//            return 0;
//        }
//
//        return height(left_child(idx)) - height(right_child(idx));
//    }
//
//    void right_rotate(int& idx)
//        {
//        int l = left_child(idx);
//        tree[idx] = tree[l];
//        tree[l] = 0;
//    }
//
//    void left_rotate(int& idx)
//    {
//        int r = right_child(idx);
//        tree[idx] = tree[r];
//        tree[r] = 0;
//    }
//
//    void insert(int id) 
//    {
//        node new_node;
//        new_node.id = id;
//        insert_rec(1, new_node);
//        cout << "ID: " << id << endl;
//        disp_in_order(1);  //display after each insertion
//        cout << endl;
//    }
//
//    void insert_rec(int idx, node new_node) 
//    {
//        if (idx >= CAP) 
//        {
//            cout << "tree is full" << endl;
//            return;
//        }
//
//        if (tree[idx] == 0) 
//        {
//            tree[idx] = new_node.id;
//            node_data[idx] = new_node;
//            size++;
//            return;
//        }
//
//        if (new_node.id < tree[idx]) 
//        {
//            insert_rec(left_child(idx), new_node);
//        }
//        else if (new_node.id > tree[idx])
//        {
//            insert_rec(right_child(idx), new_node);
//        }
//        else {
//            cout << "Duplicate not allowed" << endl;
//            return;
//        }
//
//        balance_tree(idx);
//    }
//
//    void balance_tree(int idx) 
//    {
//        int bf = balance_factor(idx);
//
//        if (bf > 1) {
//            if (balance_factor(left_child(idx)) >= 0) 
//            {
//                right_rotate(idx);  //LL rotation
//            }
//            else {
//                int index = left_child(idx);
//                left_rotate(index);
//                right_rotate(idx);  //LR rotation
//            }
//        }
//        else if (bf < -1) 
//        {
//            if (balance_factor(right_child(idx)) <= 0)
//            {
//                left_rotate(idx);  //RR rotation
//            }
//            else {
//                int index = right_child(idx);
//                right_rotate(index);
//                left_rotate(idx);  //RL rotation
//            }
//        }
//    }
//
//    bool search_rec(int idx, int id) {
//
//        if (idx >= CAP || tree[idx] == 0) {
//            return false;
//        }
//
//        if (tree[idx] == id) {
//            return true;
//        }
//        if (id < tree[idx]) return search_rec(left_child(idx), id);
//        return search_rec(right_child(idx), id);
//    }
//
//    void delete_node(int id) 
//    {
//        delete_rec(1, id);
//        cout << "After deletion\n";
//        disp_in_order(1);
//        cout << endl;
//    }
//
//    void delete_rec(int idx, int id) 
//    {
//        if (idx >= CAP || tree[idx] == 0) return;
//
//        if (id < tree[idx]) 
//        {
//            delete_rec(left_child(idx), id);
//        }
//        else if (id > tree[idx])
//        {
//            delete_rec(right_child(idx), id);
//        }
//        else {
//            if (tree[left_child(idx)] == 0 && tree[right_child(idx)] == 0) 
//            {
//                tree[idx] = 0;
//                size--;
//            }
//            else if (tree[left_child(idx)] == 0) 
//            {
//                tree[idx] = tree[right_child(idx)];
//
//                delete_rec(right_child(idx), tree[idx]);
//            }
//            else if (tree[right_child(idx)] == 0)
//            {
//                tree[idx] = tree[left_child(idx)];
//
//                delete_rec(left_child(idx), tree[idx]);
//            }
//            else {
//                int min_right = find_min(right_child(idx));
//                tree[idx] = min_right;
//                delete_rec(right_child(idx), min_right);
//            }
//        }
//
//        balance_tree(idx);
//    }
//
//    int find_min(int idx) 
//    {
//        while (tree[left_child(idx)] != 0)
//        {
//            idx = left_child(idx);
//        }
//        return tree[idx];
//    }
//
//    bool is_balanced() 
//    {
//        return check_balance(1);
//    }
//
//    bool check_balance(int idx)
//    {
//        if (idx >= CAP || tree[idx] == 0) {
//            return true;
//        }
//        int bf = balance_factor(idx);
//        return abs(bf) <= 1 && check_balance(left_child(idx)) && check_balance(right_child(idx));
//    }
//
//    void disp_in_order(int idx) {
//        if (idx >= CAP || tree[idx] == 0) 
//        
//        {
//            return;
//        }
//        disp_in_order(left_child(idx));
//        cout << tree[idx] << " ";
//        disp_in_order(right_child(idx));
//    }
//
//    void disp_pre_order(int idx) {
//        if (idx >= CAP || tree[idx] == 0) 
//        {
//            return;
//        }
//        cout << tree[idx] << " ";
//        disp_pre_order(left_child(idx));
//        disp_pre_order(right_child(idx));
//    }
//
//    void disp_post_order(int idx) 
//    {
//        if (idx >= CAP || tree[idx] == 0) return;
//        disp_post_order(left_child(idx));
//        disp_post_order(right_child(idx));
//        cout << tree[idx] << " ";
//    }
//};
//
//int main() {
//    AVL_array avl;
//
//    avl.insert(30);
//    avl.insert(20);
//    avl.insert(40);
//    avl.insert(10);
//
//    cout << "Inorder traverse\n";
//    avl.disp_in_order(1);
//    cout << endl;
//
//    int search_id = 20;
//    if (avl.search_rec(1, search_id)) 
//    {
//        cout << "Found\n";
//    }
//    else {
//        cout << "Not found\n";
//    }
//
//    if (avl.is_balanced()) 
//    {
//        cout << "tree is balanced" << endl;
//    }
//    else {
//        cout << "Tree is not balanced" << endl;
//    }
//
//    avl.delete_node(20);
//
//    cout << "Inorder after deletion: ";
//    avl.disp_in_order(1);
//    cout << endl;
//
//    return 0;
//}
