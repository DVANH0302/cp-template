def isPalindrome(x):
    if x % 10 == 0:
        return False
    y = 0
    l = 0
    while y < x:
        x, r = divmod(x, 10)
        y = y * 10 + r
        l += 1 

    if l % 2 == 0:
        return y == x 
    else:
        return y // 10 == x


x = 3
print(isPalindrome(x))