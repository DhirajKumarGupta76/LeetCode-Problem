class Solution {
public:
int iseat(vector<int>&piles,int h ,int max_element){
    int low=1;
    int high=max_element;
    int ans=INT_MAX;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            
            sum+=(piles[i]+mid-1)/mid;
        }
            if(sum<=h){
                ans=min(ans,mid);
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }

           
        
        
    }
    return ans;
}
    int minEatingSpeed(vector<int>& piles, int h) {
       
         int maxelement= *max_element(piles.begin(),piles.end());
         return iseat(piles,h,maxelement);
    }
};