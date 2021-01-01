
// THIS CODE I WROTE TO FIND THE FIRST NUMBER COMPRIME WITH COMPOSITE
    unsigned long current_gcd;
    unsigned long iter = 1;
    do {
	iter++;
	current_gcd = euclidean_algorithm(*composite_number, iter);
	printf("Current GCD:\n");
	printf("%lu \u2229 %lu = %lu\n", *composite_number, iter, current_gcd);
    } while (current_gcd != 1);
    printf("First number coprime with the composite: %lu\n", iter);
