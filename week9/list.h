/*
 * list.h
 * Copyright (C) 2021 ummagumma <ummagumma@ummagumma>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LIST_H
#define LIST_H

typedef struct 
{
    int page_number;
    unsigned int counter;
    int r_bit;
} page_table_entry;

typedef struct Node_s
{
    struct Node_s *prev;
    page_table_entry *value;
    struct Node_s *next;
} Node;

typedef struct LinkedList_s
{
    Node *head;
    int size;
    Node *last;
} LinkedList;

Node* insert_back(LinkedList *llist, page_table_entry *new_value);
void replace(Node* old_node, page_table_entry* new_page);
void delete_node(LinkedList *llist, Node *node);
int find_by_number(LinkedList *llist, int n);
void print_list(LinkedList *llist);



#endif /* !LIST_H */
