#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
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

int X[31],Y[31];
int t1,t2,t3,t4;

bool isUnique()
{
	int prd1=X[t1]*(Y[t2]-Y[t3]);
	int prd2=X[t2]*(Y[t3]-Y[t1]);
	int prd3=X[t3]*(Y[t1]-Y[t2]);

	return (prd1+prd2+prd3)!=0;
}

int id[4];
int det[4][4];

int det3rdOrd(int ar[3][3])
{
	int val1=ar[0][0]*(ar[1][1]*ar[2][2]-ar[1][2]*ar[2][1]);
	int val2=ar[0][1]*(ar[1][0]*ar[2][2]-ar[1][2]*ar[2][0]);
	int val3=ar[0][2]*(ar[1][0]*ar[2][1]-ar[1][1]*ar[2][0]);

	return val1-val2+val3;
}

double calEqn()
{
	int q1=det[0][0];
	int sml1[][3]={{det[1][1],det[1][2],det[1][3]},
					{det[2][1],det[2][2],det[2][3]},
					{det[3][1],det[3][2],det[3][3]}};

	int q2=det[0][1];
	int sml2[][3]={{det[1][0],det[1][2],det[1][3]},
					{det[2][0],det[2][2],det[2][3]},
					{det[3][0],det[3][2],det[3][3]}};

	int q3=det[0][2];
	int sml3[][3]={{det[1][0],det[1][1],det[1][3]},
					{det[2][0],det[2][1],det[2][3]},
					{det[3][0],det[3][1],det[3][3]}};

	int sml4[][3]={{det[1][0],det[1][1],det[1][2]},
					{det[2][0],det[2][1],det[2][2]},
					{det[3][0],det[3][1],det[3][2]}};

	double norml=det3rdOrd(sml1);
	double ret=q1*norml-(q2*det3rdOrd(sml2))
			+(q3*det3rdOrd(sml3))-det3rdOrd(sml4);

	ret/=norml;
	return ret;
}

bool isInside()
{
	id[0]=t4,id[1]=t1,id[2]=t2,id[3]=t3;
	FOR(j,0,4){
		det[j][0]=X[id[j]]*X[id[j]]+Y[id[j]]*Y[id[j]];
		det[j][1]=X[id[j]];
		det[j][2]=Y[id[j]];
		det[j][3]=1;
	}
	return calEqn()<1e-11;
}

int main()
{
	int T,N;
	Input(T);

	while(T--){
		Input(N);

		FOR(in,0,N)
			Input(X[in]),Input(Y[in]);

		int kills=0;
		FOR(i,0,N)		FOR(j,i+1,N)
			FOR(k,j+1,N){
				t1=i,t2=j,t3=k;

				if(isUnique()){
					FOR(l,0,N){
						t4=l;
						if(i!=l && j!=l && k!=l && isInside())
							kills++;
					}
				}
			}

		double tot=(N*(N-1)*(N-2)*(N-3))/6.0;
		printf("%lf\n",kills/tot);
	}

	return 0;
}
