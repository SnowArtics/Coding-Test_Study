#include <string>
#include <vector>
#include <unordered_map> 
#include <set>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer(room_number.size());
    set<long long>roomSet;
    unordered_map<long long, long long>roomMap;
    long long findRoomNum;
    for(int i=0; i<room_number.size(); i++)
    {
        vector<long long> temp;        
        if (roomMap[room_number[i]]==0)
        {
            findRoomNum=room_number[i];
        }
        else
        {
            findRoomNum=roomMap[room_number[i]];
        }
        temp.push_back(findRoomNum);
        while(roomSet.find(findRoomNum)!=roomSet.end())
        {
            findRoomNum=roomMap[findRoomNum];
            temp.push_back(findRoomNum);
        }
        answer[i]=findRoomNum;
        roomSet.insert(findRoomNum);
        roomMap[findRoomNum]=findRoomNum+1;
        for (int i=0; i<temp.size(); i++)
        {
            roomMap[temp[i]]=findRoomNum+1;            
        }
        roomMap[room_number[i]]=findRoomNum+1;        
    }
    return answer;
}