#include "string.extended.h"

char *width_str_from_ul(unsigned long ul)
{ return _str_from_ul(ul, *width_); }

void LOOP_ul_parse_str(error_function_ error_function, ui start)
{
    LOOP_array = UL_array_of_SIZE(*array_size_);
    for (*i_ = 0; *i_ < *array_size_; (*i_)++) conditional_goodbye(n(n(error_specification(error_function, n(_ul_parse_str(LOOP_array + *i_, (*argv_ptr)[start + *i_], -(start + 1 + *i_)))))));
}

void LOOP_ul_parsed_strs()
{ fprintf(stdout, "%lu", LOOP_array[*i_]); if (*i_ + 1 == *array_size_) return; (*i_)++; fprintf(stdout, ", "); LOOP_ul_parsed_strs(); }
