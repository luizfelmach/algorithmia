// Area of a Circle
// https://www.beecrowd.com.br/judge/en/runs
// 28405682		1002	Area of a Circle	Accepted	C++17	0.000	6/8/22, 6:47:31 PM

#include <bits/stdc++.h>

#define PI 3.14159
using namespace std;

int main() {
	double radius;
	cin >> radius;
	double area = PI * radius * radius;
	cout << "A=" << fixed << setprecision(4) <<  area << endl;
	return 0;
}
