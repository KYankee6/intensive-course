from collections import deque

queue = deque()
queue.append(1)
queue.popleft()
print(queue) # 먼저 들어온 순서대로 출력
queue.reverse()  # 다음 출력을 위해 연순으로 바꾸기
print(queue) # 나중에 들어온 원소부터 출력