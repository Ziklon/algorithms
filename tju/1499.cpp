#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
vector<int> v;
int LIS(vector<int> A)
	{
	    int N = A.size(),i;
	    set<int> s;
	    set<int>::iterator k;
	    for (i=0;i<N;i++)
	    {
	        if (s.insert(A[i]).second)
	        {
	           k = s.find(A[i]);
	           k++;
	           if (k!=s.end())
                s.erase(k);
	        }
	    }
	    return s.size();
	}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int nC,n,tn;
    v.clear();
    cin>>nC;    
    for(int i=0;i<nC;i++){
      cin>>n;      
      v.clear();
      for(int j=0;j<n;j++){
        cin>>tn;
        v.push_back(tn);
      }
      cout<<LIS(v)<<endl;      
    }          
    return 0;
}
