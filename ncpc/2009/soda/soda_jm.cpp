#include <iostream>

using namespace std;

int main()
{
	int e, f, c, sum = 0;
	cin >> e >> f >> c;
	int cur = e + f;
	while (cur >= c) {
		int b = cur/c;
		sum += b;
		cur = cur%c + b;
	}
	cout << sum << endl;
	return 0;
}
