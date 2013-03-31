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

bool orden(pair<string,double> p , pair<string,double>q){
	if(p.second!=q.second)return p.second<q.second;
	return p.first<q.first;
}
class BikeRace {
public:vector <string> eliminated(int track, vector <string> name, vector <int> start, vector <int> speed) {	
		vector<pair<string,double> >v;
		for(int i=0;i<name.sz;i++)
			v.pb(mp(name[i],10000));
		
		for(int i=0;i<name.sz;i++)
			for(int j=0;j<name.sz;j++){
				if(i==j)continue;
				double a=track/(double)speed[i];
				double b=track/(double)speed[j];
				/*
				cout<<i<<" "<<j<<endl;
				cout<<a<<" "<<b<<endl;
				cout<<start[i]<<" "<<start[j]<<endl;
				*/
				//antes de salir
				/*
				if(a<=1.0*start[j]){
					v[j].second=min(v[j].second,a);
					continue;
				}
				if(b<=1.0*start[i]){
					v[i].second=min(v[j].second,b);
					continue;
				}*/
				//carrera
				if(start[j]>=start[i]){
					if(speed[j]>speed[i]){
						
						double r=start[j]-start[i];
						if(r==0)
							v[i].second=min(v[i].second,1.0+start[j]);
						else{
							double  k=(speed[i]*r)/(double)(speed[j]-speed[i]);
							if(k+start[j]<a+start[i])
								v[i].second=min(v[i].second,k+start[j]);
						}
					}							
				}
				 				
			}
			vector<string>liz;
			sort(all(v),orden);
			for(int i=0;i<v.sz;i++)
				if(v[i].second!=10000)
					liz.pb(v[i].first);
			return liz;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, vector <int> p2, vector <int> p3, bool hasAnswer, vector <string> p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	BikeRace *obj;
	vector <string> answer;
	obj = new BikeRace();
	clock_t startTime = clock();
	answer = obj->eliminated(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p4.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p4[i] << "\"";
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
		if (answer.size() != p4.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p4[i]) {
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
	
	int p0;
	vector <string> p1;
	vector <int> p2;
	vector <int> p3;
	vector <string> p4;
	
	{
	// ----- test 0 -----
	p0 = 3000;
	string t1[] = {"B","J","A"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {66,0,15};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {50,45,3};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"A","J"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
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
