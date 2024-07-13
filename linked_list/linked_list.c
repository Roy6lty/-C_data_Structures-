/**
 * Creating a linked list
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

    // check if the list is empty
    Node *curr = *root;
    if (curr == NULL)
    {
        *root = new_node;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
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

void deallocate(Node **root, int index)
{
    Node *curr = NULL;
    Node *next_current = NULL;
    Node *previous = *root;
    if (*root == NULL)
    {
        perror("NO nodes in list");
    }

    // Remove the first Node
    if (index == 1)
    {
        *root = previous->next;
        free(previous);
        return;
    }

    // Iterate to spercific index
    for (int i = 1; i < index - 1; i++)
    {
        previous = previous->next;
    }
    curr = previous->next;
    if (curr->next == NULL) // last node in list
    {
        previous->next = NULL;
        free(curr);
        return;
    }

    if (curr->next != NULL) // Node in the middle
    {

        next_current = curr->next;
        previous->next = next_current;
    }
    free(curr);
}

void insert_sorted(Node **root, int value)
{
    /**
     * Insert in a sorted list and into
     * the correct position
     */
    Node *curr = *root;
    Node *next_node = NULL;
    Node *prev_node = NULL;

    // first Node
    if (*root == NULL)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->x = value;
        new_node->next = NULL;

        *root = new_node;
        return;
    }

    // if more than one node

    if (*root != NULL)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->x = value;
        new_node->next = NULL;

        // only one Node
        if (curr->x >= value)
        {
            new_node->next = curr;
            *root = new_node;
            return;
        }

        prev_node = curr;
        curr = prev_node->next;

        int current_value = curr->x;

        while (curr->next != NULL)
        {
            if (current_value >= value)
            {
                prev_node->next = new_node;
                new_node->next = curr;
                break;
            }
            prev_node = curr;
            curr = prev_node->next;
            current_value = curr->x;
        }
        if (curr->next == NULL)
        {
            if (current_value >= value)
            {
                prev_node->next = new_node;
                new_node->next = curr;
                return;
            }
            curr->next = new_node;
            return;
        }
        return;
    }
}

void reverse(Node **root)
{
    /**
     * This function reverse an linked list
     */
    Node *head = *root;

    Node *prev = *root;
    Node *curr = NULL;
    Node *next = NULL;

    // if only one node exists
    if (prev->next == NULL)
    {
        return;
    }

    curr = prev->next;
    while (curr->next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;

    if (head->next != NULL)
    {
        head->next = NULL;
    }
    *root = curr;
    return;
}

void reverse_recursive(Node **root)
{
    Node *prev = *root;
    Node *curr = prev->next;

    // Base case: end of the list
    if (curr == NULL)
    {
        return;
    }

    // Recurse to the next node
    reverse_recursive(&curr);

    // Reverse the pointers
    prev->next->next = prev;
    prev->next = NULL;
    *root = curr;
}

int main(int argc, char *argv[])
{
    /// Node *root = malloc(sizeof(Node));
    // if (root)
    Node *root = NULL;
    // insert_begining(&root, 13);
    // insert_begining(&root, 20);
    // insert_begining(&root, 15);
    insert_end(&root, 17);
    insert_end(&root, 18);
    insert_end(&root, 19);
    // insert_end(&root, 20);

    // deallocate(&root, 2);
    // deallocate(&root, 1);
    insert_sorted(&root, 10);
    insert_sorted(&root, 2);
    insert_sorted(&root, 1);
    insert_sorted(&root, 11);
    insert_sorted(&root, 3);
    insert_sorted(&root, 13);
    insert_sorted(&root, 5);
    insert_sorted(&root, 8);
    insert_sorted(&root, 15);
    insert_sorted(&root, 14);
    insert_sorted(&root, 17);
    insert_sorted(&root, 16);
    reverse(&root);
    reverse_recursive(&root);

    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);
    }
}