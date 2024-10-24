// https://leetcode.com/problems/word-break-ii/

public class Solution {
    public List<string> dfs(string s, ref HashSet<string> set, ref Dictionary<string, List<string>> memo){
        if(memo.ContainsKey(s)){
            return memo[s];
        }
        List<string> result = new List<string>();
        if(set.Contains(s)) result.Add(s);
        for(int len = 0; len < s.Length; len++){
            string prefix = s.Substring(0, len), suffix = s.Substring(len);
            if(set.Contains(prefix)){
                List<string> suffixRet = dfs(suffix, ref set, ref memo);
                foreach(string ret in suffixRet){
                    result.Add(prefix + " " + ret);
                }
            }
        }
        memo[s] = result;
        return result;
    }

    public IList<string> WordBreak(string s, IList<string> wordDict) {
        HashSet<string> set = new HashSet<string>();
        foreach(string str in wordDict) set.Add(str);
        Dictionary<string, List<string>> memo = new Dictionary<string, List<string>>();
        return dfs(s, ref set, ref memo);
    }
}