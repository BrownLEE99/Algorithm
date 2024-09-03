def solution(cards1, cards2, goal):
    c1 = list(map(lambda x : goal.index(x) if x in goal else -1,cards1))
    c2 = list(map(lambda x : goal.index(x) if x in goal else -1,cards2))
    while c1 and c1[-1] == -1:
        c1 = c1[:-1]
    while c2 and c2[-1] == -1:
        c2 = c2[:-1] 
    
    if len(c1) + len(c2) != len(goal):
        return "No"
        
    sort1 = sorted(c1)
    print(c1,sort1)
    if sort1 != c1:
        return "No"
    sort2 = sorted(c2)
    print(c2,sort2)
    if sort2 != c2:
        return "No"
    
    return "Yes"