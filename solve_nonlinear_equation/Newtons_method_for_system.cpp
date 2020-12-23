#include "solve_nonlinear_equation.h"

/* функции для построения прямой через две точки */
VALUE_TYPE	fun_x1(point3d x0, point3d xk, VALUE_TYPE x2)
{ return (xk.x1 - x0.x1) * (x2 - x0.x2) / (xk.x2 - x0.x2) + x0.x1; }

VALUE_TYPE	fun_x2(point3d x0, point3d xk, VALUE_TYPE x1)
{ return (xk.x2 - x0.x2) * (x1 - x0.x1) / (xk.x1 - x0.x1) + x0.x2; }

/* норма inf */
static VALUE_TYPE	norm_inf(point3d xk, point3d x0)
{
	VALUE_TYPE	del1 = abs(xk.x1 - x0.x1);
	VALUE_TYPE	del2 = abs(xk.x2 - x0.x2);
	VALUE_TYPE	max = (del1 > del2) ? del1 : del2;
	return max;
}

/* частные производные, численные */
vector<VALUE_TYPE>	find_curr_val_of_dir_iter(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f, int size, point3d x)
{
	vector<VALUE_TYPE> tmp(size);

	tmp[0] = f_d_x2_iter(f[1], x.x1, x.x2);
	tmp[1] = f_d_x2_iter(f[0], x.x1, x.x2);
	tmp[2] = f_d_x1_iter(f[1], x.x1, x.x2);
	tmp[3] = f_d_x1_iter(f[0], x.x1, x.x2);

	return tmp;
}

/* частные производные, аналитические */
vector<VALUE_TYPE>	find_curr_val_of_dir(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f_d, point3d x)
{
	vector<VALUE_TYPE> tmp;

	for (int i = 0; i < f_d.size(); i++)
		tmp.push_back(f_d[i](x.x1, x.x2));

	return tmp;
}

/* функция проверки выхода из области */
void	out_of_range_check(point3d &pnt, point3d &x0, VALUE_TYPE a, VALUE_TYPE b)
{
	if (pnt.x1 < a && abs(pnt.x2) < b)
	{
		pnt.x2 = (fun_x2(x0, pnt, a) + x0.x2) / 2;
		pnt.x1 = (a + x0.x1) / 2;
	}
	else if (pnt.x1 > b && abs(pnt.x2) < b)
	{
		pnt.x2 = (fun_x2(x0, pnt, b) + x0.x2) / 2;
		pnt.x1 = (b + x0.x1) / 2;
	}
	else if (pnt.x2 > b && abs(pnt.x1) < b)
	{
		pnt.x1 = (fun_x1(x0, pnt, b) + x0.x1) / 2;
		pnt.x2 = (b + x0.x2) / 2;
	}
	else if (pnt.x2 < a && abs(pnt.x1) < b)
	{
		pnt.x1 = (fun_x1(x0, pnt, a) + x0.x1) / 2;
		pnt.x2 = (a + x0.x2) / 2;
	}
	else if (pnt.x1 < a && pnt.x2 < 0)
	{
		VALUE_TYPE x1 = fun_x1(x0, pnt, a);
		VALUE_TYPE x2 = fun_x2(x0, pnt, a);
		if (abs(x1) < abs(x2))
		{
			pnt.x1 = (x1 + x0.x1) / 2;
			pnt.x2 = (a + x0.x2) / 2;
		}
		else
		{
			pnt.x1 = (a + x0.x1) / 2;
			pnt.x2 = (x2 + x0.x2) / 2;
		}
	}
	else if (pnt.x1 < a && pnt.x2 > 0)
	{
		VALUE_TYPE x1 = fun_x1(x0, pnt, (-1) * a);
		VALUE_TYPE x2 = fun_x2(x0, pnt, a);
		if (abs(x1) < abs(x2))
		{
			pnt.x1 = (x1 + x0.x1) / 2;
			pnt.x2 = ((-1) * a + x0.x2) / 2;
		}
		else
		{
			pnt.x1 = (a + x0.x1) / 2;
			pnt.x2 = (x2 + x0.x2) / 2;
		}
	}
	else if (pnt.x1 > b && pnt.x2 > 0)
	{
		VALUE_TYPE x1 = fun_x1(x0, pnt, b);
		VALUE_TYPE x2 = fun_x2(x0, pnt, b);
		if (abs(x1) < abs(x2))
		{
			pnt.x1 = (x1 + x0.x1) / 2;
			pnt.x2 = (b + x0.x2) / 2;
		}
		else
		{
			pnt.x1 = (b + x0.x1) / 2;
			pnt.x2 = (x2 + x0.x2) / 2;
		}
	}
	else if (pnt.x1 > b && pnt.x2 < 0)
	{
		VALUE_TYPE x1 = fun_x1(x0, pnt, (-1) * b);
		VALUE_TYPE x2 = fun_x2(x0, pnt, b);
		if (abs(x1) < abs(x2))
		{
			pnt.x1 = (x1 + x0.x1) / 2;
			pnt.x2 = ((-1) * b + x0.x2) / 2;
		}
		else
		{
			pnt.x1 = (b + x0.x1) / 2;
			pnt.x2 = (x2 + x0.x2) / 2;
		}
	}
}

/* запись в файл */
void	create_and_fill_file(point3d x0, int k, string &test_name, bool is_last)
{
	ofstream	file(DIR + test_name + "_diagram.csv", ios::app);

	file << k;
	if (!is_last) file << ", ";
	else file << endl;

	file.close();
}

point3d	Newtons_method(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f,
					   vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f_d,
					   point3d x0, VALUE_TYPE a, VALUE_TYPE b,
					   string test_name, bool is_last) // переменные для записи в файл
{
	int k = 0; // количество итераций

	point3d	x_zero, xk;
	x_zero = x0; // сохраняем начальное приближение(для вывода в файл)

	if (abs(x0.y1) < EPSILON && abs(x0.y2) < EPSILON)	// если начальное приближение совпало с корнем
		xk = x0;
	else
	{
		k += 1;

		/* матрица Якоби в текущей точке */
		vector<VALUE_TYPE>	curr_dir = (ANAL_DIR) ? find_curr_val_of_dir(f_d, x0) : find_curr_val_of_dir_iter(f, f_d.size(), x0);

		/* определитель матрицы Якоби в текущей точке */
		VALUE_TYPE	det = curr_dir[0] * curr_dir[3] - curr_dir[1] * curr_dir[2];
		if (det == 0)
		{
			cout << RED << endl << "[ERROR] det F(X^(k)) = 0" << RESET << endl;
			k = 30; // не заходим в цикл
		}
		else
		{
			xk.x1 = x0.x1 - (f[0](x0.x1, x0.x2) * curr_dir[0] - f[1](x0.x1, x0.x2) * curr_dir[1]) / det;
			xk.x2 = x0.x2 - ((-1) * f[0](x0.x1, x0.x2) * curr_dir[2] + f[1](x0.x1, x0.x2) * curr_dir[3]) / det;
			xk.y1 = f[0](xk.x1, xk.x2);
			xk.y2 = f[1](xk.x1, xk.x2);
			out_of_range_check(xk, x0, a, b);
		}

		while (norm_inf(xk, x0) > EPSILON && k < 30)
		{
			if (abs(xk.y1) < EPSILON && abs(xk.y2) < EPSILON) break;

			x0 = xk;

			curr_dir = (ANAL_DIR) ? find_curr_val_of_dir(f_d, x0) : find_curr_val_of_dir_iter(f, f_d.size(), x0);
			det = curr_dir[0] * curr_dir[3] - curr_dir[1] * curr_dir[2];
			if (det == 0)
			{
				cout << RED << endl << "[ERROR] det F(X^(k)) = 0" << RESET << endl;
				k = 30; // выходим из цикла
				break;
			}
			else
			{
				xk.x1 = x0.x1 - (f[0](x0.x1, x0.x2) * curr_dir[0] - f[1](x0.x1, x0.x2) * curr_dir[1]) / det;
				xk.x2 = x0.x2 - ((-1) * f[0](x0.x1, x0.x2) * curr_dir[2] + f[1](x0.x1, x0.x2) * curr_dir[3]) / det;

				out_of_range_check(xk, x0, a, b); // проверка выхода из области

				xk.y1 = f[0](xk.x1, xk.x2);
				xk.y2 = f[1](xk.x1, xk.x2);

				k += 1;
			}
		}
	}

	if (!DIAGRAM)
	{
		cout.precision(PREC);
		cout << MAGENTA << fixed << "количество итераций: " << k << ", " << RESET;
	}

	if (DIAGRAM) create_and_fill_file(x_zero, k, test_name, is_last);

	return xk;
}


