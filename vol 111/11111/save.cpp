#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#define sz 2000000

using namespace std;

int stk[sz];

int main()
{
    string ss;
	while(getline(cin,ss))
	{
		int nested, top = 0, on = 1, z;

        stringstream sstr(ss);

		while (sstr>>z)
		{
			if(z > 0)
			{
				for(nested = 0; top > 0 && stk[--top] != -z; nested += stk[top])
                    on &= stk[top] > 0;
				on &= stk[top] == -z && nested < z;
			}
			if(!on) break;
			stk[top++] = z;
		}
		while(top > 0 && stk[--top] > 0)
            ;
		on &= !top && stk[top] > 0;

		puts(on ? ":-) Matrioshka!" : ":-( Try again.");
	}
	return 0;
}
