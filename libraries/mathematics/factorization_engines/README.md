This is some of the especially beautiful code here:
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

return factors;
```
