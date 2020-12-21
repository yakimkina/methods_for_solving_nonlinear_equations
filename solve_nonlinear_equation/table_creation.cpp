#include "solve_nonlinear_equation.h"

vector<point>	create_table(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b)
{
	vector<point>	table;

	for (VALUE_TYPE i = a; i <= b; i += STEP)
	{
		point	tmp;
		tmp.x = i;
		tmp.y = f(i);

		table.push_back(tmp);
	}

	return table;
}

vector<point3D>	create_table(VALUE_TYPE (*f1)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE (*f2)(VALUE_TYPE, VALUE_TYPE),
								VALUE_TYPE a, VALUE_TYPE b)
{
	vector<point3D>	table;

	for (VALUE_TYPE i = a; i <= b; i += STEP)
	{
		point3D	tmp;
		tmp.x1 = i;
		tmp.x2 = i;
		tmp.f1 = f1(i, i);
		tmp.f2 = f2(i, i);

		table.push_back(tmp);
	}

	return table;
}
