class Solution {
public:
    string reorganizeString(string s) {
        //Create a vector for storing frequency of each character.
        vector<int> frequency(26,0);
        for(int i=0;i<s.size();i++) frequency[s[i]-'a']++;
        //Declare a string variable which store result of rearrangement of string
        string ans="";
        int high,ind;
        int prev=-1;
        //Outer loop is just to run the inner loop same no. of times as size of string.So, we can get exact length output string as given in parameter.
        for(int i=0;i<s.size();i++){
            //At start of inner loop , declare high to least value, which indicate that no element has beeen selected .
            high=0;
            for(int j=0;j<26;j++){
                //check for condition that current element is not equal to previous elemnt and frequency of this char is high than all element's frequency which has been traversed till now.
                if(j!=prev && frequency[j]>high){
                    high=frequency[j];
                    ind=j;
                }
            }
            // if high ==0 , it means no suitable character is present to fill this position, so it is impossible to create any string. hence, retur an empty string.
            if(high==0) return "";
            //If high>0, it means there is character which would be suited for this position, so add that character to answer string and as that character has been taken so reduce frequency of that element by 1.
                ans+=('a'+ind);
            frequency[ind]--;
            // Now, assign current ind to prev, so that if we go for next iteration then we can have a easily look over our prevous element to avoid same character as adjacent.
            prev=ind;
        }
        return ans;
    }
};