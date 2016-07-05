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


        int lcp[5500];
        lcp[0]=0;
        tmp=suffixArray.size();
        int maxi=0;
        for (int i=1;i<tmp;++i)
        {
            lcp[i]=compF(suffixArray[i],suffixArray[i-1]);
            if (lcp[i]>lcp[maxi])
                maxi=i;
        }

        printf("%d\n",lcp[maxi]);

    }
    return 0;
}
