// class Solution {
// public:
//     int maxProduct(vector<int>& arr) {
// int p=1, maxp=INT_MIN;
//         int n=arr.size();
//      for(int i=0;i<n;i++){
//          p*=arr[i];
//          maxp=max(maxp,p);
         
//          if(p==0){
//              p=1;
//          }
//      }
//      p=1;
//      for(int i=n-1;i>=0;i--){
//            p*=arr[i];
//          maxp=max(maxp,p);
//           if(p==0){
//              p=1;
//          } 
//      }
//      return maxp;
//        }
// 	   };
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        long long int p = 1, maxp = INT_MIN;
        int n = arr.size();

        // Function to check potential overflow
        auto willOverflow = [](long long a, long long b) -> bool {
            if (a == 0 || b == 0) return false;
            if (a > 0 && b > 0 && a > LLONG_MAX / b) return true;
            if (a > 0 && b < 0 && b < LLONG_MIN / a) return true;
            if (a < 0 && b > 0 && a < LLONG_MIN / b) return true;
            if (a < 0 && b < 0 && -a > LLONG_MAX / -b) return true;
            return false;
        };

        // First pass: from left to right
        for (int i = 0; i < n; i++) {
            if (willOverflow(p, arr[i])) {
                p = arr[i];
            } else {
                p *= arr[i];
            }
            maxp = max(maxp, p);
            if (p == 0) {
                p = 1;
            }
        }

        p = 1;

        // Second pass: from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (willOverflow(p, arr[i])) {
                p = arr[i];
            } else {
                p *= arr[i];
            }
            maxp = max(maxp, p);
            if (p == 0) {
                p = 1;
            }
        }

        return maxp;
    }
};
