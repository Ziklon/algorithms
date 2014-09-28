#include <cstdio>

using namespace std;
int T, seq[6];

int main() {

    //freopen("in.txt", "r", stdin);
    
    
    scanf("%d", &T);
   
    for(int t = 1; t <= T; ++t) {
        
        for(int i = 0; i < 6; ++i)scanf("%d", &seq[i]);

        bool can = 0;
        for(int mask = 0; mask < (1 << 6); ++mask) {
            int sum = 0;

            for(int i = 0; i < 6; ++i) {
                if(mask & (1 << i))sum += seq[i];
                else sum -= seq[i];
            }
            if(sum==0)can = 1;
        }
        
        if(can)puts("Tobby puede cruzar");
        else puts("Tobby no puede cruzar");


    }
    return 0;
}
