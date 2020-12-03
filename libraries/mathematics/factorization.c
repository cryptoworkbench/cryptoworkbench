// This library contains all of the factorization engines.
// 
// See the header file for function descriptions.
#define MULTIPLICATIVE_IDENTITY 1


/* ### FACTORIZATION ENGINE ONE ### */
unsigned long inflate_square(unsigned long *root, unsigned long *square, unsigned long match_up) {
    *square += *root;
    *root += MULTIPLICATIVE_IDENTITY;
    *square += *root;

    if (!(*square > match_up)) { /* For as long as the square is not bigger than match_up */
	inflate_square(root, square, match_up);
    } else if (*square > match_up) {
	*square -= *root;
	*root -= MULTIPLICATIVE_IDENTITY;
	*square -= *root;
	return *square;
    }
}

struct factors fermat_factorize(unsigned long *big_rt, unsigned long *big_sq, unsigned long small_rt, unsigned long whole) {
    if (whole == inflate_square(big_rt, big_sq, whole)) {
	free(big_sq); struct factors return_value = {*big_rt - small_rt, *big_rt + small_rt}; free(big_rt);
	// No need to free small_rt because it was not received as a pointer to an unsigned long
	return return_value;
    } else fermat_factorize(big_rt, big_sq, MULTIPLICATIVE_IDENTITY + small_rt, MULTIPLICATIVE_IDENTITY + whole + (small_rt * 2));
}
