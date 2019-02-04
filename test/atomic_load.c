/*
 * atomic_load
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

int int_val;

/*
 *     lw       a4,0(a5)
 */
void test_atomic_load_relaxed()
{
    atomic_load_explicit(&int_val, memory_order_relaxed);
}

/*
 *     lw       a4,0(a5)
 *     fence    r,rw
 */
void test_atomic_load_acquire()
{
    atomic_load_explicit(&int_val, memory_order_acquire);
}

/*
 *     fence    rw,rw
 *     lw       a4,0(a5)
 *     fence    r,rw
 */
void test_atomic_load_seq_cst()
{
    atomic_load_explicit(&int_val, memory_order_seq_cst);
}
