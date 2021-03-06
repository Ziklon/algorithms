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
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
vector<vector<int> >A(19),B(19);
void subsets(vector<int>v,vector<vector<int> >&ans){
	for(int i=0;i<ans.sz;i++)ans[i].clear();
	int n=v.sz;
	for(int mask=0;mask<(1<<n);mask++){
		int s=0,bit=0;
		for(int j=0;j<v.sz;j++)
			if((mask&(1<<j))!=0){
				bit++;
				s+=v[j];
			}
		ans[bit].push_back(s);
	}
	for(int i=0;i<ans.sz;i++)sort(all(ans[i]));
}
class ArithmeticalMean {
public:long long howMany(vector <int> ele, int L, int H) {	
		int n=(ele.sz)/2;
		subsets(vector<int>(ele.begin(),ele.begin()+n),A);
		subsets(vector<int>(ele.begin()+n,ele.end()),B);
		long long liz=0;		
		for(int i=0;i<B.sz;i++){
			for(int j=0;j<B[i].sz;j++){
				int val=B[i][j];
				for(int k=0;k<A.sz;k++){
					int nt=i+k;
					int fst=L*nt-val;
					int scd=H*nt-val;
					int x1=lower_bound(all(A[k]),fst)-A[k].begin();
					int x2=lower_bound(all(A[k]),scd+1)-A[k].begin();
					liz+=(x2-x1);
				}
			}
		}
		return liz-1;				
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	ArithmeticalMean *obj;
	long long answer;
	obj = new ArithmeticalMean();
	clock_t startTime = clock();
	answer = obj->howMany(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	int p2;
	long long p3;
	
	{
	// ----- test 0 -----
	int t0[] = {10,1,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 6;
	p3 = 4ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -1;
	p2 = 0;
	p3 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 100;
	p3 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,2,3,4,5,6,7,8,9,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 7;
	p3 = 949ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
