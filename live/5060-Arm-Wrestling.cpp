#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
#define first fst
#define second snd
#define sz size()
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int N,K,P[(1<<15)],T;

struct node{
    int idx,f;
    vector<int> v;
    node(){}
    node(int _idx, int _f){
        idx=_idx;
        f=_f;
    }

};

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&K);
        vector<node>game;
        REP(i,1<<N){
            scanf("%d",&P[i]);
            node  cur(i,P[i]);
            game.pb(cur);
        }
        REP(i,N){
            vector<node> aux;
            REP(j,game.sz){
                if(game[j].f>=game[j+1].f){
                    game[j].f-=game[j+1].f;
                    game[j].v.pb(game[j+1].idx);
                    aux.pb(game[j]);
                }else{
                    game[j+1].f-=game[j].f;
                    game[j+1].v.pb(game[j].idx);
                    aux.pb(game[j+1]);
                }
                j++;
            }
            REP(i,aux.sz)aux[i].f=min(aux[i].f+K,P[aux[i].idx]);
            game=aux;
        }
        printf("%d\n",game[0].idx+1);
        REP(i,game[0].v.sz){
            if(i)printf(" ");
            printf("%d",game[0].v[i]+1);
        }
        printf("\n");

    }
    return 0;
}

