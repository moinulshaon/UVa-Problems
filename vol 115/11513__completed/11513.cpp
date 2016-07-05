#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

struct mystruct
{
    int cnt;
    string str;
    string move;
};

mystruct moveh1(const mystruct & x)
{
    mystruct tt;
    tt.cnt=x.cnt+1;
    tt.str=x.str;
    tt.str[0]=x.str[1];
    tt.str[1]=x.str[2];
    tt.str[2]=x.str[0];
    tt.move="H1"+x.move;

    return tt;
}
mystruct moveh2(const mystruct & x)
{
    mystruct tt;
    tt.cnt=x.cnt+1;
    tt.str=x.str;
    tt.str[3]=x.str[4];
    tt.str[4]=x.str[5];
    tt.str[5]=x.str[3];
    tt.move="H2"+x.move;

    return tt;
}
mystruct moveh3(const mystruct & x)
{
    mystruct tt;
    tt.cnt=x.cnt+1;
    tt.str=x.str;
    tt.str[6]=x.str[7];
    tt.str[7]=x.str[8];
    tt.str[8]=x.str[6];
    tt.move="H3"+x.move;

    return tt;
}
mystruct movev1(const mystruct & x)
{
    mystruct tt;
    tt.cnt=x.cnt+1;
    tt.str=x.str;
    tt.str[3]=x.str[0];
    tt.str[6]=x.str[3];
    tt.str[0]=x.str[6];
    tt.move="V1"+x.move;

    return tt;
}
mystruct movev2(const mystruct & x)
{
    mystruct tt;
    tt.cnt=x.cnt+1;
    tt.str=x.str;
    tt.str[4]=x.str[1];
    tt.str[7]=x.str[4];
    tt.str[1]=x.str[7];
    tt.move="V2"+x.move;

    return tt;
}
mystruct movev3(const mystruct & x)
{
    mystruct tt;
    tt.cnt=x.cnt+1;
    tt.str=x.str;
    tt.str[5]=x.str[2];
    tt.str[8]=x.str[5];
    tt.str[2]=x.str[8];
    tt.move="V3"+x.move;

    return tt;
}


map <string,mystruct> mymap;
int main()
{
    mystruct tmp,tmp2;
    tmp.cnt=0;
    tmp.str="123456789";
    tmp.move="";
    mymap["123456789"]=tmp;

    queue <mystruct> q;

    q.push(tmp);

    while ( !q.empty() )
    {
        tmp=q.front();
        q.pop();

        tmp2=moveh1(tmp);


        if ( mymap.find(tmp2.str)==mymap.end() )
        {

            mymap[tmp2.str]=tmp2;
            q.push(tmp2);
        }

        tmp2=moveh2(tmp);
        if ( mymap.find(tmp2.str)==mymap.end() )
        {
            mymap[tmp2.str]=tmp2;
            q.push(tmp2);
        }
        tmp2=moveh1(tmp);

        if ( mymap.find(tmp2.str)==mymap.end() )
        {
            mymap[tmp2.str]=tmp2;
            q.push(tmp2);
        }

        tmp2=moveh3(tmp);

        if ( mymap.find(tmp2.str)==mymap.end() )
        {
            mymap[tmp2.str]=tmp2;
            q.push(tmp2);
        }

        tmp2=movev1(tmp);

        if ( mymap.find(tmp2.str)==mymap.end() )
        {
            mymap[tmp2.str]=tmp2;
            q.push(tmp2);
        }
        tmp2=movev2(tmp);

        if ( mymap.find(tmp2.str)==mymap.end() )
        {
            mymap[tmp2.str]=tmp2;
            q.push(tmp2);
        }
        tmp2=movev3(tmp);

        if ( mymap.find(tmp2.str)==mymap.end() )
        {
            mymap[tmp2.str]=tmp2;
            q.push(tmp2);
        }

    }
    char c;
    while (cin>>c)
    {
        if (c=='0')return 0;
        string input;

        input+=c;
        for (int i=1;i<9;++i)
        {
            cin>>c;
            input+=c;
        }
        if (mymap.find(input)==mymap.end())
            printf("Not solvable\n");
        else
        {
            tmp=mymap[input];
            cout<<tmp.cnt<<' '<<tmp.move<<endl;
        }
    }


}
