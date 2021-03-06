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
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
class MorselikeCode {
public:string decrypt(vector <string> lib, string message) {	
		map<string,char>M;
		string dev="",aux;
		for(int i=0;i<lib.sz;i++)
			M[lib[i].substr(2)]=lib[i][0];
		stringstream ss(message);
		while(ss>>aux){
			if(M[aux]==0)
				dev+='?';
			else
				dev+=M[aux];
		}
		return dev;
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	MorselikeCode *obj;
	string answer;
	obj = new MorselikeCode();
	clock_t startTime = clock();
	answer = obj->decrypt(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	string p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"O ---","S ..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "... --- ...";
	p2 = "SOS";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"O ---"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "... --- ...";
	p2 = "?O?";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"H -","E .","L --","L ..","O -."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "- . -- .. -.";
	p2 = "HELLO";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"H -.-.-.-.-.-.-.-.-.-.","I .-.-.-.-.-.-.-.-.-.-","K -.-.-.-.-.","E .-.-.-.-.-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "-.-.-.-.-.-.-.-.-.-. .-.-.-.-.-.-.-.-.-.-";
	p2 = "HI";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"O ---","S ...","B -...","T -","R .-.","E .","N -.","X -..-","D -.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "-... --- ... - --- -. .-. . -.. ... --- -..-";
	p2 = "BOSTONREDSOX";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"B -...","N -.","H ....","O --","Z --..","G ---","I ..","J .---"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "--- -- -... .- -. .- -. .-";
	p2 = "GOB?N?N?";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"A --","B -.","N ...-","I --..","F -.-.-."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "-. -- -.-.-. -.-.-. --- --.. ...- .-..--.";
	p2 = "BAFF?IN?";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
