# Circular Linked List Implementation in C++

This repository contains a C++ implementation of a **Circular Linked List** with various operations such as insertion, deletion, and display.

## Features
- Insert at the beginning of the list
- Insert at the end of the list
- Insert after a specific node
- Delete a node (including the head node)
- Display the linked list

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

### **2. Inserting at the Beginning**
This function inserts a new node at the beginning of the circular linked list.

```cpp
void insertAtBeginning(Node*& head, int value)
```
- If the list is empty, the new node points to itself.
- If the list is not empty, we traverse to the last node and adjust the links accordingly.

### **3. Displaying the List**
This function prints the elements of the circular linked list.

```cpp
void display(Node* head)
```
- It starts from the head and prints each node until it reaches the starting point again.
- If the list is empty, it prints "List is empty."

### **4. Inserting at the End**
This function inserts a new node at the end of the circular linked list.

```cpp
void insertAtEnd(Node*& head, int value)
```
- If the list is empty, it behaves like `insertAtBeginning`.
- Otherwise, it traverses to the last node and updates the links.

### **5. Inserting After a Given Node**
This function inserts a new node **after** a specific target node.

```cpp
void insertAfter(Node*& head, int targetValue, int value)
```
- It searches for the target node and inserts the new node after it.
- If the target node is not found, it prints an error message.

### **6. Deleting the Head Node**
This function deletes the **head node** or any specific node by value.

```cpp
void deleteHead(Node*& head, int value)
```
- If the head itself needs to be deleted, the last node's `next` pointer is updated to skip the head.
- If any other node needs to be deleted, it is removed while maintaining the circular links.
- If the value is not found, an error message is displayed.

### **7. Main Function**
The `main()` function demonstrates the operations by:
- Inserting elements at the beginning
- Inserting elements at the end
- Inserting elements after a given node
- Deleting a node
- Displaying the final list

```cpp
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
```

## How to Run the Code
1. Copy the code into a file named `circular_linked_list.cpp`
2. Open a terminal and compile the program using:
   ```sh
   g++ circular_linked_list.cpp -o circular_list
   ```
3. Run the compiled program:
   ```sh
   ./circular_list
   ```

## Output Example
```
Circular Linked List: 30 -> 20 -> 10 -> (Back to Head)
30 -> 20 -> 10 -> 40 -> (Back to Head)
30 -> 20 -> 25 -> 10 -> 40 -> (Back to Head)
20 -> 25 -> 10 -> 40 -> (Back to Head)
```

## Contributions
Feel free to fork the repository, raise issues, or submit pull requests!

---

**Happy Coding! 🚀**

