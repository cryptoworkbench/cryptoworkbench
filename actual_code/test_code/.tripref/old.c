#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

struct element {
    unsigned long val;
    struct element *next;
}; typedef struct element *element_ptr;

struct element *create_element(unsigned long info) {
    struct element *new_element = malloc(sizeof(struct element));
    new_element->val = info;
    new_element->next = NULL;
    return new_element;
}  

void insert_element(struct element **head, struct element *new_element) {
    struct element **tracer = head;

    // For as long as the next element in the list has a smaller value than the value of the element to be inserted
    while (*tracer != NULL && (**tracer).val < (*new_element).val)
	    tracer = &(**tracer).next; // Move onto this element, and check again

    new_element->next = *tracer;
    *tracer = new_element;
}

void print_list(struct element **head) {
    struct element **tracer = head;
    while (*tracer) {
	printf("%lu \n",(*tracer)->val);
	tracer = &(*tracer)->next;
    }
}

int main(int argc, char **argv) {
    struct element **i;
    i = (struct element **) malloc(sizeof(void *));
    *i = (struct element *) malloc(sizeof(void *));
    **i = (struct element *) NULL;

    insert_element(i, create_element(10));
    printf("%lu\n", (*i)->val);

    /* if (ring_link != _previous_ring_link) {
	printf("Start has changed!\n");
	_previous_ring_link = ring_link;
    } */

    insert_element(i, create_element(11));

    /* if (ring_link != _previous_ring_link) {
	printf("Start has changed!\n");
	_previous_ring_link = ring_link;
    } else
	printf("Start has not changed.\n"); */

    insert_element(i, create_element(9));
    /* if (ring_link != _previous_ring_link) {
	printf("Start has changed!\n");
	_previous_ring_link = ring_link;
    } else
	printf("Start has not changed.\n"); */
    print_list(i);

    return 0;
}                  
