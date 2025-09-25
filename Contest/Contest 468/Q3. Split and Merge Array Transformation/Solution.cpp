class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;

        map<vector<int>, int> dist;
        queue<vector<int>> q;

        dist[nums1] = 0;
        q.push(nums1);

        while (!q.empty()) {
            vector<int> cur = move(q.front());
            q.pop();
            int d = dist[cur];
            int n = cur.size();

            for (int L = 0; L < n; ++L) {
                for (int R = L; R < n; ++R) {
                    vector<int> removed(cur.begin() + L, cur.begin() + R + 1);
                    vector<int> remaining;
                    remaining.reserve(n - (R - L + 1));
                    remaining.insert(remaining.end(), cur.begin(), cur.begin() + L);
                    remaining.insert(remaining.end(), cur.begin() + R + 1, cur.end());

                    int m = remaining.size();
                    for (int pos = 0; pos <= m; ++pos) {
                        // reinserting at the same spot is a no-op; skip it
                        // After removal, the original position of the block translates to index L in 'remaining'
                        if (pos == L) continue;

                        vector<int> nxt;
                        nxt.reserve(n);
                        nxt.insert(nxt.end(), remaining.begin(), remaining.begin() + pos);
                        nxt.insert(nxt.end(), removed.begin(), removed.end());
                        nxt.insert(nxt.end(), remaining.begin() + pos, remaining.end());

                        if (!dist.count(nxt)) {
                            if (nxt == nums2) return d + 1;
                            dist[nxt] = d + 1;
                            q.push(move(nxt));
                        }
                    }
                }
            }
        }
        return -1;
    }
};