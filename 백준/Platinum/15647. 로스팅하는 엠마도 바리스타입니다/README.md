# [Platinum V] 로스팅하는 엠마도 바리스타입니다 - 15647 

[문제 링크](https://www.acmicpc.net/problem/15647) 

### 성능 요약

메모리: 102740 KB, 시간: 408 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 트리에서의 다이나믹 프로그래밍, 트리에서의 전방향 다이나믹 프로그래밍

### 제출 일자

2024년 9월 9일 00:00:10

### 문제 설명

<p>A tree with <em>N</em> vertices 1 to <em>N</em> is given. All the edges have a distance which is at least 1. For every vertex, calculate the sum of minimum distances to that vertex from all vertices.</p>

### 입력 

 <p><em>N</em> is given in the first line. (1 ≤ <em>N</em> ≤ 3 × 10<sup>5</sup>)</p>

<p>For the next <em>N</em>-1 lines, three numbers <em>u</em> and <em>v</em> and <em>d</em> is given. This means that there is an edge connecting <em>u</em> and <em>v</em> with a distance of <em>d</em>. (1 ≤ <em>u</em>, <em>v</em> ≤ <em>N</em>, 1 ≤ <em>d</em> ≤ 5)</p>

<p>You can assume that the given graph is a tree.</p>

### 출력 

 <p>For <em>N</em> lines, print the sum of minimum distances to that vertex from all vertices.</p>

