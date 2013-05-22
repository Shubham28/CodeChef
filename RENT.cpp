#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int N;
unsigned int strt[10001],fin[10001],prc[10001];
pair<unsigned int,unsigned int>best[10001];
unsigned int blen,ans;

inline int partition(int p,int r)
{
	int k=rand()%(r-p);
	swap(fin[p],fin[p+k]);
	swap(strt[p],strt[p+k]);
	swap(prc[p],prc[p+k]);

	int i=p;
	EFOR(j,p+1,r)
		if(fin[j]<=fin[p]){
			++i;
			swap(fin[j],fin[i]);
			swap(strt[j],strt[i]);
			swap(prc[j],prc[i]);
		}

	swap(fin[i],fin[p]);
	swap(strt[i],strt[p]);
	swap(prc[i],prc[p]);

	return i;
}

void quickSort(int p,int r)
{
	if(p<r){
		int q=partition(p,r);
		quickSort(p,q-1);
		quickSort(q+1,r);
	}
	return;
}

int main()
{
	int T;
	Input(T);

	while(T--){
		Input(N);

		FOR(inp,0,N){
			int tmp1,tmp2,tmp3;
			Input(tmp1),Input(tmp2),Input(tmp3);
			strt[inp]=tmp1,fin[inp]=tmp1+tmp2,prc[inp]=tmp3;
		}

		quickSort(0,N-1);
		ans=prc[0],blen=1;
		best[0]=make_pair(fin[0],ans);

		FOR(all,1,N){
			unsigned int tmp=strt[all],val=prc[all];

			int lo=0,hi=blen-1;
			while(lo<hi){
				int mid=lo+(hi-lo+1)/2;
				if(best[mid].first<=tmp)
					lo=mid;
				else
					hi=mid-1;
			}
			if(best[lo].first>tmp && val>ans){
				if(best[blen-1].first<fin[all])
					best[blen++]=make_pair(fin[all],val);
				else if(best[blen-1].first==fin[all])
					best[blen-1]=make_pair(fin[all],val);
			} else if(best[lo].first<=tmp){
				int nwval=val+best[lo].second;
				if(nwval>ans){
					if(best[blen-1].first<fin[all])
						best[blen++]=make_pair(fin[all],nwval);
					else if(best[blen-1].first==fin[all])
						best[blen-1]=make_pair(fin[all],nwval);
				}
			}

			ans=max(ans,best[blen-1].second);
		}
		printf("%d\n",ans);
	}

	return 0;
}
