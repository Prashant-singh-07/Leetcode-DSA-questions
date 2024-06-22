class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        ans=0
        sum=0
        count = []
        c=0
        
        for i in range(len(nums)):
            if nums[i]%2 != 0:
                count.append(c)
                sum+=1
                c=0
            else:
                c+=1
            
            if sum>=k:
                ans+=1
                ans+=count[sum-k]
        
        return ans