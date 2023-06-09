/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __TC_UTIL_USER_OVERRIDE_H__
#define __TC_UTIL_USER_OVERRIDE_H__

/* This header provides a sample user override of various tc_util.h defines. */
#include "semihost_extra.h"

// // custom PRINT_DATA
#define PRINT_DATA(fmt, ...) semihost_log(fmt, ##__VA_ARGS__)
// #define TC_SUMMARY_PRINT(fmt, ...) semihost_log(fmt, ##__VA_ARGS__)

// /* Example: Reduce vertical line verbosity by
//  * redefining the separator to nothing.
//  */
// #define PRINT_LINE

// /* Example: Prepend test cases with a counter. */
// #define TC_START(original)                          \
//     do                                              \
//     {                                               \
//         static int count;                           \
//         printk("%d: Test [%s]", ++count, original); \
//     } while (0)

// /* Example: Change result string output formats. */
// #define TC_PASS_STR "Customized PASS"
// #define TC_FAIL_STR "Customized FAIL"
// #define TC_SKIP_STR "Customized SKIP"

// /* Example: Also count the number of pass/fail/skips and display it. */
// #define Z_TC_END_RESULT(result, s)                                         \
//     do                                                                     \
//     {                                                                      \
//         static int result_keeper[3] = {0};                                 \
//         result_keeper[result]++;                                           \
//         printk(" reported %s - %s in 0 seconds(No time counted) no. %d\n", \
//                TC_RESULT_TO_STR(result),                                   \
//                s,                                                          \
//                result_keeper[result]);                                     \
//     } while (0)

#endif /* __TC_UTIL_USER_OVERRIDE_H__ */
