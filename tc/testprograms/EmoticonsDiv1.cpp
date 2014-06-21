#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

#define MAXN 1<<10
#define INF 1<<29
int dist[MAXN][MAXN];

void relax(int newCost , int newVal, int copied, priority_queue<tuple<int, int, int>>& Q) {
    if(newVal < 1 || newVal >= MAXN)return;

    if(dist[newVal][copied] > newCost) {
        dist[newVal][copied] = newCost;
        Q.push(make_tuple(-newCost, newVal, copied));
    }

}


struct EmoticonsDiv1 {
    int printSmiles(int smiles) {
        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j < MAXN; ++j)
                dist[i][j] = INF;

        dist[1][0] = 0;
        priority_queue<tuple<int, int, int>> Q;
        Q.push(make_tuple(0, 1, 0));

        while(!Q.empty()) {
            auto curNode = Q.top();
            Q.pop();
            int copied = get<2>(curNode);
            int cur = get<1>(curNode);

            if(copied)relax(dist[cur][copied] + 1, cur + copied, copied, Q);

            relax(dist[cur][copied] + 1, cur - 1, 0, Q);
            relax(dist[cur][copied] + 1, cur, cur, Q);

        }
        return *min_element(dist[smiles], dist[smiles] + 1001);
    }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Testing EmoticonsDiv1 (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402027739;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        EmoticonsDiv1 _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int smiles = 2;
            _expected = 2;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 1: {
            int smiles = 4;
            _expected = 4;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 2: {
            int smiles = 6;
            _expected = 5;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 3: {
            int smiles = 18;
            _expected = 8;
            _received = _obj.printSmiles(smiles);
            break;
        }
        case 4: {
            int smiles = 11;
            _expected = 8;
            _received = _obj.printSmiles(smiles);
            break;
        }
        /*case 5:
        {
        	int smiles = ;
        	_expected = ;
        	_received = _obj.printSmiles(smiles); break;
        }*/
        /*case 6:
        {
        	int smiles = ;
        	_expected = ;
        	_received = _obj.printSmiles(smiles); break;
        }*/
        /*case 7:
        {
        	int smiles = ;
        	_expected = ;
        	_received = _obj.printSmiles(smiles); break;
        }*/
        default:
            return 0;
        }
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        double _elapsed = (double)(clock() - _start) / CLOCKS_PER_SEC;
        if (_received == _expected)
            cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
        else {
            cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
            cout << "           Expected: " << _expected << endl;
            cout << "           Received: " << _received << endl;
        }
    }
}

// END CUT HERE
