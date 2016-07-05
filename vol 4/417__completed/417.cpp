#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;



int main()
{
    map <string,int> myindex;

    string a="a";

    int number=1;
    myindex[a]=number++;

    while (a[0]<'z'){
        ++a[0];
        myindex[a]=number++;

    }
    a[0]='a';
    a=a+"a";
    while (a[0]<'z'){
        a[1]=a[0];
        while (a[1]<'z'){
            ++a[1];
            myindex[a]=number++;
        }
        ++a[0];

    }

    a[0]='a';
    a[1]='b';
    a=a+"a";

    while (a[0]<'z'){
        a[1]=a[0];
        while (a[1]<'z'){
            ++a[1];
            a[2]=a[1];
            while (a[2]<'z'){
                ++a[2];
                myindex[a]=number++;
            }

        }
        ++a[0];
    }


    a[0]='a';
    a[1]='b';
    a[2]='c';
    a=a+"a";

    while (a[0]<'z'){
        a[1]=a[0];
        while (a[1]<'z'){
            ++a[1];
            a[2]=a[1];
            while (a[2]<'z'){
                ++a[2];
                a[3]=a[2];
                while(a[3]<'z'){
                    ++a[3];
                    myindex[a]=number++;
                }

            }

        }
        ++a[0];
    }

    a[0]='a';
    a[1]='b';
    a[2]='c';
    a[3]='d';
    a=a+"a";

    while (a[0]<'z'){
        a[1]=a[0];
        while (a[1]<'z'){
            ++a[1];
            a[2]=a[1];
            while (a[2]<'z'){
                ++a[2];
                a[3]=a[2];
                while(a[3]<'z'){
                    ++a[3];
                    a[4]=a[3];
                    while (a[4]<'z'){
                        ++a[4];
                        myindex[a]=number++;
                    }

                }

            }

        }
        ++a[0];
    }

    freopen("input.txt","r",stdin);
    while(cin>>a)
        cout<<myindex[a]<<endl;
    return 0;





}







