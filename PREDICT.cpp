#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

int main()
{

	int T;
	double P;

	scanf("%d",&T);
	while(T--){
		scanf("%lf",&P);

		if(P<.5)	P=1.0-P;
		printf("%lf\n",(3*P-2*P*P)*10000.);
	}

	return 0;
}
