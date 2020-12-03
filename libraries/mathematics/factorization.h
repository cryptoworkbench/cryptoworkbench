/* The factorization library contains all the factorization engines I write */
struct factors { unsigned long a; unsigned long b; };

/* ### FACTORIZATION ENGINE ONE: ### */
unsigned long inflate_square(unsigned long *root, unsigned long *square, unsigned long match_up);

struct factors fermat_factorize(unsigned long *big_rt, unsigned long *big_sq, unsigned long small_rt, unsigned long whole);
/* Uses Fermat's factorization algorithm to find the factors of an odd composite.
 *
 * A recursive function which takes clever advantage
 */

/*
// ### Functions for Fermat factorization method, fermat_factorize returns a struct cointaining the factors, and uses inflate_square ###
unsigned long inflate_square(unsigned long *root, unsigned long *square, unsigned long match_up); 

// How to use?
struct factors fermat_factorize(unsigned long *big_rt, unsigned long *big_sq, unsigned long small_rt, unsigned long whole);
// Call as
 * factorization solution fermat_factorize(malloc(sizeof(unsigned long)), malloc(unsigned long), ADDITIVE_IDENTITY, unsigned long *composite);
 */
