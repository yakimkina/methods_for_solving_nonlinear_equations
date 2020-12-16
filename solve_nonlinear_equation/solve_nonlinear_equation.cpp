#include "solve_nonlinear_equation.h"

void	solve_nonlinear_equation(VALUE_TYPE (*fun)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b)
{
	vector<point>	table = create_table(fun, a, b);
	vector<line_segment>	segments = localization(table);

	cout << GREEN << "количество корней уравнения: " << RESET << segments.size() << endl << endl;

	/* метод бисекции */
	cout << MAGENTA << "[МЕТОД БИЕКЦИИ]" << RESET << endl;
	for (int i = 0; i < segments.size(); i++)
	{
		point	x_i = bisection_method(fun, segments[i].a, segments[i].b);
		cout.precision(PREC);
		cout << MAGENTA << "x[" << i << "] = " << RESET << x_i.x << endl;
	}

	/* метод Ньютона */
	


}


