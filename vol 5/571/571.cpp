#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct state
{
    int a,b;
    vector<string> move;
};
int ca,cb,n;

void bfs()
{
    state begin,tmp,tt;
    begin.a=begin.b=0;
    queue<state> q;
    q.push(begin);

    int node=0;

    while (!q.empty())
    {
        tmp=q.front();q.pop();
        printf("%d %d\n",tmp.a,tmp.b);
        getchar();
        if (tmp.b==n)break;

        if (tmp.a<ca)
        {
            tt=tmp;
            tt.a=ca;
            tt.move.push_back("fill A");
            //if (myp.find(tt)==myp.end())
            {
                //myp.insert(tt);
                q.push(tt);
            }

        }
        if (tmp.b<cb)
        {
            tt=tmp;
            tt.b=cb;
            tt.move.push_back("fill B");
            //if (myp.find(tt)==myp.end())
            {
                //myp.insert(tt);
                q.push(tt);
            }
        }
        if (tmp.a>0)
        {
            tt=tmp;
            tt.a=0;
            tt.move.push_back("empty A");
            //if (myp.find(tt)==myp.end())
            {
                //myp.insert(tt);
                q.push(tt);
            }
        }
        if (tmp.b>0)
        {
            tt=tmp;
            tt.b=0;
            tt.move.push_back("empty B");
            //if (myp.find(tt)==myp.end())
            {
                //myp.insert(tt);
                q.push(tt);
            }
        }
        if (tmp.a>0 && tmp.b<cb)
        {
            tt=tmp;
            tt.a=0;
            tt.b=min(cb,tmp.a+tmp.b);
            tt.move.push_back("pour A B");
            //if (myp.find(tt)==myp.end())
            {
                //myp.insert(tt);
                q.push(tt);
            }
        }
        if (tmp.b>0 && tmp.a<ca)
        {
            tt=tmp;
            tt.b=0;
            tt.a=min(ca,tmp.a+tmp.b);
            tt.move.push_back("pour B A");
            //if (myp.find(tt)==myp.end())
            {
                //myp.insert(tt);
                q.push(tt);
            }
        }
    }
    int kk=tmp.move.size();
    for (int i=0;i<kk;++i)
        cout<<tmp.move[i]<<endl;
    cout<<"success\n";

}

int main()
{

    while (scanf("%d %d %d",&ca,&cb,&n)==3)
    {
        bfs();
    }
}
