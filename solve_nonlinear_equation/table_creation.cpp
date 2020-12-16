#include "solve_nonlinear_equation.h"

vector<point>	create_table(VALUE_TYPE (*fun)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b)
{
	vector<point>	table;

	for (VALUE_TYPE i = a; i <= b; i += STEP)
	{
		point	tmp;
		tmp.x = i;
		tmp.y = fun(i);

		table.push_back(tmp);
	}

	return table;
}

