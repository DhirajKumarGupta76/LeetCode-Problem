class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int sum=0;
        int minlen=INT_MAX;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            
            while(sum>=target){
                minlen=min(minlen,(j-i+1));
                sum-=nums[i];
                i++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};