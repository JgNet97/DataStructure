# 📌 Data Structure (자료구조)

## ✅ 선형 자료구조 (Linear Data Structure)
선형 자료구조는 데이터가 **순차적으로 저장**되는 구조로, **배열(Array), 연결 리스트(Linked List), 스택(Stack), 큐(Queue)** 등이 포함됨.

---

# 📌 Linked List (연결 리스트)

## ✅ 특징
- **중간 삽입/삭제 빠름** → O(1)  
- **탐색 느림** → O(n)  
- **메모리 사용 많음** (포인터 저장 필요)  
- **연속된 메모리 공간 필요 없음** (동적 할당 가능)  

## ✅ 종류
1. **단일 연결 리스트 (Singly Linked List)** → 노드가 하나의 방향으로 연결  
2. **이중 연결 리스트 (Doubly Linked List)** → 앞뒤 노드 모두 연결 (양방향)  
3. **원형 연결 리스트 (Circular Linked List)** → 마지막 노드가 첫 노드와 연결  

## ✅ 배열과 비교
|  | 배열 (Array) | 연결 리스트 (Linked List) |
|---|---|---|
| 크기 조절 | 고정 크기 | 동적 조절 가능 |
| 인덱스 접근 | O(1) | 불가능 (탐색 O(n)) |
| 중간 삽입/삭제 | O(n) | O(1) |

## ✅ 면접에서 자주 묻는 질문
- 배열과 연결 리스트의 차이점?  
- 중간 삽입/삭제의 시간 복잡도는?  
- **이중 연결 리스트의 장점?**  
- **원형 연결 리스트는 어디에 사용?**  
- **캐시 (LRU) 구현할 때 왜 Linked List를 쓰는가?**  

---

# 📌 Stack (스택)

## ✅ 특징
- **LIFO (Last In, First Out)** → 마지막에 들어온 데이터가 먼저 나감  
- **주요 연산**:  
  - `push()`: 요소 삽입 (O(1))  
  - `pop()`: 요소 제거 (O(1))  
  - `peek() / top()`: 최상단 요소 확인 (O(1))  
- **재귀 함수 호출 시 시스템 스택 사용**  

## ✅ 구현 방법
- **배열 기반 스택** (고정 크기, 연속된 메모리)  
- **연결 리스트 기반 스택** (동적 크기, 추가 메모리 필요)  

## ✅ 배열과 연결 리스트 비교
|  | 배열 기반 스택 | 연결 리스트 기반 스택 |
|---|---|---|
| 메모리 사용 | 고정 크기 | 동적 크기 (포인터 추가 메모리 필요) |
| 삽입/삭제 | O(1) (끝에서만 가능) | O(1) |
| 접근 속도 | O(1) (인덱스 접근 가능) | O(n) (탐색 필요) |

## ✅ 면접에서 자주 묻는 질문
- Stack의 원리 (LIFO)  
- **재귀 호출에서 Stack이 어떻게 사용되는지?**  
- **배열 기반 vs 연결 리스트 기반 Stack 차이점?**  
- **브라우저 뒤로 가기, 함수 호출 기록 등에 어떻게 활용?**  

---

# 📌 Queue (큐)

## ✅ 특징
- **FIFO (First In, First Out)** → 먼저 들어온 데이터가 먼저 나감  
- **주요 연산**:  
  - `enqueue()`: 요소 삽입 (O(1))  
  - `dequeue()`: 요소 제거 (O(1))  
  - `front()`: 맨 앞 요소 확인 (O(1))  
  - `rear()`: 맨 뒤 요소 확인 (O(1))  

## ✅ 종류
1. **일반 큐 (Queue)** → 기본적인 선입선출 구조  
2. **원형 큐 (Circular Queue)** → 배열 크기 고정 & 메모리 재사용  
3. **덱 (Deque, Double-ended Queue)** → 앞뒤 모두 삽입/삭제 가능  
4. **우선순위 큐 (Priority Queue)** → 값의 우선순위에 따라 정렬  

## ✅ 배열과 연결 리스트 비교
|  | 배열 기반 큐 | 연결 리스트 기반 큐 |
|---|---|---|
| 메모리 사용 | 고정 크기 | 동적 크기 (포인터 추가 필요) |
| 삽입/삭제 | O(1) (앞뒤 조작 비효율적) | O(1) (Head/Tail 관리) |
| 순환 구조 | 원형 큐로 해결 가능 | 필요 없음 |

## ✅ 면접에서 자주 묻는 질문
- **일반 Queue와 Circular Queue의 차이?**  
- **Deque는 언제 사용?**  
- **Stack과 Queue의 차이점?**  
- **BFS (너비 우선 탐색)에서 Queue가 왜 필요한가?**  
- **운영체제의 스케줄링, 캐시 구현, 네트워크 패킷 처리에서 어떻게 사용?**  
