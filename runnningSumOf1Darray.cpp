#include<iostream>
#include<vector>

using namespace std;
class Solution
{
public :
  vector<int> runningSum(vector<int>& nums)
  {
    
    for(int i=1; i<nums.size(); i++)
    {
        nums[i]=nums[i-1]+nums[i];
    }
    return nums;
  }
};
int main()
{
   

    Solution sol; // Create an instance of the class
    vector<int> nums = {1, 2, 3, 4};
    
    vector<int> result = sol.runningSum(nums);

    // Print the result using a loop
    cout << "Running Sum: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}