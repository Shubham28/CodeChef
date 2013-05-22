#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define VI vector<int>
#define UI unsigned int

using namespace std;

inline void Input(UI &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

UI L=46400;
UI ans[46400+1];
map<UI,UI>eval;

UI evalWays(UI N)
{
	if(N<L)
		return ans[N];

	if(eval.find(N)!=eval.end())
		return eval[N];

	N++;
	UI st=2,inc=1;
	UI ret=1;

	if(N&1)
		st=3,inc=2;

	for(UI chk=st;chk*chk<=N;chk+=inc)
		if(N%chk==0){
			UI qt=N/chk-1;
			ret+=evalWays(qt);

			if((qt+1)!=chk){
				qt=chk-1;
				ret+=evalWays(qt);
			}
		}

	eval[N-1]=ret;
	return ret;
}

int main()
{
	vector< VI >fact(L+1);
	for(UI st=2;st<=L;st++)
		for(UI ml=2;ml*st<=L;ml++)
			PB(fact[ml*st],st);

	ans[0]=ans[1]=1;
	EFOR(cal,3,L){
		int F=SZ(fact[cal]);
		UI wy=1;
		FOR(e,0,F){
			UI qt=cal/fact[cal][e]-1;
			wy+=ans[qt];
		}
		ans[cal-1]=wy;
	}

	UI T,N;
	Input(T);
	while(T--){
		Input(N);
		printf("%u\n",evalWays(N));
	}

	return 0;
}
