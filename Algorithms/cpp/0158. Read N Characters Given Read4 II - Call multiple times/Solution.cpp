// https://leetcode-cn.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    char *temp4 = new char[4];
    int idx_written = 0, idx_read = 0, init = 1;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if(init){
            idx_read = read4(temp4);
            init = 0;
        }
        int i = 0;
        while(i < n && i < idx_read){
            buf[i++] = temp4[idx_written%4];
            idx_written++;
            if(idx_written%4 == 0) idx_read += read4(temp4);
        }
        idx_read -= i;
        return i;
    }
};