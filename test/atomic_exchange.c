/*
 * atomic_exchange
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

int int_val;

/*
 *     amoswap.w      a4,1,(a5)
 */
int test_atomic_exchange_relaxed()
{
    return atomic_exchange_explicit(&int_val, 1, memory_order_relaxed);
}

/*
 *     amoswap.w.aq   a4,1,(a5)
 */
int test_atomic_exchange_acquire()
{
    return atomic_exchange_explicit(&int_val, 1, memory_order_acquire);
}

/*
 *     amoswap.w.rl   a4,1,(a5)
 */
int test_atomic_exchange_release()
{
    return atomic_exchange_explicit(&int_val, 1, memory_order_release);
}

/*
 *     amoswap.w.aqrl a4,1,(a5)
 */
int test_atomic_exchange_acq_rel()
{
    return atomic_exchange_explicit(&int_val, 1, memory_order_acq_rel);
}

/*
 *     amoswap.w.aqrl a4,1,(a5)
 */
int test_atomic_exchange_seq_cst()
{
    return atomic_exchange_explicit(&int_val, 1, memory_order_seq_cst);
}
