from collections import deque

N = int(input())
adj = [[] for _ in range(N+1)]
for _ in range(int(input())):
    s, e = map(int,input().split())
    adj[s].append(e)
    adj[e].append(s)


def bfs():
    queue = deque([1])
    visited = [False] * (N+1)
    visited[1] = True
    count = -1
    while queue:
        node = queue.popleft()
        count += 1
        for nxt in adj[node]:
            if not visited[nxt]:
                visited[nxt] = True
                queue.append(nxt)
    print(count)


bfs()