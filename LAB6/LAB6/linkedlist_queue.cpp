#include <iostream>
#include <string>
using namespace std;

class node {
public:
    node* next;
    string name, AR, Time;

    node()
    {
        next = NULL;
        name = AR = Time = "";
    }
};

class Doctor {
public:
    string name, degree;

    Doctor()
    {
        name = degree = "";
    }

    void setname(string s)
    {
        name = s;
    }

    void setdegree(string d)
    {
        degree = d;
    }

    void display2()
    {
        cout << "Doctor name: " << name << endl;
        cout << "Degree name: " << degree << endl;
    }
};

class patient:public Doctor {
    node* front, * rear;

public:
    patient()
    {
        front = rear = NULL;
    }

    bool isempty()
    {
        return front == NULL;
    }

    void enqueue(string n, string a, string d)
    {
        node* ptr = new node;
        ptr->name = n;
        ptr->AR = a;
        ptr->Time = d;
        ptr->next = NULL;

        if (isempty())
        {
            front = rear = ptr;
        }
        else {
            rear->next = ptr;
            rear = ptr;
        }
    }

    void dequeue(string& n, string& a, string& d)
    {
        if (isempty())
        {
            cout << "Bruh nothing in queue\n";
            n = a = d = "";
            return;
        }
        node* temp = front;
        n = front->name;
        a = front->AR;
        d = front->Time;
        front = front->next;
        delete temp;

        if (isempty()) {
            rear = NULL;
        }
    }

    void display()
    {

        if (isempty())
        {
            cout << "nothing to show\n";
            return;
        }

        node* temp = front;
        display2();

        while (temp)
        {
            cout << "Name: " << temp->name << endl;
            cout << "Appointment reason: " << temp->AR << endl;
            cout << "Time: " << temp->Time << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    patient q1;
    cout << "Enter name of doctor: ";
    string DN; cin >> DN;
    q1.setname(DN);
    cout << "Enter degree of doctor: ";
    string degree; cin >> degree;
    q1.setdegree(degree);
    cout << "Now " << DN << " shb has control over the program\n";

    while (true)
    {
        cout << "1.Add Patient\n2.Remove Patient\n3.Display doctor and patient data\n4.is Empty\n5. Exit\n";
        cout << "Your choice: ";
        int ch; cin >> ch;

        if (ch == 1)
        {
            cout << "Enter name of patient: ";
            string n; cin >> n;
            cout << "Enter reason of appointment: ";
            string a;
            cin.ignore();
            getline(cin, a);
            cout << "Enter Time and date: ";
            string d;
            getline(cin, d);
            q1.enqueue(n, a, d);
        }
        else if (ch == 2)
        {
            string n, a, d;
            q1.dequeue(n, a, d); 
            if (!n.empty())
            {
                cout << "Removed patient is:\n";
                cout << "Name: " << n << endl;
                cout << "Reason: " << a << endl;
                cout << "Date and time: " << d << endl;
            }
        }
        else if (ch == 3)
        {
            q1.display();
        }
        else if (ch == 4)
        {
            if (q1.isempty())
                cout << "queue is empty\n";
            else 
                cout << "queue is not empty\n";
        }
        else if (ch == 5) 
        {
            break;
        }
    }

    return 0;
}
