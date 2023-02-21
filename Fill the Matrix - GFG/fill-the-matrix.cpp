//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        vector<vector<int>> v(n,vector<int>(m,0));
        v[x-1][y-1]=1;
        queue<pair<int,int>> q;
        int sz;
        int count=0;
        pair<int,int> p;
        int row,col;
        q.push({x-1,y-1});
        while(q.size()>0){
            sz = q.size();
            while(sz>0){
            p = q.front();
            q.pop();
            row = p.first;
            col = p.second;
            if(row+1<n && v[row+1][col]!=1)v[row+1][col]=1, q.push({row+1,col});
            if(row-1>=0 && v[row-1][col]!=1) v[row-1][col]=1,q.push({row-1,col});
            if(col+1<m && v[row][col+1]!=1)v[row][col+1]=1, q.push({row,col+1});
            if(col-1>=0 && v[row][col-1]!=1)v[row][col-1]=1, q.push({row,col-1});
                sz--;
            }
            count++;
        }
        return count-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends