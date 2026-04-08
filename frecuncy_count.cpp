#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> counts;
    int maxFreq = 0;

    for (int num : nums) {
        counts[num]++;
        maxFreq = max(maxFreq, counts[num]);
    }

    int totalMaxFrequency = 0;

    
    for (auto const& [num, freq] : counts) {
        if (freq == maxFreq) {
            totalMaxFrequency += freq;
        }
    }

    return totalMaxFrequency;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    cout << "Output: " << maxFrequencyElements(nums) << endl; 
    return 0;
}