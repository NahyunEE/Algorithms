# Algorithms

Personal Algorithms Study

## 기억해야할 꺼

### 8월 27일

#### 1. strlen()함수

strlen함수는 문자열의 길이를 계산하는 함수
char a[100]으로 선언하더라도, a 가 "helo"일때 strlen은 4이다.

'''
  for(int i=0; i < strlen(arr); ++i) {...}
'''
위와 같은 코드는 O(N^2)의 시간복잡도를 가진다.
strlen(arr)이 O(N)의 시간복잡도를 가지기 때문에

'''
num = strlen(arr);
for(int i=0; i < num; ++i) {...}
'''
으로 나타내야한다.

#### 2. 메모리 사용

|자료형| 메모리 크기|최댓값|
|------|-----------|-----------------------|
|char| 1 byte| -127  ~ 128|  
|int| 4 byte| -2,147,483,648~ 2,147,483,647| 
|unsigned int| 4 byte| 0 ~ 4294967295|
|float|4byte| 3.4*10^7-37 ~ 3.4*10^38|
|double|8byte| 1.7^10^-307 ~ 3.4 * 10^308|
|long(window)|4byte|-2,147,483,648~ 2,147,483,647|
|long(other)|8byte|-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807|

1 ) 크로스 플랫폼에서 개발할 시에는 stdint.h에 포함된 int32_t, int64_t를 쓰는 것을 권장한다.
2 ) 16 비트 CPU 에서는 int형은 2byte이다.




