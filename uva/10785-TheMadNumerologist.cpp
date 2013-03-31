#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	int T,N;
	scanf("%d",&T);
	vector<pair<int,char> >consonant;
	vector<pair<int,char> >vowel;
	
	consonant.push_back(make_pair(1,'J'));
	consonant.push_back(make_pair(1,'S'));
	
	consonant.push_back(make_pair(2,'B'));
	consonant.push_back(make_pair(2,'K'));
	consonant.push_back(make_pair(2,'T'));
	
	consonant.push_back(make_pair(3,'C'));
	consonant.push_back(make_pair(3,'L'));
	
	consonant.push_back(make_pair(4,'D'));
	consonant.push_back(make_pair(4,'M'));
	consonant.push_back(make_pair(4,'V'));
	
	consonant.push_back(make_pair(5,'N'));
	consonant.push_back(make_pair(5,'W'));
	
	consonant.push_back(make_pair(6,'F'));
	consonant.push_back(make_pair(6,'X'));
	
	consonant.push_back(make_pair(7,'G'));
	consonant.push_back(make_pair(7,'P'));
	consonant.push_back(make_pair(7,'Y'));
	
	consonant.push_back(make_pair(8,'H'));
	consonant.push_back(make_pair(8,'Q'));
	consonant.push_back(make_pair(8,'Z'));
	
	consonant.push_back(make_pair(9,'R'));
	
	vowel.push_back(make_pair(1,'A'));
	vowel.push_back(make_pair(3,'U'));
	vowel.push_back(make_pair(5,'E'));
	vowel.push_back(make_pair(6,'O'));
	vowel.push_back(make_pair(9,'I'));
	
	sort(consonant.begin(),consonant.end());
	sort(vowel.begin(),vowel.end());
			
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		int inda=0,indb=0;
		vector<int> vc (21,0);
		vector<int> vv (5,0);
		string ansa;		
		string ansb,ans;
		
		for(int j=1;j<=N;j++){
			if(j&1){
				ansa+=vowel[inda].second;
				vv[inda]++;	
				if(vv[inda]==21)inda++;
			}else{				
				ansb+=consonant[indb].second;
				vc[indb]++;
				if(vc[indb]==5)indb++;
			}
		}		
		sort(ansa.begin(),ansa.end());
		sort(ansb.begin(),ansb.end());
		inda=0;
		indb=0;
		for(int j=1;j<=N;j++){
			if(j&1)ans+=ansa[inda++];
			else ans+=ansb[indb++];
		}		
		printf("Case %d: %s\n",i+1,ans.c_str());
		
	}
	return 0;
}
