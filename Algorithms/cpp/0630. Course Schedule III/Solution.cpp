class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        priority_queue<int, vector<int>, less<int> >pq;
        int cur_total_time = 0;
        for(auto course:courses){
            if(cur_total_time + course[0] <= course[1]){
                cur_total_time += course[0];
                pq.push(course[0]);
            }
            else if(!pq.empty() && pq.top() > course[0]){
                // 当前的撑不下，拿出最长的替换
                cur_total_time += (course[0] - pq.top());
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size();
    }
};