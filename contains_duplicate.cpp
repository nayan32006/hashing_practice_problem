#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int it: nums){
            mp[it]++;
        }

        for(auto it: mp){
            if(it.second > 1) return true;

        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 2, 3, 1};
    if (sol.containsDuplicate(test1)) {
        cout << "Test 1: Duplicate found!" << endl;
    } else {
        cout << "Test 1: No duplicates." << endl;
    }

    vector<int> test2 = {1, 2, 3, 4};
    if (sol.containsDuplicate(test2)) {
        cout << "Test 2: Duplicate found!" << endl;
    } else {
        cout << "Test 2: No duplicates." << endl;
    }

    return 0;
}