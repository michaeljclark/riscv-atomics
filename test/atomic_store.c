/*
 * atomic_store
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

int int_val;

/*
 *     sw       a4,0(a5)
 */
void test_atomic_store_relaxed()
{
    atomic_store_explicit(&int_val, 1, memory_order_relaxed);
}

/*
 *     fence    rw,w
 *     sw       a4,0(a5)
 */
void test_atomic_store_release()
{
    atomic_store_explicit(&int_val, 1, memory_order_release);
}

/*
 *     fence    rw,w
 *     sw       a4,0(a5)
 */
void test_atomic_store_seq_cst()
{
    atomic_store_explicit(&int_val, 1, memory_order_seq_cst);
}
