#include "solve_nonlinear_equation.h"

void	solve_nonlinear_equation(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b)
{
	vector<point>	table = create_table(f, a, b);
	vector<line_segment>	segments = localization(table);

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

void	solve_nonlinear_equation(VALUE_TYPE (*f1)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE (*f2)(VALUE_TYPE, VALUE_TYPE),
								 VALUE_TYPE a, VALUE_TYPE b)
{
	vector<point3D>	table = create_table(f1, f2, a, b);

}

