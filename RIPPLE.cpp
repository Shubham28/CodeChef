#include <algorithm>
#include <iostream>
#include <cmath>
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

int N;
char tmp[100002],subt[100002];
char numb[2][100002];
char ans[2][100002];

inline void binSub(char num1[], char num2[])
{
	int len1=strlen(num1),len2=strlen(num2);
	int carry=0;
	int fir,sec;

	FOR(pos,0,len2){
		fir=num1[pos]-'0',sec=num2[pos]-'0';

		if(fir-sec+carry>=0)
			tmp[pos]=char(48+fir-sec+carry),carry=0;
		else
			tmp[pos]=char(50+fir-sec+carry),carry=-1;
	}

	FOR(pos,len2,len1){
		fir=num1[pos]-'0';

		if(fir+carry>=0)
			tmp[pos]=char(48+fir+carry),carry=0;
		else
			tmp[pos]=char(50+fir+carry),carry=-1;
	}
	tmp[len1]=0;

	int last=len1-1;
	while(tmp[last]=='0')
		tmp[last--]=0;

	strcpy(num1,tmp);

	return;
}

inline void calAns(int choose)
{
	int cnt=0;
	ans[choose][0]='0';
	FOR(ind,0,N){
		ans[choose][1+ind]=numb[choose][N-1-ind];
		cnt+=(numb[choose][N-1-ind]=='1')?1:0;
	}
	ans[choose][N+1]=0;

	EFOR(all,0,18)
		subt[all]=char(48+((cnt>>all)&1));
	subt[19]=0;

	binSub(ans[choose],subt);
	return;
}

int main()
{
	int T;
	Input(T);

	while(T--){
		Input(N);
		scanf("%s%s",numb[1],numb[0]);

		calAns(0);
		calAns(1);

		binSub(ans[0],ans[1]);
		reverse(ans[0],ans[0]+strlen(ans[0]));
		printf("%s\n",ans[0]);
	}

	return 0;
}
