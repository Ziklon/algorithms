#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N, T;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        vector<int> v(N); 
        for(int i = 0; i < N; ++i)scanf("%d", &v[i]);
        
        for(int len = 1; v.size() ; ++len) {

            for(int j = 0; j < len; ++j) {
                int tmp  = v[0];
                v.erase(v.begin());
                v.push_back(tmp);
            }
            printf(" %d", v[0]);
            v.erase(v.begin());            
        }
        printf("\n");
    }

    return 0;
}
