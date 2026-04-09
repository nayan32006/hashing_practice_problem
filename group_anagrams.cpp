#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution
{
public:
   vector<vector<string>> groupAnagrams(vector<string>& strs)
   {
    unordered_map<string, vector<string>> anagramGroups ;
    for(string s: strs)
    {
        string  key = s;
        sort(key.begin(), key.end());
        anagramGroups[key].push_back(s);

    }
    vector<vector<string>> result;
    for(auto const &[key, group]: anagramGroups)
    {
        result.push_back(group);

    }
    return result;
   }
};
int main()
{
    Solution sol;
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    cout << "Input: eat, tea, tan, ate, nat, bat" << endl;
    vector<vector<string>> result = sol.groupAnagrams(input);

    cout <<"Group Anagrams:"<<endl;
    for(auto const & group : result)
    {
        cout <<"[" ;
        for(const string & s :group)
        {
            cout << s <<" ";

        }
        cout <<"]" <<endl ;
    }
    return 0;

}
