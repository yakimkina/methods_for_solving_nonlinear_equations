#include "main.h"

/* аналитическая производная теста 1 */
VALUE_TYPE	test_d_1(VALUE_TYPE x)
{ return (0.121495 - 1.5119 * x + 5.9535 * pow(x, 2) - 9.28 * pow(x, 3) + 5 * pow(x, 4)); }

/* аналитическая производная теста 2 */
VALUE_TYPE	test_d_2(VALUE_TYPE x)
{ return 1 / (2 * sqrt(x + 1)); }

/* аналитическая производная теста 3 */
VALUE_TYPE	test_d_3(VALUE_TYPE x)
{ return (105 * pow(x, 2) - 134 * x - 3); }
