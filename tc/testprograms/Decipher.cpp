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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}

bool ord(pair<char,int> p1, pair<char,int> p2){
	if(p1.second!=p2.second)return p1.second>p2.second;
	return p1.first<p2.first;
}


class Decipher {
public:vector <string> decipher(vector <string> e, string f) {	
		map<char,int> M;
		for(int i=0;i<e.sz;i++)			
			for(int j=0;j<e[i].sz;j++)
				if(e[i][j]!=' ')
					M[e[i][j]]++;
			
		vector<pair<char,int> >V (all(M));
		sort(all(V),ord);
		map<char,char> C;
		C[' ']=' ';
		for(int x=0;x<f.sz;x++)
			C[V[x].first]=f[x];
		for(int i=0;i<e.sz;i++)
			for(int j=0;j<e[i].sz;j++)
				e[i][j]=C[e[i][j]];	
		return e;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, string p1, bool hasAnswer, vector <string> p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	Decipher *obj;
	vector <string> answer;
	obj = new Decipher();
	clock_t startTime = clock();
	answer = obj->decipher(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p2[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
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
	
	vector <string> p0;
	string p1;
	vector <string> p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"ABBBCC"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "XYZ";
	string t2[] = {"ZXXXYY"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"RZLW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "CEFD";
	string t2[] = {"EDCF"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"XX YYY Z YYY XX","WWWWWZWWWWW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "ETMQ";
	string t2[] = {"MM TTT Q TTT MM","EEEEEQEEEEE"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {" X ",""," ","  ","   "};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "B";
	string t2[] = {" B ",""," ","  ","   "};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"RAZVLHAR KNW CNR","HEA HNFMNSAR NFAK"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "EORTPNFHSCDIWG";
	string t2[] = {"REGISTER NOW FOR","THE TOPCODER OPEN"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
