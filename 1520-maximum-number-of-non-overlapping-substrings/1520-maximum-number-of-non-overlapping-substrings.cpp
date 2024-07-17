class Solution {
public:
    bool static cmp(pair<int,int>a , pair<int,int>b){
        return a.second < b.second;
    }
    vector<string> maxNumOfSubstrings(string s) {
        map<char,pair<int,int>>m; //character firstindex lastindex
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(m.find(c)==m.end()){ //c is not present
                m[c]={i,i};
            }
            else{
                m[c].second = i;
            }
        }
        vector<pair<int,int>>validIntervals;
        for(auto x:m){
            char c = x.first;
            int left = x.second.first;
            int right = x.second.second;

            for (int j = left; j <= right; ++j) {
                left = min(left,m[s[j]].first);
                right = max(right,m[s[j]].second);
            }
            
            bool valid=true;
            for(int i=left;i<=right;i++){
                if(m[s[i]].first < left || m[s[i]].second > right){
                    valid=false;
                    break;
                }
            }
            if(valid == true){
                validIntervals.push_back({left,right});
            }
        }   
        sort(validIntervals.begin(),validIntervals.end(),cmp);
        vector<string>res;
        int end=-1;
        for(auto x:validIntervals){
            if(x.first > end ){
                res.push_back(s.substr(x.first , x.second - x.first + 1));
                end=x.second;
            }
        }
        return res;
    }
};
