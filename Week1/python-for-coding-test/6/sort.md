# 정렬

## 6-1. 기준에 따라 데이터를 정렬

`정렬`이란 데이터를 특정한 기준에 따라서 순서대로 나열하는 것을 말한다.
- 이진 탐색의 전처리 과정이기도 하다.
- 선택 정렬, 삽입 정렬, 퀵 정렬, 계수 정렬
- 리스트를 뒤집는 연산은 O(N)의 복잡도

## 6-2. 선택 정렬
가장 작은 데이터를 선택해 맨 앞에 있는 데이터와 바꾸고 이를 반복한다.
```python
array = [7,5,9,0,3,1,6,2,4,8]

for i in range(len(array)):
	min_idx = i;
	for j in range(i+1, len(array)):
    	if array[min_idx] > array[j]:
        	min_idx = j
	array[i], array[min_idx] = array[min_idx], array[i]

print(array)
```
- 선택 정렬은 N-1번 만큼 가장 작은 수를 찾아서 맨 앞으로 보낸다.
- $N-1 + N-2 + \ldots + 2 \approx \frac{N\times(N+1)}{2}$  
- $O(N^2)$ => 그다지 효율적이지 못하다.

## 6-3. 삽입 정렬
데이터를 하나씩 확인하며, 각 데이터를 적절한 위치에 삽입하면 어떨까?
- 선택정렬에 비해 시간측면에서 더 효율적인 알고리즘
- '데이터가 거의 정렬 되어 있을 떄' 효율적이다.
- 선택정렬(모든 원소 확인)과 다르다.
- 그 앞까지 데이터는 이미 정렬되어 있다고 가정한다.
- 정렬이 된 원소는 항상 오름차순을 유지하고 있다.
- 삽입될 위치를 선정할 때, 삽입될 데이터 그 위치에서 멈추면 된다.

```python
array = [7, 5, 9, 9, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
	for j in range(i, 0, -1):
    if array[j]<array[j-i[:
    	array[j], array[j-1] = array[j-1], array[j]
	else:
    	break;

print(array)
```

- 삽입 정렬의 시간복잡도 = $O(N^2)$
- 그러나, 현재 리스트의 데이터가 거의 정렬되어 있는 상태라면 매우 빠르게 동작 $\approx O(N)$
- 대부분 정렬 되어있다면, 퀵 정렬보다 강력하다

## 6-4 퀵 정렬
기준 데이터를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸자

- 피벗(pivot, 기준)이 사용된다.
- 어떻게 피벗을 설정하는 가 => 호어 분할(리스트의 첫번째를 선택)이 대표적이다.
- 먼저 첫번째를 피벗으로 정하고, 왼쪽에서 피벗보다 큰 수를, 오른쪽에서 피벗보다 작은 수를 선택한다.
- 둘의 위치를 바꾸고 반복한다.
- 단, 왼쪽에서부터 찾는 값과 오른쪽에서 부터 찾는 값의 위치가 서로 엇갈릴 때, '작은 데이터'와 '피벗'의 위치를 서로 변경한다

```python
array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(array, start, end):
	if start >= end: # 원소가 1개인 경우
    	return
    pivot = start 
    left = start + 1
    right = end
    while left <= right:
    	while left <= end and array[left] <= array[pivot]
        	left +=1
		while right > start and array[right] >= array[pivot]
        if left > array: # 엇갈렸다면 작은 right -= 1 데이터와 피벗을 교체
        	array[right], array[pivot] = array[pivot], array[right]
		else:
        	array[left], array[right] = array[right], array[left]
	quick_sort(array,start, right-1)
    quick_sort(Array,right +1, end)

quick_sort(array, 0, len(array)-1)
print(arary)
```
아래는 직관적이나, 조금 비효율적인 코드이다.
```python
array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(array):
	if(len(array)==1):
    	return
	
    pivot = array[0]
    tail = array[1:]
    
    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x> pivot]
    
    return quick_sort(left_side) + [pivot] + quick_sort(right_side)
```

- 퀵 정렬의 평균 시간 복잡도는 $O(Nlog{N})$로 빠른 편이다.
- 그러나 최악의 경우 시간 복잡도는 $(O(N^2))$이다.

## 6-5. 계수정렬
특정한 조건이 부합할 때만 사용할 수 있지만 매우 빠른 정렬 알고리즘이다.
모든 데이터가 양의 정수이고, 데이터의 수가 N, 최댓값이 K라면 계수 정렬은 최악의 경우에도 수행 시간 $O(N+K)$를 보장한다. (공간 복잡도 또한 $O(N+K)$)

- 데이터 값이 무한한 범위를 가질 땐 이용하기 어렵다.
```python
# 모든 원소의 값이 0보다 크거나 같다고 가정
array = [7, 5, 9, 1, 4, 7, 2, 5, 3]

# 모든 범위를 포함하는 리스트 (0으로 초기화)
count = [0]*(max(array)+1)

for i in range(len(array)):
	count[array[i]] += 1

for j in range(len(count)):
	for j in range(count[i]):
    	print(i, end=' ')
        
```

> C++에서는 map을 정렬하는 함수가 없다. (기본적으로 Key 기준 정렬으로 알고 있음)
> 그러므로 성적이 낮은 순서로 출력하기 문제를 풀려면 아래와 같이 해결해야한다.
> ```cpp
>#include <bits/stdc++.h>
>using namespace std;
>
>bool compare(pair<string, int> p1, pair<string, int> p2)
>{
>    return p1.second < p2.second;
>}
>
>int main()
>{
>    ios::sync_with_stdio(false);
>    cin.tie(nullptr);
>    cout.tie(nullptr);
>
>    int N;
>    map<string, int> m;
>    cin >> N;
>    for (int i = 0; i < N; i++)
>    {
>        string s;
>        int val;
>        cin >> s >> val;
>        m[s] = val;
>    }
>    vector<pair<string,int>> v(m.begin(),m.end());
>    sort(v.begin(),v.end(),compare);
>    for (auto p : v)
>    {
>        cout << p.first << " ";
>    }
>    return 0;
>}
>```
> 이런 문제를 볼 때마다 파이썬이 참 강력하다 싶다.

## 연습문제
성적이 낮은 순서대로 출력하기
```python
n = int(input())

array = []
for i in range(n):
	input_data = input().split()
    array.append((input_data[0], int(input_data[1])))
array = sorted(array, key=lambda student: student[1])
```
