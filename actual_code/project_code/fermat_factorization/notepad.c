unsigned long prime (potential_prime) {
    for (unsigned long i = 2; i <= (potential_prime - (potential_prime % 2)) / 2; i++)
	if (potential_prime % i == 0) /* If there is a divisor of potential_prime in between 1 and ((potential_prime - (potential_prime % 2)) / 2) */
	    return 1; /* <-- return 0, else --> */ return 0;
}

/* Some other bs */
    unsigned long prime_no = ADDITIVE_IDENTITY;
    unsigned int success_reading;
    do {
	success_reading = fscanf(filestream, "%s[\n]\n", prime_in_string); /* Increment prime_no --> */
	prime_in_table = string_to_unsigned_long(prime_in_string); prime_no++;
    } while ((success_reading == 1) && !(potential_prime > prime_in_table));

    if (potential_prime == prime_in_table) {
	fclose(filestream);
	return 0;
    } else if (potential_prime != prime_in_table) {
	fclose(filestream);
	return 1;
    }
