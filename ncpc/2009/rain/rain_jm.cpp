#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double l, k, t1, t2, h;
	cin >> l >> k >> t1 >> t2 >> h;
	
	double h2 = h + k*t2;
	double p = -h2-k*t1;
	double q = k*t1*l;
	double f = -p/2+sqrt(p*p/4-q);
	
	cout << fixed << setprecision(9) << (h <= l ? h : f) << " " << (h < l ? h : f) << endl;
	
	return 0;
}
