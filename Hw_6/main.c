
#include <stdio.h>
#include <stdlib.h>

// Node Struct
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}






                                /// SECOND EX


/*      // That part is included on top but for to show what needed in question, I writed again.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
*/


/// converting into the pre-ordering (traversing as pre-order)
// Rule-> root -> left -> right
void preOrder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);     // go to left
    preOrder(root->right);    // go to right
}




int main(void)
{


    /// HW:  Create simple Tree like in below:
    /// Ex: For the expression a = b + c * 2, AST is:


    //   =
    //  / \
    // a   +
    //    / \
    //   b   *
    //      / \
    //     c   2



    // creating tree (from below to top)

    // below part -> c * 2
    struct Node* n_c = createNode('c');
    struct Node* n_2 = createNode('2');

    struct Node* n_mult = createNode('*');
    n_mult->left = n_c;
    n_mult->right = n_2;

    // middle part -> b + (c * 2)
    struct Node* n_b = createNode('b');

    struct Node* n_plus = createNode('+');
    n_plus->left = n_b;
    n_plus->right = n_mult; // top right side multiplication op

    // top part (root) -> a = ...
    struct Node* n_a = createNode('a');

    struct Node* root = createNode('=');
    root->left = n_a;
    root->right = n_plus; // top right side sum op


    printf("root node: %c\n", root->data); // output -> =
    printf("on the right operation of the root: %c\n", root->right->data); // output -> +






                            /// HW 2:
                            printf("\n---------\n");

    // let's creating that example on below with code, after that we'll turn this tree into pre-order
    //       1
    //     /   \
    //    2     3
    //   / \   / \
    //  4   5 6   7

    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    root2->right->left = createNode(6);
    root2->right->right = createNode(7);

    printf("Pre-Order output: ");
    preOrder(root2); //1 2 4 5 3 6 7 (look carefully) it's not directly ordered from 1 to 7. it's correct order for "pre-order"



        /// HW 3: why we use Pre-order Traversal in trees ?

//    1-Tree Cloning (Copying): It is the primary method used to create a copy of a tree because the root is processed before its children, allowing you to build the structure from the top down.
//    2-Serialization: It is used to store a tree in a file or database in a way that preserves the original hierarchy when it is reconstructed later.
//    3-Expression Trees: It helps in converting expression trees into Prefix notation (Polish Notation), which is useful for certain compiler designs.
//    4-Directory Structures: It is ideal for listing directories and files in a hierarchical folder structure, where the parent folder must be accessed before its contents.


    return 0;





}