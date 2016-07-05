#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct node
{
    int index,val;
}start,finish,word[210];

bool comparesh(string& a,string& b)
{
    if (a.length() !=b.length() )return false;

    int count=0;
    for (int i=0;i<a.length();++i)
    {
        if (a[i]!=b[i])
            ++count;
    }
    if (count==1)
        return true;
    else
        return false;


}

int main()
{
        int cases;

        freopen("input.txt","r",stdin);
        scanf("%d",&cases);
        getchar();
        getchar();
        while(cases--)
        {
            bool mat[210][210]={false};
            string str[210];
            char input[30];
            gets(input);
            str[0]=input;

            int wordnumber=1;
            for (;str[wordnumber-1][0]!='*';++wordnumber)
            {
                gets(input);
                str[wordnumber]=input;
            }

            map <string,int> myindex;

            for (int i=0;i<wordnumber-1;++i)
            {
                myindex[str[i]]=i;

                for (int j=0;j<i;++j)
                {
                    if (comparesh(str[i],str[j]))
                    {
                        mat[i][j]=mat[j][i]=true;
                    }
                }

            }



            while (gets(input)&& strlen(input))
            {
                char *tempstr;
                string a,b;

                bool vis[210]={false};
                tempstr=strtok(input," ");
                a=tempstr;
                tempstr=strtok(NULL," ");
                b=tempstr;

                queue <node> q;

                start.index =myindex[a];
                finish.index=myindex[b];
                q.push(start);
                vis[start.index]=true;
                start.val=0;
                while (!vis[finish.index])
                {
                    node temp=q.front();
                    q.pop();



                    for (int i=0;i<wordnumber-1;++i)
                    {
                        if (mat[temp.index][i] && !vis[i] )
                        {
                            vis[i]=true;
                            word[i].val=temp.val+1;
                            word[i].index=i;
                            q.push(word[i]);
                        }
                    }
                }
                printf("%s %s %d\n",a.c_str(),b.c_str(),word[finish.index].val);
            }
            if (cases)printf("\n");
        }
        return 0;

}

