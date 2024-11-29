#include<stack>
#include<iostream>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;
class User;
class bst_node {
public:
    string username; // Username stored in the BST
    User* user_ptr;  // Pointer to the corresponding User object
    bst_node* left;
    bst_node* right;

    bst_node(string username, User* user_ptr) : username(username), user_ptr(user_ptr), left(NULL), right(NULL) {}
};
class BST {
public:
    bst_node* root;

    BST() {
        root = NULL;
    }
    friend class User;      //bcz we will use functions of BST using user class object

    //inserting username and user pointer into the BST
    void insert(const string& username, User* user_ptr)
    {
        bst_node* new_node = new bst_node(username, user_ptr);
        if (root == NULL) //if first user
        {
            root = new_node;
            return;
        }

        bst_node* current = root;
        bst_node* parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (username < current->username)
            {
                current = current->left;
            }
            else if (username > current->username)
            {
                current = current->right;
            }
            else
            {
                delete new_node; //if already exist with same name
                return;
            }
        }
        //after the loop ends `parent` holds the last non-NULL node
        //now we have to decide perfect location for new user
        if (username < parent->username)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }

    // Search function to find a user by username in the BST
    User* search(const string& username)
    {
        bst_node* current = root;
        while (current != NULL)
        {
            if (current->username == username)
            {
                return current->user_ptr;
            }
            else if (username < current->username)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return NULL; //not found
    }

    void in_order_traversal(bst_node* node)
    {
        if (node == NULL)
        {
            return;
        }

        in_order_traversal(node->left);
        cout << node->username << endl;
        in_order_traversal(node->right);
    }

    
    ~BST()
    {
        delete_BST(root);
    }

    void delete_BST(bst_node* node)
    {
        if (node != NULL)
        {
            delete_BST(node->left);
            delete_BST(node->right);
            delete node;
        }
    }
};

class node {
public:
    string data;
    string dateTime;
    node* next;
};

//linked list based stack class for all functionality.
class Stack {
    friend class User;

    node* top;
public:
    Stack() : top(NULL) {}

    void push(string data) 
    {
        time_t t = time(0);             //current date & time.
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &t);
        string dateTime = buffer;


        node* newNode = new node();
        newNode->data = data;
        newNode->dateTime = dateTime;
        newNode->next = top;
        top = newNode;
    }

    bool pop(string& dateTime, string& data) 
    {
        if (isEmpty()) 
        {
            return false;
        }
        dateTime = top->dateTime;
        data = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void makeNull() 
    {
        while (!isEmpty()) 
        {
            string temp1, temp2;
            pop(temp1, temp2);
        }
    }

    ~Stack() {
        makeNull();
    }
};
class Message {
public:
    string content;
    string timestamp;

    Message(const string& content, const string& timestamp)
        : content(content), timestamp(timestamp) {}
};

class follower_edge {
public:
    User* follow_user;
    string relation_type;     //friend or sibling or else
    string status;            //active,blocked,pending
    follower_edge* next;
    stack<Message> messages;  // Stack to store messages for this follower

    follower_edge(User* follow_user, const string& relation_type, const string& status)
        : follow_user(follow_user), relation_type(relation_type), status(status), next(NULL) {}
};
class User {
    string name;
    string password;
    string city;
    Stack posts;
    string lastLogin;
    follower_edge* head_follow;     //head of the follower list
    follower_edge* head_following;     //head of the following list
    bool isLogin;
    string securityQuestion; 
    string securityAnswer;
    BST obj_BST;
public:
    User* next;
    friend class createUsers;   //in order to access private data members of User class.

    User(const string& name, const string& password, const string& city, const string& securityQuestion, const string& securityAnswer) : name(name), password(password), city(city),
        lastLogin(""), next(NULL), isLogin(false), securityQuestion(securityQuestion), securityAnswer(securityAnswer) {}


    void add_follwer(User* follow_user, const string& relation_type, const string& status)
    {
        //adding to follower list of current user
        if (find_edge(follow_user) == NULL)
        {
            follower_edge* new_edge = new follower_edge(follow_user, relation_type, status);
            new_edge->next = head_follow;
            head_follow = new_edge;
        }

        //adding to following list of follow user
        if (follow_user->find_edge(this) == NULL)
        {
            follower_edge* reverse_edge = new follower_edge(this, relation_type, status);
            reverse_edge->next = follow_user->head_following;
            follow_user->head_following = reverse_edge;
        }
    }

    void add_following(User* follow_user, const string& relation_type, const string& status)
    {
        //adding to following list of other user
        if (find_edge(follow_user) == NULL)
        {
            follower_edge* new_edge = new follower_edge(follow_user, relation_type, status);
            new_edge->next = head_following;
            head_following = new_edge;
        }

        //adding to follower list of current user
        if (follow_user->find_edge(this) == NULL)
        {
            follower_edge* reverse_edge = new follower_edge(this, relation_type, status);
            reverse_edge->next = follow_user->head_follow;
            follow_user->head_follow = reverse_edge;
        }
    }
    bool check_follower_status(User* a_user)
    {
        if (a_user == NULL)
        {
            cout << "User is null.\n";
            return false;
        }

        follower_edge* temp = head_follow; //checking linked list to find 'follower' user
        while (temp != NULL)
        {
            if (temp->follow_user == a_user)
            {
                if (temp->status == "active") //checking status if active then send massage
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            temp = temp->next; //moving to next follower
        }

        return false; //status not found
    }
    bool check_following_status(User* a_user)
    {
        if (a_user == NULL)
        {
            cout << "User is null.\n";
            return false;
        }

        follower_edge* temp = head_following; //checking linked list to find 'following' user
        while (temp != NULL)
        {
            if (temp->follow_user == a_user)
            {
                if (temp->status == "active") //checking status if active then send massage
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            temp = temp->next; //moving to next
        }

        return false; //status not found
    }
    void check_relation_search(const string& user_name)        //this function checks the relation of current user with searched one
    {

        User* user = obj_BST.search(user_name);

        if (user != NULL)
        {
            bool follower_check = check_follower_status(user);  //finding types of relation between the users
            bool following_check = check_following_status(user);
            if (follower_check && following_check)
            {
                cout << "Both of you are following each other\n";
            }
            else if (!follower_check && following_check)
            {
                cout << "You are following him but he is not following back\n";
            }
            else if (follower_check && !following_check)
            {
                cout << "He is following you but you are not\n";
            }
            else cout << "no relation with this user\n";
        }
        else
        {
            cout << "User not found!" << endl;
        }
    }
    //fucntion to show follower
    void show_followers()
    {
        if (head_follow == NULL)
        {
            cout << "You have no followers\n";
            return;
        }
        follower_edge* temp = head_follow;
        while (temp != NULL)
        {
            cout << "Follower: " << temp->follow_user->name
                << ", Type: " << temp->relation_type
                << ", Status: " << temp->status << endl;
            temp = temp->next;
        }
    }
    void view_following()
    {
        if (head_following == NULL)
        {
            cout << "You are not following anyone.\n";
            return;
        }

        cout << "Users you are following:\n";
        follower_edge* temp = head_following;
        while (temp != NULL)
        {
            cout << "Follower: " << temp->follow_user->name
                << ", Type: " << temp->relation_type
                << ", Status: " << temp->status << endl;
            temp = temp->next;
        }
    }

    void login() 
    {
        time_t t = time(0);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &t);
        string dateTime = buffer;


        isLogin = true;
    }

    void logout() {
        isLogin = false;
    }

    void post(const string& content) 
    {
        if (isLogin)
        {
            posts.push(content);
        }
    }

    void showPosts() 
    {
        if (isLogin)
        {
            string dateTime, content;
            node* temp = posts.top;
            while (temp != NULL)
            {
                cout << temp->dateTime << ": " << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    void showLastLogin()
    {
        if (isLogin)
        {
            cout << "Last Login: " << lastLogin << endl;
        }
    }

    void showUserInfo() 
    {
        if (isLogin)
        {
            cout << "Username: " << name << endl;
            cout << "City: " << city << endl;
            showLastLogin();
        }
    }
    follower_edge* find_edge(User* target_user)
    {
        follower_edge* temp = head_follow;
        while (temp != NULL)
        {
            if (temp->follow_user == target_user)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void send_msg(User* follower, const string& content, const string& timestamp)
    {
        Message new_message(content, timestamp); // Create a new message

        // Sender's message stack
        follower_edge* sender_edge = find_edge(follower);
        if (sender_edge != NULL)
        {
            sender_edge->messages.push(new_message);
        }

        // Receiver's message stack
        follower_edge* receiver_edge = follower->find_edge(this);
        if (receiver_edge != NULL)
        {
            receiver_edge->messages.push(new_message);
        }

        cout << "Message sent to " << follower->name << "!" << endl;
    }




    void view_latest_msg(User* follower)
    {
        follower_edge* edge = find_edge(follower);
        if (edge != NULL)
        {
            if (!edge->messages.empty())
            {
                Message last_msg = edge->messages.top();
                cout << "Latest message with " << follower->name << ":\n"
                    << "Message: " << last_msg.content << "\n"
                    << "Timestamp: " << last_msg.timestamp << endl;
            }
            else
            {
                cout << "No messages with " << follower->name << endl;
            }
        }
        else
        {
            cout << "No relationship found between you and " << follower->name << "!" << endl;
        }
    }


    void show_all_msg(User* follower)
    {
        follower_edge* temp = head_follow;
        while (temp != NULL)
        {
            if (temp->follow_user == follower)  //check if this the follower we are looking for
            {
                if (!temp->messages.empty())
                {
                    cout << "Messages with " << follower->name << ":\n";

                    //create a temporary stack to display messages without losing
                    stack<Message> temp_msg = temp->messages;

                    while (!temp_msg.empty())
                    {
                        Message message = temp_msg.top();
                        cout << "Message: " << message.content << "\n"
                            << "Timestamp: " << message.timestamp << endl;
                        temp_msg.pop();
                    }
                }
                else {
                    cout << "No messages with " << follower->name << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Follower not found!" << endl;
    }


    ~User()
    {   
        //delete all edges of followers
        while (head_follow != NULL)
        {
            follower_edge* temp = head_follow;
            head_follow = head_follow->next;
            delete temp;
        }
    }

};

class createUsers {
    User* head;
    BST obj_BST;
public:
    createUsers() : head(NULL) {}

    //void add_relationship(const string& user1_name, const string& user2_name, const string& relation_type, const string& status)
    //{
    //    User* user1 = obj_BST.search(user1_name);
    //    User* user2 = obj_BST.search(user2_name);

    //    if (user1 != NULL && user2 != NULL)
    //    {
    //        user1->add_follower(user2, relation_type, status);
    //        user2->add_follower(user1, relation_type, status); //mutual friendship
    //        cout << "relation between these two users has been added...." << endl;
    //    }
    //    else
    //    {
    //        cout << "One or both users not found...." << endl;
    //    }
    //}

    
    bool isempty() {
        return head == NULL;
    }
    bool isStrong(const string& password)
    {
        if (password.length() < 12)
        {
            cout << "Password length must be at least 12." << endl;
            return false;
        }
        bool hasUpper = false, hasDigit = false, hasSpecial = false;
        for (int i = 0; i < password.length(); i++) 
        {
            char ch = password[i];
            if (isupper(ch)) 
            {
                hasUpper = true;
            }
            else if (isdigit(ch))
            {
                hasDigit = true;
            }
            else if (ispunct(ch))
            {
                hasSpecial = true;
            }
        }

        if (!hasUpper) {
            cout << "Password must have an uppercase character." << endl;
            return false;
        }
        if (!hasDigit) {
            cout << "Password must have a number." << endl;
            return false;
        }
        if (!hasSpecial) {
            cout << "Password must have an special character." << endl;
            return false;
        }
        return true;
    }


    void registerUser()
    {
        string name, password, confirmPassword, city, question, answer;
        cout << "Enter Username: ";
        getline(cin, name);
        if (obj_BST.search(name) == NULL)       //means the name is unique
        {
            cout << "Enter Password: ";
            getline(cin, password);
            cout << "Confirm Password: ";
            getline(cin, confirmPassword);
            if (!isStrong(password)) {          //enforce strong password strength rules
                cout << "\nregister wasn't successfull try again...\n";
                return;
            }
            if (password == confirmPassword)
            {
                cout << "Enter City: ";
                getline(cin, city);
                cout << "Enter Security Question: "; 
                getline(cin, question); 
                cout << "Enter Security Answer: "; 
                getline(cin, answer);
                User* newUser = new User(name, password, city, question, answer);
                newUser->next = head; 
                head = newUser;

                obj_BST.insert(name, newUser); //inserting in BST

                cout << "User registered successfully!" << endl;
            }
            else {
                cout << "Passwords do not match!" << endl;
                return;
            }
        }
        else {
            cout << "ID already exists!" << endl;
        }
    }

    User* loginUser()
    {
        bool reset = false;
        string name, password, choice;

        cout << "Enter Username: ";
        getline(cin, name);

        User* temp = head;
        while (temp != NULL)        //checking if that name exists or not
        {
            if (temp->name == name)
            {
                cout << "Enter Password: ";     //if user found than ask password
                getline(cin, password);

                if (temp->password == password)
                {
                    temp->login();
                    cout << "\nLogin successful! Welcome back, " << name << endl;
                    return temp;
                }
                else
                {
                    cout << "Incorrect password!" << endl;
                    cout << "Would you like to reset your password? (Y/N)" << endl;
                    getline(cin, choice);

                    if (choice == "Y" || choice == "y")
                    {
                        resetPassword();
                    }
                    return NULL;
                }
            }
            temp = temp->next;
        }

        //if username not found
        cout << "Username does not exist!" << endl;
        return NULL;
    }


    void logoutUser(User* user) 
    {
        if (user) {
            user->logout();
        }
    }

    void resetPassword() 
    {
        string name, question, answer, new_pass, confirm_pass;
        cout << "Enter Username: ";
        getline(cin, name);
        User* temp = head;
        while (temp != NULL)
        {
            if (temp->name == name) 
            {
                cout << temp->securityQuestion << endl;
                cout << "Enter Answer: ";
                getline(cin, answer);
                if (temp->securityAnswer == answer)
                {
                    cout << "Enter New Password: ";
                    getline(cin, new_pass);
                    if (!isStrong(new_pass)) 
                    {
                        return;
                    }
                    cout << "Confirm New Password: ";
                    getline(cin, confirm_pass);
                    if (new_pass == confirm_pass) 
                    {
                        temp->password = new_pass;
                        cout << "Password reset successfully!" << endl;
                        return;
                    }
                    else {
                        cout << "Passwords do not match!" << endl;
                        return;
                    }
                }
                else {
                    cout << "Incorrect answer!" << endl;
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Username not found!" << endl;
    }
    User* search_BST(string& const name)
    {
        User* temp = obj_BST.search(name);
        return temp;
    }
};

void display_menu()
{
    cout << "\n================== MENU ==================\n";
    cout << "1. Register a new user\n";
    cout << "2. Login as a user\n";
    cout << "3. Logout current user\n";
    cout << "4. Relationship features\n";
   // cout << "5. View followers\n";
    cout << "6. Post content\n";
    cout << "7. View posts\n";
    cout << "8. Reset password\n";
    cout << "9. Searching features\n";
    cout << "10. Massaging features\n";
    cout << "11. Exit\n";
    cout << "==========================================\n";
    cout << "Enter your choice: ";
}
int main()
{
    createUsers users;    //main user managing object
    User* current_user = NULL; //keeps track of logged-in user
    string ch;              //string for exception handling
    while(true)
    {
        display_menu();
        cin >> ch;
        cin.ignore();

        if (ch == "1") //register a new user
        {
            users.registerUser();
        }
        else if (ch == "2") //login as a user
        {
            if (current_user != NULL)
            {
                cout << "An account is already logged in. Please log out first.\n";
            }
            else
            {
                if (!users.isempty()) //checking if there is any registered user or not
                {
                    User* logged_in_user = users.loginUser(); 
                    if (logged_in_user != NULL)
                    {
                        current_user = logged_in_user;
                    }
                    else
                    {
                        cout << "\nError in logging in... Please try again!\n";
                    }
                }
                else
                {
                    cout << "No users found .please reigster first\n";
                }
            }
        }

        else if (ch == "3") //logout current user
        {
            if (current_user !=NULL)
            {
                current_user->logout();
                cout << "Logged out ..BYE BYE\n";
                current_user = NULL;
            }
            else
            {
                cout << "No user is currently logged in.\n";
            }
        }
        else if (ch == "4") //follow someone
        {
            if (current_user == NULL)
            {
                cout << "Please login to follow someone\n";
            }
            else
            {
                system("cls");
                cout << "1.Start following someone\n"
                    << "2.View following list\n"
                    << "3.View follower list\n"
                    << "Your choice: ";
                int ch2; cin >> ch2;
                cin.ignore();
                if (ch2 == 1)       //add follower
                {
                    string follower_name, relation_type, status;
                    cout << "Enter other user name: ";
                    getline(cin, follower_name);
                    cout << "Enter relation type with " << follower_name << ": ";
                    getline(cin, relation_type);
                    cout << "Enter status of relation with " << follower_name << ": ";
                    getline(cin, status);

                    User* follow_user = users.search_BST(follower_name);
                    if (follow_user != NULL)
                    {
                        follow_user->add_follwer(current_user, relation_type, status);   //current_user will be the follower of follow_user
                        //current_user->add_following(follow_user, relation_type, status);   //current_user will start following the follow_user

                    }
                    else
                    {
                        cout << "There is no account with the name you entered for following\n";
                    }
                }
                else if (ch2 == 2)
                {
                    current_user->view_following();

                }
                else if (ch2 == 3)
                {
                    current_user->show_followers();

                }
            }
        }
        else if (ch == "5") //view followers
        {
            if (current_user != NULL)
            {
                cout << endl;
            }
            else
            {
                cout << "Please login to view friends.\n";
            }
        }
        //else if (ch == "6") // Post content
        //{
        //    if (current_user == NULL)
        //    {
        //        cout << "Please login to post content.\n";
        //    }
        //    else
        //    {
        //        string content;
        //        cout << "Enter content to post: ";
        //        getline(cin, content);
        //        current_user->post(content);
        //        cout << "Content posted successfully.\n";
        //    }
        //}
        //else if (choice == 7) // View posts
        //{
        //    if (current_user != NULL)
        //    {
        //        current_user->show_posts();
        //    }
        //    else
        //    {
        //        cout << "Please login to view posts.\n";
        //    }
        //}
        //else if (choice == 8) // Reset password
        //{
        //    users.reset_password();
        //}
        else if (ch == "9") //searching
        {
            system("cls");
            cout << "1.Simple search (no login required)\n"
                << "2.advanced search (login required)\n"
                << "Your choice: ";
            string ch2; cin >> ch2;
            cin.ignore();
            if (ch2 == "1")
            {
                cout << "Enter name of user to search: ";
                string name;
                getline(cin, name);
                User* search = users.search_BST(name);
                if (search != NULL)
                {
                    cout << "This user is on instagram\n";
                }
                else cout << "This user is not on instagram\n";
            }
            else if (ch2 == "2")
            {
                if (current_user == NULL)
                {
                    cout << "Please login to do advanced search\n";
                }
                else {
                    cout << "Enter name of user to search: ";
                    string name;
                    getline(cin, name);
                    current_user->check_relation_search(name);
                }

            }
            else cout << "Enter valid choice\n";
        }
        else if (ch == "10")
        {
            system("cls");
            if (current_user == NULL)
            {
                cout << "login to send a massage\n";
            }
            else {
                cout << "1.Send a massage\n"
                    << "2.View latest massage\n"
                    << "3.Show all massages\n"
                    << "Your choice: ";
                string ch2; cin >> ch2;
                cin.ignore();
                if (ch2 == "1") //send message
                {
                    string follower_name, content, timestamp;
                    cout << "Enter the follower's name: ";
                    getline(cin, follower_name);

                    User* follower = users.search_BST(follower_name);
                    if (follower != NULL && (current_user->check_follower_status(follower) || (current_user->check_following_status(follower))))
                    {//the if statement checks if there user with that name and also check if the status of ID entered
                        //is active with either the follower or following...
                        //if the entered user is in any of these two lists than send msg else not
                        cout << "Enter message content: ";
                        getline(cin, content);
                        cout << "Enter timestamp: ";
                        getline(cin, timestamp);

                        current_user->send_msg(follower, content, timestamp);  //send message to the follower
                    }
                    else
                    {
                        cout << "Follower not found or relation not suitable to send massage\n";
                    }
                }
                else if (ch2 == "2") //view latest message
                {
                    cout << "Enter follower ID with whom you want to see the lastest massage: ";
                    string fol_name;
                    getline(cin, fol_name);
                    User* follower = users.search_BST(fol_name);
                    if (follower != NULL && (current_user->check_follower_status(follower) || (current_user->check_following_status(follower))))
                    {//if statement is same as above
                        current_user->view_latest_msg(follower);
                    }
                    else {
                        cout << "Follower not found or relation with this follower is not suitable for massage" << endl;

                    }
                }
                else if (ch2 == "3") //show all messages
                {
                    cout << "Enter follower ID with whom you want to see all massages: ";
                    string fol_name;
                    getline(cin, fol_name);
                    User* follower = users.search_BST(fol_name);
                    if (follower != NULL) {
                        current_user->show_all_msg(follower);
                    }
                    else cout << "Follower not found!" << endl;

                }
                else cout << "Enter valid choice\n";
            }
        }
        else if (ch == "11")
        {
            cout << "Thanks for installing our mini instagram\n"
                << "Hope you had good experience\n"
                << "Removing all the data\n"
                << "BYE...\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "press any key to continue....";
        _getch();
        system("cls");
    }

    return 0;
}