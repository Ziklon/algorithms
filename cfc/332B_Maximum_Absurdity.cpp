#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
#define MAXN 200005
typedef long long ll;
int N,K;
int A[MAXN];
ll S[MAXN];

bool orden(pair<ll,int> p1, pair<ll,int> p2){
    if(p1.first!=p2.first)return p1.first>p2.first;
    return p1.second<p2.second;
}
int main(){
    scanf("%d %d",&N,&K);
    for (int i = 0; i < N; i++)
        scanf("%d",&A[i]);

    for(int i=0;i<MAXN;i++)S[i]=0;
    for (int i = 0; i < N; i++) 
        S[i+1]=S[i]+A[i];


    vector<pair<ll,int> >  v;
    for(int i=0;i+K<=N;i++)v.push_back(make_pair(S[i+K]-S[i], i+1));

    sort(v.begin(),v.end(),orden);
    int p1=v[0].second;
    int p2=-1;
    for(int i=1;i<v.size();i++){
        if((p1+K-1)<v[i].second || (v[i].second+K-1)<p1){
            p2=v[i].second;
            break;
        }
    }
    if(p1>p2)swap(p1,p2);
    printf("%d %d\n",p1,p2);
    return 0;
}
