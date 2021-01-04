From _fermats_algorithm.h_:
```c
struct pure_square {
    unsigned long root;
    unsigned long square;
};
```

From _fermats_algorithm.c_:
```c
void inflate(struct pure_square *square_pair) {
    square_pair->square += square_pair->root;
    square_pair->root += 1;
    square_pair->square += square_pair->root;
}
```

Then couple lines further we find:
```c
while (pair_one->square != pair_two->square) {
    while (pair_one->square < pair_two->square)
	inflate(pair_one);
    while (pair_one->square > pair_two->square)
	inflate(pair_two);
}

struct pure_square factors =
    { pair_one->root - pair_two->root,
    pair_one->root + pair_two->root };
```
Then just before main()
```c
struct pure_square fermat_factorize(unsigned long odd_composite) {
    return _fermat_factorize(construct_square(0, 0), construct_square(0, odd_composite)); // the first and second pure_square structs are automatically freed by _fermat_factorize()
}
```

This is the gist of it. Do ya get it? It is pretty easy to guess.

See what I mean?
