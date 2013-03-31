/*
  Sample solution for NCPC 2009: Allergy Test
  Author: Marcus Isaksson
*/

#include <iostream>
#include <vector>

using namespace std;

const int MaxAllergens=20;
const int MaxDays=7;
const int Inf=1000000;

typedef vector<int> Vi;
typedef vector<Vi> Mi;

int main() {
  int k;
  cin >> k;
  int nSets=1<<k;
  Vi d(k);
  for(int i=0; i<k; i++) cin >> d[i];

  // T[S][p]=shortest time to test for all allergens in the set S
  // if the allergen ending next to last ends p days before the
  // last allergen.
  Mi T(nSets, Vi(MaxDays+1, Inf));
  T[0][1]=0;
  for (int S=1; S<nSets; S++)
    for (int p=1; p<=MaxDays; p++) {
      int &t=T[S][p];
      for (int j=0; j<k; j++) if (p<=d[j] && (S&(1<<j))) {
          for (int p2=d[j]+1-p; p2<=MaxDays; p2++) 
            t=min(t,T[S-(1<<j)][p2]+p);
		}
    }

  int mn=Inf;
  for (int p=1; p<=MaxDays; p++)
    mn=min(mn,T[nSets-1][p]);
  cout << mn << endl;
}
