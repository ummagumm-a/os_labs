#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int value;
    struct Node_s *next;
} Node;

typedef struct LinkeList_s
{
    Node *head;
    int size;
} LinkedList;

Node* return_i(LinkedList *llist, int index)
{
    int count = 0;
    struct Node_s *current = llist->head;

    while (current->next != 0 && count++ != index)
        current = current->next;

    return current;
}

Node* return_last(LinkedList* llist)
{
   return return_i(llist, llist->size - 1);
}

Node* insert_node(LinkedList *llist, int new_value, int index)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->next = 0;

    Node* prev = return_i(llist, index);
    new_node->next = prev->next;
    prev->next = new_node;

    llist->size++;
    
    return new_node;
}

Node delete_node(LinkedList* llist, int index)
{
    Node* prev_node;
    Node to_return;

    if (index > 0)
        prev_node = return_i(llist, index - 1);
    else 
    {
        to_return = *llist->head;

        if (llist->size > 1) llist->head = llist->head->next;
        else llist->head = 0;

        return to_return;
    }

    to_return = *prev_node->next;
    if (index == llist->size - 1)
        prev_node->next = 0;
    else 
        prev_node->next = to_return.next;

    llist->size = llist->size - 1;

    return to_return;
}
    
void print_list(LinkedList *llist)
{
    Node current = *llist->head;

    while (current.next != 0)
    {
        printf("%d ", current.value);
        current = *current.next;
    }

    printf("%d\n", current.value);
}

int main()
{
    LinkedList *llist = (LinkedList*) malloc(sizeof(LinkedList));
    llist->head = (struct Node_s*) malloc(sizeof(struct Node_s));
    llist->head->value = 0;
    llist->head->next = 0;
    llist->size = 1;

    print_list(llist);

    insert_node(llist, 2, 0);
    print_list(llist);

    insert_node(llist, 3, 1);
    insert_node(llist, 4, 1);
    print_list(llist);

    delete_node(llist, 0);
    delete_node(llist, 0);

    insert_node(llist, 4, 1);
    print_list(llist);

    return 0;
}
