#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign=1;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int sq,tr,tar;
int first[10001],incr[10001],cnt[10001];

inline bool possible(int timechk)
{
	FOR(chk,0,tr){
		cnt[chk]=0;
		if(timechk>=first[chk])
			cnt[chk]=1+(timechk-first[chk])/incr[chk];
	}

	sort(cnt,cnt+tr);
	reverse(cnt,cnt+tr);
	long long maxim=accumulate(cnt,cnt+sq,0ll);
	if(maxim>=tar)
		return true;
	return false;
}

int main()
{
	int T;
	Input(T);
	while(T--){

		Input(tr),Input(sq),Input(tar);
		sq=min(sq,tr);

		int start=0,limit=2000000000;

		FOR(inp,0,tr){
			Input(first[inp]);
			start=min(start,first[inp]);
		}

		FOR(inp,0,tr){
			Input(incr[inp]);
			limit=min(limit,first[inp]+(tar-1)*incr[inp]);
		}

		int mid;
		while(start<limit){
			mid=(start+limit)/2;

			if(possible(mid))
				limit=mid;
			else
				start=mid+1;
		}
		printf("%d\n",limit);
	}

	return 0;
}
