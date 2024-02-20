from collections import deque

N, M = map(int, input().split())
list = [[0] * M for _ in range(N)]
for i in range(N):
    str = input()
    for j in range(len(str)):
        list[i][j] = int(str[j])


visited = [[False] * M for _ in range(N)]

queue = deque([(0,0,1)])
visited[0][0] = True
dx = [-1,1,0,0]
dy = [0,0,1,-1]
while queue:
    t = queue.popleft()
    #print(t)
    if t[0] == (N-1) and t[1] == (M-1):
        print(t[2])
        break
    for i in range(4):
        nx = t[0] + dx[i]
        ny = t[1] + dy[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if not visited[nx][ny] and list[nx][ny] == 1:
            queue.append((nx,ny,t[2]+1))
            visited[nx][ny] = True

