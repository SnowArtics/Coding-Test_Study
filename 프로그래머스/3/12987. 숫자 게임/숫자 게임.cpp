#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int AC = 0;
    int BC = 0;
    while(AC != A.size()){
        if(B[BC]>A[AC]){
            ++answer;
            ++AC;
            ++BC;
        }
        else{
            ++AC;
        }
    }
    
    return answer;
}