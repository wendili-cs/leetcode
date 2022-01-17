// https://leetcode.com/problems/shortest-word-distance-ii/

class WordDistance {
public:
    map<string, vector<int>> mp;
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++) mp[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int ret = INT_MAX, l1 = 0, l2 = 0;
        while(l1 < mp[word1].size() && l2 < mp[word2].size()){
            ret = min(ret, abs(mp[word1][l1] - mp[word2][l2]));
            if(mp[word1][l1] < mp[word2][l2]) l1++;
            else l2++;
        }
        return ret;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */