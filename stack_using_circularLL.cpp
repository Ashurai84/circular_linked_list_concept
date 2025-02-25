// #include <iostream>
// using namespace std;
// struct Node
// {
//     int data;
//     Node *next;
// };
// Void InsertAtBegining(int d , Node * &head){
//     Node *m = new Node();
//     m->data=value;


//     if (head==nullptr){

//         m->next=m;
//         head=m;

//     }


//     void display(Node* top)
// {
//     Node* temp = top;
//     if (top != nullptr)
//     {
//         do
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         } while (temp != top);
//     }
//     cout << endl;

// }
   
// }

// ing main(){
//     Node *top = nullptr;
//     push(top, 1);
//     push(top, 2);
//     push(top, 3);
//     display(top);
// }


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) { 
        newNode->next = newNode; 
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) { 
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(Back to Head)" << endl;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) { 
        newNode->next = newNode; 
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) { 
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
    }
}

void insertAfter(Node*& head, int targetValue, int value) {
    Node* temp = head;
    do {
        if (temp->data == targetValue) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Target value not found!" << endl;
}

// Deleting head node
void deleteHead(Node*& head, int value) {
    if (head == nullptr)
        return; // Empty list

    Node* temp = head;
    Node* prev = head;

    // Case 1: Deleting the head node
    if (temp->data == value) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }

    // Case 2: Deleting a node in between
    do { 
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);

    if (temp->data == value) {
        prev->next = temp->next;
        delete temp;
    } else {
        cout << "Value " << value << " not found" << endl;
    }
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);

    cout << "Circular Linked List: ";
    display(head);

    insertAtEnd(head, 40);
    display(head);

    insertAfter(head, 20, 25);
    display(head);

    deleteHead(head, 30);
    display(head);

    return 0;
}
