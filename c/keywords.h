#ifndef KEYWORDS_H
#define KEYWORDS_H

#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int id;
    char name[50];
} Person;

void aauto(void);
void break_continue(void);
void const_volatile(void);
void eenum(void);
void eextern(void);
void ggoto(void);
void if_else(void);
void for_loop(void);
void sswitch(void);
void struct_union(void);
void ttypedef(void);
void while_loop(void);
void ssizeof(void);
void sstatic(void);
// void iinline(void);
void rrestrict(void);
// void atomic(void);
void signed_unsigned(void);
void rregister(void);
void vvoid(void);
void rreturn(void);

#endif // KEYWORDS_H
