from functools import lru_cache
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def isScramble(self, A, B):
		if len(A) != len(B):
			return False
		n = len(A)
		@lru_cache(maxsize = None)
		def dp(sa, sb, length):

			if length == 1:
				return A[sa] == B[sb]
			
			for k in range(1, length):

				res = (dp(sa, sb, k) and dp(sa+k, sb+k, length-k)) or (
						dp(sa, sb+length-k, k) and dp(sa+k, sb, length-k))

				if res: 
					return True
			return False

		return 1 if dp(0, 0, n) else 0
	
A = "great"
B = "rgtae"


print(Solution().isScramble(A, B))

