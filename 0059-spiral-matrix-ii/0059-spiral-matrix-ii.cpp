class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n) );
        
        int c=0;
        int i=0;
        int j=0;
        int s=n;
        int p;
        /*for(i=0;i<n;i++){
            vector<int> r(n);
            for(j=0;j<n;j++){
                a[i][j] =0;
            }
            
        }*/
        while(s>1){
            cout<<"it is running";
             p=j;
            while(p < (n-i)){
                cout<<"it ias hhfgdkk"<<" ";
                c++;
                a[i][p] = c;
                p++;
            }
            p =i+1;
            while(p<(n-i)){
                cout<<" ye bhi chla"<<" ";
                c++;
                a[p][n-i-1] =c;
                p++;
            }
            p = (n-i-2);
            while(p>=i){
                cout<<" achaa ji ye bhi chla"<<" ";
                c++;
                a[n-i-1][p] = c;
                p--;
            }
            p = (n-i-2);
            while(p>i){
                cout<<" ohoooooo ye bhi chla"<<" ";
                c++;
                a[p][i] = c;
                p--;
            }
            s =s-2;
            i = i+1;;
            j = j+1;
        }
        if(n%2!=0){
            p = n/2;
            c++;
            a[p][p] = c;
        }
        return a;
    }
};