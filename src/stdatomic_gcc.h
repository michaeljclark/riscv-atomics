// See LICENSE for license details.

#pragma once

#define atomic_flag_test_and_set(obj) \
    __atomic_test_and_set(obj, __ATOMIC_SEQ_CST)
#define atomic_flag_test_and_set_explicit(obj, order) \
    __atomic_test_and_set(obj, order)

#define atomic_flag_clear(obj) \
    __atomic_test_and_set(obj, __ATOMIC_SEQ_CST)
#define atomic_flag_clear_explicit(obj, order) \
    __atomic_test_and_set(obj, order)

#define atomic_is_lock_free(obj) \
    __atomic_is_lock_free(sizeof(obj), obj)

#define atomic_store(obj, val) \
    __atomic_store_n(obj, val, __ATOMIC_SEQ_CST)
#define atomic_store_explicit(obj, val, order) \
    __atomic_store_n(obj, val, order)

#define atomic_load(obj) \
    __atomic_load_n(obj, __ATOMIC_SEQ_CST)
#define atomic_load_explicit(obj,order) \
    __atomic_load_n(obj,order)

#define atomic_exchange(obj, val) \
    __atomic_exchange_n(obj, val, __ATOMIC_SEQ_CST)
#define atomic_exchange_explicit(obj, val, order) \
    __atomic_exchange_n(obj, val, order)

#define atomic_compare_exchange_strong(obj, exp, val) \
    __atomic_compare_exchange_n(obj, exp, val, 0, \
        __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#define atomic_compare_exchange_strong_explicit(obj, exp, val, succ, fail) \
    __atomic_compare_exchange_n(obj, exp, val, 0, succ, fail)

#define atomic_compare_exchange_weak(obj, exp, val) \
    __atomic_compare_exchange_n(obj, exp, val, 1, \
        __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#define atomic_compare_exchange_weak_explicit(obj, exp, val, succ, fail) \
    __atomic_compare_exchange_n(obj, exp, val, 1, succ, fail)

#define atomic_fetch_add(obj, arg) \
    __atomic_fetch_add(obj, arg, __ATOMIC_SEQ_CST)
#define atomic_fetch_add_explicit(obj, arg, order) \
    __atomic_fetch_add(obj, arg, order)

#define atomic_fetch_sub(obj, arg) \
    __atomic_fetch_sub(obj, arg, __ATOMIC_SEQ_CST)
#define atomic_fetch_sub_explicit(obj, arg, order) \
    __atomic_fetch_sub(obj, arg, order)

#define atomic_fetch_or(obj, arg) \
    __atomic_fetch_or(obj, arg, __ATOMIC_SEQ_CST)
#define atomic_fetch_or_explicit(obj, arg, order) \
    __atomic_fetch_or(obj, arg, order)

#define atomic_fetch_xor(obj, arg) \
    __atomic_fetch_xor(obj, arg, __ATOMIC_SEQ_CST)
#define atomic_fetch_xor_explicit(obj, arg, order) \
    __atomic_fetch_xor(obj, arg, order)

#define atomic_fetch_and(obj, arg) \
    __atomic_fetch_and(obj, arg, __ATOMIC_SEQ_CST)
#define atomic_fetch_and_explicit(obj, arg, order) \
    __atomic_fetch_and(obj, arg, order)

#define atomic_thread_fence(order) \
    __atomic_thread_fence(order)

#define atomic_signal_fence(order) \
    __atomic_signal_fence(order)
