// https://leetcode.com/problems/guess-the-word/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        auto check_sim = [](string &a, string &b){
            // get number of matching letters in two words
            int ret = 0;
            for(int i = 0; i < 6; i++){
                if(a[i] == b[i]) ret++;
            }
            return ret;
        };

        unordered_set<string> s(words.begin(), words.end()); // candidates of words
        string word = words[0];
        while(true){
            int num_match = master.guess(word);
            if(num_match == 6) return; // guess correctly
            s.erase(word);
            for(string tmp:words){
                if(s.find(tmp) == s.end()) continue;
                if(check_sim(tmp, word) != num_match){
                    s.erase(tmp);
                }
            }
            word = *(s.begin());
        }
    }
};