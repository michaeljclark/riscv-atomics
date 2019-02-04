/*
 * atomic_fetch_or
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

int int_val;

/*
 *     amoor.w      a4,1,(a5)
 */
int test_atomic_fetch_or_relaxed()
{
    return atomic_fetch_or_explicit(&int_val, 1, memory_order_relaxed);
}

/*
 *     amoor.w.aq   a4,1,(a5)
 */
int test_atomic_fetch_or_acquire()
{
    return atomic_fetch_or_explicit(&int_val, 1, memory_order_acquire);
}

/*
 *     amoor.w.rl   a4,1,(a5)
 */
int test_atomic_fetch_or_release()
{
    return atomic_fetch_or_explicit(&int_val, 1, memory_order_release);
}

/*
 *     amoor.w.aqrl a4,1,(a5)
 */
int test_atomic_fetch_or_acq_rel()
{
    return atomic_fetch_or_explicit(&int_val, 1, memory_order_acq_rel);
}

/*
 *     amoor.w.aqrl a4,1,(a5)
 */
int test_atomic_fetch_or_seq_cst()
{
    return atomic_fetch_or_explicit(&int_val, 1, memory_order_seq_cst);
}
