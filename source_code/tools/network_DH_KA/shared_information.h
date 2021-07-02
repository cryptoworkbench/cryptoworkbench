#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/functional/logbook_functions.h" // <<< Needed for open_modular_group()
#include "../../libraries/mathematics/maths.h" // <<< "endpoint_alice.c" and "endpoint_bob.c" need this one

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define ENDPOINT_ALICE ".endpoint_alice"
#define ENDPOINT_BOB ".endpoint_bob"

struct group_element { unsigned long value; struct group_element *next; }; // <<< For use with triple ref pointers
unsigned long cap; // <<< I call the mod value "cap"
void insert(struct group_element **channel, unsigned long group_element);
struct group_element *group_elements_in_file(struct group_element **channel, FILE *input_file);
unsigned long length(unsigned long element);
unsigned long present(struct group_element *ll, unsigned long element);
