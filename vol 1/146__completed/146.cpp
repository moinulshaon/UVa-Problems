#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
    string a;

	while (getline(cin,a) && a!="#")
	{
		if (next_permutation(a.begin(),a.end() ) )
            cout<<a<<endl;
        else
            cout<<"No Successor\n";
	}
	return 0;
}
