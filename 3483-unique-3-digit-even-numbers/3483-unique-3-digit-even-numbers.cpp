class Solution {
public:
int solve(vector<int>&digits,int index,vector<int>&path,set<vector<int>>&res,vector<int>&used){
    int count=0;
    if(path.size()==3){
         // Don't allow leading zero
            if (path[0] != 0 && path[2]%2==0) {
                res.insert(path);
            }

        return 0;
    }
    for(int i=0;i<digits.size();i++){
        if(used[i]) continue;
        // Don't allow 0 at first position
            if (path.empty() && digits[i] == 0)
                continue;
        used[i]=true;
         path.push_back(digits[i]);
        solve(digits,i+1,path,res,used);
        //backtrack;
        path.pop_back();
        used[i]=false;
    }
    
    return 0;
}
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int>used(n,false);
        set<vector<int>>res;
        vector<int>path;
        solve(digits,0,path,res,used);
        return res.size();
    }
};