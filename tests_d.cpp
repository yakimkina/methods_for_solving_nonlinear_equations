#include "main.h"

/* численная производная для одномерного случая */
VALUE_TYPE	f_d_iter(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE x)
{ return (f(x + EPSILON) - f(x)) / EPSILON; }

/* численная производная для двумерного случая */
VALUE_TYPE	f_d_x1_iter(VALUE_TYPE (*f)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE x1, const VALUE_TYPE x2)
{ return (f(x1 + EPSILON, x2) - f(x1, x2)) / EPSILON; }

/* численная производная для двумерного случая */
VALUE_TYPE	f_d_x2_iter(VALUE_TYPE (*f)(VALUE_TYPE, VALUE_TYPE), const VALUE_TYPE x1, VALUE_TYPE x2)
{ return (f(x1, x2 + EPSILON) - f(x1, x2)) / EPSILON; }

/* аналитическая производная теста 1 */
VALUE_TYPE	test_d_1(VALUE_TYPE x)
{ return (0.121495 - 1.5119 * x + 5.9535 * pow(x, 2) - 9.28 * pow(x, 3) + 5 * pow(x, 4)); }

/* аналитическая производная теста 2 */
VALUE_TYPE	test_d_2(VALUE_TYPE x)
{ return 1 / (2 * sqrt(x + 1)); }

/* аналитическая производная теста 3 */
VALUE_TYPE	test_d_3(VALUE_TYPE x)
{ return (105 * pow(x, 2) - 134 * x - 3); }

/* аналитическая производная теста 4 */
VALUE_TYPE	test_4_1_x1(VALUE_TYPE x1, VALUE_TYPE x2)
{ return 2 * x1; }
VALUE_TYPE	test_4_1_x2(VALUE_TYPE x1, VALUE_TYPE x2)
{ return -2 * x2; }
VALUE_TYPE	test_4_2_x1(VALUE_TYPE x1, VALUE_TYPE x2)
{ return x2; }
VALUE_TYPE	test_4_2_x2(VALUE_TYPE x1, VALUE_TYPE x2)
{ return x1; }

/* аналитическая производная теста 5 */
VALUE_TYPE	test_5_1_x1(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (2 * x1 + 1); }
VALUE_TYPE	test_5_1_x2(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (2 * x2 + 1); }
VALUE_TYPE	test_5_2_x1(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (2 * x1 + x2); }
VALUE_TYPE	test_5_2_x2(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (2 * x2 + x1); }