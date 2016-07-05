#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int compF(string a,string b)
{
    int len=( a.size()<b.size() )?a.size():b.size();
    int same;
    for (same=0;same<len;++same)
        if (a[same]!=b[same])
            return same;
    return same;
}

int main()
{
    int test;
    string input;
    scanf("%d",&test);
    while (test--)
    {
        cin>>input;
        vector <string> suffixArray;
        int tmp=input.length();
        for (int i=0;i<tmp;++i)
            suffixArray.push_back(input.substr(i,tmp-i));
        sort(suffixArray.begin(),suffixArray.end());


        int lcp[3000];
        lcp[0]=0;
        tmp=suffixArray.size();
        int maxi=0;
        for (int i=1;i<tmp;++i)
        {
            lcp[i]=compF(suffixArray[i],suffixArray[i-1]);
            if (lcp[i]>lcp[maxi])
                maxi=i;
        }

        string result=suffixArray[maxi].substr(0,lcp[maxi]);
        int cnt=0;
        for (int i=0;i<tmp;++i)
        {
            if (compF( suffixArray[i] ,result )==lcp[maxi] )
            {
                ++cnt;
            }
        }
        if (!lcp[maxi])
            printf("No repetitions found!\n");
        else
            printf("%s %d\n",result.c_str(),cnt);

    }
    return 0;
}
