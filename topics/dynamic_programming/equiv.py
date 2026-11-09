def isEquiv(s1, s2): 
    n1, n2 = len(s1), len(s2)
        
    if n1 != n2:
        return False
    if s1 == s2:
        return True
    half = n1 // 2 
    x1 = s1[:half]
    x2 = s1[half:]
    
    y1 = s2[:half]
    y2 = s2[half:]

    return (isEquiv(x1, y1) and isEquiv(x2, y2)) or (isEquiv(x1, y2) and isEquiv(x2, y1)) 