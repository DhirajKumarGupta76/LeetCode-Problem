class Solution {
public:

    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int jump=0;
        int maxjump=0;
        int currend=0;
        for(int i=0;i<nums.size();i++){
            maxjump=max(maxjump,i+nums[i]);
            if(i==currend){
                jump++;
                currend=maxjump;
                if(maxjump>=nums.size()-1) break;
            }
            
        }
        return jump;
    }
};