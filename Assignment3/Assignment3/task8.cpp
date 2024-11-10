//#include "task8.h"
//
//node::node()
//{
//    left = right = linked_list = NULL;
//    name = "";
//    frequency = 0;
//}
//
//node::node(string n, int freq) {
//    left = right = linked_list = NULL;
//    name = n;
//    frequency = freq;
//}
//
//AVL_song::AVL_song() {
//    root = NULL;
//}
//
//int AVL_song::getheight(node* ptr) {
//    if (ptr == NULL) return -1;
//    int l_height = getheight(ptr->left);
//    int r_height = getheight(ptr->right);
//    return 1 + max(l_height, r_height);
//}
//
//int AVL_song::getbalance(node* ptr) {
//    if (ptr == NULL) return -1;
//    return getheight(ptr->left) - getheight(ptr->right);
//}
//
//node* AVL_song::right_rot(node* ptr) {
//    node* temp = ptr->left;
//    node* temp2 = temp->right;
//    temp->right = ptr;
//    ptr->left = temp2;
//    return temp;
//}
//
//node* AVL_song::left_rot(node* ptr)
//{
//    node* temp = ptr->right;
//    node* temp2 = temp->left;
//    ptr->right = temp2;
//    temp->left = ptr;
//    return temp;
//}
//
//void AVL_song::insert(string n, int freq)
//{
//    node* ptr = new node(n, freq);
//    root = insert(root, ptr);
//}
//
//node* AVL_song::insert(node* hello, node* ptr)
//{
//    if (hello == NULL)
//        return ptr;
//    if (ptr->frequency < hello->frequency)
//    {
//        hello->left = insert(hello->left, ptr);
//    }
//    else if (ptr->frequency > hello->frequency)
//    {
//        hello->right = insert(hello->right, ptr);
//    }
//    else {
//        node* temp = hello;
//        while (temp->linked_list != NULL)
//        {
//            temp = temp->linked_list;
//        }
//        temp->linked_list = new node(ptr->name, ptr->frequency);
//        cout << "Song with name: " << ptr->name << " was added to linked list due to same frequency\n";
//        return hello;
//    }
//
//    int balance = getbalance(hello);
//    if (balance > 1 && ptr->frequency < hello->frequency)
//    {
//        return right_rot(hello);
//    }
//    if (balance < -1 && ptr->frequency > hello->frequency)
//    {
//        return left_rot(hello);
//    }
//    if (balance > 1 && ptr->frequency > hello->frequency)
//    {
//        hello->left = left_rot(hello->left);
//        return right_rot(hello);
//    }
//    if (balance < -1 && ptr->frequency < hello->frequency) {
//        hello->right = right_rot(hello->right);
//        return left_rot(hello);
//    }
//    return hello;
//}
//
//void AVL_song::get_min_right(node*& ptr, int& freq, string& n)
//{
//    if (ptr->left == NULL)
//    {
//
//        freq = ptr->frequency;
//        n = ptr->name;
//        node* temp = ptr;
//        ptr = ptr->right;
//        delete temp;
//    }
//    else {
//        get_min_right(ptr->left, freq, n);
//    }
//}
//
//int AVL_song::find_frequency(node* ptr, string n)
//{
//    if (ptr == NULL)
//        return -1;
//    if (ptr->name == n)
//        return ptr->frequency;
//    int freq = find_frequency(ptr->left, n);
//
//    if (freq != -1)
//        return freq;
//    return find_frequency(ptr->right, n);
//}
//
//node* AVL_song::delete_node(node* ptr, int freq, string n)
//{
//    if (ptr == NULL)
//    {
//        cout << "Nothing to delete\n";
//        return NULL;
//    }
//    if (ptr->frequency > freq)
//    {
//        ptr->left = delete_node(ptr->left, freq, n);
//    }
//    else if (ptr->frequency < freq)
//    {
//        ptr->right = delete_node(ptr->right, freq, n);
//    }
//    else if (ptr->name == n) {
//        if (ptr->left == NULL && ptr->right == NULL)
//        {
//            delete ptr;
//            return NULL;
//        }
//        else if (ptr->left == NULL)
//        {
//            node* temp = ptr->right;
//            delete ptr;
//            return temp;
//        }
//        else if (ptr->right == NULL) {
//            node* temp = ptr->left;
//            delete ptr;
//            return temp;
//        }
//        else {
//            int minFreq;
//            string minName;
//            get_min_right(ptr->right, minFreq, minName);
//            ptr->frequency = minFreq;
//            ptr->name = minName;
//        }
//    }
//    else {
//        cout << "Song not found\n";
//        return ptr;
//    }
//
//    int balance = getbalance(ptr);
//    if (balance > 1 && getbalance(ptr->left) >= 0)
//        return right_rot(ptr);
//    if (balance > 1 && getbalance(ptr->left) < 0)
//    {
//        ptr->left = left_rot(ptr->left);
//        return right_rot(ptr);
//    }
//    if (balance < -1 && getbalance(ptr->right) <= 0) return left_rot(ptr);
//    if (balance < -1 && getbalance(ptr->right) > 0)
//    {
//        ptr->right = right_rot(ptr->right);
//        return left_rot(ptr);
//    }
//
//}
//void AVL_song::play(int freq, string n)
//{
//    node* temp = play(root, n);
//    if (temp == NULL) {
//        cout << "Song not found\n";
//        return;
//    }
//    cout << "Playing the song: " << temp->name << " with frequency: " << temp->frequency << endl;
//    int old_freq = temp->frequency;
//    temp->frequency++;
//    root = delete_node(root, old_freq, n);
//    insert(temp->name, temp->frequency);
//}
//
//node* AVL_song::play(node* ptr, string n) {
//    if (ptr == NULL) return NULL;
//    if (ptr->name == n) return ptr;
//
//    node* temp = play(ptr->left, n);	//first finding in left then right
//    if (temp != NULL)
//        return temp;
//    return play(ptr->right, n);
//}
//
//void AVL_song::inorder(node* ptr)
//{
//    if (ptr != NULL) {
//        inorder(ptr->left);
//        cout << ptr->frequency << "-" << ptr->name << endl;
//        inorder(ptr->right);
//    }
//}