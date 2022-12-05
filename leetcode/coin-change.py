class Solution:

    def coinChange(self, coins: list[int], amount: int) -> int:
        n = len(coins)
        dp = [float('inf')]*(amount+1)

        def getMinCoins(amount):
            if amount==0:
                dp[amount] = 0
                return dp[amount]
            if n<0:
                return float('inf')
            if dp[amount]!=float('inf'):
                return dp[amount]
            
            for coin in coins:
                if amount<coin:
                    continue
                dp[amount] = min(dp[amount], 1 + getMinCoins(amount-coin))

            return dp[amount]
        ans = getMinCoins(amount)
        return -1 if ans==float('inf') else ans