# RISC-V Atomics

This repository contains a standalone implementation of the C/C++ Atomic
operations library; one implementation using GCC compiler intrinsics,
and another implementation using in-line assembly.

The assembly macros follow guidelines for mapping C/C++ Atomic primitives
to the RISC-V atomic primitives, as outlined in _The RISC-V Instruction Set
Manual Volume I: Unprivileged ISA, Appendix A — RVWMO Explanatory Material,
Version 0.1, Section A.5 Code Porting and Mapping Guidelines, Table A.6:
Mappings from C/C++ primitives to RISC-V primitives._

The following versions of the C/C++ atomics are implemented in bare-metal
inline assembly based on those guidelines:

- atomic_compare_exchange
- atomic_fetch_add
- atomic_fetch_sub
- atomic_fetch_or
- atomic_fetch_xor
- atomic_fetch_and
- atomic_exchange
- atomic_load
- atomic_store
- atomic_flag_test_and_set
- atomic_flag_clear
- atomic_thread_fence
- atomic_signal_fence

## Dependencies

A recent version of `riscv-gnu-toolchin` with a multilib build of RISC-V GCC.

- [riscv-gnu-toolchain](https://github.com/riscv/riscv-gnu-toolchain)

## Code Generation Tests

The primary purpose of the repository is to test the GCC atomic builtins and
allow comparison of their output with hand-coded assembly versions that have
been constructed to match the atomic mappings in the _RISC-V Instruction Set
Manual Memory Model Guidelines_.

The `test` directory contains code generation test macros along with assembly
language exemplars. The `Makefile` is set up to compile using the RISC-V GCC
compiler intrinsics (`-DATOMIC_ASM=0`), or the in-line assembly versions
(`-DATOMIC_ASM=1`).  To build the tests, type `make`:

```
$ make
```

There currently are no automated tests, thus visually inspection must be used
to compare against the exemplars in the _RISC-V Instruction Set Manual Memory
Model Guidelines_, the test-case comments, the object code emitted by the
GCC compiler intrinsics, and lastly, the object code generated by the
hand-coded versions. The following files should be output:

```
atomic_compare_exchange_asm.txt
atomic_compare_exchange_gcc.txt
atomic_exchange_asm.txt
atomic_exchange_gcc.txt
atomic_fetch_add_asm.txt
atomic_fetch_add_gcc.txt
atomic_fetch_and_asm.txt
atomic_fetch_and_gcc.txt
atomic_fetch_or_asm.txt
atomic_fetch_or_gcc.txt
atomic_fetch_sub_asm.txt
atomic_fetch_sub_gcc.txt
atomic_fetch_xor_asm.txt
atomic_fetch_xor_gcc.txt
atomic_flag_clear_asm.txt
atomic_flag_clear_gcc.txt
atomic_flag_test_and_set_asm.txt
atomic_flag_test_and_set_gcc.txt
atomic_load_asm.txt
atomic_load_gcc.txt
atomic_signal_fence_asm.txt
atomic_signal_fence_gcc.txt
atomic_store_asm.txt
atomic_store_gcc.txt
atomic_thread_fence_asm.txt
atomic_thread_fence_gcc.txt
```
