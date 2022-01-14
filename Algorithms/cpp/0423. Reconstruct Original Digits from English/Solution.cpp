// https://leetcode.com/problems/reconstruct-original-digits-from-english/

class Solution {
public:
    string originalDigits(string s) {
        map<char, int>mp;
        for(char& c:s){
            mp[c]++;
        }
        vector<int> cnter(10, 0);
        cnter[0] = mp['z'];
        cnter[2] = mp['w'];
        cnter[4] = mp['u'];
        cnter[6] = mp['x'];
        cnter[8] = mp['g'];
        cnter[1] = max(0, mp['o'] - cnter[0] - cnter[2] - cnter[4]);
        cnter[3] = max(0, mp['t'] - cnter[2] - cnter[8]);
        cnter[5] = max(0, mp['f'] - cnter[4]);
        cnter[7] = max(0, mp['v'] - cnter[5]);
        cnter[9] = max(0, mp['i'] - cnter[5] - cnter[6] - cnter[8]);
        string res;
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j < cnter[i]; j++){
                res.push_back(i + '0');
            }
        }
        return res;
    }
};