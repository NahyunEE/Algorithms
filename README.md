# Algorithms

Personal Algorithms Study



## 1. strlen()함수

strlen함수는 문자열의 길이를 계산하는 함수<br>
char a[100]으로 선언하더라도, a 가 "helo"일때 strlen은 4이다.

```
  for(int i=0; i < strlen(arr); ++i) {...}
```
위와 같은 코드는 O(N^2)의 시간복잡도를 가진다.<br>
strlen(arr)이 O(N)의 시간복잡도를 가지기 때문에

```
num = strlen(arr);
for(int i=0; i < num; ++i) {...}
```
으로 나타내야한다.

관련문제: 1157

## 2. 메모리 사용

|자료형| 메모리 크기|최댓값|
|------|-----------|-----------------------|
|char| 1 byte| -127  ~ 128|  
|int| 4 byte| -2,147,483,648~ 2,147,483,647| 
|unsigned int| 4 byte| 0 ~ 4294967295|
|float|4byte| 3.4*10^7-37 ~ 3.4*10^38|
|double|8byte| 1.7^10^-307 ~ 3.4 * 10^308|
|long(window)|4byte|-2,147,483,648~ 2,147,483,647|
|long(other)|8byte|-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807|


1 ) 크로스 플랫폼에서 개발할 시에는 stdint.h에 포함된 int32_t, int64_t를 쓰는 것을 권장한다. <br>
2 ) 16 비트 CPU 에서는 int형은 2byte이다.<br>
관련문졔: 1157

## 3. 시간복잡도<br>
- 일반적인 cpu기반의 pc나 채점용 컴퓨터에서 1초에 실행할 수있는 최대 연산 횟수는 약 1억번이다.<br>
- 1초에 최대 연산 횟수
  
|시간복잡도| 최대연산횟수|
|:------|:---------|
|O(n) | 약 1억 번| 
|O(n^2) | 약 1만 번|
|O(n^3) | 약 500 번|
|O(2^n) | 약 20 번|
|O(n!) | 약 10 번|

#### 제한 시간이 1초인 경우 N의 범위에 따른 시간 복잡도의 선택<br>

- N의 범위가 500: 시간 복잡도가 O(N^3) 이하인 알고리즘을 설계<br>
- N의 범위가 2,000: 시간 복잡도가 O(N^2) 이하인 알고리즘을 설계<br>
- N의 범위가 100,000: 시간 복잡도가 O(NlogN) 이하인 알고리즘을 설계<br>
- N의 범위가 10,000,000: 시간 복잡도가 O(N) 이하인 알고리즘을 설계<br>
- N의 범위가 10,000,000,000: 시간 복잡도가 O(logN) 이하인 알고리즘을 설계<br>

## strcmp() 함수
- 일반적으로 문자열을 비교할 때는 strcmp 함수를 써야한다.<br>
  그 이유는 '==' 연산자는 포인터 기반의 연산을 하기 때문이다. 

```
int changeScore(const char *str) {
    if (strcmp(str, "A0") == 0) return 0;
    if (strcmp(str, "A+") == 0) return 1;
     ...
    if (strcmp(str, "P") == 0) return 9;
    return -1; 
}
```

## scanf() 함수
- scanf()함수는 포인터 기반의 변수를 입력으로 받는다. 즉 입력버퍼에서 받는 값을 포언터를 통해서 메모리에 저장한다.
- "%d"에 숫자를 중간에 넣으면 입력버퍼의 길이를 정할 수 있다.

```
 struct obj{
	 char name[51];
	 float hakjum;
	 char score[3];
 };
 struct obj BuRupDa;
 scanf("%50s %f %2s", BuRupDa.name, &BuRupDa.hakjum, BuRupDa.score);
```

## switch 문
- C언어는 switch문에 정수만 가능하다.
- 문자열이나 실수같은 경우는 변환해서 사용해야한다.
- 해쉬함수로 문자열을 바꿀 수있다고 한다.



