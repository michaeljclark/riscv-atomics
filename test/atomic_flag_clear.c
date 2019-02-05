/*
 * atomic_flag_clear
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include <stdatomic.h>

atomic_flag flag_val;

/*
 *     slli     a0,a4,0x3
 *     andi     a3,a0,24
 *     li       a5,255
 *     sllw     a5,a5,a3
 *     andi     a4,a4,-4
 *     not      a5,a5
 *     amoand.w a0,a5,(a4)
 *     srlw     a0,a0,a3
 *     andi     a0,a0,255
 *     snez     a0,a0
 */
_Bool test_atomic_flag_clear_relaxed()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_relaxed);
}

/*
 *     ,,,
 *     amoand.w.aq a0,a5,(a4)
 *     ,,,
 */
_Bool test_atomic_flag_clear_acquire()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_acquire);
}

/*
 *     ,,,
 *     amoand.w.rl a0,a5,(a4)
 *     ,,,
 */
_Bool test_atomic_flag_clear_release()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_release);
}

/*
 *     ,,,
 *     amoand.w.aqrl a0,a5,(a4)
 *     ,,,
 */
_Bool test_atomic_flag_clear_acq_rel()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_acq_rel);
}

/*
 *     ,,,
 *     amoand.w.aqrl a0,a5,(a4)
 *     ,,,
 */
_Bool test_atomic_flag_clear_seq_cst()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_seq_cst);
}
