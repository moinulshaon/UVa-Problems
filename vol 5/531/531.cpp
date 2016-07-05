#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int mat[310][310];
vector <string> result;
string a,b;

void buildString( int x,int y,string str )
{
    if (x==0 || y==0)
    {
        int tmp=str.size()/2,len=str.length();
        for (int i=0;i<tmp;++i)
            swap(str[i],str[len-i-1]);

        result.push_back( str );
        return ;
    }
    else if (b[x-1]==a[y-1])
        buildString( x-1,y-1,str+b[x-1] );
    else
    {
        if ( mat[x][y-1] >= mat[x-1][y] )
            buildString(x, y-1,str);
        if  ( mat[x-1][y] >= mat[x][y-1] )
            buildString(x-1, y,str);
    }


}

int main()
{
    freopen("in.txt","r",stdin);

    for (bool on=false; getline(cin,a) ;on=true)
    {
        getline(cin,b);

        if (on)
        {
            printf("\n");
        }

        int length_a=a.length();
        int length_b=b.length();

        for (int i=0;i<=length_a;++i)
            mat[i][0]=0;
        for (int i=0;i<=length_b;++i)
            mat[0][i]=0;

        for (int i=1;i<=length_b;++i)
        {
            for (int j=1;j<=length_a;++j)
            {
                if (b[i-1]==a[j-1])
                {
                    mat[i][j]=1+mat[i-1][j-1];
                }
                else
                    mat[i][j]=max( mat[i-1][j],mat[i][j-1] );
            }
        }
        if (mat[length_b][length_a])
        {
            result.clear();
            buildString(length_b,length_a,"");
            sort( result.begin(),result.end() );
            int tmp=result.size();
            cout<<result[0]<<endl;
            for (int i=1;i<tmp ;++i)
                if (result[i]!=result[i-1])
                    cout<<result[i]<<endl;
        }
        else
            printf("No common sequence.\n");
        getchar();
    }
    return 0;
}
