#ifndef SOLVE_NONLINEAR_EQUATION_H
#define SOLVE_NONLINEAR_EQUATION_H

#include "../main.h"

/* функция для решения нелинейных уравнений  */
void	solve_nonlinear_equation(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);

/* функция для решения нелинейных систем уравнений  */
void	solve_nonlinear_equation(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	&f,
								 vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f_d,
								 vector<point3d> &x0, VALUE_TYPE a, VALUE_TYPE b);

vector<point>	create_table(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b);
vector<line_segment>	localization(vector<point> &table);

/* метод бисекции  */
point	bisection_method(VALUE_TYPE (*f)(VALUE_TYPE), point a, point b);

/* метод Ньютона для уравнений */
point	Newtons_method(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE (*f_d)(VALUE_TYPE), point a, point b);

/* метод Ньютона для систем уравнений */
point3d	Newtons_method(vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f,
						  vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)> &f_d,
						  point3d	x0, VALUE_TYPE a, VALUE_TYPE b,
						  string test_name, bool is_last, VALUE_TYPE step);

#endif
