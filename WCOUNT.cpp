#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ULL unsigned long long

using namespace std;

int main()
{
	ULL fct[505],inv[15];
	ULL MOD=1000000007;

	fct[0]=1;
	EFOR(f,1,501)
		fct[f]=(fct[f-1]*f)%MOD;

	inv[1]=1;
	EFOR(iv,2,10){
		ULL bs=fct[iv],exp=MOD-2;
		inv[iv]=1;

		for(;exp!=0;exp/=2,bs*=bs,bs%=MOD)
			if(exp&1){
				inv[iv]*=bs;
				inv[iv]%=MOD;
			}
	}

	int T;
	scanf("%d",&T);

	char inp[505];
	map<char,int>frq;
	map<char,int>::iterator it;

	ULL ans=0;
	while(T--){
		scanf("%s",inp);
		int L=strlen(inp);

		frq.clear();
		FOR(c,0,L)
			++frq[inp[c]];

		ans=fct[L];
		for(it=frq.begin();it!=frq.end();it++){
			int cnt=(*it).second;

			if(cnt>=2){
				ans*=inv[cnt];
				ans%=MOD;
			}
		}

		printf("%d\n",(int)ans);
	}

	return 0;
}
