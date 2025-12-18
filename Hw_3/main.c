#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;



/// Traversal
void printList() {              /// Complexity = O(n)
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



/// Inserting beggining of the list
void insertAtBeginning(int new_data) {          /// Complexity = O(1)

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}




///Inserting middle of the list
void insertMiddle(struct Node* prev_node, int new_data) {              /// Complexity = O(n)
    if (prev_node == NULL) return;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}




///Inserting ending of the list
void insertAtEnd(int new_data) {            /// Complexity = O(1)

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL) { // Liste boşsa
        head = new_node;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) { // Sona kadar git
        temp = temp->next;
    }
    temp->next = new_node;
}




///Deleting element from  list
void deleteNode(int key) {            /// Complexity = O(n)
    struct Node* temp = head;
    struct Node* prev = NULL;


    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}





int main(void)
{



    /// Homework: On liked list, do create list, add into beggining, middle, ending, deleting and traversal operations.



    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;

    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;

    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;

    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;



    printf("Traversing List:\n");
    printList();

    insertAtBeginning(9);
    insertMiddle(head->next->next, 99); // adding into 4 th element // 7 element
    insertAtEnd(24);

    printf("After adding:\n");
    printList();

    return 0;



}