#include "solve_nonlinear_equation.h"

vector<line_segment>	localization(vector<point> &table)
{
	int n = table.size();
	vector<line_segment>	segments; // здесь будем хранить отрезки, которые содержат корни функции

	for (int i = 0; i < n - 1; i++)
	{
		VALUE_TYPE ch = table[i].y * table[i + 1].y; // если ch < 0, значит функция поменяла знак
		if (ch < 0 || abs(ch) < EPSILON * EPSILON)
		{
			point	a, b;
			a.x = table[i].x;
			a.y = table[i].y;
			b.x = table[i + 1].x;
			b.y = table[i + 1].y;

			line_segment	tmp;
			tmp.a = a;
			tmp.b = b;

			segments.push_back(tmp);

			/* случай, когда нуль функции совпал с концом отрезка */
			if (abs(ch) < EPSILON * EPSILON &&
				abs(table[i + 1].y) < EPSILON * EPSILON) ++i;
		}
	}

	return segments;
}

