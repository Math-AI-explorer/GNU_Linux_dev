#include <check.h>
#include <stdio.h>
#include "../src/converter.h"

START_TEST(test_same_unit)
{
    int err = 0;
    double val = 100.0;
    double result = convert_temperature(val, UNIT_CELSIUS, UNIT_CELSIUS, &err);
    ck_assert_int_eq(err, 0);
    ck_assert_double_eq_tol(val, result, 1e-9);
}
END_TEST

START_TEST(test_c_to_f)
{
    int err = 0;
    double result = convert_temperature(0.0, UNIT_CELSIUS, UNIT_FAHRENHEIT, &err);
    ck_assert_int_eq(err, 0);
    ck_assert_double_eq_tol(result, 32.0, 1e-6);
}
END_TEST

START_TEST(test_invalid_unit)
{
    int err = 0;
    double result = convert_temperature(100.0, UNIT_UNKNOWN, UNIT_CELSIUS, &err);
    ck_assert_int_ne(err, 0);
    ck_assert_double_eq_tol(result, 0.0, 1e-9);
}
END_TEST

Suite* converter_suite(void)
{
    Suite *s = suite_create("converter");
    TCase *tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_same_unit);
    tcase_add_test(tc_core, test_c_to_f);
    tcase_add_test(tc_core, test_invalid_unit);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite *s = converter_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}