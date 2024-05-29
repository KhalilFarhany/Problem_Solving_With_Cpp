#include <bits/stdc++.h>

class Solution {
public:
    //Problem 1 : Find the XOR of Numbers Which Appear Twice
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans = (ans ^ nums[i]);
                i++;
            }
        }
        return ans;
    }

    //Problem 2 : Find Occurrences of an Element in an Array
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occs;
        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                occs.push_back(i);
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            if (queries[i] <= occs.size()) {
                ans[i] = occs[queries[i] - 1];
            }
        }
        return ans;
    }
};