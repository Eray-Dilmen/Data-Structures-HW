#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;


/// Inserting into the beggining
struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

/// Inserting into the ending
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/// Deleting from the beggining
struct node* deleteFromBeginning(struct node* head) {
    if (head == NULL)
        return NULL;

    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

/// Deleting from the ending
struct node* deleteFromEnd(struct node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    return head;
}

///Printing reverse of linked list
void printreverse(struct node *head) {
    if (head == NULL)
        return;
    else
        printreverse(head->next);

    printf("%d\t", head->data);
}


int main(void) {

    /// week 1 homework
    /// print reverse of the linked list, addition and removal operations will be performed on the linked list.

}
