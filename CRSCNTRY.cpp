#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

inline void Input(short &N)
{
	short ch,sign;
	N=0;

	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
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

short agn[2005],tmp[2005];
short fir,sec;
short len[2005][2005];

short lcs()
{
	FOR(row,0,sec)	FOR(col,0,fir)	len[row][col]=0;

	FOR(i,0,sec)
		FOR(j,0,fir){
			if(tmp[i]==agn[j]){
				if(i>=1 && j>=1)
					len[i][j]=len[i-1][j-1]+1;
				else
					len[i][j]=1;
			} else {
				if(i==0 && j==0)
					len[i][j]=0;
				else if(i==0)
					len[i][j]=len[i][j-1];
				else if(j==0)
					len[i][j]=len[i-1][j];
				else
					len[i][j]=(len[i-1][j]>len[i][j-1])?len[i-1][j]:len[i][j-1];
			}
		}

	return len[sec-1][fir-1];

}

int main()
{//		freopen("Input.txt","r",stdin);
	short d,num,ans;
	Input(d);

	while(d--){
		fir=0,ans=0;

		Input(num);
		while(num!=0){
			agn[fir++]=num;
			Input(num);
		}

		Input(num);
		while(num!=0){
			sec=0;
			tmp[sec++]=num;

			short val;
			Input(val);
			while(val!=0){
				tmp[sec++]=val;
				Input(val);
			}
			ans=max(ans,lcs());

			Input(num);
		}

		printf("%hd\n",ans);
	}

	return 0;
}
