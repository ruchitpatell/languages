#ifndef UNDEFINED_BEHAVIOR_H
#define UNDEFINED_BEHAVIOR_H

void uninitialized_variable(void);
void division_by_zero(void);
void signed_integer_overflow(void);
void dereferencing_null_pointer(void);
void out_of_bounds_array_access(void);
void modifying_string_literal(void);
void use_after_free(void);
void strict_aliasing_violation(void);
int missing_return(void);
void invalid_bit_shift(void);
void modifying_const_data(void);
void passing_pointer_to_realloc(void);
void passing_pointer_to_free(void);
void memory_function_ub(void);

#endif // UNDEFINED_BEHAVIOR_H
