#include <cstdio>
#include <vector>

using namespace std;

bool on;
int absol(int a)
{
    return (a<0)?-a:a;
}

vector<int> v;

int func(int i)
{
    int tmp,sum=0;
    scanf("%d",&tmp);
    if (!on)return 0;
    if (absol(tmp) > absol(v[i]))
    {
        on=false;
        string ss;
        getline(cin,ss);

        return 0;
    }
    else if (absol(tmp)==absol(v[i]) )
    {
        v.pop_back();
        //sum+=absol(tmp)+func(i-1);
        return absol(tmp);
    }
    else
    {
        v.push_back(tmp);
        sum+=func(i+1);
        return sum;
    }
}

int main()
{
    int lval;
    while (scanf("%d",&lval)==1)
    {
        v.clear();
        on=true;
        v.push_back(lval);
        func(0);

        if (on)
            printf(":-) Matrioshka!\n");
        else
            printf(":-( Try again.\n");
    }
}
