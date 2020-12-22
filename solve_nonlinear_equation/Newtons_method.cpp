#include "solve_nonlinear_equation.h"

VALUE_TYPE	fun_x1(point3d x0, point3d xk, VALUE_TYPE x2)
{ return (xk.x1 - x0.x1) * (x2 - x0.x2) / (xk.x2 - x0.x2) + x0.x1; }

VALUE_TYPE	fun_x2(point3d x0, point3d xk, VALUE_TYPE x1)
{ return (xk.x2 - x0.x2) * (x1 - x0.x1) / (xk.x1 - x0.x1) + x0.x2; }

static VALUE_TYPE	norm_inf(point3d xk, point3d x0)
{
	VALUE_TYPE	del1 = abs(xk.x1 - x0.x1);
	VALUE_TYPE	del2 = abs(xk.x2 - x0.x2);
	VALUE_TYPE	max = (del1 > del2) ? del1 : del2;
	return max;
}

vector<VALUE_TYPE>	find_curr_val_of_dir_iter(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f, int size, point3d x)
{
	vector<VALUE_TYPE> tmp(size);

	tmp[0] = f_d_x2_iter(f[1], x.x1, x.x2);
	tmp[1] = f_d_x2_iter(f[0], x.x1, x.x2);
	tmp[2] = f_d_x1_iter(f[1], x.x1, x.x2);
	tmp[3] = f_d_x1_iter(f[0], x.x1, x.x2);

	return tmp;
}

vector<VALUE_TYPE>	find_curr_val_of_dir(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f_d, point3d x)
{
	vector<VALUE_TYPE> tmp;

	for (int i = 0; i < f_d.size(); i++)
		tmp.push_back(f_d[i](x.x1, x.x2));

	return tmp;
}

point3d	Newtons_method(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f, vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f_d, point3d x0, VALUE_TYPE a, VALUE_TYPE b)
{
	int k = 1;

	vector<VALUE_TYPE>	curr_dir = (ANAL_DIR) ? find_curr_val_of_dir(f_d, x0) : find_curr_val_of_dir_iter(f, f_d.size(), x0);
	VALUE_TYPE	det = curr_dir[0] * curr_dir[2] - curr_dir[1] * curr_dir[3];

	point3d	xk;
	xk.x1 = x0.x1 - (f[0](x0.x1, x0.x2) * curr_dir[0] - f[1](x0.x1, x0.x2) * curr_dir[1]) / det;
	xk.x2 = x0.x2 - ((-1) * f[0](x0.x1, x0.x2) * curr_dir[2] + f[1](x0.x1, x0.x2) * curr_dir[3]) / det;
	xk.y1 = f[0](xk.x1, xk.x2);
	xk.y2 = f[1](xk.x1, xk.x2);
	while (norm_inf(xk, x0) > EPSILON && k < 100)
	{
		if (xk.y1 == 0 && xk.y2 == 0) break;

		// метод Ньютона
		x0 = xk;

		curr_dir = (ANAL_DIR) ? find_curr_val_of_dir(f_d, x0) : find_curr_val_of_dir_iter(f, f_d.size(), x0);
		det = curr_dir[0] * curr_dir[2] - curr_dir[1] * curr_dir[3];

		xk.x1 = x0.x1 - (f[0](x0.x1, x0.x2) * curr_dir[0] - f[1](x0.x1, x0.x2) * curr_dir[1]) / det;
		xk.x2 = x0.x2 - ((-1) * f[0](x0.x1, x0.x2) * curr_dir[2] + f[1](x0.x1, x0.x2) * curr_dir[3]) / det;

		if (xk.x1 < a && abs(xk.x2) < b)
		{
			xk.x2 = fun_x2(x0, xk, a);
			xk.x1 = a;
		}
		else if (xk.x1 > b && abs(xk.x2) < b)
		{
			xk.x2 = fun_x2(x0, xk, b);
			xk.x1 = b;
		}
		else if (xk.x2 > b && abs(xk.x1) < b)
		{
			xk.x1 = fun_x1(x0, xk, b);
			xk.x2 = b;
		}
		else if (xk.x2 < a && abs(xk.x1) < b)
		{
			xk.x1 = fun_x1(x0, xk, a);
			xk.x2 = a;
		}
		else if (xk.x1 < a && xk.x2 < 0)
		{
			VALUE_TYPE x1 = fun_x1(x0, xk, a);
			VALUE_TYPE x2 = fun_x2(x0, xk, a);
			if (abs(x1) < abs(x2))
			{
				xk.x1 = x1;
				xk.x2 = a;
			}
			else
			{
				xk.x1 = a;
				xk.x2 = x2;
			}
		}
		else if (xk.x1 < a && xk.x2 > 0)
		{
			VALUE_TYPE x1 = fun_x1(x0, xk, (-1) * a);
			VALUE_TYPE x2 = fun_x2(x0, xk, a);
			if (abs(x1) < abs(x2))
			{
				xk.x1 = x1;
				xk.x2 = (-1) * a;
			}
			else
			{
				xk.x1 = a;
				xk.x2 = x2;
			}
		}
		else if (xk.x1 > b && xk.x2 > 0)
		{
			VALUE_TYPE x1 = fun_x1(x0, xk, b);
			VALUE_TYPE x2 = fun_x2(x0, xk, b);
			if (abs(x1) < abs(x2))
			{
				xk.x1 = x1;
				xk.x2 = b;
			}
			else
			{
				xk.x1 = b;
				xk.x2 = x2;
			}
		}
		else if (xk.x1 > b && xk.x2 < 0)
		{
			VALUE_TYPE x1 = fun_x1(x0, xk, (-1) * b);
			VALUE_TYPE x2 = fun_x2(x0, xk, b);
			if (abs(x1) < abs(x2))
			{
				xk.x1 = x1;
				xk.x2 = (-1) * b;
			}
			else
			{
				xk.x1 = b;
				xk.x2 = x2;
			}
		}

		xk.y1 = f[0](xk.x1, xk.x2);
		xk.y2 = f[1](xk.x1, xk.x2);

		k += 1;
	}
	
	cout.precision(PREC);
	cout << MAGENTA << fixed << "количество итераций: " << k << ", " << RESET;
	point3d xcurr = xk;
//	return xk;
	return xcurr;
}

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
//	while (xk.x < a.x || xk.x > b.x)
//	{
		if (xk.x < a.x) // выход за пределы отрезка локализации, метод хорд
			xk.x = (xk.y * a.x - a.y * xk.x) / (xk.y - a.y);
		else if (xk.x > b.x) // выход за пределы отрезка локализации, метод хорд
			xk.x = (b.y * xk.x - xk.y * b.x) / (b.y - xk.y);
//	}
	xk.y = f(xk.x);

	while (abs(xk.x - x0.x) > EPSILON)
	{
		if (xk.y == 0) break;
		
		if (xk.x < a.x) // выход за пределы отрезка локализации, метод хорд
			xk.x = (xk.y * a.x - a.y * xk.x) / (xk.y - a.y);
		else if (xk.x > b.x) // выход за пределы отрезка локализации, метод хорд
			xk.x = (b.y * xk.x - xk.y * b.x) / (b.y - xk.y);

		// метод Ньютона
		x0 = xk;
		xk.x = x0.x - x0.y / ((ANAL_DIR) ? f_d(x0.x) : f_d_iter(f, x0.x));
		xk.y = f(xk.x);
//		cout << "|xk = " << xk.x << "|, ";
		k += 1;
	}

	cout.precision(PREC);
	cout << MAGENTA << fixed << "количество итераций: " << k << ", начальное приближение: " << x_zero << ", " << RESET;

	return xk;
}

