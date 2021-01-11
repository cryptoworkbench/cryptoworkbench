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
	printf("%lu\n",(*tracer)->val);
	tracer = &(*tracer)->next;
    }
}

struct element **list() {
    struct element ***i;
    *(i = (struct element ***) malloc(sizeof(void *))) = (struct element **) malloc(sizeof(void *));
    **i = NULL;

    return *i;
}

int main(int argc, char **argv) {
    struct element **list_one = list();
    printf("List #1, revision 0:\n");
    insert_element(list_one, create_element(10));
    print_list(list_one); printf("\n\n");

    printf("List #1, revision 1:\n");
    insert_element(list_one, create_element(11));
    print_list(list_one); printf("\n\n");

    printf("List #1, revision 2:\n");
    insert_element(list_one, create_element(9));
    print_list(list_one); printf("\n\n");

    struct element **list_two = list();
    printf("List #2, revision 0:\n");
    insert_element(list_two, create_element(5));
    print_list(list_two); printf("\n\n");

    printf("List #2, revision 1:\n");
    insert_element(list_two, create_element(4));
    print_list(list_two); printf("\n\n");

    printf("List #2, revision 2:\n");
    insert_element(list_two, create_element(6));
    print_list(list_two); printf("\n\n");
    return 0;
}                  
