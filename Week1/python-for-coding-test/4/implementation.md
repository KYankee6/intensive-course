![](https://velog.velcdn.com/images/petit-prince/post/b40f53fc-0d34-419c-affa-79ff822bc2f9/image.png "문제를 해결하는 과정")

# 아이디어를 코드로 바꾸는 구현
- 코딩테스트에서 구현이란 `머릿속에 있는 알고리즘을 소스코드로 바꾸는 과정`이다.
- 코드 작성 속도가 빠르다 = 피지컬이 좋다
- 완전탐색, 시뮬레이션 
	완전탐색) 모든 경우의 수를 모두 계산
    시뮬레이션) 문제에서 제시한 알고리즘에 맞게 한단계씩 구현
- ex) 순열/조합 구하기, N\*M 지도에서 (방향) 이동 

## 4.1 상하좌우
여행가 A씨가 N\*N 크기의 정사각형 공간 위에 서있다.
가장 왼쪽 위 좌표는 (1,1), 가장 오른쪽 아래 좌표는 (N,N)에 해당한다.
상(U), 하(D), 좌(L), 우(R)로 이동할 수 있으며, 시작 좌표는 항상 (1,1)이다.
만약 N\*N 크기의 정사각형 공간을 벗어난다면, 움직임을 무시한다.
지도와 계획서가 주어질때 여행가 A가 최종적으로 도착하는 곳을 출력하는 프로그램 작성하시오.
```cpp
#include <bits/stdc++.h>
#define in_range(x, y) x >= 0 && y >= 0 && x < N &&y < N
using namespace std;
int N;

pair<int, int> get_next_pos(pair<int, int> cur_pos, char dir)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int idx;
    switch (dir)
    {
    case 'U':
        idx = 0;
        break;
    case 'R':
        idx = 1;
        break;
    case 'D':
        idx = 2;
        break;
    case 'L':
        idx = 3;
        break;
    }
    pair<int, int> next_pos = make_pair(cur_pos.first + dx[idx], cur_pos.second + dy[idx]);
    if (in_range(next_pos.first, next_pos.second))
        return next_pos;
    else
        return cur_pos;
}

int main()
{
    char c;
    pair<int, int> cur_pos = make_pair(0, 0);
    cin >> N;
    while(cin>>c)
    {
        cur_pos = get_next_pos(cur_pos, c);
    }
    cout << cur_pos.first + 1 << " " << cur_pos.second + 1;
}
```

## 4-2 시각
(이 문제는 파이썬으로 푸는 방법이 편해보여서 보여서 가져옴)
정수 N이 입력되면 00시 00분 00초부터 N($0\leq N \leq23$)시 59분 59초 까지의 모든 시각중 3이 하나라도 포함되는 모든 경우의 수를 구하시오.
$60*60*24 = 86400$이므로 하나하나 구할 수 있다.
```python
h = int(input())
count = 0

for i in range(h+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i)+str(j)+str(k):
                count+=1

print(count)
```

이후 문제는 [깃허브](https://github.com/KYankee6/intensive-course/tree/main/Week1/python-for-coding-test/4)에 작성중입니다.
