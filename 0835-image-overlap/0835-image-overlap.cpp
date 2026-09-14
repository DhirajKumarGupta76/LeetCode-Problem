class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       vector<pair<int,int>>a,b;
       int ans=0;
       int n=img1.size();
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(img1[i][j]==1){
                a.push_back({i,j});
            }
        }
       }

        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(img2[i][j]==1){
                b.push_back({i,j});
            }
        }
       }
       unordered_map<string,int>mpp;
       for(auto [x1,y1]:a){
        for(auto [x2,y2]:b){
            //relative position;
            int dx=x2-x1;
            int dy=y2-y1;
            string s=to_string(dx)+","+to_string(dy);
            mpp[s]++;
            ans=max(ans,mpp[s]);

        }
       }
       return ans;
     
    }
};