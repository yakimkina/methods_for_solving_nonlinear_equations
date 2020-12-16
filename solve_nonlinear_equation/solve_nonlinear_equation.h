#ifndef SOLVE_NONLINEAR_EQUATION_H
#define SOLVE_NONLINEAR_EQUATION_H

#include "../main.h"

void	solve_nonlinear_equation(VALUE_TYPE (*fun)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);

vector<point>	create_table(VALUE_TYPE (*fun)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);
vector<line_segment>	localization(vector<point> table);

point	bisection_method(VALUE_TYPE (*fun)(VALUE_TYPE), point a, point b);
point	Newtons_method(VALUE_TYPE (*fun)(VALUE_TYPE), point a, point b);

#endif
