#include "main.h"

int		main()
{
	cout << GREEN << "TEST 1:" << RESET << endl;
	solve_nonlinear_equation(test_1, test_d_1, 0, 1);

	cout << endl << GREEN << "TEST 2:" << RESET << endl;
	solve_nonlinear_equation(test_2, test_d_2, -1, 10);

	cout << endl << GREEN << "TEST 3:" << RESET << endl;
	solve_nonlinear_equation(test_3, test_d_3, 0, 1);

//	cout << endl << GREEN << "TEST 4:" << RESET << endl;
//	solve_nonlinear_equation(test_4_1, test_4_2, -10, 10);

//	cout << endl << GREEN << "TEST 5:" << RESET << endl;
//	solve_nonlinear_equation(test_5_1, test_5_1, -10, 10);

	return 0;
}
