/*
 * atomic_compare_exchange_strong
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include "test_template.h"

/*
 * 0:  lr.[wd]       a0,(a5)
 *     bne	         a0,a4,1f
 *     sc.[wd]       a2,a3,(a5)
 *     bnez          a2,0b
 * 1:
 */
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int32_t, 0, 1,
	memory_order_relaxed, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int64_t, 0, 1,
	memory_order_relaxed, memory_order_relaxed)
#endif

/*
 * 0:  lr.[wd].aq    a0,(a5)
 *     bne	         a0,a4,1f
 *     sc.[wd]       a2,a3,(a5)
 *     bnez          a2,0b
 * 1:
 */
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int32_t, 0, 1,
	memory_order_acquire, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int64_t, 0, 1,
	memory_order_acquire, memory_order_relaxed)
#endif

/*
 * 0:  lr.[wd]       a0,(a5)
 *     bne	         a0,a4,1f
 *     sc.[wd].rl    a2,a3,(a5)
 *     bnez          a2,0b
 * 1:
 */
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int32_t, 0, 1,
	memory_order_release, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int64_t, 0, 1,
	memory_order_release, memory_order_relaxed)
#endif

/*
 * 0:  lr.[wd].aq    a0,(a5)
 *     bne	         a0,a4,1f
 *     sc.[wd].rl    a2,a3,(a5)
 *     bnez          a2,0b
 * 1:
 */
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int32_t, 0, 1,
	memory_order_acq_rel, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int64_t, 0, 1,
	memory_order_acq_rel, memory_order_relaxed)
#endif

/*
 * 0:  lr.[wd].aqrl  a0,(a5)
 *     bne	         a0,a4,1f
 *     sc.[wd].rl    a2,a3,(a5)
 *     bnez          a2,0b
 * 1:
 */
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int32_t, 0, 1,
	memory_order_seq_cst, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_CMPXCHG(atomic_compare_exchange_strong_explicit, int64_t, 0, 1,
	memory_order_seq_cst, memory_order_relaxed)
#endif
