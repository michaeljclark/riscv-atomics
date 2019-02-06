/*
 * atomic_load
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include "test_template.h"

/*
 * l[b|h|w|d]        a4,0(a5)
 */
TEST_TEMPLATE_LOAD(atomic_load_explicit, int8_t, memory_order_relaxed)
TEST_TEMPLATE_LOAD(atomic_load_explicit, int16_t, memory_order_relaxed)
TEST_TEMPLATE_LOAD(atomic_load_explicit, int32_t, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_LOAD(atomic_load_explicit, int64_t, memory_order_relaxed)
#endif

/*
 * l[b|h|w|d]        a4,0(a5)
 * fence             r,rw
 */
TEST_TEMPLATE_LOAD(atomic_load_explicit, int8_t, memory_order_acquire)
TEST_TEMPLATE_LOAD(atomic_load_explicit, int16_t, memory_order_acquire)
TEST_TEMPLATE_LOAD(atomic_load_explicit, int32_t, memory_order_acquire)
#if __riscv_xlen == 64
TEST_TEMPLATE_LOAD(atomic_load_explicit, int64_t, memory_order_acquire)
#endif

/*
 * fence             rw,rw
 * l[b|h|w|d]        a4,0(a5)
 * fence             r,rw
 */
TEST_TEMPLATE_LOAD(atomic_load_explicit, int8_t, memory_order_seq_cst)
TEST_TEMPLATE_LOAD(atomic_load_explicit, int16_t, memory_order_seq_cst)
TEST_TEMPLATE_LOAD(atomic_load_explicit, int32_t, memory_order_seq_cst)
#if __riscv_xlen == 64
TEST_TEMPLATE_LOAD(atomic_load_explicit, int64_t, memory_order_seq_cst)
#endif
