#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>


using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int kase;
    char line[1000000];
    gets(line);

    sscanf(line,"%d",&kase);

    while(kase--){
        map<string,string> mp1,mp2;

        gets(line);
        string s1,s2;
        char *pch = strtok (line,"{}:,");
        while (pch != NULL){
            //printf ("%s\n",pch);
            s1=pch;
            //cout<<s1<<endl;
            pch = strtok (NULL, "{}:,");
            s2=pch;
            //cout<<s2<<endl;
            pch = strtok (NULL, "{}:,");
            mp1[s1]=s2;
        }

        gets(line);
        pch = strtok (line,"{}:,");
        while (pch != NULL){
            //printf ("%s\n",pch);
            s1=pch;
            pch = strtok (NULL, "{}:,");
            s2=pch;
            pch = strtok (NULL, "{}:,");
            mp2[s1]=s2;
        }
        vector<string> in,out,change;
        map<string,string> ::iterator it;

        for (it=mp1.begin();it!=mp1.end();++it){
            if ( mp2.find( it->first )==mp2.end() ){
                out.push_back( it->first );
            }else if ( it->second!=mp2[it->first] ){
                change.push_back( it->first );
            }
        }
        for (it=mp2.begin();it!=mp2.end();++it){
            if ( mp1.find( it->first )==mp1.end() ){
                in.push_back( it->first );
            }
        }
        if ( in.size()==0 && out.size()==0 && change.size()==0 ){
            printf("No changes\n");
        }else{
            if ( in.size() ){
                printf("+");
                for (int i=0;i<in.size();++i){
                    if ( i )printf(",");
                    printf("%s",in[i].c_str());
                }
                printf("\n");
            }
            if ( out.size() ){
                printf("-");
                for (int i=0;i<out.size();++i){
                    if ( i )printf(",");
                    printf("%s",out[i].c_str());
                }
                printf("\n");
            }
            if (  change.size() ){
                printf("*");
                for (int i=0;i<change.size();++i){
                    if ( i )printf(",");
                    printf("%s",change[i].c_str());
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
