#include "solve_nonlinear_equation.h"

vector<line_segment>	localization(vector<point> &table)
{
	int n = table.size();
	vector<line_segment>	segments;

	for (int i = 0; i < n - 1; i++)
	{
		VALUE_TYPE ch = table[i].y * table[i + 1].y;
		if (ch <= 0)
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

			if (ch == 0 && table[i + 1].y == 0) ++i;
		}
	}

	return segments;
}

