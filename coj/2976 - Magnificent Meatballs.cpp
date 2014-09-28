#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int N, P;



int main() {
    //freopen("in.txt", "r", stdin);

    while(scanf("%d", &N) == 1) {
        if(N == 0)break;
        vector<int> v(N);
        for(int i = 0; i < N; ++i)scanf("%d", &v[i]);
        bool found = 0;

        int sum1 = 0;
        int n1, n2;
        for(int i = 0; i < N; ++i) {
            sum1 += v[i];
            int sum2 = 0;
            int pos = N+1;
            for(int j = i + 1; j < N; ++j) {
                pos--;
                sum2 += v[j];
            }
            if(sum1 == sum2) {
                found = 1;
                n1 = i + 1;
                n2 = pos;
                break;
            }
        }
        if(!found)printf("No equal partitioning.\n");
        else printf("Sam stops at position %d and Ella stops at position %d.\n", n1, n2);



    }
    return 0;
}
