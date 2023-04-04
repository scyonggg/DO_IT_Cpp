## 입력을 위한 전형적인 소스코드

> e.g. input example

    5
    65 90 75 34 99

> Code:
```Python
n = int(input())
data = list(map(int, input().split()))
```

> 입력의 개수가 많은 경우
```python
import sys
sys.stdin.readline().rstrip()
```
- sys 라이브러리를 사용할 때는 한 줄 입력을 받고 나서 rstrip() 함수를 꼭 호출.
    - `readline()`으로 입력하면 입력 후 엔터가 줄 바꿈 기호로 입력됨

## 주요 라이브러리의 문법과 유의점
- 파이썬 표준 라이브러리
    - https://docs.python.org/ko/3/library/index.html

- 알아둬야할 6가지 라이브러리
    - 내장 함수: print(), input(), sorted() 등
    - itertools: 파이썬에서 반복되는 형태의 데이터를 처리하는 기능. 순열과 조합 라이브러리 제공
    - heapq: 힙(Heap) 기능을 제공하는 라이브러리. 우선순위 큐 기능 구현에 사용
    - bisect: 이진 탐색(Binary Search) 기능 제공
    - collections: 덱(deque), 카운터(Counter)등의 유용한 자료구조
    - math: 필수적인 수학적 기능. 팩토리얼, 제곱근, 최대공약수, 삼각함수 관련 함수, 파이(pi)와 같은 상수

- 내장 함수
    - eval() : 수학 수식이 문자열 형식으로 들어오면 해당 수식을 계산한 결과 반환
        ```python
        result = eval("(3+5)*7")
        print(result)  # 56
        ```
    - sorted() : iterable 객체가 들어왔을 때 정렬된 결과 반환.
        - key 속성으로 정렬 기준 명시 가능.
        - reverse 속성으로 뒤집을 수 있음.
    ```python
    result = sorted([9, 1, 8, 5, 4])
    print(result)  # 1, 4, 5, 8, 9

    result = sorted([9, 1, 8, 5, 4], reverse = True)
    print(result)  # 9, 8, 5, 4, 1

    # 튜플의 두 번째 원소를 기준으로 내림차순 정렬
    result = sorted([('홍길동', 35), ('이순신', 75), ('아무개', 50)], key = lambda x: x[1], reverse = True)
    print(result)  # [('이순신', 75), ('아무개', 50), ('홍길동', 35)]

    # 내장된 sort() 함수
    data = [9, 1, 8, 5, 4]
    data.sort()
    print(data)  # [1, 4, 5, 8, 9]
    ```

    - itertools
        - 반복되는 데이터를 처리하는 기능. permutations, combination 등.
    1. permutations
    ```python
    from itertools import permutations

    data = ['A', 'B', 'C']  # 데이터 준비
    result = lsit(permutations(data, 3))
    print(result)  # [('A', 'B', 'C'), ('A', 'C', 'B'), ..., ('C', 'B', 'A')]
    ```
    
    2. combinations

    ```python
    from itertools import combinations
    
    data = ['A', 'B', 'C']
    result = list(combinations(data, 2))
    print(result)  # [('A', 'B'), ('A', 'C'), ('B', 'C')]
    ```

    3. product
    - permutations과 같으나, 원소를 중복하여 뽑기 가능.
    ```python
    from itertools import product

    data = ['A', 'B', 'C']
    result = list(product(data, repeat=2))

    print(result)  # [('A', 'A'), ('A', 'B'), ('A', 'C'), ('B', 'A'), ('B', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'B'), ('C', 'C')]
    ```

    4. combinations_with_replacement
    - combinations와 같으나, 원소 중복하여 뽑기 가능
    ```python
    from itertools import combinations_with_replacement

    data = ['A', 'B', 'C']
    result = list(combinations_with_replacement(data, repeat=2))
    print(result)  # [('A', 'A'), ('A', 'B'), ('A', 'C'), ('B', 'B'), ('B', 'C'), ('C', 'C')]

- heapq
    - 최소 힙 (Min Heap) 제공. PriorityQueue 라이브러리를 사용할 수 있지만, 코테 환경에서는 보통 heapq가 더 빠르다고 함.
    - `heapq.heappush()` : 원소 삽입
    - `heapq.headpop()` : 원소 꺼내기
    - 힙 정렬 (Heap Sort) 예시
    ```python
    import heapq

    def heapsort(iterable):
        h = []
        result = []
        # Insert all elements into heap
        for value in iterable:
            heapq.headpush(h, value)
        # Pop all elements from heap into result
        for i in range(len(h)):
            result.append(heapq.headpop(h))
        return result

    result = heapsort([1, 3, 5, 7, 9, 2, 4, 6, 8, 0])
    print(result)  # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    ```
    - 최대 힙 (Max Heap) 쓰려면, 원소의 부호를 임시로 변경하는 방식을 사용해야함.
    ```python
    import heapq

    def heapsort(iterable):
        h = []
        result = []
        # Insert all elements into heap
        for value in iterable:
            heapq.heappush(h, -value)
        # Pop all elements from heap into result
        for value in range(len(h)):
            result.append(-heapq.heappop(h))
        return result

    result = heapsort([1, 3, 5, 7, 9, 2, 4, 6, 8, 0])
    print(result)  # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    ```

- collections
    - 유용한 자료구조 제공. `deque`와 `Counter` 두 가지 자주 씀.
    - `deque` : 보통 파이썬에서 큐 구현
        - `popleft()` : 첫 번째 원소 제거
        - `pop()` : 마지막 원소 제거
        - `appendleft(x)` : 첫 번째 인덱스에 원소 x 삽입
        - `append(x)` : 마지막 인덱스에 원소 x 삽입
    - `Counter` : 등장 횟수를 세는 기능 제공. 리스트와 같은 iterable 객체가 주어졌을 때, 해당 객체 내부의 원소가 몇 번씩 등장했는지를 알려준다.
    ```python
    from collections import Counter

    counter = Counter(['red', 'blue', 'red', 'green', 'blue', 'blue'])

    print(counter['blue'])  # 3
    print(counter['green'])  # 1
    print(dict(counter))  # {'red': 2, 'blue': 3, 'green': 1}
    ```

- math
    - 자주 사용되는 수학적인 기능. 팩토리얼, 제곱근, 최대공약수 등등.
    - `factorial(x)` : x! 반환
    ```python
    import math
    print(math.factorial(5))  # 120
    ```
    - `sqrt(x)` : x의 제곱근 반환
    ```python
    import math
    print(math.sqrt(7))  # 2.645...
    ```
    - `gcd(a, b)` : a와 b의 최대 공약수 반환
    ```python
    import math
    print(math.gcd(21, 14))  # 7
    ```
    - `math.pi`, `math.e` : 파이 및 자연상수 e 반환
    ```python
    import math
    print(math.pi)
    print(math.e)
    ```