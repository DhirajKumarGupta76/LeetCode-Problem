class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int sum=0;
        int ans=INT_MAX;
        vector<int>best(n,INT_MAX);
        for(int j=0;j<n;j++){
            sum+=arr[j];
            while(sum>target){
                sum-=arr[i];
                i++;
            }
            if(sum==target){
                int len=j-i+1;
                if(i>0 && best[i-1]!=INT_MAX){
                    ans=min(ans,len+best[i-1]);
                    
                }
                best[j]=len;

            }
            if(j>0){
                best[j]=min(best[j],best[j-1]);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};