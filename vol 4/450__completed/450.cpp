#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>


using namespace std;

struct account
{
    string name;
    string lastname;
    string address;
    string dept;
    string homephone;
    string workphone;
    string campusbox;
};

bool cmp(const account &a,const account &b)
{
    if (a.lastname>b.lastname)
        return false;
    return true;
}

int main()
{

    freopen("in.txt","r",stdin);

    int total;
    struct account tmp;
    while ( cin>>total )
    {
        vector<account> v;
        getchar();
        while (total--)
        {
            string givendept;
            getline(cin,givendept);

            tmp.dept=givendept;

            //cout<<givendept<<"sss"<<endl;

            string tt;

            while ( getline(cin,tt) && tt.length() )
            {
                int del=tt.find(",",0);

                tmp.name=tt.substr(0,del);

                int del2=tt.find(",",del+1);
                tmp.name+=" "+tt.substr(del+1,del2-del-1);

                del=tt.find(",",del2+1);
                tmp.lastname=tt.substr(del2+1,del-del2-1);

                del2=tt.find(",",del+1);
                tmp.address=tt.substr(del+1,del2-del-1);

                del=tt.find(",",del2+1);
                tmp.homephone=tt.substr(del2+1,del-del2-1);

                del2=tt.find(",",del+1);
                tmp.workphone=tt.substr(del+1,del2-del-1);

                tmp.campusbox=tt.substr(del2+1);

                v.push_back(tmp);
            }
        }

        stable_sort( v.begin(), v.end(), cmp);

        int pp=v.size();
        for (int i=0;i<pp;++i)
        {
            printf("----------------------------------------\n");
            cout<<v[i].name<<' '<<v[i].lastname<<endl;
            cout<<v[i].address<<endl;
            printf("Department: ");
            cout<<v[i].dept<<endl;

            printf("Home Phone: ");
            cout<<v[i].homephone<<endl;

            printf("Work Phone: ");
            cout<<v[i].workphone<<endl;

            printf("Campus Box: ");
            cout<<v[i].campusbox<<endl;
        }
    }
    return 0;
}
