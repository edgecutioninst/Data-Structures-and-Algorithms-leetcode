class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char,int> last;

        for(int i = 0; i < s.size(); i++) last[s[i]] = i;

        int partitionEnd = 0;
        int start = 0;
        vector<int> ans;

        for(int i = 0; i < s.size(); i++)
        {
            partitionEnd = max(partitionEnd, last[s[i]]);

            if(i == partitionEnd)
            {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};