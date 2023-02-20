//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int n){
        // code here 
        int mod=1e9+7;
        if(n<=1) return 0;
        if(n==2) return 3;
        long long a = 1,b=1,c=1,d=0;
        //sum=0;
        long long temp1,temp2,temp3,temp4;
        for(int i=2;i<n;i++){
            temp1=a;
            temp2=b;
            temp3=c;
            temp4=d;
            a = (temp2+temp3+temp4)%mod;
            b = (temp1+temp3+temp4)%mod;
            c = (temp1+temp2+temp4)%mod;
            d = (temp1+temp2+temp3)%mod;
        }
        return (a+b+c)%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends