// https://leetcode-cn.com/problems/unique-email-addresses/

class Solution {
public:
    string get_true_str(string email) {
        int l = 0, r = 0;
        string temp;
        while(r < email.size() && email[r] != '+'){
            if(email[r]=='.'){
                temp += email.substr(l, r - l);
                l = r + 1;
            }
            r++;
        }
        if(l < r) temp += email.substr(l, r - l);
        return temp;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(string& email:emails){
            int idx = email.find('@');
            s.insert(get_true_str(email.substr(0, idx)) + email.substr(idx));
        }
        return s.size();
    }
};