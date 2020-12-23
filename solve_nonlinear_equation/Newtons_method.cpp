#include "solve_nonlinear_equation.h"

/* функция проверки выхода из области */
void	out_of_range_check(point &pnt, point a, point b, VALUE_TYPE (*f)(VALUE_TYPE))
{
	if (pnt.x < a.x)
	{
		pnt.x = (pnt.y * a.x - a.y * pnt.x) / (pnt.y - a.y);
		pnt.y = f(pnt.x);
	}
	else if (pnt.x > b.x)
	{
		pnt.x = (b.y * pnt.x - pnt.y * b.x) / (b.y - pnt.y);
		pnt.y = f(pnt.x);
	}
}

point	Newtons_method(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), point a, point b)
{
	int k = 0; // количество итераций

	/* выбор начального приближения */
	point	x0, xk;
	if (TEST2) x0.x = 8;
	else if (TEST3) x0.x = 0;
	else x0.x = (a.y * b.x - b.y * a.x) / (a.y - b.y);
	x0.y = f(x0.x);
	out_of_range_check(x0, a, b, f);

	VALUE_TYPE 	x_zero = x0.x; // сохраняем начальное приближение(для вывода на экран)

	if (abs(x0.y) < EPSILON)	// если начальное приближение совпало с корнем
		xk = x0;
	else
	{
		k += 1;

		xk.x = x0.x - x0.y / ((ANAL_DIR) ? f_d(x0.x) : f_d_iter(f, x0.x));
		xk.y = f(xk.x);

		while (abs(xk.x - x0.x) > EPSILON)
		{
			if (abs(xk.y) < EPSILON) break;
			out_of_range_check(xk, a, b, f); // проверка на выход из области

			x0 = xk;
			xk.x = x0.x - x0.y / ((ANAL_DIR) ? f_d(x0.x) : f_d_iter(f, x0.x));
			xk.y = f(xk.x);

			k += 1;
		}
	}

	cout.precision(PREC);
	cout << MAGENTA << fixed << "количество итераций: " << k << ", начальное приближение: " << x_zero << ", " << RESET;

	return xk;
}

