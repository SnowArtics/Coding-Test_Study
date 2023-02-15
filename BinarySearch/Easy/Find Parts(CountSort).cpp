//Time Complexity : M

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    vector<int> part_array(1000000);
    vector<int> estimate;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        part_array[x]+=1;
    }
    
    cin>>M;
    
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        estimate.push_back(x);
    }
    
    for(int i=0;i<M;i++){
        if(part_array[estimate[i]]>=1) cout<<"yes"<<' ';
        else cout<<"no"<<' ';
    }
    
}