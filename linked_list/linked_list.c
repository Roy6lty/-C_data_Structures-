/**
 * Creating a linked list
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int x;
    struct Node *next;
} Node;

void insert_end(Node **root, int value)
{
    /**
     * root has to be the address of the first Node
     */

    // creates a new Node
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("Cannot allocate memory");
        exit(1);
    }
    new_node->x = value;   // allocates value
    new_node->next = NULL; // The last not pointer points to null

    // root is the address of the first pointer
    // iterating through next till the end is reached which is null
    // the pointing it to the new node
    Node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}
/**
 * in c ** is used to refer to a pointer
 * pointing to another pointer
 */

void insert_begining(Node **root, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("Error creating begining Node");
    }

    new_node->x = value;
    new_node->next = *root;

    *root = new_node; //*root is a pointer to type Node
}

int main(int argc, char *argv[])
{
    Node *root = malloc(sizeof(Node));
    // if (root)
    Node *root = NULL;
    insert_begining(&root, 13);
    insert_begining(&root, 14);
    insert_begining(&root, 15);

    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);
    }
}