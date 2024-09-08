#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int solution(vector<int> food_times, long long k) {    
    for(int i=0;i<food_times.size();++i)
        pq.push({food_times[i],i});
    
    //힙에서 윗값 확인
    //temp = 값의 시간 * 힙의 크기.
    //k가 temp보다 값이 크거나 같으면 k-=temp;
    //힙에서 값을 뽑음.
    //k가 temp보다 작으면 힙에서 k의 크기만큼 값을 확인하고 뽑음.
    //이후 힙의 가장 위에 있는 second의 값이 정답.    
    
    long long length = 0;
    while(1){
        if(pq.empty()) return -1;
        auto cur = pq.top();
        if(cur.first == length){
            pq.pop();
            continue;
        }
        long long temp = (cur.first - length) * pq.size();
        if(k>=temp){
            k-=temp;
            pq.pop();
            length = cur.first;
        }else{
            if(pq.empty()) return -1;
            break;
        }
    }
    
    if(k >= pq.size()){
        length += k/pq.size();
        k = k%pq.size();
    }
    
    for(int i=0;i<food_times.size();++i){
        food_times[i] -= length;
        if(food_times[i] < 1) continue;
        if(k == 0) return i+1;
        --k;
    }
    
    return -1;
}