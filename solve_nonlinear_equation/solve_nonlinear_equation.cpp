#include "solve_nonlinear_equation.h"

void	solve_nonlinear_equation(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b)
{
	vector<point>	table = create_table(f, a, b); // создаем таблицу значений функции с шагом STEP
	vector<line_segment>	segments = localization(table); // локализация

	cout << GREEN << "количество корней уравнения: " << segments.size() << RESET << endl << endl;

	/* метод бисекции */
	cout << MAGENTA << "[МЕТОД БИCЕКЦИИ]" << RESET << endl;
	for (int i = 0; i < segments.size(); i++)
	{
		cout.precision(PREC);
		cout << MAGENTA << fixed << "отрезок локализации: [" << segments[i].a.x << ", " << segments[i].b.x << "], ";
		point	x_i = bisection_method(f, segments[i].a, segments[i].b);
		cout << MAGENTA << fixed  << "x[" << i << "] = " << x_i.x << ", f[x] = " << x_i.y << RESET << endl;
	}

	/* метод Ньютона */
	cout << endl << MAGENTA << "[МЕТОД  НЬЮТОНА]" << RESET << endl;
	for (int i = 0; i < segments.size(); i++)
	{
		cout.precision(PREC);
		cout << MAGENTA << fixed << "отрезок локализации: [" << segments[i].a.x << ", " << segments[i].b.x << "], ";
		point	x_i = Newtons_method(f, f_d, segments[i].a, segments[i].b);
		cout << MAGENTA << fixed << "x[" << i << "] = " << x_i.x << ", f[x] = " << x_i.y << RESET << endl;
	}
}

void	solve_nonlinear_equation(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	&f, // 2 функции системы
								 vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f_d, // 4 частные производные
								 vector<point3d> &x0, VALUE_TYPE a, VALUE_TYPE b)
{
	cout << GREEN << "количество корней уравнения: " << x0.size() << RESET << endl << endl;
	
	cout.precision(PREC);
	cout << endl << MAGENTA << fixed << "[МЕТОД  НЬЮТОНА] отрезок локализации: [" << a << ", " << b << "]:" << endl;

	for (int i = 0; i < x0.size(); i++)
	{
		cout << MAGENTA << fixed << "начальное приближение: (" << x0[i].x1 << ", " << x0[i].x2 << "), ";
		point3d	x_i = Newtons_method(f, f_d, x0[i], a, b, "", false);
		cout << MAGENTA << fixed << "x[" << i << "] = (" << x_i.x1 << ", " << x_i.x2 << "), f1[x] = " << x_i.y1 << ", f2[x] = " << x_i.y2 << endl;
	}
}

