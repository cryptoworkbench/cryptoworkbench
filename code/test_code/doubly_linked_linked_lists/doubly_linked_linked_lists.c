#include <stdio.h>
#include <stdlib.h>

struct shackle {
    unsigned long id;
    struct shackle *previous;
    struct shackle *next;
}; typedef struct shackle *shackle_ptr;

void insert(struct shackle *previous_shackle, unsigned long new_identifier) {
    /* ### CREATE NEW SHACKLE ### */
    struct shackle *new_shackle = malloc(sizeof(struct shackle));
    new_shackle->id = new_identifier;

    /* Attach new shackle */
    new_shackle->next = previous_shackle->next;
    new_shackle->previous = previous_shackle;
    previous_shackle->next = new_shackle;
}

void debug(struct shackle *focus) {
    printf("Iterator's current focus: %lu\n", focus->id);
    printf("Iterator's next sloth: %lu\n", focus->next->id);
    printf("Iterator's previous sloth: %lu\n", focus->previous->id);
}

int main(int argc, char **argv) {
    /* ### Assign space for elements on the heap ### */
    struct shackle *id_el = malloc(sizeof(struct shackle));
    struct shackle *neg_id_el = malloc(sizeof(struct shackle));

    /* ## Give elements appropriate value ## */
    id_el->id = 1;
    neg_id_el->id = 22;

    id_el->previous = neg_id_el;
    neg_id_el->previous = id_el;

    id_el->next = neg_id_el;
    neg_id_el->next = id_el;

    /* Start experimenting */
    struct shackle *iterator = id_el;
    printf("Id_el:\n");
    debug(iterator);
    printf("\n");

    iterator = iterator->next;
    printf("Neg_id_el:\n");
    debug(iterator);
    printf("\n");

    /* INSERT */
    iterator = id_el;
    insert(iterator, 11);
    iterator = iterator->next;
    printf("After inserting after id_el and shifting the focus here:\n");
    debug(id_el);



    // printf(
    return 0;
}
