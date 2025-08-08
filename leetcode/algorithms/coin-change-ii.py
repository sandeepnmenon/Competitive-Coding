class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [[-1]*(amount+1) for _ in range(n+1)]
        def get_combinations(n, amount):
            if amount==0:
                dp[n][amount]=1
                return 1
            if n<0:
                return 0
            if dp[n][amount]!=-1:
                return dp[n][amount]

            if amount < coins[n]:
                dp[n][amount] = get_combinations(n-1,amount)
            else:
                dp[n][amount] = get_combinations(n-1,amount) + get_combinations(n,amount-coins[n])
            
            return dp[n][amount]

        ans = get_combinations(n-1, amount)
        return 0 if ans==-1 else ans
            