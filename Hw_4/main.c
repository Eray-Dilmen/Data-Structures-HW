#include <stdio.h>
#include <stdlib.h>



struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;




///Insertion to the beggining
void insertAtHead(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
}


///Insertion to the middle
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) return;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}





///Insertion to the ending
void insertAtEnd(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}



/// Deletion with recursive
void deleteListRecursive(struct Node* node) {
    if (node == NULL) return;

    deleteListRecursive(node->next);

    printf("%d deleting...\n", node->data);
    free(node);
}


///Traversal
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}





// Normal Double Linked List Ordering
void sortNormalList(struct Node* head) {
    if (head == NULL) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;


        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Veri değişimi (Swap)
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Convering List into Circular
// It takes the end of the current normal list and connects it to the beginning
void makeCircular(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
}

// Circular Double Linked List Ordering
void sortCircularList(struct Node* head) {
    if (head == NULL) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != head && ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}







int main(void)
{

    /// HW: How to add an element to beggining, middle and end of double linked list?
    /// How you can delete all the elements of a linked list? (Write it as recursive)
    /// Figure out the difference between circular linked list and linked list. Write it and check the difference with sorting algorithms.


    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;


    insertAtHead(5);
    insertAtEnd(20);
    insertAfter(head->next, 15);

    printf("List:\n");
    printList();


    printf("\nDeleting Process:\n");
    deleteListRecursive(head);
    head = NULL;




    /// difference between linked list and double linked list

    // Normal List Sorting
    printf("Normal List Ordering\n");
    sortNormalList(head);
    printList(); // Senin print fonksiyonun (NULL görene kadar yazan)

    // Making the List Circular and Sorting it
    makeCircular(head);

    printf("Circular List Ordering\n");
    sortCircularList(head);

    //The normal printList function will enter an infinite loop in there
    //so small loop to print the circular list:
    struct Node* temp = head;
    printf("Circular Result: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Came back to beggining)\n");





}