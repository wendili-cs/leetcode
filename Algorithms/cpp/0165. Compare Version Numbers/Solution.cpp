// https://leetcode-cn.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        long long ver1, ver2;
        int idx1 = 0, idx2 = 0;
        int len1 = version1.length(), len2 = version2.length();
        while(idx1 < len1 && idx2 < len2){
            int strlen1 = 0, strlen2 = 0;
            while(idx1 + strlen1 < version1.length() && version1[idx1 + strlen1] != '.') strlen1++;
            while(idx2 + strlen2 < version2.length() && version2[idx2 + strlen2] != '.') strlen2++;
            ver1 = stoi(version1.substr(idx1, strlen1));
            ver2 = stoi(version2.substr(idx2, strlen2));
            idx1 += strlen1 + 1;
            idx2 += strlen2 + 1;
            if(ver1 > ver2) return 1;
            else if(ver1 < ver2) return -1;
        }
        while(idx1 < len1){
            int strlen1 = 0;
            while(idx1 + strlen1 < version1.length() && version1[idx1 + strlen1] != '.') strlen1++;
            ver1 = stoi(version1.substr(idx1, strlen1));
            idx1 += strlen1 + 1;
            if(ver1 > 0) return 1;
        }
        while(idx2 < len2){
            int strlen2 = 0;
            while(idx2 + strlen2 < version2.length() && version2[idx2 + strlen2] != '.') strlen2++;
            ver2 = stoi(version2.substr(idx2, strlen2));
            idx2 += strlen2 + 1;
            if(ver2 > 0) return -1;
        }
        return 0;
    }
};