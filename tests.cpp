#include "main.h"

/* f(x) = (x - 0.1)(x - 0.22)(x - 0.55)(x - 0.7)(x - 0.75), x from 0 to 1 */
VALUE_TYPE	test_1(VALUE_TYPE x)
{ return (x - 0.1) * (x - 0.22) * (x - 0.55) * (x - 0.7) * (x - 0.75); }

/* f(x) = Sqrt(x + 1) - 1, x from -1 to 10 */
VALUE_TYPE	test_2(VALUE_TYPE x)
{ return sqrt(x + 1) - 1; }

/* f(x) = 35x^3 - 67x^2 - 3x + 3, x from 0 to 1 */
VALUE_TYPE	test_3(VALUE_TYPE x)
{ return 35 * pow(x, 3) - 67 * pow(x, 2) - 3 * x + 3; }

/* system:
 * f1 = x1^2 - x2^2 - 15
 * f2 = x1 * x2 + 4
 * */
VALUE_TYPE	test_4_1(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (pow(x1, 2) - pow(x2, 2) - 15); }
VALUE_TYPE	test_4_2(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (x1 * x2 + 4); }

/* system:
 * f1 = x1^2 + x2^2 + x1 + x2 - 8
 * f2 = x1^2 + x2^2 + x1 * x2 - 7
 * */
VALUE_TYPE	test_5_1(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (pow(x1, 2) + pow(x2, 2) + x1 + x2 - 8); }
VALUE_TYPE	test_5_2(VALUE_TYPE x1, VALUE_TYPE x2)
{ return (pow(x1, 2) + pow(x2, 2) + x1 * x2 - 7); }