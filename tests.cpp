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

/* y = (4x^3 + 2x^2 - 4x + 2)^√2 + arcsin(1 / (5 + x - x^2)) - 5 */
//VALUE_TYPE	test_4(VALUE_TYPE x)
//{
//	VALUE_TYPE	x2 = pow(x, 2);
//	return (pow((4 * pow(x, 3) + 2 * x2 - 4 * x + 2), sqrt(2)) +
//	asin(1 / (5 + x - x2)) - 5);
//}


