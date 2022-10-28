class Solution {
public:
    
    string longestPalindrome(string s) {
        int left = 0,mir=1,right=2;
        string tmp = "|";
        for(int i=0; i < s.length();i++) {
            tmp += s[i];
            tmp += "|";
        }
        
        int len[2 * s.length() + 1];
        
        len[0] = 0;
        len[1] = 1;
        int maxx = 2 * s.length() + 1;

        for(int i=2;i < maxx; i++) {
            if(i >= right) {
                mir = i;
                left = mir;
                right = mir;
                while(right + 1 < maxx && left - 1 >= 0 && tmp[right+1]==tmp[left-1]) {
                    right += 1;
                    left -= 1;
                }
                len[i] = mir - left;
                continue;
            }
            len[i] = len[mir - (i - mir)];
            len[i] = min(right-i, len[i]);
            if(i+len[i]+1 < maxx && i-len[i]-1 >= 0 && tmp[i+len[i]+1] == tmp[i-len[i]-1]) {
               mir = i;
               right = i + len[i] + 1;
                left = i - len[i] - 1;
                while(right + 1 < maxx && left - 1 >= 0 && tmp[right+1]==tmp[left-1]) {
                    right += 1;
                    left -= 1;
                }
                len[i] = mir - left;
                continue;
            }
        }
        
        int ans = 0;
        int ansi = -1;
        for(int i=0;i < maxx;i++) {
            if(len[i] > ans) {
                ans = len[i];
                ansi = i;
            }
        } 
        string res = "";
        for(int i=ansi-len[ansi]; i<=ansi+len[ansi];i++) {
            if(tmp[i] != '|') {
                res += tmp[i];
            }
        }
        return res;
    }
}; 