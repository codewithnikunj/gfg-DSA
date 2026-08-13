class Solution {
public:
    int nthRoot(int n, int m) {
        if (m == 0)
    return 0;
        
        for(int i = 1; i <= m; i++) {
            
            long long result = 1;
            
            for(int j = 1; j <= n; j++) {
                
                result *= i;
                
                if(result > m) {
                    break;
                }
            }
            
            if(result == m) {
                return i;
            }
        }
        
        return -1;
    }
};