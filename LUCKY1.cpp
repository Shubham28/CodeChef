#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

inline void Input(int &N)
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

int main()
{
	const int LIM=100005;
	int S4[LIM],S7[LIM],dif[LIM];
	S4[0]=S7[0]=dif[0]=0;

	char conv[10];
	EFOR(a,1,100000){
		sprintf(conv,"%d",a);
		int fr=count(conv,conv+strlen(conv),'4');
		int sv=count(conv,conv+strlen(conv),'7');

		S4[a]=S4[a-1]+fr;
		S7[a]=S7[a-1]+sv;
		dif[a]=S4[a]-S7[a];
	}

	int ans[LIM],cnt[12000];
	MEM(cnt,0);

	cnt[0]=1,ans[0]=0;
	EFOR(a,1,100000){
		ans[a]=ans[a-1];

		int prv=cnt[dif[a]]++;
		ans[a]-=( (prv*(prv-1))/2 );
		ans[a]+=( ((prv+1)*prv)/2 );
	}

	int T,N;
	Input(T);

	while(T--){
		Input(N);
		printf("%d\n",ans[N]);
	}

	return 0;
}
