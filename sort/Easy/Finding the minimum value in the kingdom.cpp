#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b);

int main()
{
    int N;
    
    cin>>N;
    
    vector<int> A(N);
    vector<int> B(N);
    int result = 0;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(), compare);
    
    for(int i=0;i<N;i++){
        result += A[i]*B[i];
    }
    
    cout<<result;
    
}

bool compare(int a, int b){
    return a>b;
}