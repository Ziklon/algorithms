#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
int A[20];
int Suma[20];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int C,S;
    int set=1;
    while(scanf("%d %d",&C,&S)==2){
        vector<vector<int> >v(C);
        int sum=0;
        double avg=0;
        REP(i,0,S){
            scanf("%d",&A[i]);
            sum+=A[i];
        }
        avg=sum/(C*1.0);
        sort(A,A+S);
       
        double opt=1e+30;
        do{
            int pt=0;
            vector<vector<int> >va(C);
            REP(i,0,S){
                va[pt].push_back(A[i]);
                Suma[pt]+=A[i];
                pt=(pt+1)%C;                
            }

            double aux=0;
            
            REP(i,0,C)
               aux+=abs(Suma[i]-avg);

            if(aux<opt){
                opt=aux;
                v=va;
            }


            
        }while(next_permutation(A,A+S));
        
        printf("Set #%d\n",set++);
        REP(i,0,C){
            printf("%d:",i);
            REP(j,0,v[i].sz)
                printf(" %d",v[i][j]);
            printf("\n");    
        }

        printf("IMBALANCE = %0.5f\n",opt);
        printf("\n");
    }
    //system("pause");
    return 0;
}
