#include <bits/stdc++.h>

using namespace std;

int MyCeil(int _a, int _b){
    int qutioent = _a/_b;
    int remain = _a%_b;
    if(remain != 0)
        ++qutioent;
    
    return qutioent;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int st = 0;
    for(int i=0;i< stations.size();++i){
        if(stations[i]-w-1 > st){
            int range = (stations[i] - w - 1) - st;
            answer += MyCeil(range , (w*2) + 1);
        }        
        st = stations[i] + w ;
    }
    if(st < n){
        int range = n - st;
        answer += MyCeil(range, (w*2) + 1);
    }

    return answer;
}