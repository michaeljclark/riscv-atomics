CROSS_COMPILE   ?= riscv64-unknown-elf-

CC              = $(CROSS_COMPILE)gcc
CFLAGS          = -std=gnu11 -g -Wall -Wpedantic -O3 -Isrc -nostdinc \
		  -mcmodel=medany

GCC_ATOMIC_HDRS = src/stdatomic.h src/stdatomic_gcc.h
ASM_ATOMIC_HDRS = src/stdatomic.h src/stdatomic_asm.h

TESTS           = atomic_compare_exchange \
                  atomic_load \
                  atomic_store \
                  atomic_exchange \
                  atomic_fetch_add \
                  atomic_fetch_sub \
                  atomic_fetch_or \
                  atomic_fetch_xor \
                  atomic_fetch_and \
                  atomic_flag_test_and_set \
                  atomic_flag_clear \
                  atomic_thread_fence \
                  atomic_signal_fence

GCC_TEST_OBJS   = $(addsuffix _gcc.o,$(addprefix build/obj/,$(TESTS)))
ASM_TEST_OBJS   = $(addsuffix _asm.o,$(addprefix build/obj/,$(TESTS)))
ALL_TEST_OBJS   = $(GCC_TEST_OBJS) $(ASM_TEST_OBJS)

# build targets

all: tests

tests: $(ALL_TEST_OBJS)

clean: ; rm -fr build

# build rules

.PRECIOUS: build/obj/%.o

build/obj/%_gcc.o: test/%.c
	@echo CC $@ ; mkdir -p $(@D) ; $(CC) $(CFLAGS) -DATOMIC_ASM=0 -c -o $@ $<

build/obj/%_asm.o: test/%.c
	@echo CC $@ ; mkdir -p $(@D) ; $(CC) $(CFLAGS) -DATOMIC_ASM=1 -c -o $@ $<
