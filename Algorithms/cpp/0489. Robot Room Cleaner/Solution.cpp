// https://leetcode.com/problems/robot-room-cleaner/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void goBack(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }

    void cleanRoom(Robot& robot) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // order up, right, down, left
        set<pair<int, int>> s;
        function<void(int, int, int)> dfs;
        dfs = [&](int x, int y, int direction) -> void {
            s.emplace(x, y);
            robot.clean();
            for(int i = 0; i < 4; i++){
                int new_dir = (direction + i) % 4, nx = x + dirs[new_dir][0], ny = y + dirs[new_dir][1];
                if(s.find(make_pair(nx, ny)) == s.end() && robot.move()){
                    dfs(nx, ny, new_dir);
                    goBack(robot);
                }
                robot.turnRight();
            }
        };
        dfs(0, 0, 0);
        return;
    }
};