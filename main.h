#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#define PREC	6	// точность вывода чисел( = кол-во знаков после запятой)
#define STEP	0.02   // шаг, с которым строим таблицу значений функции
#define EPSILON	0.000001    // точность нахождения решение, 10^-6 по методичке

#define	TEST2	false	// true если во 2 тесте берем нач. приближение x0 = 8
#define TEST3	false   // true если в 3 тесте берем нач. приближение x0 = 0

#define ANAL_DIR	true  // true если хотим вчислять производные аналитически, false если численно

#define DIR		"output/" // папка, в которую сохраняются файлы

#define PRINT_STEPS	false
#define PRINT_CHECK	false

/* цветной вывод */
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

struct	point	// точка
{
	VALUE_TYPE	x;
	VALUE_TYPE	y;
};

struct	line_segment   // отрезок
{
	point	a;
	point	b;
};

struct	point3d     // точка в 3х мерном пространстве
{
	VALUE_TYPE	x1;
	VALUE_TYPE	x2;
	VALUE_TYPE	y1;
	VALUE_TYPE	y2;
};

VALUE_TYPE	test(VALUE_TYPE x);
VALUE_TYPE	test_d(VALUE_TYPE x);

/* тестовые функции */
VALUE_TYPE	test_1(VALUE_TYPE x);
VALUE_TYPE	test_2(VALUE_TYPE x);
VALUE_TYPE	test_3(VALUE_TYPE x);
VALUE_TYPE	test_4_1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_4_2(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_2(VALUE_TYPE x1, VALUE_TYPE x2);

/* производные тестовых функций */
VALUE_TYPE	f_d_iter(VALUE_TYPE (*f)(VALUE_TYPE), VALUE_TYPE x);
VALUE_TYPE	f_d_x1_iter(VALUE_TYPE (*f)(VALUE_TYPE, VALUE_TYPE), VALUE_TYPE x1, const VALUE_TYPE x2);
VALUE_TYPE	f_d_x2_iter(VALUE_TYPE (*f)(VALUE_TYPE, VALUE_TYPE), const VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_d_1(VALUE_TYPE x);
VALUE_TYPE	test_d_2(VALUE_TYPE x);
VALUE_TYPE	test_d_3(VALUE_TYPE x);
VALUE_TYPE	test_4_1_x1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_4_1_x2(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_4_2_x1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_4_2_x2(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_1_x1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_1_x2(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_2_x1(VALUE_TYPE x1, VALUE_TYPE x2);
VALUE_TYPE	test_5_2_x2(VALUE_TYPE x1, VALUE_TYPE x2);

#include "solve_nonlinear_equation/solve_nonlinear_equation.h"

#endif
