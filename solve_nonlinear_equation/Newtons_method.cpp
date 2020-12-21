#include "solve_nonlinear_equation.h"

VALUE_TYPE	f_d_iter(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE x)
{ return (f(x + EPSILON) - f(x)) / EPSILON; }

point	Newtons_method(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), point a, point b)
{
	int k = 1; // количество итераций

	point	x0;
	if (TEST2) x0.x = 8;
	else if (TEST3) x0.x = 0;
	else x0.x = (a.y * b.x - b.y * a.x) / (a.y - b.y);
	x0.y = f(x0.x);

	VALUE_TYPE 	x_zero = x0.x;

	point	xk;
	xk.x = x0.x - x0.y / ((ANAL_DIR) ? f_d(x0.x) : f_d_iter(f, x0.x));
	xk.y = f(xk.x);
	while (abs(xk.x - x0.x) > EPSILON)
	{
		if (abs(xk.y) < EPSILON)
			break;
		
		x0 = xk;

		if (xk.x < a.x) // выход за пределы отрезка локализации, метод хорд
			xk.x = (xk.y * a.x - a.y * xk.x) / (xk.y - a.y);
		else if (xk.x > b.x) // выход за пределы отрезка локализации, метод хорд
			xk.x = (b.y * xk.x - xk.y * b.x) / (b.y - xk.y);
		else // метод Ньютона
			xk.x = x0.x - x0.y / ((ANAL_DIR) ? f_d(x0.x) : f_d_iter(f, x0.x));

		xk.y = f(xk.x);

		k += 1;
	}

	cout.precision(PREC);
	cout << MAGENTA << fixed << "количество итераций: " << k << ", начальное приближение: " << x_zero << ", " << RESET;

	return xk;
}

