#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <limits.h>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define ULL unsigned long long
#define LL long long

using namespace std;

const int MAXD=1005,DIG=9,BASE=1000000000;
const ULL BOUND=ULLONG_MAX-(ULL)(BASE*BASE);

struct bignum
{
	int D,digits[MAXD/DIG+2];

	inline void trim()
	{
		while(D>1 && digits[D-1]== 0)
			D--;
	}

	inline void init(long long x)
	{
		memset(digits,0,sizeof(digits));
		D=0;

		do
		{
			digits[D++]=x%BASE;
			x/=BASE;
		} while(x>0);
	}

	inline bignum(long long x)
	{
		init(x);
	}

	inline bignum(int x=0)
	{
		init(x);
	}

	inline bignum(char *s)
	{
		memset(digits,0,sizeof(digits));
		int len=strlen(s),first=(len+DIG-1)%DIG+1;
		D=(len+DIG-1)/DIG;

		for(int i=0;i<first;i++)
			digits[D-1]=digits[D-1]*10+s[i]-'0';

		for(int i=first,d=D-2;i<len;i+=DIG,d--)
			for(int j=i;j<i+DIG;j++)
				digits[d]=digits[d]*10+s[j]-'0';

		trim();
	}

	inline char *toStr()
	{
		trim();
		char *buf=new char[DIG*D+1];
		int pos=0,d=digits[D-1];

		do
		{
			buf[pos++]=d%10+'0';
			d/=10;
		} while(d>0);

		reverse(buf,buf+pos);

		for(int i=D-2;i>=0;i--,pos+=DIG)
			for(int j=DIG-1,t=digits[i];j>=0;j--){
				buf[pos+j]=t%10+'0';
				t/=10;
			}

		buf[pos]='\0';
		return buf;
	}

	inline bignum range(int a,int b) const
	{
		bignum temp=0;
		temp.D=b-a;

		for(int i=0;i<temp.D;i++)
			temp.digits[i]=digits[i+a];

		return temp;
	}

	inline bignum operator + (const bignum &o) const
	{
		bignum sum=o;
		int carry=0;

		for(sum.D=0;sum.D<D || carry>0;sum.D++){
			sum.digits[sum.D]+=(sum.D<D?digits[sum.D]:0)+carry;

			if(sum.digits[sum.D]>=BASE){
				sum.digits[sum.D]-=BASE;
				carry=1;
			} else
				carry=0;
		}

		sum.D=max(sum.D,o.D);
		sum.trim();
		return sum;
	}

	inline bignum operator - (const bignum &o) const
	{
		bignum diff=*this;

		for(int i=0,carry=0;i<o.D || carry>0;i++){
			diff.digits[i]-=(i<o.D?o.digits[i]:0)+carry;

			if(diff.digits[i]<0){
				diff.digits[i]+=BASE;
				carry=1;
			} else
				carry=0;
		}

		diff.trim();
		return diff;
	}

	inline bignum operator * (const bignum &o) const
	{
		bignum prod=0;
		ULL sum=0,carry=0;

		for(prod.D=0;prod.D<D+o.D-1 || carry>0;prod.D++){
			sum=carry%BASE;
			carry/=BASE;

			for(int j=max(prod.D-o.D+1,0);j<=min(D-1,prod.D);j++){
				sum+=(ULL)digits[j]*o.digits[prod.D-j];

				if(sum>=BOUND){
					carry+=sum/BASE;
					sum%=BASE;
				}
			}

			carry+=sum/BASE;
			prod.digits[prod.D]=sum%BASE;
		}

		prod.trim();
		return prod;
	}

};

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int T,R,C;
	Input(T);

	while(T--){
		Input(R),Input(C);
		if(R>C)
			swap(R,C);

		if(R==1 && C==1)
			printf("0\n");
		else if(R==1){
			LL ans=C;
			ans*=(C-1);
			printf("%lld\n",ans);
		} else {
			bignum tot=R;
			tot=tot*C;
			tot=tot*(tot-1);

			bignum dwnr=(C-2);
			dwnr=dwnr*(R-1);
			bignum dwnl=dwnr;

			bignum upr=dwnr,upl=dwnr;

			if(R>=3){
				bignum botr=(C-1);
				botr=botr*(R-2);
				bignum botl=botr;

				bignum topr=botr,topl=botr;

				bignum ans=tot-dwnr-dwnl-upr-upl-botr-botl-topr-topl;
				printf("%s\n",ans.toStr());
			} else {
				bignum ans=tot-dwnr-dwnl-upr-upl;
				printf("%s\n",ans.toStr());
			}
		}
	}

	return 0;
}
