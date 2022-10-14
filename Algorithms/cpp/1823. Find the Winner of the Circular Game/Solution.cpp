// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Basically, we know that at last, who ever gets the kth turn is lost. 
// Now this k is including the current player, so if the current player is x, we know x+k, will be the person just after person eliminated. 
// At last, the person 'just after the person eliminated' on the table will be the winner. 
// So in the recursion, one can say that base condition is number of players (n) == 1, so answer is the player sitting at index 0. 
// For rest of the number of players (2 to n), we know that answer will be-> F(n) = (F(n-1)+k)%n


class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for(int i = 2; i <= n; i++){
            res = (res + k) % i;
        }
        return res + 1; // index start from 1
    }
};