class Solution:
    def waysToReachStair(self, k: int) -> int:
        @cache
        def dp(curr, j, prev):
          cnt = 0
          if curr == k:
            cnt += 1
          
          if prev != 0 and curr > 0:
            cnt += dp(curr - 1, j, 0)
          
          if (curr + 2 ** j - k) <= 1:
            cnt += dp(curr + 2**j, j + 1, 1)
          
          return cnt
        
        ret = dp(1, 0, None)
        dp.cache_clear()
        
        return ret