# Berlekamp-Massey 알고리즘

[설명](https://koosaga.com/231)

[CPP](https://gist.github.com/koosaga/d4afc4434dbaa348d5bef0d60ac36aa4)

[python](./Berlekamp-Massey.py)

점화식을 만족하는 최소 선형 다항식을 찾는 알고리즘입니다.

피보나치 수열은 a_n = a_{n-1} + a_{n-2} 입니다.

이는 선형이므로 벌레캠프 메시 알고리즘을 사용할 수 있습니다.

반면 카탈란 수는 점화식이 선형이 아니므로 사용할 수 없습니다.

(웬만한 1차원 dp문제에 적용 가능)

벌레캠프 각이 보였다면 초기 적당한 몇 항 이상 넣어주면 답을 구할 수 있습니다.

넣어야 하는 항의 개수 : 3 x 점화식의 길이(피보나치 같은 경우는 2)

## 주의 사항

모듈러는 소수여야 함 (ex 1,000,000,007 1,000,000,009 998,244,353)

항의 개수는 최대한 많이 넣고 미리 계산해 놓으면 편함

## 풀만한 문제

- [9461](https://www.acmicpc.net/problem/9461)

- [11442](https://www.acmicpc.net/problem/11442)

- [11443](https://www.acmicpc.net/problem/11443)

- [11444](https://www.acmicpc.net/problem/11444)

- [24731](https://www.acmicpc.net/problem/24731)

- [13716](https://www.acmicpc.net/problem/13716)

- [19102](https://www.acmicpc.net/problem/19102)

- [19366](https://www.acmicpc.net/problem/19366)
