#include <stdlib.h>
#include <stdio.h>

#include "list.h"

Node* find_page_to_evict(LinkedList* llist)
{
    int min_count = 1024;
    Node* current = llist->head;
    Node* with_min_count = current;

    while (current != NULL)
    {
        if (with_min_count->value->counter > current->value->counter)
            with_min_count = current;
        else if (with_min_count->value->counter == current->value->counter
                && with_min_count->value->page_number > current->value->page_number)
            with_min_count = current;

        current = current->next;
    }

    return with_min_count;
}

void handle_miss(LinkedList* llist, int number, int n_page_frames)
{
    page_table_entry* new_page = (page_table_entry*) malloc(sizeof(page_table_entry));
    new_page->page_number = number;
    new_page->counter = 0;
    new_page->r_bit = 1;

    if (llist->size < n_page_frames)
        insert_back(llist, new_page);
    else
    {
        Node* page_to_evict = find_page_to_evict(llist);

        delete_node(llist, page_to_evict);
        insert_back(llist, new_page);
    }
}

void make_older(LinkedList* llist)
{
    Node* current = llist->head;

    while (current != NULL)
    {
        current->value->counter = current->value->counter >> 1;
        current->value->counter += current->value->r_bit << 7;
        current->value->r_bit = 0;

        current = current->next;
    } 
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    LinkedList *llist = (LinkedList*) malloc(sizeof(LinkedList));

    int hitcount = 0;
    int t, a;
    int prev_t = 0;
    int iter = 1;
    int is_first = 1;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &t);
        scanf("%d", &a);

        if (is_first)
        {
            is_first = 0;
            prev_t = t;
        }

        if (t != prev_t)
        {
            prev_t = t;
            make_older(llist);
        }

        int is_found = find_by_number(llist, a);
        if (is_found)
        {
            hitcount++;
            printf("1\n");
        }
        else
        {
            handle_miss(llist, a, n);
            printf("0\n");
        }

    }

    printf("%f\n", (double) hitcount / (m - hitcount));

    return 0;
}
