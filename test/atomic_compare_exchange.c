/*
 * atomic_compare_exchange_strong
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

int int_val;

/*
 * 0:  lr.w         a0,(a5)
 *     bne	        a0,a4,1f
 *     sc.w         a2,a3,(a5)
 *     bnez         a2,0b
 * 1:
 */
int test_atomic_compare_exchange_strong_relaxed()
{
    return atomic_compare_exchange_strong_explicit(&int_val, 0, 1,
    	memory_order_relaxed, memory_order_relaxed);
}

/*
 * 0:  lr.w.aq      a0,(a5)
 *     bne	        a0,a4,1f
 *     sc.w         a2,a3,(a5)
 *     bnez         a2,0b
 * 1:
 */
int test_atomic_compare_exchange_strong_acquire()
{
    return atomic_compare_exchange_strong_explicit(&int_val, 0, 1,
    	memory_order_acquire, memory_order_relaxed);
}

/*
 * 0:  lr.w         a0,(a5)
 *     bne	        a0,a4,1f
 *     sc.w.rl      a2,a3,(a5)
 *     bnez         a2,0b
 * 1:
 */
int test_atomic_compare_exchange_strong_release()
{
    return atomic_compare_exchange_strong_explicit(&int_val, 0, 1,
    	memory_order_release, memory_order_relaxed);
}

/*
 * 0:  lr.w.aq      a0,(a5)
 *     bne	        a0,a4,1f
 *     sc.w.rl      a2,a3,(a5)
 *     bnez         a2,0b
 * 1:
 */
int test_atomic_compare_exchange_strong_acq_rel()
{
    return atomic_compare_exchange_strong_explicit(&int_val, 0, 1,
    	memory_order_acq_rel, memory_order_relaxed);
}

/*
 * 0:  lr.w.aqrl    a0,(a5)
 *     bne	        a0,a4,1f
 *     sc.w.rl      a2,a3,(a5)
 *     bnez         a2,0b
 * 1:
 */
int test_atomic_compare_exchange_strong_seq_cst()
{
    return atomic_compare_exchange_strong_explicit(&int_val, 0, 1,
    	memory_order_seq_cst, memory_order_relaxed);
}
