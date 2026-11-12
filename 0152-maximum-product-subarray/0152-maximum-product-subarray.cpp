class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
       vector<int>prefix(n,1),suffix(n,1);
       int product1=1;
       int product2=1;
       int maxproduct=INT_MIN;
       for(int i=0;i<n;i++){
        // Reset only the product which became zero
            if(product1 == 0)
                product1 = 1;

            if(product2 == 0)
                product2 = 1;
        product1*=nums[i];
        product2*=nums[n-1-i];
        maxproduct=max(maxproduct,max(product1,product2));
        


       } 
       return maxproduct;
    }
};