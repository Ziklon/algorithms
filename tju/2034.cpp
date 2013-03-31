#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(int t){stringstream st; st<<t;return st.str();}
int S,N,n;

int last_digit_factorial(int N)
{
	int i,j,ans=1,a2=0,a5=0,a;
	    
	    for (i = 1; i <= N; i++)
	    {
	        j = i;                 
	        //divide i by 2 and 5
	        while (j%2==0)
	        {
	              j /= 2;
	              a2++;
	        }
	        while (j%5==0)
	        {
	              j/=5;
	              a5++;
	        }
	    
	        ans = (ans*(j%10))%10;
	    }
	    
	    a=a2-a5;
    
	    for (i = 1; i <= a; i++)
	        ans=(ans * 2) %10;
	    
	    return ans;
	}


int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  while(cin>>n){		
		printf("%5d -> %d\n",n,last_digit_factorial(n));  
  }
  
  return 0;
}

