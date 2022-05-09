# 7. 이진 탐색

## 7-1. 순차 탐색

- N개의 데이터가 있을 때, 그 데이터를 차례대로 하나씩 확인하는 것
- $O(N)$

```python
def sequnetial_search(n, target, array):
	for i in range(n):
    	if array[i] == target:
        	return i + 1 #현재 위치 반환, 인덱스 + 1
```

## 7-2. 이진 탐색

- 반으로 쪼개면서 탐색하기.
- 내부의 데이터가 **정렬**되어 있어야 한다.
- $O(log{N})$
- `시작점`, `끝점`, `중간점`

```python
# 재귀
def binary_search(array, target, start, end):
	if start > end:
    	return None
	mid = (start+end)//2
    if array[mid] == target:
    	return mid
	elif array[mid] > target:
    	return binary_search(array, target, start ,mid-1)
	else:
    	return binary_search(array, target, mid+1, end)

# 반복문
def binary_search(array, target, start, end):
	while start<= end:
    	mid = (start+end)//2
	if array[mid] == target:
    	return mid
	elif array[mid] > target :
    	end = mid -1
	else :
    	start = mid +1
return None
```

c++로 구현한 이진탐색은 다음과 같다.

```cpp
int binary_serach(int data[], int size, int d){
	int s =0;
    int e = size -1;
    int m = 0;
    while (s <= e){
    	m = (s+e)/2;
        if(data[m]==d) return m;
        else if (data[m] >d) e= m-1;
        else s = m+1;
    }
    return -1;
}
```

## 7-3. 트리 자료구조

- 항상 데이터가 정렬된 자료구조
- 데이터가 많아도 (비교적) 속도가 빠르다.
- 부모노드 & 자식노드
- 최상단 노드 => 루트, 최하단 노드 => 단말 노드
- 트리의 일부분도 트리이며, 이를 서브트리라고 한다.
- 파일 시스템과 가이 계층적이고 정렬된 데이터를 다루기에 적합

## 7-4. 이진 탐색 트리

- 부모 노드보다 왼쪽 자식 노드가 작다.
- 부모 노드보다 오른쪽 자식 노드가 크다.

## 7-5. 실전문제

### 7-5-1. 부품찾기

동빈이네 전자 매장에는 부품이 N개 있다. (부품마다 고유번호 존재한다.)
어느날 손님이 M개 종류의 부품을 대량 구매하겠다고 한다.
문의한 부품 M개종류를 모두 확인해서 가게안에 부품이 존재하는지 확인해보자.

- 첫째 줄에 정수 N 이 주어진다. $1\leq N \leq 1,000,000 $
- 둘째 줄에 N개의 정수가 주어진다. 1보다 크고 1,000,000 이하다.
- 셋째 줄에 M이, 4째줄에 공백으로 구분하여 M개의 정수가 주어진다. 정수는 1도가 크고 10억 이하이다.
- 셋째 줄에 공백으로 각 부품이 존재하는지 yes/no로 출력하라.

```cpp
// 부품찾기
// binary_Serach

#include <bits/stdc++.h>
using namespace std;

bool bs(vector<int>& data, int target){
    int start = 0;
    int end = data.size()-1;
    int mid = 0;
    while(start<=end){
        mid = (start+end)/2;
        if(data[mid]==target){
            return true;
        }
        else if(target>data[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}

int N, M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> store(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> store[i];
    }
    cin>>M;
    vector<int> request(M,0);
    for (int i = 0; i < M; i++)
    {
        cin >> request[i];
    }
    for(int i=0; i<M; i++){
        if(bs(store, request[i])){
            cout<<"yes ";
        }
        else cout<<"no ";
    }
}
```

이 문제는 계수정렬, 또는 set로도 풀 수 있다. (N의 범위가 백만 이하이기에)

### 7-5-2. 떡볶이 떡 만들기

- 떡볶이 떡의 길이가 일정하지 않다.
- 한 봉지 안에 들어가는 떡의 총길이를 절단기로 잘라서 맞춰준다.
- 절단기에 높이(H)를 지정하면 줄지어진 떡을 한번에 절단한다. 절단기 보다 높이가 긴 떡은 H위 부분이 잘리고, 낮은 떡은 잘리지 않는다.
- 손님은 잘린 떡 위를 가져간다.

손님이 왔을때 요청한 총 길이가 M일 때 적어도 M만큼의 떡을 얻기 위해 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

- 첫째 줄에 떡의 개수 N, 요청한 떡의 길이 M이 주어진다. ($1\leq N \leq 1,000,000, 1 \leq M \leq 2,000,000,000$)
- 둘째 줄에는 떡의 개별 높이가 주어진다. 떡 높이의 총합은 항상 M이상이고, 높이는 10억보다 작거나 같은 양의 정수 또는 0이다.
- 적어도 M만큼의 떡을 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.

```cpp
#include <bits/stdc++.h>

using namespace std;

int N, M;
int max_el;
vector<int> rcs;

int get_left_rcs(int standard)
{
    if(standard >= max_el) return 0; //max_el부터 탐색했으면 이런 문제가 없었을 텐데..
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (standard < rcs[i])
            result += rcs[i] - standard;
    }
    return result;
}

int guillotine()
{
    int answer = 0;
    int start = 0;
    int end = 2000000000;
    int mid = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int result = get_left_rcs(mid);
        if (result >= M)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    rcs.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> rcs[i];
    }
    sort(rcs.begin(), rcs.end());
    max_el = rcs[N-1];
    cout << guillotine();
}
```

전형적인 이진 탐색 문제이자 `파라메트릭 서치(Parametric Search)` 문제이다.
최적화문제를 결정 문제로 바꾸어 해결하는 기법이다.원하는 조건을 만족하는 가장 알맞는 값을 찾는 문제에서 자주 이용된다.

- ex) 범위 내 조건을 만족하는 가장 큰값 -> 이진 탐색으로 결정 문제 해결하며 범위를 좁혀감

이번 문제의 경우 절단기 높이(탐색 범위)는 1~10억 정수중 하나인데, 절단기 높이가 10억이므로, 이진 탐색을 이용하면 31*\N 즉, 최대 3,000만 번 정도의 연산으로 문제를 풀 수 있다.
파라메트릭 서치의 경우 재귀적으로 구하면 귀찮아 지기 때문에, 반복문을 이용하면 더 간단하게 풀 수 있다.
