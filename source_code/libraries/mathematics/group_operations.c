// Group operation for addition under modular arithmetic
unsigned long _the_unary_operator_addition_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus) {
    unsigned long return_value = (generated_element + generating_element) % group_modulus;
    return return_value; }

// Group operation for multiplication under modular arithmetic
unsigned long _the_unary_operator_multiplication_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus) {
    unsigned long return_value = (generated_element * generating_element) % group_modulus;
    return return_value; }
