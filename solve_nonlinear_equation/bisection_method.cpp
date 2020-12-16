#include "solve_nonlinear_equation.h"

point	bisection_method(VALUE_TYPE (*fun)(VALUE_TYPE), point a, point b)
{
	point	root;
	root.x = (a.x+ b.x) / 2;
   	root.y = fun(root.x);

   	int k = 0; // количество итераций
	while (b.x - a.x >= 2 * EPSILON)
	{
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
		root.y = fun(root.x);

		k += 1;
	}

	cout << MAGENTA << "количество итераций: " << RESET << k << ", ";

	return root;
}

