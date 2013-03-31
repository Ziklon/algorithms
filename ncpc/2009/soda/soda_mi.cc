/*
  Sample solution for NCPC 2009: Sody Surpler
  Author: Marcus Isaksson
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main() {
  int e,f,c;
  cin >> e >> f >> c;
  int empty=e+f;
  int drunken=0;
  while (empty>=c) {
    empty=empty-c+1;
    drunken++;
  }
  cout << drunken << endl;
}
