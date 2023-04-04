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
    - 힙 (Heap)