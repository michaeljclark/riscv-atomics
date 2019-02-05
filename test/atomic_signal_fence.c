/*
 * atomic_signal_fence
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

/*
 *     <no output>
 */
void test_atomic_signal_fence_relaxed()
{
    atomic_signal_fence(memory_order_relaxed);
}

/*
 *     <no output>
 */
void test_atomic_signal_fence_acquire()
{
    atomic_signal_fence(memory_order_acquire);
}

/*
 *     <no output>
 */
void test_atomic_signal_fence_release()
{
    atomic_signal_fence(memory_order_release);
}

/*
 *     <no output>
 */
void test_atomic_signal_fence_acq_rel()
{
    atomic_signal_fence(memory_order_acq_rel);
}

/*
 *     <no output>
 */
void test_atomic_signal_fence_seq_cst()
{
    atomic_signal_fence(memory_order_seq_cst);
}
