#include "main.h"

int		main()
{
//	cout << GREEN << "TEST:" << RESET << endl;
//	solve_nonlinear_equation(test, test_d, 0.8, 1.2);

//	тест 1
	if (!TEST2 && !TEST3)
	{
		cout << GREEN << "TEST 1:" << RESET << endl;
		solve_nonlinear_equation(test_1, test_d_1, 0, 1);
	}
//	тест 2
	if (!TEST3)
	{
		cout << endl << GREEN << "TEST 2:" << RESET << endl;
		solve_nonlinear_equation(test_2, test_d_2, -1, 10);
	}
//	тест 3
	if (!TEST2)
	{
		cout << endl << GREEN << "TEST 3:" << RESET << endl;
		solve_nonlinear_equation(test_3, test_d_3, 0, 1);
	}
//	тест 4
	// начальное приближение
	vector<point3d>	x0_t4;
	point3d	p1_t4, p2_t4;
	p1_t4.x1 = 3.5; p1_t4.x2 = -0.5; p1_t4.y1 = test_4_1(p1_t4.x1, p1_t4.x2); p1_t4.y2 = test_4_2(p1_t4.x1, p1_t4.x2);
	p2_t4.x1 = -3.5; p2_t4.x2 = 0.5; p2_t4.y1 = test_4_1(p2_t4.x1, p2_t4.x2); p2_t4.y2 = test_4_2(p2_t4.x1, p2_t4.x2);
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

	if (!DIAGRAM)
	{
		cout << endl << GREEN << "TEST 4:" << RESET << endl;
		solve_nonlinear_equation(f_t4, f_d_t4, x0_t4, -10, 10);
	}

//	тест 5
	// начальное приближение
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

	if (!DIAGRAM)
	{
		cout << endl << GREEN << "TEST 5:" << RESET << endl;
		solve_nonlinear_equation(f_t5, f_d_t5, x0_t5, -10, 10);
	}

	/* составление диаграммы сходимости */
	if (DIAGRAM)
	{
		/* очищаем файлы */
		string test_name4 = "test4"; string test_name5 = "test5";
		ofstream	file4(DIR + test_name4 + "_diagram.csv");
		ofstream	file5(DIR + test_name5 + "_diagram.csv");
		file4.close();
		file5.close();

		cout << endl << endl;
		point3d	x0;
		VALUE_TYPE	step = 0.2;
		for (VALUE_TYPE i = 10; i > -10; i -= step)
		{
			x0.x2 = i - step / 2;
			for (VALUE_TYPE j = -10; j < (10 - step); j += step)
			{
				x0.x1 = j + step / 2;

				x0.y1 = test_4_1(x0.x1, x0.x2); x0.y2 = test_4_1(x0.x1, x0.x2);
				Newtons_method(f_t4, f_d_t4, x0, -10, 10, "test4", false, step / 2); // тест 4

				x0.y1 = test_5_1(x0.x1, x0.x2); x0.y2 = test_5_1(x0.x1, x0.x2);
				Newtons_method(f_t5, f_d_t5, x0, -10, 10, "test5", false, step / 2); // тест 5
			}

			/* последний символ в строке выносится в отдельную итерацию,
			 * чтобы вместо запятой напечатать символ конца строки */
			x0.y1 = test_4_1(x0.x1, x0.x2); x0.y2 = test_4_1(x0.x1, x0.x2);
			Newtons_method(f_t4, f_d_t4, x0, -10, 10, "test4", true, step / 2); // тест 4

			x0.y1 = test_5_1(x0.x1, x0.x2); x0.y2 = test_5_1(x0.x1, x0.x2);
			Newtons_method(f_t5, f_d_t5, x0, -10, 10, "test5", true, step / 2); // тест 5
		}
	}

//	тест от преподавателя
/*	// начальное приближение
	vector<point3d>	x0_t;
	point3d	p1_t;
	p1_t.x1 = 1.5; p1_t.x2 = -0.5; p1_t.y1 = test_1(p1_t.x1, p1_t.x2); p1_t.y2 = test_2(p1_t.x1, p1_t.x2);
	x0_t.push_back(p1_t);

	// система уравнений
	vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	f_t;
	f_t.push_back(test_1);
	f_t.push_back(test_2);

	// элементы обратной матрицы Якоби
	vector<VALUE_TYPE (*)(VALUE_TYPE, VALUE_TYPE)>	f_d_t;
	f_d_t.push_back(test_2_x2);
	f_d_t.push_back(test_1_x2);
	f_d_t.push_back(test_2_x1);
	f_d_t.push_back(test_1_x1);

	if (!DIAGRAM)
	{
		cout << endl << GREEN << "TEST FINAL:" << RESET << endl;
		solve_nonlinear_equation(f_t, f_d_t, x0_t, -2, 2);
	}*/

	return 0;
}
