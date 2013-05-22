#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
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

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	Input(T);

	int K;
	char word[(1<<16)+5],ans[(1<<16)+5];

	while(T--){
		Input(K);
		scanf("%s",word);
		int len=1<<K;

		FOR(all,0,len){
			int nwpos=0;
			FOR(pos,0,K)
				nwpos=(nwpos<<1)+((all>>pos)&1);
			ans[nwpos]=word[all];
		}
		ans[len]=0;
		printf("%s\n",ans);
	}

//	fclose(stdin);
	return 0;
}
