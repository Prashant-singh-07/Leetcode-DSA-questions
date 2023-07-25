class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());

        long long total = 0; // Use long long to avoid overflow
        int count = 0;

        for (int i = 0; i < usageLimits.size(); i++) {
            total += usageLimits[i];
            if (total >= ((count + 1LL) * (count + 2LL)) / 2LL) { // Use LL for long long constants
                count++;
            }
        }

        return count;
    }
};