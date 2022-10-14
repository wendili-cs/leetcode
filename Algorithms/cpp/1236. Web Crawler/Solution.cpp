// https://leetcode.com/problems/web-crawler/

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        auto find_hostname = [](string &url) -> string {
            int cnt = 0;
            for(int i = 0; i < url.length(); i++){
                if(url[i] == '/') cnt++;
                if(cnt == 3) return url.substr(0, i);
            }
            return url;
        };
        string host_name = find_hostname(startUrl);
        unordered_set<string> urls;
        urls.insert(startUrl);
        vector<string> res = {startUrl};
        function<void(string)> recur;
        recur = [&](string url) -> void {
            vector<string> parsed = htmlParser.getUrls(url);
            for(string str:parsed){
                if(urls.find(str) == urls.end() && find_hostname(str) == host_name){
                    res.push_back(str);
                    urls.insert(str);
                    recur(str);
                }
            }
        };
        recur(startUrl);
        return res;
    }
};