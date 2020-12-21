#include "solve_nonlinear_equation.h"

point	bisection_method(VALUE_TYPE (*f)(VALUE_TYPE), point a, point b)
{
	point	root;
	root.x = (a.x + b.x) / 2;
   	root.y = f(root.x);

   	VALUE_TYPE	x0 = root.x;
   	int k = 1; // количество итераций
	while (b.x - a.x > 2 * EPSILON)
	{
		if (abs(root.y) < EPSILON || abs(a.y) < EPSILON || abs(b.y) < EPSILON)
			break;
		
		if (a.y * root.y < 0)
		{
			b.x = root.x;
			b.y = root.y;
		}
		else
		{
			a.x = root.x;
			a.y = root.y;
		}

		root.x = (a.x + b.x) / 2;
		root.y = f(root.x);

		k += 1;
	}

	cout.precision(PREC);
	cout << MAGENTA << fixed << "количество итераций: " << k << ", начальное приближение: " << x0 << ", " << RESET;

	return root;
}

