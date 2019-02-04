/*
 * atomic_fetch_xor
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

int int_val;

/*
 *     amoxor.w      a4,1,(a5)
 */
int test_atomic_fetch_xor_relaxed()
{
    return atomic_fetch_xor_explicit(&int_val, 1, memory_order_relaxed);
}

/*
 *     amoxor.w.aq   a4,1,(a5)
 */
int test_atomic_fetch_xor_acquire()
{
    return atomic_fetch_xor_explicit(&int_val, 1, memory_order_acquire);
}

/*
 *     amoxor.w.rl   a4,1,(a5)
 */
int test_atomic_fetch_xor_release()
{
    return atomic_fetch_xor_explicit(&int_val, 1, memory_order_release);
}

/*
 *     amoxor.w.aqrl a4,1,(a5)
 */
int test_atomic_fetch_xor_acq_rel()
{
    return atomic_fetch_xor_explicit(&int_val, 1, memory_order_acq_rel);
}

/*
 *     amoxor.w.aqrl a4,1,(a5)
 */
int test_atomic_fetch_xor_seq_cst()
{
    return atomic_fetch_xor_explicit(&int_val, 1, memory_order_seq_cst);
}
