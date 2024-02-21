from collections import deque

N, M = map(int,input().split())
L = [list(map(int,input().split())) for _ in range(N)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
year = 1
while True:
    melt = [[0] * M for _ in range(N)]
    # 빙산을 먼저 녹인다
    for i in range(1,N):
        for j in range(1,M):
            count = 0
            for x in range(4):
                nx = i + dx[x]
                ny = j + dy[x]
                if 0 <= nx < N and 0 <= ny < M and L[nx][ny] == 0:
                    count += 1
            melt[i][j] = count
    ice = 0
    start = (0,0)
    for i in range(1,N):
        for j in range(1,M):
            L[i][j] = L[i][j] - melt[i][j]
            L[i][j] = 0 if L[i][j] < 0 else L[i][j]
            if L[i][j] > 0:
                ice += 1
                start = (i,j)
    if ice == 0:
        print(0)
        break
    queue = deque([start])
    visited = [[False]*M for _ in range(N)]
    visited[start[0]][start[1]] = True
    space = 0
    while queue:
        t = queue.popleft()
        space += 1
        for i in range(4):
            nx = t[0] + dx[i]
            ny = t[1] + dy[i]
            if L[nx][ny] >= 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                queue.append((nx,ny))
    if space != ice:
        print(year)
        break
    # bfs로 빙산이 분리되었는지를 확인한다.
    # bfs로 아무 빙산에서 시작해서 총 빙산의 개수와 일치하면 아직 안나뉜것
    year += 1