#include "main.h"

int		main()
{
	if (!TEST2 && !TEST3)
	{
		cout << GREEN << "TEST 1:" << RESET << endl;
		solve_nonlinear_equation(test_1, test_d_1, 0, 1);
	}

	if (!TEST3)
	{
		cout << endl << GREEN << "TEST 2:" << RESET << endl;
		solve_nonlinear_equation(test_2, test_d_2, -1, 10);
	}

	if (!TEST2)
	{
		cout << endl << GREEN << "TEST 3:" << RESET << endl;
		solve_nonlinear_equation(test_3, test_d_3, 0, 1);
	}

	// начальное приближение  [тест 4]
	vector<point3d>	x0_t4;
	point3d	p1_t4, p2_t4;
	p1_t4.x1 = 3.7; p1_t4.x2 = -0.7; p1_t4.y1 = test_4_1(p1_t4.x1, p1_t4.x2); p1_t4.y2 = test_4_2(p1_t4.x1, p1_t4.x2);
	p2_t4.x1 = -3.7; p2_t4.x2 = 0.7; p2_t4.y1 = test_4_1(p2_t4.x1, p2_t4.x2); p2_t4.y2 = test_4_2(p2_t4.x1, p2_t4.x2);
	x0_t4.push_back(p1_t4);
	x0_t4.push_back(p2_t4);

	// система уравнений
	vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	f_t4;
	f_t4.push_back(test_4_1);
	f_t4.push_back(test_4_2);

	// элементы обратной матрицы Якоби
	vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	f_d_t4;
	f_d_t4.push_back(test_4_2_x2);
	f_d_t4.push_back(test_4_1_x2);
	f_d_t4.push_back(test_4_2_x1);
	f_d_t4.push_back(test_4_1_x1);

	cout << endl << GREEN << "TEST 4:" << RESET << endl;
	solve_nonlinear_equation(f_t4, f_d_t4, x0_t4, -10, 10);


	// начальное приближение [тест 5]
	vector<point3d>	x0_t5;
	point3d	p1_t5, p2_t5, p3_t5, p4_t5;
	p1_t5.x1 = -3.5; p1_t5.x2 = 0.7; p1_t5.y1 = test_5_1(p1_t5.x1, p1_t5.x2); p1_t5.y2 = test_5_2(p1_t5.x1, p1_t5.x2);
	p2_t5.x1 = 1.2; p2_t5.x2 = -2.5; p2_t5.y1 = test_5_1(p2_t5.x1, p2_t5.x2); p2_t5.y2 = test_5_2(p2_t5.x1, p2_t5.x2);
	p3_t5.x1 = 0.8; p3_t5.x2 = 2.4; p3_t5.y1 = test_5_1(p3_t5.x1, p3_t5.x2); p3_t5.y2 = test_5_2(p3_t5.x1, p3_t5.x2);
	p4_t5.x1 = 1.8; p4_t5.x2 = 0.5; p4_t5.y1 = test_5_1(p4_t5.x1, p4_t5.x2); p4_t5.y2 = test_5_2(p4_t5.x1, p4_t5.x2);
	x0_t5.push_back(p1_t5);
	x0_t5.push_back(p2_t5);
	x0_t5.push_back(p3_t5);
	x0_t5.push_back(p4_t5);

	// система уравнений
	vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	f_t5;
	f_t5.push_back(test_5_1);
	f_t5.push_back(test_5_2);

	// элементы обратной матрицы Якоби
	vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	f_d_t5;
	f_d_t5.push_back(test_5_2_x2);
	f_d_t5.push_back(test_5_1_x2);
	f_d_t5.push_back(test_5_2_x1);
	f_d_t5.push_back(test_5_1_x1);

	cout << endl << GREEN << "TEST 5:" << RESET << endl;
	solve_nonlinear_equation(f_t5, f_d_t5, x0_t5, -10, 10);

	return 0;
}
