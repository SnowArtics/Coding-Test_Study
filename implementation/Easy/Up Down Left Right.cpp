#include <bits/stdc++.h>

using namespace std;

bool threeTest(int i, int j, int k){
    if(i/10==3 || i%10==3||j/10==3 || j%10==3||k/10==3 || k%10==3){
        return true;
    }
    return false;
}

int main()
{
    int n;
    int output=0;
    
    cin>>n;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<60;j++){
            for(int k=0;k<60;k++){
                if(threeTest(i,j,k)==true){
                    output++;
                }
            }
        }
    }
    
    cout<<output;
}