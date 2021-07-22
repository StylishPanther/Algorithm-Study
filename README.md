# Algorithm Study

SW 직무 코딩테스트 통과를 위한 알고리즘 공부 내용

사용언어 : C/C++


## Index
  - [BFS](#BFS) 
  - [DFS](#DFS)
  - [DynamicProgramming](#DynamicProgrammingg)

---
## BFS (너비 우선 탐색)

<p align="center"><img src="./Images/Breadth-First-Search-Algorithm.gif" ></p>  
<p align="center"> < BFS Simulation ></p> 

>### BFS (Breadth First Search)

- 루트 노드(혹은 다른 임의의 노드)에서 시작해서 인접한 노드를 먼저 탐색하는 방법

- 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법이다.
즉, 넓게(wide) 탐색하는게 우선이고 그 다음 깊게(deep) 탐색을 수행한다.

- 사용하는 경우: 두 노드 사이의 최단 경로 혹은 임의의 경로를 찾고 싶을 때 이 방법을 선택한다.


>### BFS의 특징

 - 시작 지점에서 거리에 따라서 탐색하게 된다. 즉, 자동적으로 최단 혹은 최소 거리를 추출하게 된다.

 - 재귀적으로 동작하지 않는다.

 - 그래프 탐색의 경우, 어떤 노드를 방문했었는지 방문 여부를 기록해야 한다. 그렇지 않으면 무한 루프에 빠질 수 있다.
 - 일반적으로 먼저 방문한 노드와 연결된 노드들을 큐(Queue)에 저장해서 구현한다.

>### BFS의 시간복잡도

- 인접 리스트로 표현된 그래프: O(N+E) (N : 노드의 수, E : 간선의 수)

- 인접 행렬로 표현된 그래프: O(N^2)

- 간선 숫자가 적은 경우 인접 리스트를 이용하는 것이 더 효율적이다.

---
## DFS (깊이 우선 탐색)

>### DFS (Breadth First Search)

<p align="center"><img src="./Images/Depth-First-Search.gif" ></p>  
<p align="center"> < DFS Simulation ></P><




- 루트 노드(혹은 다른 임의의 노드)에서 시작해서 다음 분기(branch)로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법

- 시작 정점으로부터 가장 먼 정점을 먼저 방문하고 가까운 갈림길로 돌아와서 다른 방향으로 다시 탐색을 진행하는 방법이다. 즉, 깊게(deep)하게 탐색하는 것이 우선이고 그 다음 넓게(wide) 탐색한다.

- 사용하는 경우: 두 노드 사이의 최단 경로 혹은 임의의 경로를 찾고 싶을 때 이 방법을 선택한다.


>### DFS의 특징

 - 자기 자신을 호출하는 재귀적 알고리즘의 형태를 가진다.

 - 그래프 탐색의 경우, 어떤 노드를 방문했었는지 방문 여부를 기록해야 한다. 그렇지 않으면 무한 루프에 빠질 수 있다.

 - 구현 할 때, 재귀를 이용한 순환 호출과 스택을 이용한 구현 방법이 있다.

>### DFS의 시간복잡도

- 인접 리스트로 표현된 그래프: O(N+E) (N : 노드의 수, E : 간선의 수)

- 인접 행렬로 표현된 그래프: O(N^2)

- 간선 숫자가 적은 경우 인접 리스트를 이용하는 것이 더 효율적이다.

---
## DynamicProgramming
---
---
## 참고 자료
 - [IT취업을 위한 알고리즘 문제풀이 (with C/C++) : 코딩테스트 대비](https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/dashboard)

 - [코딩 테스트를 위한 자료 구조와 알고리즘 with C++](http://www.yes24.com/Product/Goods/95863013)
 
 - [Heee's Development Blog](https://gmlwjd9405.github.io/)

 - [WIKIMEDIA COMMON](https://commons.wikimedia.org/wiki/)
