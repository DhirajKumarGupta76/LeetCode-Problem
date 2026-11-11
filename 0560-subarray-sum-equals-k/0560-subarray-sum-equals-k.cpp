class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       mpp[0]=1;
       int sum=0;
       int count=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int need=sum-k;
        if(mpp.find(need)!=mpp.end()){
            count+=mpp[need];
        }
        mpp[sum]++;
       }
       return count;

    }
};