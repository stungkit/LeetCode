class Solution {
    int dp[50005][1<<4];
    
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) 
    {
        int m = target.size();
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        int ret = INT_MAX/2;
        
        for (int state = 0; state < (1<<m); state++) 
            dp[0][state] = INT_MAX/2;
        dp[0][0] = 0;

        for (int i=1; i<=n; i++)
            for (int state = 0; state < (1<<m); state++) 
            {
                dp[i][state] = dp[i-1][state];
                for (int subset=state; subset>0; subset=(subset-1)&state)
                {
                    long long L = 1;
                    for (int j=0; j<m; j++)
                    {
                        if ((subset>>j)&1)
                            L = lcm(L, target[j]);
                        if (L>INT_MAX/2) break;
                    }
                    if (L>INT_MAX/2) continue;
                    int cost = (nums[i]%L==0)?0:(L-nums[i]%L);
                    dp[i][state] = min(dp[i][state], dp[i-1][state-subset] + cost);
                }
            }
        
        return dp[n][(1<<m)-1];
    }
};
