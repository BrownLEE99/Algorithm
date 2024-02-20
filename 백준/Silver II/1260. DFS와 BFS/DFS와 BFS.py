from collections import deque

N, M, V = map(int, input().split())
adj = [[] for _ in range(N+1)]

for _ in range(M):
    s, e = map(int, input().split())
    adj[s].append(e)
    adj[e].append(s)
    adj[s].sort()
    adj[e].sort()

visited = [False] * (N+1)


def dfs(node):
    if visited[node]:
        return
    print(node, end=' ')
    visited[node] = True
    for i in range(len(adj[node])):
        nxt = adj[node][i]
        dfs(nxt)


def bfs(start):
    queue = deque([start])
    visited[start] = True
    while queue:
        node = queue.popleft()
        print(node, end=' ')
        for nxt in adj[node]:
            if not visited[nxt]:
                visited[nxt] = True
                queue.append(nxt)


dfs(V)
print()
visited = [False] * (N + 1)
bfs(V)