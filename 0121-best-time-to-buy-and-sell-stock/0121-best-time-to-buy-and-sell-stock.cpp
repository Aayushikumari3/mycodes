class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int ind=0,mini=prices[0],maxi=0;
    
     for(int i=0;i<prices.size();i++)
     {
       mini=min(mini,prices[i]);
       if(prices[i]>mini)
       maxi=max(maxi,prices[i]);
       ind=max(prices[i]-mini,ind);
       
     }
      return ind;
    }
};