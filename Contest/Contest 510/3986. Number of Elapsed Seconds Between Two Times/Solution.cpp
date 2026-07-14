// https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        auto to_hour = [](string timeStamp) -> int {
            return stoi(timeStamp.substr(0, 2));
        };
        auto to_minute = [](string timeStamp) -> int {
            return stoi(timeStamp.substr(3, 2));
        };
        auto to_seconds = [](string timeStamp) -> int {
            return stoi(timeStamp.substr(6, 2));
        };
        int endSeconds = to_hour(endTime)*3600 + to_minute(endTime)*60 + to_seconds(endTime);
        int startSeconds = to_hour(startTime)*3600 + to_minute(startTime)*60 + to_seconds(startTime);
        return endSeconds - startSeconds;
    }
};