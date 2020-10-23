940. 不同的子序列 II.cpp
    public int distinctSubseqII(String s){
        int n = s.length(), mod = (int) 1e9 + 7;
        int[] dp = new int[n];
        char[] cs = s.toCharArray();
        int ans = 0;
        Arrays.fill(dp, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(cs[i] != cs[j]){
                    dp[i] = (dp[i] + dp[j]) % mod;
                }
            }
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
