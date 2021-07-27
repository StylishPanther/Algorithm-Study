# Hyundai Softeer

Hyundai Softeer 연습문제들의 소스 코드 및 해설을 적어놓은 문서입니다.

## Index

1. 로봇이 지나간 거리 : [문제 해설](#로봇이-지나간-거리), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=577)

2. 스마트 물류 : [문제 해설](#스마트물류), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=414)

3. H-클린알파 : [문제 해설](#h-클린알파), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=423)

4. 성적평균 : [문제 해설](#성적평균), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=389)

5. 금고털이 : [문제 해설](#금고털이), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=395)

6. 우물 안 개구리 : [문제 해설](#우물-안-개구리), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=394) 

7. 징검다리1 : [문제 해설](#징검다리1), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=390)

8. 징검다리2 : [문제 해설](#징검다리2), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=393)

9. 차세대 지능형 교통시스템 : [문제 해설](#차세대-지능형-교통시스템), [문제 링크](https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=580)

## 문제 해설

2021.07.24 최신

### 로봇이 지나간 거리

문제에서 입력하는 명령어의 개수를 최소화 시키고 경로의 한 끝에서 다른 끝으로 이동을 하려면 BFS를 이용해야 함을 알 수 있다.

맨 처음 시작을 위해 해야하는 일은 

1. 시작점 찾기(경로의 양 끝)
2. 맨 처음 움직이는 방향 찾기 (시작점 주변에 있는 움직인 경로)
3. 탐색하면서 위치와 보고있는 방향을 함께 넘기기

다음 세가지를 구현하기 위해 

1. for문을 통해 0 < i, j < n 내부에서 로봇이 움직인 경로(1) 중 상하좌우에 움직일 수 있는 경로를 1개만 가진 점, 즉 시작점과 도착점을 탐색한다.
2. 시작점을 찾은 뒤 다음 어디로 움직여야 하는지 파악한다. 상하좌우 중에 1이 있는 방향을 기록해놓는다.
3. 구조체를 이용해 도착점의 좌표와 방향을 구조체로 만들어서 q.push를 하고  BFS 탐색을 진행.
4. 방향이 같아서 바로 갈 수 있는 길은 char형 Queue에 'A', 방향이 달라서 바로 갈 수 없는 길은 방향 탐색 후 'L', 'R' 을 push한 후 'A' push
5. 탐색이 완료되면 char형 Queue를 출력한다.

### 스마트물류

간단한 형태의 완전 탐색 문제이다.

N이 1이상 20,000이하, 로봇이 잡을 수 있는 최대 거리는 10이고 
20,000 * 10 = 200,000이므로 시간 초과는 걱정 안해도 된다.

1. 입력받은 문자열에서 P를 찾으면 그 위치를 $r$이라고 했을 때  그 양 옆으로 $k$만큼의 거리$(r-k \leq r \leq r+k)$를 탐색 한다.
2. 따로 할당해놓은 n의 크기를 가진 check 배열을 통해 이미 집은 물건인지 아닌지 확인하고 잡을 수 있을 때 1번의 탐색 반복문을 break한다. (연산량 감소)

### H 클린알파

메모이제이션과 모듈러 연산의 특징을 잘 이해해야 한다.

메모이제이션을 하지 않으면 $ 1 \leq N \leq 10^6$이므로 $O(N^2)$인 상황이 발생하여 시간초과가 발생한다.

#### 메모이제이션 (Memoization)

메모이제이션(memoization)은 컴퓨터 프로그램이 동일한 계산을 반복해야 할 때, 이전에 계산한 값을 메모리에 저장함으로써 동일한 계산의 반복 수행을 제거하여 프로그램 실행 속도를 빠르게 하는 기술이다. 

#### 모듈러 연산의 특징

$$ 1.\space (a \space mod \space n  + b \space mod \space n) \space mod \space n = (a+b)\space mod \space n $$
$$ 2.\space (a \space mod \space n  - b \space mod \space n) \space mod \space n = (a-b)\space mod \space n $$
$$ 3.\space (a \space mod \space n  * b \space mod \space n) \space mod \space n = (a* b)\space mod \space n $$

풀이 과정은 다음과 같다.

1. 처음 N만큼의 for문 탐색을 할 때, 지나가는 인덱스마다 P값을 곱해주어야 한다.

2. 모듈러 연산을 1000,000,007로 하므로 그냥 int형으로 선언하면 오버플로우가 발생하므로 64비트 long long int로 선언한다.

3. 위의 모듈러 연산의 특징을 이용해서 곱해지는 값마다 모듈러 연산을 취해서 일종의 시간별 테이블을 만든다.

4. 입력된 바이러스 값과 테이블을 곱하면서 모듈러 연산을 취해 총 바이러스의 수를 구한다.

### 성적평균

간단한 평균문제지만 $1 \leq N \leq 10^6$이므로 그냥 2중 for문을 돌리면 시간 초과가 발생한다.

따라서 이 문제도 메모이제이션을 이용해 각 인덱스 까지의 합을 미리 저장해두어야 한다.

1. 입력을 받으면서 해당 인덱스 까지의 합을 배열에 저장한다.
2. 인덱스 차이에서 발생하는 합의 차이와 사람 수의 차이값을 실수형 자료형(float, double)에 저장한다.
3. printf("%.2lf) 의 형태로 출력해 반올림을 구현한다. 혹은 얻어낸 평균 값에 0.005를 더해서 출력해도 된다.

### 금고털이

우선순위 큐(Priority Queue)를 이용하면 쉽게 해결 할 수 있다.

[우선순위 큐 자료구조 설명](https://chanhuiseok.github.io/posts/ds-4/)

1. 무게과 무게 당 가격값을 구조체 형태로 선언한다.

2. 무게 당 가격값이 높은 순서대로, 즉 Max Heap의 우선순위 큐에 넣는다.

3. 가방의 제한까지 순서대로 큐에서 pop을 하여 누적 합을 한다.

### 우물 안 개구리

인접 리스트를 이용한 해결법이 제일 먼저 떠올랐다.

[인접 행렬과 인접 리스트란?](https://sarah950716.tistory.com/12)

간선의 수가 최대 10만이므로 입력에 의해 형성된 양방향 인접 리스트의 방문 확인은 할 필요 없다고 생각해서 구현하지 않고 완전 탐색의 형식으로 구현했다.

1. 각 개인이 최대로 들 수 있는 배열 weight와 연결 관계를 나타내는 인접 리스트를 만든다.

2. 인접 리스트를 통해 각각의 최대 무게를 비교해서 높은 사람이 발견 되면 탐색 중에 바로 break, 발견 되지 않으면 정답 변수를 증가시킨다.

### 징검다리1

가장 유명한 형태의 LIS(Longest Increasing Subsequent)이다.

[LIS(Longest Increasing Subsequent)란?](https://jason9319.tistory.com/113)

N이 3,000이므로 2중 for문을 이용해서 구현했다.

### 징검다리2

### 차세대 지능형 교통시스템
