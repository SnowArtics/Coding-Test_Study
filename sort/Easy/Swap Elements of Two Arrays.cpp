#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    
    vector<int> a;
    vector<int> b;
    
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        b.push_back(num);
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    for(int i=0;i<K;i++){
        if(a[i]<b[N-1-i]) swap(a[i],b[N-1-i]);
    }
    
    int result = 0;
    for(int i=0;i<N;i++){
        result += a[i];
    }
    
    cout<<result;
}