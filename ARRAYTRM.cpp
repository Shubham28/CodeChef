#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int N,K;
int ar[105];

inline int zero()
{
	int cn=0;
	FOR(a,0,N)	cn+=(ar[a]==0);
	return cn;
}

int main()
{
	int T;
	Input(T);

	while(T--){
		Input(N),Input(K);
		FOR(i,0,N)	Input(ar[i]);

		sort(ar,ar+N);
		if(zero()==N){
			printf("NO\n");
			continue;
		} else if(zero()==N-1){
			printf("YES\n");
			continue;
		}

		bool ans=0;
		FOR(ch,0,N){
			int en=(ch!=N-1)?(N-1):(N-2);
			int L=ar[en];

			bool th=1;
			FOR(a,0,N)
				if(a!=ch && a!=en){
					int sm=K*L+ar[a];
					if(!(sm%(K+1)==0 && 0<=sm/(K+1) && sm/(K+1)<=L)){
						th=0;
						break;
					}
				}

			if(th && ((L==0 && ar[ch]) || L!=0)){
				ans=1;
				break;
			}
		}

		printf((ans)?"YES\n":"NO\n");
	}

	return 0;
}
