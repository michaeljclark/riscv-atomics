# RISC-V Atomics

This repository contains a standalone implementation of the C/C++ Atomic
operations library, one implementation using GCC compiler intrinsics,
as well as bare metal implementations using in-line assembly.

The assembly macros follow guidelines for mapping of C/C++ Atomic primitives
to the RISC-V atomic primitives, as outlined in _The RISC-V Instruction Set
Manual Volume I: Unprivileged ISA, Appendix A — RVWMO Explanatory Material,
Version 0.1, Section A.5 Code Porting and Mapping Guidelines, Table A.6:
Mappings from C/C++ primitives to RISC-V primitives._

The following versions of the C/C++ atomics are implemented in bare-metal
inline assembly based on the hitherto guidelines:

- atomic_compare_exchange
- atomic_fetch_add
- atomic_fetch_sub
- atomic_fetch_or
- atomic_fetch_xor
- atomic_fetch_and
- atomic_exchange
- atomic_load
- atomic_store

The follow versions of the C/C++ atomics currently only have mappings to
the GCC builtin atomics:

- atomic_flag_test_and_set
- atomic_flag_clear
- atomic_is_lock_free
- atomic_thread_fence
- atomic_signal_fence

The purpose of the repository is to test the GCC atomic builtins and compare
their output to hand-coded assembly constructed to match the atomic mappings
in the _RISC-V Instruction Set Manual Memory Model Guidelines_.

## Code Generation Tests

The following sections has extracts from some of the code generation tests.

### atomic_compare_exchange

_Examplar and test-case:_

```
/*
 * 0:  lr.w.aq      a0,(a5)
 *     bne          a0,a4,1f
 *     sc.w.rl      a2,a3,(a5)
 *     bnez         a2,0b
 * 1:
 */
int test_atomic_compare_exchange_strong_acq_rel()
{
    return atomic_compare_exchange_strong_explicit(&int_val, 0, 1,
    	memory_order_acq_rel, memory_order_relaxed);
}
```

_Visual inspection commands:_

```
riscv64-unknown-elf-objdump -d build/obj/atomic_compare_exchange_gcc.o
riscv64-unknown-elf-objdump -d build/obj/atomic_compare_exchange_asm.o
```

### atomic_load

_Examplar and test-case:_

```
/*
 *     lw       a4,0(a5)
 *     fence    r,rw
 */
void test_atomic_load_acquire()
{
    atomic_load_explicit(&int_val, memory_order_acquire);
}
```

_Visual inspection commands:_

```
riscv64-unknown-elf-objdump -d build/obj/atomic_load_gcc.o
riscv64-unknown-elf-objdump -d build/obj/atomic_load_asm.o
```

### atomic_store

_Examplar and test-case:_

```
/*
 *     fence    rw,w
 *     sw       a4,0(a5)
 */
void test_atomic_store_release()
{
    atomic_store_explicit(&int_val, 1, memory_order_release);
}
```

_Visual inspection commands:_

```
riscv64-unknown-elf-objdump -d build/obj/atomic_store_gcc.o
riscv64-unknown-elf-objdump -d build/obj/atomic_store_asm.o
```

### atomic_fetch_xor

_Examplar and test-case:_

```
/*
 *     amoxor.w.rl a4,1,(a5)
 */
int test_atomic_fetch_xor_release()
{
    return atomic_fetch_xor_explicit(&int_val, 1, memory_order_acq_rel);
}
```

_Visual inspection commands:_

```
riscv64-unknown-elf-objdump -d build/obj/atomic_fetch_xor_gcc.o
riscv64-unknown-elf-objdump -d build/obj/atomic_fetch_xor_asm.o
```
