#include<stdio.h>
#include<stdlib.h>
struct list
{
int value;
struct list* link;//self referential pointer
};
struct list* add_first(struct list*);
struct list* add_last(struct list*);
struct list* add_in_sorted(struct list*);
void Display(struct list*);
void print_mth_node_from_last(struct list*);
struct list* remove_multiple(struct list*);
struct list* delete_last(struct list*);
