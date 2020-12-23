#include "solve_nonlinear_equation.h"

point	bisection_method(VALUE_TYPE (*f)(VALUE_TYPE), point a, point b)
{
	int k = 0; // количество итераций

	point	root; // искомый корень уравнения
	VALUE_TYPE	x0; // сохраняем начальное приближение(для вывода на экран)


	/* случай, когда ноль лежит в самой правой границе отрезка (в дальнейшем
 	* алгоритм построен так, что значения в правых точках будут смотреться
 	* на этапе подсчета root.y, то есть на итерацию раньше, и смысла проверять
 	* значени b на каждой итерации нет) */
	if (abs(b.y) < EPSILON)
	{
		root.x = b.x;
		root.y = b.y;
		x0 = root.x;
	}
	else
	{
		root.x = (a.x + b.x) / 2;
   		root.y = f(root.x);
		x0 = root.x;

		while (b.x - a.x > 2 * EPSILON)
		{
			if (abs(a.y) < EPSILON)	// левая граница отрезка совпала с нулем функции
			{
				root.x = a.x;
				root.y = a.y;
				break;
			}
			else if (abs(root.y) < EPSILON)	// правая граница отрезка совпала с нулем функции
				break;
			else if (a.y * root.y < 0)
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
	}

	cout.precision(PREC);
	cout << MAGENTA << fixed << "количество итераций: " << k << ", начальное приближение: " << x0 << ", " << RESET;

	return root;
}

