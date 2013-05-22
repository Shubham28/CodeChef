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

using namespace std;

char A[20005],B[20005];
int L;
int cntA[5],cntB[5];			//	Array: count of { digits>7, digit=7, 4<digit<7, digit=4, digit<4 }

int mn(int &fir,int &sec)
{
	int dif=min(fir,sec);
	fir-=dif,sec-=dif;
	return dif;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",A,B);
		L=strlen(A);
		MEM(cntA,0);	MEM(cntB,0);

		FOR(i,0,L){
			if(A[i]>'7')	cntA[0]++;
			else if(A[i]=='7')		cntA[1]++;
			else if('4'<A[i] && A[i]<'7')		cntA[2]++;
			else if(A[i]=='4')		cntA[3]++;
			else 	cntA[4]++;

			if(B[i]>'7')	cntB[0]++;
			else if(B[i]=='7')		cntB[1]++;
			else if('4'<B[i] && B[i]<'7')		cntB[2]++;
			else if(B[i]=='4')		cntB[3]++;
			else 	cntB[4]++;
		}

		int fr=0,sv=0;

		sv+=mn(cntA[1],cntB[2]) + mn(cntB[1],cntA[2]);
		sv+=mn(cntA[1],cntB[4]) + mn(cntB[1],cntA[4]);
		sv+=mn(cntA[1],cntB[3]) + mn(cntB[1],cntA[3]);
		sv+=mn(cntA[1],cntB[1]);

		fr+=mn(cntA[3],cntB[4]) + mn(cntB[3],cntA[4]);
		fr+=mn(cntA[3],cntB[3]);

		FOR(i,0,sv)		printf("7");
		FOR(j,0,fr)		printf("4");
		printf("\n");
	}

	return 0;
}
