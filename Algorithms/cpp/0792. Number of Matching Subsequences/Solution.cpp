// https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<string*> > cnt(26);
        for(string& word:words){
            reverse(word.begin(), word.end());
            cnt[word.back()-'a'].push_back(&word);
        }
        int res = 0;
        for(char& sc:s){
            int vsize = cnt[sc-'a'].size();
            for(int i = 0; i < vsize; i++){
                string *sptr = cnt[sc-'a'][i];
                sptr->pop_back();
                char c = sptr->back();
                if(sptr->empty()) res++;
                else{
                    cnt[sptr->back()-'a'].push_back(sptr);
                }
            }
            cnt[sc-'a'].erase(cnt[sc-'a'].begin(), cnt[sc-'a'].begin()+vsize);
        }
        return res;
    }
};