#pragma once

#include <stdint.h>
#include <stdatomic.h>

#define CONCAT_3(sep,a,b,c) a##sep##b##sep##c
#define CONCAT_4(sep,a,b,c,d) a##sep##b##sep##c##sep##d
#define GLUE_X(a,b) a##b
#define GLUE(a,b) GLUE_X(a,b)

#define TEST_TEMPLATE_LOAD(func,type,order)                             \
type CONCAT_3(_,func,type,order)()                                      \
{                                                                       \
    return func(&GLUE(type,_val), order);                               \
}

#define TEST_TEMPLATE_OP(func,type,arg,order)                           \
type CONCAT_3(_,func,type,order)()                                      \
{                                                                       \
    return func(&GLUE(type,_val), arg, order);                          \
}

#define TEST_TEMPLATE_STORE(func,type,arg,order)                        \
void CONCAT_3(_,func,type,order)()                                      \
{                                                                       \
    func(&GLUE(type,_val), arg, order);                                 \
}

#define TEST_TEMPLATE_CMPXCHG(func,type,expected,desired,succ,fail)     \
type CONCAT_3(_,func,type,succ)()                                       \
{                                                                       \
    return func(&GLUE(type,_val), expected, desired, succ, fail);       \
}

atomic_flag flag_val;
int8_t  int8_t_val;
int16_t int16_t_val;
int32_t int32_t_val;
#if __riscv_xlen == 64
int64_t int64_t_val;
#endif
