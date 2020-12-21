#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#define WIDTH	8
#define PREC	8
#define STEP	0.02
#define EPSILON	0.000001

#define	TEST2	false
#define TEST3	false

#define ANAL_DIR	false

#define DIR		"output/"		

#define PRINT_STEPS	false
#define PRINT_CHECK	false

/* colorful output */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;

typedef double VALUE_TYPE;

struct	point
{
	VALUE_TYPE	x;
	VALUE_TYPE	y;
};

struct	line_segment
{
	point	a;
	point	b;
};

struct	point3D
{
	VALUE_TYPE	x1;
	VALUE_TYPE	x2;
	VALUE_TYPE	f1;
	VALUE_TYPE	f2;
};

VALUE_TYPE	test_1(VALUE_TYPE x);
VALUE_TYPE	test_2(VALUE_TYPE x);
VALUE_TYPE	test_3(VALUE_TYPE x);
VALUE_TYPE	test_4_1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_4_2(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_2(VALUE_TYPE x1, VALUE_TYPE x2);

VALUE_TYPE	test_d_1(VALUE_TYPE x);
VALUE_TYPE	test_d_2(VALUE_TYPE x);
VALUE_TYPE	test_d_3(VALUE_TYPE x);

#include "solve_nonlinear_equation/solve_nonlinear_equation.h"

void	print_vector(vector<VALUE_TYPE> x);
void 	print_slae(vector<vector<VALUE_TYPE>> slae, int m, int n); /* print SLAE with b vector */
void	print_slae(vector<vector<VALUE_TYPE>> &slae, int size); /* print SLAE without b vector */

#endif
