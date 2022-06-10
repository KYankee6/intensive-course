# 이걸 이렇게 빨리 풀 수 있다는 것을 상상도 못했음;
h = int(input())
count = 0

for i in range(h+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i)+str(j)+str(k):
                count+=1

print(count)