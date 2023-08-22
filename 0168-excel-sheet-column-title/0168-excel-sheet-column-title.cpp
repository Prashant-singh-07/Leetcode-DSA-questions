class Solution {
public:
    string convertToTitle(int column) {
        int rem;
        string temp="";
        char c;
        while(column>0){
            rem = column%26;
            if(rem>0){
                c = 'A'+(rem-1);
                column-=rem;
            }
            else{
                c='A'+25;
                column-=26;
            }
            temp = c+temp;
            column=column/26;
        }
        return temp;
    }
};