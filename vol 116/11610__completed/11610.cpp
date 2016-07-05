#include <cstdio>
#include <vector>
#include <algorithm>
#define sz 1000001
#include <utility>

using namespace std;

bool prime[sz];
vector <int> p;
vector <int> ppp;
vector <pair <int,int> > result;

int reversefunc(int n)
{
    int cnt;
    int digit[10];
    for (cnt=0;n;++cnt)
    {
        digit[cnt]=n%10;
        n/=10;
    }

    int result=0,powten=1000000;
    for (int i=0;i<cnt;++i)
    {
        result+=digit[i]*powten;
        powten/=10;
    }
    return result;
}

int div(int input)
{
	int  result=0;
	for (int i=0; input!=1  && ppp[i]*ppp[i]<=input;++i)
	{
        while (input%ppp[i]==0)
        {
            input/=ppp[i];
            ++result;
        }
	}

	if (input!=1)
		return result+1;
	else
		return result;
}

int bsearch(int x){
    int low=1,high=result.size()-1;
    while (low<=high){
        int mid=(low+high)/2;
        if (result[mid].first==x)return mid;
        else if (result[mid].first<x)low=mid+1;
        else high=mid-1;
    }
    return -1;
}




int main()
{

    freopen("in.txt","r",stdin);

    prime[0]=prime[1]=true;
    for (int i=2;i<=1000;++i)
        if (!prime[i])
            for (int j=2*i;j<sz;j+=i)
                prime[j]=true;

    for (int i=2;i<sz;++i)
        if (!prime[i]  && i%10!=0)
        {
            ppp.push_back(i);
            if (i%10)
                p.push_back( reversefunc(i) );
        }
    sort( p.begin(),p.end() );

    int ss=p.size();
    result.push_back( make_pair(0 , 0 ) );
    for (int i=0;i<ss;++i)
    {
        result.push_back( make_pair( p[i] , div( p[i] ) ) );
    }

    for (int i=1;i<ss;++i)
        result[i].second+=result[i-1].second;

    char query[3];
    int number;
    int sum;
    while (scanf("%s %d",query,&number)==2)
    {
        if (query[0]=='q')
        {
            printf("%d\n",result[ number+1 ].second );
        }
        else
        {
            int ind=bsearch(number);
            int tt=result[ind].second-result[ind-1].second;


            for (int i=ind;i<result.size()-1;++i)
            {
                result[i].second=result[i+1].second-tt;
                result[i].first=result[i+1].first;
            }

        }
    }
    return 0;
}
