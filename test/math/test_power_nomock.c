#ifdef TEST

#include "unity.h"

#include "power.h"
#include "exp.h"
#include "common.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_pow(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(pow(2.0, 2), pow_rtos(2.0, 2));
    TEST_ASSERT_EQUAL_DOUBLE(pow(-5.0, 2), pow_rtos(-5.0, 2));
    TEST_ASSERT_EQUAL_DOUBLE(pow(-5.0, -2), pow_rtos(-5.0, -2));
    TEST_ASSERT_EQUAL_DOUBLE(pow(123.567, 1.456), pow_rtos(123.567, 1.456));
    TEST_ASSERT_EQUAL_DOUBLE(pow(123.567, -1.456), pow_rtos(123.567, -1.456));
    TEST_ASSERT_EQUAL_DOUBLE(pow(123.567, -6), pow_rtos(123.567, -6));
}

#endif // TEST
