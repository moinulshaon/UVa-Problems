#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int mat[310][310];

int main()
{

    freopen("in.txt","r",stdin);

    string a,b;
    int length_a,length_b;
    while ( getline(cin,a) )
    {

        getline(cin,b);
        length_a=a.length();
        length_b=b.length();

        memset(mat,0,sizeof(mat));

        for (int i=1;i<=length_a;++i)
            for (int j=1;j<=length_b;++j)
                if (a[i-1]==b[j-1])
                    mat[i][j]=1+mat[i-1][j-1];

        int mx=0;
        for (int i=1;i<=length_a;++i)
            for (int j=1;j<=length_b;++j)
                if (mat[i][j]>mx)
                    mx=mat[i][j];
        if (mx)
        {
            vector <string> result;
            for (int i=1;i<=length_a;++i)
                for (int j=1;j<=length_b;++j)
                    if (mat[i][j]==mx)
                        result.push_back(a.substr(i-mx,mx) );

            sort(result.begin(),result.end());

            cout<<result[0]<<endl;
            for (int i=1;i<result.size();++i)
                if (result[i]!=result[i-1])
                    cout<<result[i]<<endl;
        }
        else
            cout<<"No common sequence.\n";

        if (getchar()!=EOF)
            cout<<'\n';
        else
            return 0;
    }
    return 0;
}
