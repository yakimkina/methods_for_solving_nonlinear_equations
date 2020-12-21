#ifndef SOLVE_NONLINEAR_EQUATION_H
#define SOLVE_NONLINEAR_EQUATION_H

#include "../main.h"

void	solve_nonlinear_equation(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);
void	solve_nonlinear_equation(VALUE_TYPE (*f1)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE (*f2)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);
vector<point>	create_table(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);
vector<point3D>	create_table(VALUE_TYPE (*f1)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE (*f2)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);
vector<line_segment>	localization(vector<point> &table);

point	bisection_method(VALUE_TYPE (*f)(VALUE_TYPE), point a, point b);
point	Newtons_method(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), point a, point b);

#endif
