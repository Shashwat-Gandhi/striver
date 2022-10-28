#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i < nums.size();i++) {
            mpp[nums[i]] = i;
        }
        
        for(int i=0;i < nums.size();i++) {
            int sec = target - nums[i];
            if(mpp.find(sec) != mpp.end() && mpp[sec] != i) {
                return vector<int>{i, mpp[sec]};
            }
        }
        
        return vector<int> {-1};
    }
};