#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 10005
#define minimum(a,b) (!greater(a,b)?(a):(b))
#define Int double
#define In 10005.0
#define eps 1e-8
#define zero(a) fabs(a)<eps
#define greater(a,b) ((a)>(b)+eps)
template<class X > class vec
{
public:
	X x,y;
	vec<X>(X a=0,X b=0)
	{
		x=a,y=b;
	}
	X sqDis(vec a)
	{
		X d=sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
		return d;
	}
};
vec<Int> P[MAX],T[MAX];
bool operator<(vec<Int> a,vec<Int> b)
{
	return greater(b.x,a.x);
}
double problem(int low,int high)
{
	if(high==low)return In;
	if(high-low==1)
		return P[low].sqDis(P[high]);
	/*if(high-low==2)
	{
		Int u=P[low].sqDis(P[high]),v=P[low].sqDis(P[low+1]),w=P[high].sqDis(P[low+1]);
		return minimum(u,minimum(v,w));
	}*/
	int mid=(low+high)/2,i,k=0,j;
	Int a=problem(low,mid),b=problem(mid+1,high),t=In;
	t=minimum(t,minimum(a,b));

	for(i=mid;i>=low&&!greater((P[mid+1].x-P[i].x),t);i--)
		T[k++]=P[i];

	for(i=mid+1;i<=high&&!greater((P[i].x-P[mid].x),t);i++)
		T[k++]=P[i];

	for(i=0;i<k;i++)for(j=i+1;j<k;j++)
		t=minimum(t,T[i].sqDis(T[j]));
	return t;
}
int main()
{
    freopen("in.txt","r",stdin);
	//freopen("in.txt","r",stdin);//unsigned a=(1<<31)+(1<<30);printf("%u\n",a);return 0;
	//freopen("out.txt","w",stdout);
	int n,i;Int ans;
	while(scanf("%d",&n)&&n>0)
	{
		for(i=0;i<n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
		sort(P,P+n);ans=problem(0,n-1);
		if(greater(10000.0,ans))//||zero(ans-10000.0))
			printf("%.4lf\n",ans+1e-10);
		else puts("INFINITY");
	}
	return 0;
}
