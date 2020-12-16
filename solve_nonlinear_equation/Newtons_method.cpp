#include "solve_nonlinear_equation.h"

VALUE_TYPE	fun_d(VALUE_TYPE (*fun)(VALUE_TYPE), VALUE_TYPE x)
{ return (fun(x + EPSILON)- fun(x)) / EPSILON; }

point	Newtons_method(VALUE_TYPE (*fun)(VALUE_TYPE), point a, point b)
{
	int k = 1; // количество итераций

	point	x0;
	x0.x = (a.y * b.x - b.y * a.x) / (a.y - b.y);
	x0.y = fun(x0.x);

	point	xk;
	xk.x = x0.x - x0.y / fun_d(fun, x0.x);
	xk.y = fun(xk.x);
	while (abs(xk.x - x0.x) > EPSILON)
	{
		x0 = xk;
		xk.x = x0.x - x0.y / fun_d(fun, x0.x);
		xk.y = fun(xk.x);

		k += 1;
	}

	cout << MAGENTA << "количество итераций: " << k << ", " << RESET;

	return xk;
}

