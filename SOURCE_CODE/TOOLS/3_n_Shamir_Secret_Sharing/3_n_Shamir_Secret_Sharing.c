/* This is a proof of concept for 3-n Shamir Secret Sharing (which is based on 2-nd degree polynomials over finite fields).
 *
 * This little project has been inspired by:
 * 1). https://www.youtube.com/watch?v=iFY5SyY3IMQ	"Secret Sharing Explained Visually" (yt channel "Art of the Problem")
 * 2). https://www.youtube.com/watch?v=K54ildEW9-Q	"How to keep an open secret with mathematics." (yt channel "Stand-up Maths")
 * 3). https://www.youtube.com/watch?v=ohc1futhFYM	"Equation of Parabola Given 3 Points (System of Equations)" (yt channel "Mario's Math Tutoring")
 */
#include <stdio.h>
#include <stdlib.h> // 'exit()'
#include <unistd.h> // 'execvp()'
#include <sys/wait.h> // 'waitpid()'
#include "../../libraries/functional/string.h"
ul MOD = 0;

unsigned long a, b, c;

struct linear_equation {
    unsigned long coefficient_a;
    unsigned long coefficient_b;
    unsigned long result;
};

struct cartesian_coordinates {
    unsigned long x;
    unsigned long y;
};

struct linear_equation multiply_values_by(struct linear_equation INP, unsigned long multiplier) {
    struct linear_equation return_value;
    return_value.coefficient_a = (multiplier * INP.coefficient_a) % MOD;
    return_value.coefficient_b = (multiplier * INP.coefficient_b) % MOD;
    return_value.result = (multiplier * INP.result) % MOD;
    return return_value;
}

struct linear_equation INV(struct linear_equation EQUATION) {
    struct linear_equation ret;
    ret.coefficient_a = additive_inverse(EQUATION.coefficient_a);
    ret.coefficient_b = additive_inverse(EQUATION.coefficient_b);
    ret.result = additive_inverse(EQUATION.result);
    return ret;
}

struct linear_equation ADD_equation(struct linear_equation equation_one, struct linear_equation equation_two) {
    struct linear_equation ret;
    ret.coefficient_a = equation_one.coefficient_a + equation_two.coefficient_a;
    ret.coefficient_b = equation_one.coefficient_b + equation_two.coefficient_b;
    ret.result = equation_one.result + equation_two.result;
    // ^^ Add equations

    ret.coefficient_a %= MOD;
    ret.coefficient_b %= MOD;
    ret.result %= MOD;
    // ^^ But do not forget we are doing algebra in a finite field

    return ret;
}
void C_reduce() { if (c >= MOD) { c%=MOD; fprintf(stdout, "The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", MOD, c); } }

char *one = "%s is not a suitable value for the field modulus!\n\nExiting '-%lu'.\n";
char *two = "%s is not a suitable value for the second-degree polynomial parameter 'a'!\n\nExiting '-%lu'.\n";
char *three = "%s is not a suitable value for the second-degree polynomial parameter 'b'!\n\nExiting '-%lu'.\n";
char *intermediate_error = "The value that I inferred from coordinate points for variable '%c' did not correspond to the variable '%c' that was used to plot the points. %lu != %lu. Exiting '-%lu'.\n";

void argv_ERROR(unsigned long index, char **argv) {
    char *error; switch (index) {
	case 1: error = one; break;
	case 2: error = two; break;
	case 3: error = three;
    }; fprintf(stderr, error, argv[index], index);
    exit(-index);
}


// Returns the multiplier needed to multiply 'first_equation' by, in order to have the coefficient that was passed to this program,
// become the additive inverse of the coefficient passed to this program as "coefficient_from_second_equation". VERY USEFUL.
unsigned long mod_LCM(unsigned long coefficient_from_first_equation, unsigned long coefficient_from_second_equation) { ul compounds = 1;
    ul compounded; for (compounded = coefficient_from_first_equation; compounded != additive_inverse(coefficient_from_second_equation); compounded = (compounded + coefficient_from_first_equation) % MOD) compounds++;
    return compounds;
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) argv_ERROR(1, argv); ignored_arguments(argc, argv, 1);
    fprintf(stdout, "Give me three (x, y)\n\nSuch that 'y \u2261 a * x^2 + b * x^1 + c (mod %lu)' (a, b, c \u2208 N)\n\n", MOD);

    struct cartesian_coordinates point_one, point_two, point_three;
    fprintf(stdout, "y_1 \u2261 "); fscanf(stdin, "%lu", &point_one.y);   fprintf(stdout, "x_1 \u2261 "); fscanf(stdin, "%lu", &point_one.x); fprintf(stdout, "\n");
    fprintf(stdout, "y_2 \u2261 "); fscanf(stdin, "%lu", &point_two.y);   fprintf(stdout, "x_2 \u2261 "); fscanf(stdin, "%lu", &point_two.x); fprintf(stdout, "\n");
    fprintf(stdout, "y_3 \u2261 "); fscanf(stdin, "%lu", &point_three.y); fprintf(stdout, "x_3 \u2261 "); fscanf(stdin, "%lu", &point_three.x); fprintf(stdout, "\n");
    // ^ Take in information

    struct linear_equation equation_a = { exponentiation(point_one.x, 2), exponentiation(point_one.x, 1), point_one.y};
    struct linear_equation equation_b = { exponentiation(point_two.x, 2), exponentiation(point_two.x, 1), point_two.y};
    struct linear_equation equation_c = { exponentiation(point_three.x, 2), exponentiation(point_three.x, 1), point_three.y};
    // fprintf(stdout, "\nEquation a:\n%lu = %lua + %lub\n", equation_a.result, equation_a.coefficient_a, equation_a.coefficient_b);
    // fprintf(stdout, "\nEquation b:\n%lu = %lua + %lub\n", equation_b.result, equation_b.coefficient_a, equation_b.coefficient_b);
    // fprintf(stdout, "\nEquation c:\n%lu = %lua + %lub\n", equation_c.result, equation_c.coefficient_a, equation_c.coefficient_b);

    struct linear_equation equation_a_and_b = ADD_equation(equation_a, INV(equation_b));
    struct linear_equation equation_b_and_c = ADD_equation(equation_b, INV(equation_c));
    // ^^ 

    unsigned long required_multiplier = mod_LCM(equation_a_and_b.coefficient_b, equation_b_and_c.coefficient_b);
    struct linear_equation INV_equation_a_and_b = multiply_values_by(equation_a_and_b, required_multiplier);
    struct linear_equation final_linear_equation = ADD_equation(INV_equation_a_and_b, equation_b_and_c);
    fprintf(stdout, "\nFinal linear equation:\n%lu = %lua + %lub\n", final_linear_equation.result, final_linear_equation.coefficient_a, final_linear_equation.coefficient_b);
    // ^^ Prepare all the required linear equations

    ul a = modular_division(final_linear_equation.result, final_linear_equation.coefficient_a) % MOD;
    ul b = modular_division((equation_a_and_b.result + (MOD - ((equation_a_and_b.coefficient_a * a) % MOD))) % MOD, equation_a_and_b.coefficient_b) % MOD;
    ul c = (equation_a.result + (MOD - (((b * point_one.x) % MOD ) + ((((point_one.x * point_one.x) % MOD ) * a) % MOD )) % MOD )) % MOD;

    fprintf(stdout, "Solutions:\n");
    fprintf(stdout, "%lu * %lu^2 + %lu * %lu + %lu \u2261 %lu\n", a, point_one.x, b, point_one.x, c, point_one.y);
    fprintf(stdout, "%lu * %lu^2 + %lu * %lu + %lu \u2261 %lu\n", a, point_two.x, b, point_two.x, c, point_two.y);
    fprintf(stdout, "%lu * %lu^2 + %lu * %lu + %lu \u2261 %lu\n\n", a, point_three.x, b, point_three.x, c, point_three.y);
    fprintf(stdout, "Second degree polynomial function over \U0001D53D%lu that maps %lu to %lu, %lu to %lu and %lu to %lu:\n", MOD, point_one.x, point_one.y, point_two.x, point_two.y, point_three.x, point_three.y);
    fprintf(stdout, "f(x) \u2261 %lu * x^2 + %lu * x + %lu	(%% %lu)\n", a, b, c, MOD);
    fprintf(stdout, "\nSolution:\n");
    fprintf(stdout, "f(0) \u2261 %lu * (0)^2 + %lu * (0)^1 + %lu \u2261 %lu * 0 + %lu * 0 + %lu \u2261 0 + 0 + %lu \u2261 %lu (%% %lu)\n\n", a, b, c, a, b, c, c, c, MOD);
    fprintf(stdout, "The secret  split / shared \\ encoded  is always the constant term in the polynomial, 'c' in this case; so the secret is (represented by) the numeric value '%lu'.\n", c);
    return 0;
}
