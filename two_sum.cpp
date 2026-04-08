#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i]) !=mp.end()){
                return{mp[target-nums[i]], i};

            }
            mp[nums[i]]=i;
        }
        return {};
    }
};   

int main(){
    Solution sol;
    vector<int> nums = { 2, 7, 3, 1, 4};
    int target = 9;


    vector<int> result = sol.twoSum(nums, target);

    
    if(!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0; 
   
}
