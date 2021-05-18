# https://leetcode-cn.com/problems/compare-version-numbers/

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        ver_str1 = version1.split(".")
        ver_str2 = version2.split(".")
        i = 0
        while(len(ver_str1) > i and len(ver_str2) > i):
            ver1 = int(ver_str1[i])
            ver2 = int(ver_str2[i])
            if ver1 > ver2:
                return 1
            elif ver1 < ver2:
                return -1
            i += 1
        while(len(ver_str1) > i):
            ver1 = int(ver_str1[i])
            if ver1 > 0: return 1
            i += 1
        while(len(ver_str2) > i):
            ver2 = int(ver_str2[i])
            if ver2 > 0: return -1
            i += 1
        return 0