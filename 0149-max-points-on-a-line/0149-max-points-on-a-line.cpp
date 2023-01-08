class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
         int res=0,res2=0;
        
        for(int i=0;i<points.size();i++)
        {
            int overlap=0,yaxis=0,curr=0;
            map<pair<int,int>,int> mp;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[i]==points[j]) overlap++;
                else if(points[i][0]==points[j][0]) 
                    yaxis++;
                else
                {
                    int x=(points[i][0]-points[j][0]);
                    int y=(points[i][1]-points[j][1]);
                    int g=__gcd(x,y); 
                    mp[{x/g,y/g}]++;
                    curr=max(curr,mp[{x/g,y/g}]);
                    
                }
                curr=max(curr,yaxis);
                
            }
            
            res=max(res,curr+overlap+1);
            
        }
        return res;
    }
};