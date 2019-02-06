/*
 * atomic_fetch_sub
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include "test_template.h"

/*
 * li                a4,-1
 * amoadd.[wd]       a0,a4,(a5)
 */
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int32_t, 1, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int64_t, 1, memory_order_relaxed)
#endif

/*
 * li                a4,-1
 * amoadd.[wd].aq    a0,a4,(a5)
 */
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int32_t, 1, memory_order_acquire)
#if __riscv_xlen == 64
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int64_t, 1, memory_order_acquire)
#endif

/*
 * li                a4,-1
 * amoadd.[wd].rl    a0,a4,(a5)
 */
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int32_t, 1, memory_order_release)
#if __riscv_xlen == 64
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int64_t, 1, memory_order_release)
#endif

/*
 * li                a4,-1
 * amoadd.[wd].aqrl  a0,a4,(a5)
 */
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int32_t, 1, memory_order_acq_rel)
#if __riscv_xlen == 64
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int64_t, 1, memory_order_acq_rel)
#endif

/*
 * li                a4,-1
 * amoadd.[wd].aqrl  a0,a4,(a5)
 */
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int32_t, 1, memory_order_seq_cst)
#if __riscv_xlen == 64
TEST_TEMPLATE_OP(atomic_fetch_sub_explicit, int64_t, 1, memory_order_seq_cst)
#endif
