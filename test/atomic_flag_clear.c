/*
 * atomic_flag_clear
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include "test_template.h"

/*
 * slli              a0,a4,0x3
 * andi              a3,a0,24
 * li                a5,255
 * sllw              a5,a5,a3
 * andi              a4,a4,-4
 * not               a5,a5
 * amoand.[wd]       a0,a5,(a4)
 * srlw              a0,a0,a3
 * andi              a0,a0,255
 * snez              a0,a0
 */
_Bool test_atomic_flag_clear_relaxed()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_relaxed);
}

/*
 * ,,,
 * amoand.[wd].aq    a0,a5,(a4)
 * ,,,
 */
_Bool test_atomic_flag_clear_acquire()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_acquire);
}

/*
 * ,,,
 * amoand.[wd].rl    a0,a5,(a4)
 * ,,,
 */
_Bool test_atomic_flag_clear_release()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_release);
}

/*
 * ,,,
 * amoand.[wd].aqrl  a0,a5,(a4)
 * ,,,
 */
_Bool test_atomic_flag_clear_acq_rel()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_acq_rel);
}

/*
 * ,,,
 * amoand.[wd].aqrl  a0,a5,(a4)
 * ,,,
 */
_Bool test_atomic_flag_clear_seq_cst()
{
    return atomic_flag_clear_explicit(&flag_val, memory_order_seq_cst);
}
