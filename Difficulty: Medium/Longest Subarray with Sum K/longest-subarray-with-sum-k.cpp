#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mp;
        long long prefix_sum = 0;
        int max_len = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefix_sum += arr[i];

            // Case 1: Subarray starting from index 0 has sum equal to k
            if (prefix_sum == k) {
                max_len = i + 1;
            }

            // Case 2: Subarray starting from index (j + 1) has sum equal to k
            long long rem = prefix_sum - k;
            if (mp.find(rem) != mp.end()) {
                int len = i - mp[rem];
                max_len = max(max_len, len);
            }

            // Store prefix_sum index only if it does not already exist
            // (Keeping the leftmost index gives the longest possible subarray length)
            if (mp.find(prefix_sum) == mp.end()) {
                mp[prefix_sum] = i;
            }
        }

        return max_len;
    }
};