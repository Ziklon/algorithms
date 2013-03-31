/*
  Sample solution for NCPC 2009: Sody Surpler
  Author: Marcus Isaksson
*/

#include <cmath>
#include <iostream>

using namespace std;

double l,k,t1,t2;

// Amount of fall needed assuming that h>l.
double drainFall(double h)
{
  double a=(k*t1+k*t2+h)/2;
  return a+sqrt(a*a-l*k*t1);
}

int main() {
  double h;
  cin >> l >> k >> t1 >> t2 >> h;

  // Rain fall nedded to get h>l.
  double fc=max(max(k*t1,l),drainFall(l));
    
  double mn,mx;
  if (h<l) 
    mn=mx=h;
  else if (h==l) {
    mn=l;
    mx=fc;
  } else
    mn=mx=drainFall(h);

  cout.precision(12);
  cout << mn << " " << mx << endl;
}
