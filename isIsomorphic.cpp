class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> relationF;
        map<char, char> relationB;
        for(int i = 0; i < s.size(); ++i){
            map<char, char>::iterator itF = relationF.find(s[i]);
            map<char, char>::iterator itB = relationB.find(t[i]);
            if(itF == relationF.end()){
                relationF[s[i]] = t[i];
                if(itB != relationB.end() && itB->second != s[i])
                    return false;
                else
                    relationB[t[i]] = s[i];
            }else if(itF->second != t[i])
                return false;
        }
        return true;
    }
};
