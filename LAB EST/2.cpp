class Solution {
    public:
        int dp[40001][21];
        int target, n;
        int add = 20000;
        int helper(int i, int curr, vector<int> &nums){
            if(i == n){
                // cout << curr << endl;
                if(curr == target) return 1;
                return 0;
            }
            else if(dp[curr + add][i] != -1) return dp[curr + add][i];
    
            return dp[curr+add][i] = helper(i+1, curr+nums[i], nums) + helper(i+1, curr - nums[i], nums);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            this->target = target;
            n = nums.size();
            memset(dp, -1, sizeof(dp));
    
            return helper(0, 0, nums);
        }
    };
