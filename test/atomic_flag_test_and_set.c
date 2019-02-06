/*
 * atomic_flag_test_and_set
 *
 * The RISC-V Instruction Set Manual Volume I: Unprivileged ISA
 * . Appendix A — RVWMO Explanatory Material, Version 0.1
 * .. Section A.5 Code Porting and Mapping Guidelines
 * ... Table A.6: Mappings from C/C++ primitives to RISC-V primitives.
 */

#include "test_template.h"

/*
 * slli              a0,a5,0x3
 * andi              a4,a0,24
 * li                a3,1
 * andi              a5,a5,-4
 * sllw              a3,a3,a4
 * amoor.[wd]        a0,a3,(a5)
 * srlw              a0,a0,a4
 * andi              a0,a0,255
 * snez              a0,a0
 */
_Bool test_atomic_flag_test_and_set_relaxed()
{
    return atomic_flag_test_and_set_explicit(&flag_val, memory_order_relaxed);
}

/*
 * ,,,
 * amoor.[wd].aq     a0,a3,(a5)
 * ,,,
 */
_Bool test_atomic_flag_test_and_set_acquire()
{
    return atomic_flag_test_and_set_explicit(&flag_val, memory_order_acquire);
}

/*
 * ,,,
 * amoor.[wd].rl     a0,a3,(a5)
 * ,,,
 */
_Bool test_atomic_flag_test_and_set_release()
{
    return atomic_flag_test_and_set_explicit(&flag_val, memory_order_release);
}

/*
 * ,,,
 * amoor.[wd].aqrl   a0,a3,(a5)
 * ,,,
 */
_Bool test_atomic_flag_test_and_set_acq_rel()
{
    return atomic_flag_test_and_set_explicit(&flag_val, memory_order_acq_rel);
}

/*
 * ,,,
 * amoor.[wd].aqrl   a0,a3,(a5)
 * ,,,
 */
_Bool test_atomic_flag_test_and_set_seq_cst()
{
    return atomic_flag_test_and_set_explicit(&flag_val, memory_order_seq_cst);
}
