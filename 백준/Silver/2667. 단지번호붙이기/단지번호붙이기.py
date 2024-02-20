from collections import deque

N = int(input())
house = [input() for _ in range(N)]
check = [[False] * N for _ in range(N)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]


def bfs(x,y):
    sum = 0
    check[x][y] = True
    queue = deque([(x,y)])

    while queue:
        t = queue.popleft()
        sum += 1
        for i in range(4):
            nx = t[0] + dx[i]
            ny = t[1] + dy[i]

            if 0 <= nx < N and 0 <= ny < N and not check[nx][ny] and house[nx][ny] == '1':
                check[nx][ny] = True
                queue.append((nx,ny))

    return sum


answer = []
for i in range(N):
    for j in range(N):
        if house[i][j] == '1' and not check[i][j]:
            answer.append(bfs(i,j))


print(len(answer))
answer.sort()
for a in answer: print(a)
