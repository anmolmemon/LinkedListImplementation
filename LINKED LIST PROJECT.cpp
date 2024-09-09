#include <iostream>
#include <cstdlib>
using namespace std;

// Define a structure for a node in the linked list
struct node {
    int data;
    node* next;         // Pointer to the next node in the list


    // Constructor to initialize the node with a given value
    node(int value) {
        data = value;
        next = NULL;
    }
};

// Pointer that points to the first node in the linked list
node* head = NULL;

// Insertion at the beginning of the linked list
void INSERT_BEGIN(int data) {
	
    node* newnode = new node(data);           // Creating a new node
    newnode->next = head;
    head = newnode;
}

// Insertion at the end of the linked list
void INSERT_END(int data) {
    node* newnode = new node(data);     // Creating a new node

    if (!head) {          // If the list is empty, make the new node ( first node)
        head = newnode;
        return;
    }

    node* current = head;       // Start from the first node 
    while (current->next != NULL) {    //move to the last node in the list
        current = current->next;
    }

    current->next = newnode;     // Attach the new node to the last node
}

// Insertion at a specific position in the linked list
void insert_at(int data, int position) {
    if (position < 0) {            // Check if the position is invalid (less than 0)
        cout << "Invalid position" << endl;
        return;
    }
    
    if (position == 0 || !head) {        // Check if the position is at the beginning or the list is empty
        INSERT_BEGIN(data);        // If so, insert the new node at the beginning
        return;
    }

    node* newnode = new node(data);      // Create a new node with the provided data

    node* current = head;      // Start from the first node

    for (int i = 1; i < position && current->next; ++i) {      // Traverse to the node just before the desired position
        current = current->next;
    }

    newnode->next = current->next;     // Attach the new node to the linked list at the desired position
    current->next = newnode;
}

// Deletion from the beginning of the linked list
void DELET_BEGIN() {
    if (head) {  
        node* temp = head;     // Create a temporary pointer to the first node
        head = head->next;    // Update the head to point to the next node (the new first node)
        delete temp;         // Delete the original first node
    }
}

// Deletion from the end of the linked list
void DELET_END() {
    if (!head) {     // Check if the list is empty
        return;
    }

    if (!head->next) {        // Check if there is only one node in the list
        delete head;         // If so, delete the single node and update the head
        head = NULL;
        return;
    }

    node* current = head;        // Start from the first node
    while (current->next->next) {    // Move to the second-to-last node in the list
        current = current->next;
    }

    delete current->next;      // Delete the last node
    current->next = NULL;      // Set the next pointer of the second-to-last node to nullptr
}

// Deletion from a specific position in the linked list
void delete_at(int position) {
    if (position < 0 || !head) {      // Check if the position is invalid or the list is empty
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 0) {       // Check if the position is the first node
        DELET_BEGIN();        // If so, use the delete_begin function to delete the first node
        return;
    }

    node* current = head;             // Start from the first node
    node* temp = NULL;         // Create a temporary pointer to the node to be deleted
    for (int i = 1; i < position && current->next; ++i) {      // Traverse to the node just before the specified position
        current = current->next;
    }

    if (current->next) {                                 // Check if the node at the specified position exists
        temp = current->next;                          // Save the pointer to the node to be deleted
        current->next = current->next->next;         // Update the next pointer of the current node to skip the node to be deleted
        delete temp;                             // Delete the node at the specified position
    }
}

// Deletion of a specific data in the linked list
void delete_data(int data) {
    node* current = head;          // Start from the first node
    node* temp = NULL;           // Create a temporary pointer to the node to be deleted

    if (head && head->data == data) {   // Check if the first node contains the specified data
        temp = head;                    // If so, delete the first node and update the head
        head = head->next;
        delete temp;
        return;
    }

    // Traverse through the list until the node with the specified data is found or the end of the list is reached
    while (current->next && current->next->data != data) {
        current = current->next;
    }

    if (current->next) {         // Check if the node with the specified data is found
        temp = current->next;           // Save the pointer to the node to be deleted
        current->next = current->next->next;         // Update the next pointer of the current node to skip the node to be deleted
        delete temp;                        // Delete the node with the specified data
    }
}

// Traverse the linked list and print elements
void traverse() {
    node* current = head;       //WE ARE DECLARAING pointer to a node and initiallizing it with address of head 
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;      //it moves the current pointer to next node
    }
    cout << endl;
}

// Search for a node with specific data in the linked list
node* search(int data) {
    node* current = head;          // Start from the first node
    while (current != NULL) {
        if (current->data == data) {     // Traverse through the list until the node with the specified data is found
            return current;
        }
        current = current->next;
    }
    return NULL;      // Return null if the data is not found
}

// Additional operations
// Function to reverse the linked list
void reversal() {
    node* prev = NULL;        // Initialize pointers for the reversal process
    node* current = head;
    node* next = NULL;

    while (current != NULL) {       // Traverse through the linked list and reverse the pointers
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;     // Update the head to the new first node after reversal
}

// Function to sort the linked list in ascending order
void sort() {
    node* i = head;    // Initialize a pointer for iterating through the linked list
    while (i != NULL) {
        node* j = i->next;      // Initialize a pointer for comparing elements with the first pointer
        while (j != NULL) {
            // Swap data if the current element is greater than the compared element
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

// Memory Management:
// Function to clear the entire linked list and free memory
void deleteList() {
    node* temp = head;       // Initialize a temporary pointer to traverse the linked list
    while (temp != NULL) {
        node* toBeDeleted = temp;       // Save the pointer to the current node
        temp = temp->next;          // Move to the next node
        delete toBeDeleted;      // Delete the current node
    }
    head = NULL;             // Set the head to nullptr after clearing the linked list
}

// Function to interact with the user and perform various linked list operations
void userInterface() {
    int choice, data, position;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at a specific position\n";
        cout << "4. Delete from the beginning\n";
        cout << "5. Delete from the end\n";
        cout << "6. Delete from a specific position\n";
        cout << "7. Delete a specific data\n";
        cout << "8. Traverse\n";
        cout << "9. Search\n";
        cout << "10. Reverse\n";
        cout << "11. Sort\n";
        cout << "12. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                INSERT_BEGIN(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                INSERT_END(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                insert_at(data, position);
                break;
            case 4:
                DELET_BEGIN();
                break;
            case 5:
                DELET_END();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                delete_at(position);
                break;
            case 7:
                cout << "Enter data to delete: ";
                cin >> data;
                delete_data(data);
                break;
            case 8:
                cout << "Linked list elements: ";
                traverse();
                break;
            case 9:
                cout << "Enter data to search: ";
                cin >> data;
                if (node* result = search(data)) {
                    cout << "Data found at address: " << result << endl;
                } else {
                    cout << "Data not found." << endl;
                }
                break;
            case 10:
                reversal();
                cout << "Linked list reversed." << endl;
                break;
            case 11:
                sort();
                cout << "Linked list sorted." << endl;
                break;
            case 12:
                deleteList();
                cout << "Linked list cleared. Exit\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Main function to start the linked list user interface
int main() {
    userInterface();
    return 0;
}
