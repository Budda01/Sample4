#include "s21_test.h"

START_TEST(calculation_test_1) {
  const char str[] = "12.311(31 + 12)/45 + 12.4235^5";
  double res = 295962.77055718104;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
}
END_TEST

START_TEST(calculation_test_2) {
  const char str[] = "2^2^3";
  double res = 256;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
}
END_TEST

START_TEST(calculation_test_3) {
  const char str[] = "123";
  double res = 123;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
}
END_TEST

START_TEST(calculation_test_4) {
  const char str[] = "12.123455+ 15432.4";
  double res = 15444.523455;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
}
END_TEST

START_TEST(calculation_test_5) {
  const char str[] = "sqrt(9)";
  double res = 3;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
END_TEST
}

START_TEST(calculation_test_6) {
  const char str[] = "ln(54)";
  double res = 3.9889840465642745;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_7) {
  const char str[] = "log(54)";
  double res = 1.73239375982296;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_8) {
  const char str[] = "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))3-(2+(1+1))(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  double res = -30.072164948453608;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_9) {
  const char str[] = "sin(0.31)/cos(0.4) + tan(1)";
  double res = 1.88861123715;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_10) {
  const char str[] = "atan(2)/2^2";
  double res = 0.2767871794485226;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_11) {
  const char str[] = "asin(1)";
  double res = 1.5707963267948966;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_12) {
  const char str[] = "(-(121+3454)*12)*12^2";
  double res = -6177600;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
END_TEST
}

START_TEST(calculation_test_13) {
  const char str[] = "acos(0)";
  double res = 1.5707963267948966;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_14) {
  const char str[] = "atan(0.031)";
  double res = 0.03099007538856943;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_15) {
  const char str[] = "(+(121+3454)*12/555)*12^2";
  double res = 11130.8108108108;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_le(fabs(res - output), EPS);
END_TEST
}

START_TEST(calculation_test_16) {
  const char str[] = "7 mod 4 mod 2";
  double res = 1;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
END_TEST
}

START_TEST(calculation_test_17) {
  const char str[] = "000100.23124";
  double res = 100.23124;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
END_TEST
}

START_TEST(calculation_test_18) {
  const char str[] = "0.23+ 0.21";
  double res = 0.44;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
END_TEST
}

START_TEST(calculation_test_19) {
  const char str[] = "12.333";
  double res = 12.333;
  double output = 0;
  s21_smart_calc(str, &output);
  ck_assert_int_eq(output, res);
END_TEST
}

Suite* s21_calculation_test(void) {
  Suite* s;
  s = suite_create("\033[33ms21_calculation\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_calculation_core");
  tcase_add_test(tc_core, calculation_test_1);
  tcase_add_test(tc_core, calculation_test_2);
  tcase_add_test(tc_core, calculation_test_3);
  tcase_add_test(tc_core, calculation_test_4);
  tcase_add_test(tc_core, calculation_test_5);
  tcase_add_test(tc_core, calculation_test_6);
  tcase_add_test(tc_core, calculation_test_7);
  tcase_add_test(tc_core, calculation_test_8);
  tcase_add_test(tc_core, calculation_test_9);
  tcase_add_test(tc_core, calculation_test_10);
  tcase_add_test(tc_core, calculation_test_11);
  tcase_add_test(tc_core, calculation_test_12);
  tcase_add_test(tc_core, calculation_test_13);
  tcase_add_test(tc_core, calculation_test_14);
  tcase_add_test(tc_core, calculation_test_15);
  tcase_add_test(tc_core, calculation_test_16);
  tcase_add_test(tc_core, calculation_test_17);
  tcase_add_test(tc_core, calculation_test_18);
  tcase_add_test(tc_core, calculation_test_19);
  suite_add_tcase(s, tc_core);

  return s;
}