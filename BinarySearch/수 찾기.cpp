#include <bits/stdc++.h>

using namespace std;

int arr01[100002];

int n;

bool FindNum(int _a){
    int _small = 0;
    int _large = n-1;
    
    while(_small<=_large){
        int pivot = (_small + _large)/2;
        if(arr01[pivot]<_a)
            _small = pivot+1;
        else if(arr01[pivot]>_a)
            _large = pivot-1;
        else
            return 1;
    }    
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    for(int i=0;i<n;++i) cin >> arr01[i];    
    sort(arr01, arr01+n);
    int m;
    cin >> m;
    for(int i=1;i<m+1;++i){
        int t;
        cin>>t;
        cout<<FindNum(t)<<'\n';
    }
}