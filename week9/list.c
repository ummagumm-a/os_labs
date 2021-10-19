#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Node* insert_back(LinkedList *llist, page_table_entry *new_value)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL)
        printf("\nOVERFLOW\n");
    else
    {
        new_node->value = new_value;
        if (llist->head == NULL)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            llist->size = 1;
            llist->head = new_node;
            llist->last = new_node;
        }
        else
        {
            llist->last->next = new_node;
            new_node->prev = llist->last;
            new_node->next = NULL;
            llist->last = new_node;
            llist->size++;
        }

    }
    
    return new_node;
}

void replace(Node* old_node, page_table_entry* new_page)
{
    old_node->value = new_page;
}

void delete_node(LinkedList *llist, Node *node)
{
    if (node == llist->head)
    {
        if (llist->last == llist->head) llist->last = NULL;

        Node *new_head = llist->head->next;
        free(llist->head);
        llist->head = new_head;
    }
    else if (node == llist->last)
    {
        Node *new_last = llist->last->prev;
        free(llist->last);
        llist->last = new_last;
        llist->last->next = NULL;
    }
    else
    {
        Node *old = node;
        node->prev->next = node->next;
        old->next->prev = old->prev;
        free(old);
    }
    
    llist->size--;
}

int find_by_number(LinkedList *llist, int n)
{
    Node* current = llist->head;

    while (current != NULL && current->value->page_number != n)
        current = current->next;

    if (current != NULL)
    {
        current->value->r_bit = 1;
        return 1;
    }
    else
        return 0;
}

void print_list(LinkedList *llist)
{
    printf("size: %d\nList: \n", llist->size);

    Node* current = llist->head;

    while (current != NULL)
    {
        printf("%d ", current->value->page_number);
        printf("%d ", current->value->counter);
        printf("%d\n", current->value->r_bit);
        current = current->next;
    }

    printf("\n");
}

/*
int main()
{
    LinkedList *llist = (LinkedList*) malloc(sizeof(LinkedList));

    print_list(llist);

    page_table_entry *pte1 = (page_table_entry*) malloc(sizeof(page_table_entry));
    pte1->page_number = 1;
    Node *node1 = insert_back(llist, pte1);
    print_list(llist);

    page_table_entry *pte2 = (page_table_entry*) malloc(sizeof(page_table_entry));
    pte2->page_number = 2;
    Node *node2 = insert_back(llist, pte2);
    print_list(llist);

    page_table_entry *pte3 = (page_table_entry*) malloc(sizeof(page_table_entry));
    pte3->page_number = 4;
    Node *node3 = insert_back(llist, pte3);

    page_table_entry *pte4 = (page_table_entry*) malloc(sizeof(page_table_entry));
    pte4->page_number = 3;
    Node *node4 = insert_back(llist, pte4);
    print_list(llist);

    delete_node(llist, node4);
    delete_node(llist, node2);
    print_list(llist);

    page_table_entry *pte5 = (page_table_entry*) malloc(sizeof(page_table_entry));
    pte5->page_number = 5;
    Node *node5 = insert_back(llist, pte5);

    print_list(llist);

    delete_node(llist, node1);
    print_list(llist);

    delete_node(llist, node3);
    print_list(llist);

    delete_node(llist, node5);
    print_list(llist);

    page_table_entry *pte6 = (page_table_entry*) malloc(sizeof(page_table_entry));
    pte6->page_number = 6;
    Node *node6 = insert_back(llist, pte6);
    print_list(llist);

    return 0;
}
*/
