#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

vector<int> board,tmp;


int main(){

    for (int i=0;i<8;++i){
        board.push_back(i+1);
    }
    board.push_back(-1);

    map< vector<int> ,string> myp ;

    myp[ board ] = "" ;

    queue< vector<int> > q;

    q.push(board);

    while (!q.empty()){
        tmp=q.front();
        q.pop();
        int pos;
        for (int i=0;i<tmp.size();++i){
            if ( tmp[i]==-1 ){
                pos=i;
                break;
            }
        }



    }



}
