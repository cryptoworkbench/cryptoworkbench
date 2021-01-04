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

This is the gist of it. What do ya think?
