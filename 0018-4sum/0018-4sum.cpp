class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                  int low=j+1;
            int high=nums.size()-1;
            while(low<high){
                long long sum= (long long)nums[i]+nums[j]+nums[low]+nums[high];
                if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[low],nums[high]};
                    low++;
                    high--;
                    ans.push_back(temp);
                    while(low<high && nums[low-1]==nums[low]) low++;
                    while(high>low && nums[high+1]==nums[high]) high--;
                }
                else if (sum>target) high--;
                else low++;
            }
            }

        
        }
        return ans; 
    }
};