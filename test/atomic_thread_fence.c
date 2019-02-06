/*
 * atomic_thread_fence
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include "test_template.h"

/*
 * <no output>
 */
void test_atomic_thread_fence_relaxed()
{
    atomic_thread_fence(memory_order_relaxed);
}

/*
 * fence             r,rw
 */
void test_atomic_thread_fence_acquire()
{
    atomic_thread_fence(memory_order_acquire);
}

/*
 * fence             rw,w
 */
void test_atomic_thread_fence_release()
{
    atomic_thread_fence(memory_order_release);
}

/*
 * fence.tso
 *
 * Note: fence.tso is unimplemented so this currently emits fence rw,rw
 */
void test_atomic_thread_fence_acq_rel()
{
    atomic_thread_fence(memory_order_acq_rel);
}

/*
 * fence             rw,rw
 */
void test_atomic_thread_fence_seq_cst()
{
    atomic_thread_fence(memory_order_seq_cst);
}
