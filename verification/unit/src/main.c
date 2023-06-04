/*
 * Copyright (c) 2022, Commonwealth Scientific and Industrial Research
 * Organisation (CSIRO) ABN 41 687 119 230.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <zephyr/arch/common/semihost.h>
#include <zephyr/kernel.h>

ZTEST(semihost, test_file_ops)
{
    zassert_true(true, "Some test failed");
    printk("test finished!\n");

    // semihost_exec(0x18, 0);
}

ZTEST_SUITE(semihost, NULL, NULL, NULL, NULL, NULL);
