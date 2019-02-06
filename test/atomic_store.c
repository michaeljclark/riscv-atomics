/*
 * atomic_store
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include "test_template.h"

/*
 * li                a4,1
 * s[b|h|w|d]        a4,0(a5)
 */
TEST_TEMPLATE_STORE(atomic_store_explicit, int8_t, 1, memory_order_relaxed)
TEST_TEMPLATE_STORE(atomic_store_explicit, int16_t, 1, memory_order_relaxed)
TEST_TEMPLATE_STORE(atomic_store_explicit, int32_t, 1, memory_order_relaxed)
#if __riscv_xlen == 64
TEST_TEMPLATE_STORE(atomic_store_explicit, int64_t, 1, memory_order_relaxed)
#endif

/*
 * li                a4,1
 * fence             rw,w
 * s[b|h|w|d]        a4,0(a5)
 */
TEST_TEMPLATE_STORE(atomic_store_explicit, int8_t, 1, memory_order_release)
TEST_TEMPLATE_STORE(atomic_store_explicit, int16_t, 1, memory_order_release)
TEST_TEMPLATE_STORE(atomic_store_explicit, int32_t, 1, memory_order_release)
#if __riscv_xlen == 64
TEST_TEMPLATE_STORE(atomic_store_explicit, int64_t, 1, memory_order_release)
#endif

/*
 * li                a4,1
 * fence             rw,w
 * s[b|h|w|d]        a4,0(a5)
 */
TEST_TEMPLATE_STORE(atomic_store_explicit, int8_t, 1, memory_order_seq_cst)
TEST_TEMPLATE_STORE(atomic_store_explicit, int16_t, 1, memory_order_seq_cst)
TEST_TEMPLATE_STORE(atomic_store_explicit, int32_t, 1, memory_order_seq_cst)
#if __riscv_xlen == 64
TEST_TEMPLATE_STORE(atomic_store_explicit, int64_t, 1, memory_order_seq_cst)
#endif
