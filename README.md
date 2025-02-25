# Circular Linked List Implementation in C++

This repository contains a C++ implementation of a **Circular Linked List** with various operations such as insertion, deletion, and display.

## Features
- Insert at the beginning of the list
- Insert at the end of the list
- Insert after a specific node
- Delete a node (including the head node)
- Display the linked list

## What is a Circular Linked List?
A **Circular Linked List (CLL)** is a variation of a linked list where the last node points back to the first node instead of pointing to `NULL`. This forms a circular structure that allows continuous traversal of the list.

### **Types of Circular Linked Lists:**
1. **Singly Circular Linked List:** Each node points to the next node, and the last node connects to the first node.
2. **Doubly Circular Linked List:** Each node has two pointers, one pointing to the next node and one to the previous node, forming a bi-directional circle.

## Code Explanation

### **1. Node Structure**
Each node in the circular linked list contains:
- An integer `data` field
- A pointer `next` that points to the next node in the list

```cpp
struct Node {
    int data;
    Node* next;
};
```

### **2. Algorithm for Inserting at the Beginning**
1. Create a new node.
2. If the list is empty:
   - Set the `next` of the new node to point to itself.
   - Assign the new node as the `head`.
3. Otherwise:
   - Traverse to the last node.
   - Update the last node's `next` to point to the new node.
   - Set the new node's `next` to the previous head.
   - Update the head pointer.

#### **Implementation:**
```cpp
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
```

### **3. Algorithm for Displaying the List**
1. If the list is empty, print "List is empty".
2. Start from the `head` node.
3. Traverse through each node and print its data.
4. Stop when we reach the starting node again.

#### **Implementation:**
```cpp
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (true) {
        cout << temp->data << " -> ";
        temp = temp->next;
        if (temp == head) break;
    }
    cout << "(Back to Head)" << endl;
}
```

### **4. Algorithm for Inserting at the End**
1. Create a new node.
2. If the list is empty, insert it like in `insertAtBeginning`.
3. Otherwise:
   - Traverse to the last node.
   - Update the last node's `next` to point to the new node.
   - Set the new node's `next` to head.

#### **Implementation:**
```cpp
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
```

### **5. Algorithm for Inserting After a Given Node**
1. Search for the node with the target value.
2. If found:
   - Create a new node.
   - Adjust the `next` pointers to insert the new node.
3. If not found, print an error message.

#### **Implementation:**
```cpp
void insertAfter(Node*& head, int targetValue, int value) {
    Node* temp = head;
    while (temp->data != targetValue && temp->next != head) {
        temp = temp->next;
    }
    if (temp->data == targetValue) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Target value not found!" << endl;
    }
}
```

### **6. Algorithm for Deleting the Head Node**
1. If the list is empty, return.
2. If only one node exists, delete it and set `head` to `nullptr`.
3. Otherwise:
   - Find the last node.
   - Update the last node's `next` to skip the head node.
   - Delete the head and update it to the next node.

#### **Implementation:**
```cpp
void deleteHead(Node*& head, int value) {
    if (head == nullptr) return;
    Node* temp = head;
    Node* prev = head;

    if (temp->data == value) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }
    while (temp->next != head && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next->data == value) {
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    } else {
        cout << "Value " << value << " not found" << endl;
    }
}
```

### **7. Main Function**
```cpp
int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    display(head);
    insertAtEnd(head, 40);
    display(head);
    insertAfter(head, 20, 25);
    display(head);
    deleteHead(head, 30);
    display(head);
    return 0;
}
```

## How to Run the Code
1. Compile using: `g++ circular_linked_list.cpp -o circular_list`
2. Run the program: `./circular_list`

## Contributions
Feel free to fork, raise issues, or submit pull requests!

---

**Happy Coding! 🚀**

