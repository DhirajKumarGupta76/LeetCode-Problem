class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int req=0;
        int minlen=INT_MAX;
        int start=0;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
            req++;

        }
        int i=0;
        for(int j=0;j<s.size();j++){
            if(mpp[s[j]]>0){
                req--;
            }
            mpp[s[j]]--;
            while(req<=0){
               if(j - i + 1 < minlen) {
                      minlen = j - i + 1;
                     start = i;
                  }
                  if(mpp[s[i]]>=0){
                    req++;
                  }
                  

                mpp[s[i]]++;

                i++;

            }
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};