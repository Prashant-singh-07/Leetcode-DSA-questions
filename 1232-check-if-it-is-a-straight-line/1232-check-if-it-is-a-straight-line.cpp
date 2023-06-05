class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(),coordinates.end());
        
        int startx = (coordinates[1][0]-coordinates[0][0]);
        int starty = (coordinates[1][1]-coordinates[0][1]);
        int x = coordinates[1][0];
        int y = coordinates[1][1];
        // int currx,curry;
        // for(int i=1;i<coordinates.size()-1;i++){
        //     currx = abs(coordinates[i+1][0]-coordinates[i][0]);
        //     curry = abs(coordinates[i+1][1]-coordinates[i][1]);
        //     if(currx==0 && startx!=0) return false;
        //     else if(currx==0 && currx==startx){
        //         if(((curry>starty && curry%starty!=0) || (curry<=starty && starty%curry!=0))) return false;
        //         continue;
        //     }
        //      if(startx==0) return false;
        //     if(curry==0 && starty!=0) return false;
        //     else if(curry == starty){
        //         if(((currx>startx && currx%startx!=0) || (currx<=startx && startx%currx!=0))) return false;
        //         continue;
        //     }
        //     if(starty==0) return false;
        //     if(((currx>startx && currx%startx!=0) || (currx<=startx && startx%currx!=0))  &&  ((curry>starty && curry%starty!=0) || (curry<=starty && starty%curry!=0))) return false;
        // }
        
        for(int i=0;i<coordinates.size();i++){
            if(starty*(coordinates[i][0]-x)!= startx*(coordinates[i][1]-y)) return false;
    
        }
        
        return true;
    }
};