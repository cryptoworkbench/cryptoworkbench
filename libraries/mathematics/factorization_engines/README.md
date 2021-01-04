This is some of the exceptionally beautiful code in this library.
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

The inflate function:
```c
struct pure_square *construct_square(unsigned long root, unsigned long square) {
    struct pure_square *constructed_number_pair_struct = (struct pure_square *) malloc(sizeof(struct pure_square));
    constructed_number_pair_struct->root = root;
    constructed_number_pair_struct->square = square;
    return constructed_number_pair_struct;
}
```
