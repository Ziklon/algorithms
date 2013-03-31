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
class SMBus {
public:int transmitTime(vector <string> messages, vector <int> times) {	
				
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	SMBus *obj;
	int answer;
	obj = new SMBus();
	clock_t startTime = clock();
	answer = obj->transmitTime(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"123","124","134"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 25;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"012","1234","1233","1223","1123"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,1,5,2,9};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 94;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0002019289019101039663222896280025447","00201873554718989597528841094293294387326","010699029378761","0110118","011143279122561420","001046384966198","00200570375817801109530240012","0003163277589822","01100240744590150136673219652442108","012033596872642679096489479354","0121059494098","00001002303019117948961792176","00216399923558","02014","00224999120803846121427603894967637446889670369","01101009414735635151893037596051740080475886","0000101211809647472761605153430927981533514","176845042961739039392207791589","02000047506929386333221966659552927385017901842706","021001117450487502127241076595509511","021010776262723557108100899515","0210114830738951774606917781619656","0211798433083855430","00000005842153604632996228135814","0001000766929248550736138555144997170272757787","0001010247593342056062432721557","01100004828618452515832113396660046634951","0132559984733529872911444204991646138116334788","0224149857349431864906523152249992","00001142929552573133212195441932219","00110904"
			"98947092002457447355036811372647896489218","000001275414757476198997466","00010014","00111025861963467834393486017602553072649743","000102085","00120882661783539","01100018938145727291185020","01100191373790478446634214244459341793","0001129060","001111287431066271555393813846448","011010160778408696098486370196313","0002125146381515395"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {42,86,47,86,32,95,2,98,17,58,31,32,85,77,87,61,1,20,15,80,20,95,55,87,52,14,55,68,2,66,67,3,28,97,100,67,65,20,28,77,93,64};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 71048;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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
