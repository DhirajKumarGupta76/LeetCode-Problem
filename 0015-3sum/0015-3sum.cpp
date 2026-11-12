class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum==0){
                    vector<int>temp={nums[i],nums[low],nums[high]};
                    low++;
                    high--;
                    ans.push_back(temp);
                    while(low<high && nums[low-1]==nums[low]) low++;
                    while(high>low && nums[high+1]==nums[high]) high--;
                }
                else if (sum>0) high--;
                else low++;
            }
        }
        return ans;
    }
};