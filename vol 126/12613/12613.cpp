#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define SIZE 110000
#define MAXLG 20

struct entry
{
    int first, second, p;
} L[SIZE];
int P[MAXLG][SIZE];
int LCP[SIZE];
int step;
int B[SIZE];

int cmp(const struct entry &a, const struct entry &b)
{
    return a.first == b.first ? (a.second < b.second ? 1 : 0) : (a.first < b.first ? 1 : 0);
}

int comp2(const int& a, const int& b)
{
	return P[step-1][a] < P[step-1][b];
}

int suffixArray(char *A)
{
    int i, count;
    int len = strlen(A);

    for (i = 0; i < len; i ++)
        P[0][i] = A[i] - 'a';

    for (step = 1, count = 1; count>>1 < len; step++, count <<= 1)
    {
    	for (i = 0; i < len; i++)
    	{
			L[i].first = P[step - 1][i];
			L[i].second = i + count < len ? P[step - 1][i + count] : -1;
			L[i].p = i;
    	}

 		sort(L, L + len, cmp);

        for (i = 0; i < len; i ++)
            P[step][L[i].p] = i > 0 && L[i].first == L[i - 1].first && L[i].second == L[i - 1].second ?
				P[step][L[i - 1].p] : i;
    }

    for(i = 0; i < len; i++) B[i] = i;
    sort(B, B + len, comp2);

    for(i = 1; i < len; i++)
    {
	    int k;
	    int x = B[i], y = B[i - 1];

	    LCP[i] = 0;
	    for (k = step - 1; k >= 0 && x < len && y < len; k--)
	        if (P[k][x] == P[k][y])
	            x += 1 << k, y += 1 << k, LCP[i] += 1 << k;
    }
    int rr=0;
    for(i = 0; i < len; i++){
        //cout << LCP[i] << ' '<<B[i]<<endl;
        rr+=B[i]-LCP[i]+1;
    }
    //printf("%d\n",rr);
    return rr;
}

typedef long long LL;


char another[SIZE];
char str[SIZE];
int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",str);
        LL ans=suffixArray(str);
        strcpy(another,str);
        strcat(str,another);
        LL me = suffixArray(str)-ans;

        LL pp;
        scanf("%lld",&pp);

        ans+=me*(pp-1);

        printf("Case %d: %lld\n",kk,ans);
    }
    return 0;
}
