#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);

    int adj[105][105],i,j,k,number,result[105],n,flag,visited[105],kase=1;
    string ss1,ss2;

    while (cin>>n)
    {
        map<string,int> myp;
        map<int,string> rmyp;

        for (i=0;i<n;++i){
            cin>>ss1;
            myp[ss1]=i;
            rmyp[i]=ss1;
        }

        number=0;
        for (i=0;i<n;++i)
            for(j=0;j<n;++j)
                adj[i][j]=0;
        for (i=0;i<n;++i)
            visited[i]=0;

        cin>>k;
        while(k--)
        {
            cin>>ss1>>ss2;
            adj[ myp[ss1] ][ myp[ss2] ]=1;
        }

        while (number<n)
        {
            for (j=0;j<n;++j)
            {
                if (!visited[j])
                {
                    flag=1;
                    for (i=0;i<n;++i)
                    {
                        if (adj[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if (flag)
                    {
                        result[number++]=j;
                        for (i=0;i<n;++i)
                            adj[j][i]=0;
                        visited[j]=1;
                        j=-1;
                    }
                }
            }

        }
        printf("Case #%d: Dilbert should drink beverages in this order:",kase++);
        for (i=0;i<n;++i)
            cout<<' '<<rmyp[ result[i] ];
        printf(".\n\n");

    }
    return 0;
}
