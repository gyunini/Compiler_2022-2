# Compiler_2022

## HW1

* Lexical Analyzer 구현
* 수(integer, real number)와 스트링으로 이루어진 수식(assignment 포
함)의 어휘를 인식하는 lexical analyzer를 작성한다. lex를 사용하지 않고 state
transition diagram을 그려 이를 기반으로 직접 구현한다

## HW2

* 수식 인터프리터 개발
* Recursive Descent Parsing 기법을 이용하여 간단한 expression을 위한 인터프리터를 개발한
다. 

## HW3

* 중간코드 생성기 개발
* 단계별로 구현
    * 단계 1 – 변수선언이 없는 수식
    - 상수, 변수, 연산자, 지정문 등이 포함된 수식 프로그램
    - type declaration, type checking, type conversion, array 등이 없음
    - 중간 코드 명령에 혼합형 연산이 가능함
    e.g. t1 = 10 + 10.5
    - symbol table에는 변수의 name만 저장됨
    * 단계 2 – 변수선언이 포함된 수식
    - 변수 선언이 있음
    - type ckecking을 하고 필요시 type 변환을 해야 함
    - symbol table에는 변수의 name, type, offset(변수의 상대적 주소)을 저장해야 한다.
    - 4 -
    * 단계 3 – array가 포함된 수식
    - array type은 구조화되어 symbol table에 저장되고(강의노트 참조) 출력시에는 string형
    태로 출력한다.
