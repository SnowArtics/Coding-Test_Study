#include <bits/stdc++.h>

using namespace std;

int n = 1260;
int cnt = 0;
int coinTypes[4] = {500, 100, 50, 10};

int main()
{
    for(int i=0;i<4;i++){
        cnt += n/coinTypes[i];
        n = n%coinTypes[i];
        
    }
    cout<<cnt<<endl;
    return 0;
}

