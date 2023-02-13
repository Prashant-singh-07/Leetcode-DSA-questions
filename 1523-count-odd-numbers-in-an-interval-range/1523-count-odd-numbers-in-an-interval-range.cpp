class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high-low;
        if(high%2==0 && low%2==0){
            diff = (diff-1)/2;
            if(high==low) return diff;
            diff++;
            return diff;
        }
        else if(high%2!=0 && low%2!=0){
            diff = (diff-1)/2;
            if(high==low) return diff+1;
            diff+=2;
            return diff;
        }
        else {
            return (diff+1)/2;
        }
        return 0;
    }
};