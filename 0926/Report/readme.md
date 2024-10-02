# `09/26` Report
09.26일자 강의내용을 바탕으로 작성된 레포트입니다.
본 문서는 각 파일(01~07)의 실행결과를 순서대로 담고 있습니다.<br><br><br>

## 자릿수 순차 출력 `Slide02~04`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/01%20Digit_Default.png" width="500px" /><br>
Scanf로 입력받은 수를 문자열로 취급하여 char[]에 하나씩 넣고 index 0부터 출력<br><br><br>

## 자릿수 역순 출력 `Slide02~04`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/02%20Digit_Reverse.png" width="500px" /><br>
Scanf로 입력받은 수를 문자열로 취급하여 char[]에 하나씩 넣고 index strlen(char)부터 출력<br><br><br>

## 자릿수 순-역 출력 - for Loop `Slide05~08`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/03%20Digit_Loop.png" width="500px" /><br>
입력된 수를 문자열로 취급하지 않고 몫과 나머지 연산을 for-loop으로 실행하여 자릿수 출력<br><br><br>

## 자릿수 순-역 출력 - Recursion `Slide09~13`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/04%20Digit_Recursion.png" width="500px" /><br>
입력된 수를 문자열로 취급하지 않고 몫과 나머지 연산을 재귀호출로 실행하여 자릿수 출력<br><br><br>

## 디지털 숫자 표현 `Slide14~19`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/05%20Segment.png" width="500px" /><br><br><br><br>
0~9의 각 숫자에 대한 7세그먼트 표현 프리셋을 배열의 형태로 저장해 둔다.
입력받은 수를 가장 높은 자릿수에 도달할 때까지 `number_check`을 재귀호출하고,
최고 자릿수에 도달하면 인자로 전달된 `line`에 해당하는 줄을 출력한 후 재귀를 빠져나가면서 그 다음 자릿수들도 차례로 line에 해당하는 줄을 출력한다.
`line`은 `main()`에서 관리되고, 0~4까지 for-loop으로 증가한다.
123456789가 입력되면 1을 출력하고, 2를 출력하고, ... 이렇게 진행되는 것이 아니라
1~9의 첫 번째 줄을 차례대로 출력하고 그 다음 줄을 출력하는 식으로 진행된다.

## 슬라이드 바 `Slide20~28`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/06%20Slide_1.png" width="500px" /><br>
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/06%20Slide_2.png" width="500px" /><br><br><br><br>

## 도형 이동 및 변환 `Slide29~37`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/07%20Arrow.png" width="500px" /><br><br><br><br>

