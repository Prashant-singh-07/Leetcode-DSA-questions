// class UndergroundSystem {
// public:
   
//     unordered_map<string,vector<pair<int,int>>> inst;
//     unordered_map<string,vector<pair<int,int>>> oust;
//     UndergroundSystem() {
        
//     }
    
//     void checkIn(int id, string stationName, int t) {
//         inst[stationName].push_back({id,t});
//         return ;
//     }
    
//     void checkOut(int id, string stationName, int t) {
//         oust[stationName].push_back({id,t});
//         return ;
//     }
    
//     double getAverageTime(string startStation, string endStation) {
//         vector<pair<int,int>> start = inst[startStation];
//         vector<pair<int,int>> endu = oust[endStation];
//         int i=0,j=0;
//         double count=0,time=0,ans;
        
        
        
//         sort(start.begin(),start.end());
//         sort(endu.begin(),endu.end());
        
//         while(i<start.size() && j<endu.size()){
//             if(start[i].first == endu[j].first){
//                 count+=1.00000;
//                 time+=(endu[j].second - start[i].second);
                
//                 i++;
//                 j++;
//             }
//             else if(start[i].first > endu[j].first) j++;
//             else i++;
//         }
//         ans = time/count;
//          return ans;
//     }
// };

// /**
//  * Your UndergroundSystem object will be instantiated and called as such:
//  * UndergroundSystem* obj = new UndergroundSystem();
//  * obj->checkIn(id,stationName,t);
//  * obj->checkOut(id,stationName,t);
//  * double param_3 = obj->getAverageTime(startStation,endStation);
//  */

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInMap; // Uid - {StationName, Time}
    unordered_map<string, pair<double, int>> routeMap; // RouteName - {TotalTime, Count}
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInMap[id];
        checkInMap.erase(id); // Remove after using it which will not make HashTable big
            
        string routeName = checkIn.first + "_" + stationName;
        routeMap[routeName].first += t - checkIn.second;
        routeMap[routeName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& route = routeMap[routeName];
        return route.first / route.second;
    }
};