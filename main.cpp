#include "main.h"

int		main()
{
	cout << GREEN << "TEST 1:" << RESET << endl;
	solve_nonlinear_equation(test_1, 0, 1);

	cout << endl << GREEN << "TEST 2:" << RESET << endl;
	solve_nonlinear_equation(test_2, -1, 10);

	cout << endl << GREEN << "TEST 3:" << RESET << endl;
	solve_nonlinear_equation(test_3, 0, 1);

	return 0;
}
