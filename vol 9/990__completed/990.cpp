#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int t,w;
vector< pair<int,int> > khoni;
vector<int> empty;


int sumof(vector<int> & tt)
{
    int sum=0;
    for (int i=0;i<tt.size();++i)
        sum+=khoni[ tt[i] ].second;
    return sum;
}


vector< int > func(int taken,int spent)
{
    if ( taken==khoni.size() )return empty;

    vector<int>result1,result2;



    if (t-spent>= 3*w*khoni[taken].first )
    {
        result1.push_back(taken);
        vector<int> tmp;
        tmp=func(taken+1,spent+3*w*khoni[taken].first);
        result1.insert(result1.end() ,tmp.begin(),tmp.end());
    }
    result2=func(taken+1,spent);

    if (sumof(result1)>sumof(result2))
        return result1;
    else
        return result2;

}


int main()
{
    freopen("in.txt","r",stdin);

    int kase,a,b;
    for (bool on=false;scanf("%d %d",&t,&w)==2;on=true)
    {
        if (on)printf("\n");

        khoni.clear();
        scanf("%d",&kase);
        while (kase--)
        {
            scanf("%d %d",&a,&b);
            khoni.push_back( make_pair(a,b) );
        }

        vector< int > result=func(0,0);

        printf("%d\n%d\n",sumof(result),result.size());


        for (int i=0;i<result.size();++i)
            printf("%d %d\n",khoni[ result[i] ].first,khoni[ result[i] ].second);

    }
    return 0;
}
