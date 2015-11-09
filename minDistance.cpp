class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> upline(word1.size() + 1, 0);
        vector<int> downline(word1.size() + 1, 0);
        for(int i = 0; i <= word1.size(); ++i)
            upline[i] = i;

        for(int i = 1; i <= word2.size(); ++i){
            downline[0] = i;
            for(int j = 1; j <= word1.size(); ++j){
                downline[j] = min(min(downline[j - 1] + 1, upline[j] + 1),
                                    (word1[j - 1] == word2[i - 1]) ? upline[j - 1] : upline[j - 1] + 1);
            }
            swap(upline, downline);
        }

        return upline.back();
    }
};