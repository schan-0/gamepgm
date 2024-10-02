# `09/26` Report
09.26일자 강의내용을 바탕으로 작성된 레포트입니다.
본 문서는 각 파일(01~07)의 실행결과를 순서대로 담고 있습니다.<br><br><br>

## 01 자릿수 순차 출력 `Slide02~04`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/01%20Digit_Default.png" width="500px" /><br>
Scanf로 입력받은 수를 문자열로 취급하여 char[]에 하나씩 넣고 index 0부터 출력<br><br><br><br>

## 02 자릿수 역순 출력 `Slide02~04`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/02%20Digit_Reverse.png" width="500px" /><br>
Scanf로 입력받은 수를 문자열로 취급하여 char[]에 하나씩 넣고 index strlen(char)부터 출력<br><br><br><br>

## 03 자릿수 순-역 출력 - for Loop `Slide05~08`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/03%20Digit_Loop.png" width="500px" /><br>
입력된 수를 문자열로 취급하지 않고 몫과 나머지 연산을 for-loop으로 실행하여 자릿수 출력<br><br><br><br>

## 04 자릿수 순-역 출력 - Recursion `Slide09~13`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/04%20Digit_Recursion.png" width="500px" /><br>
입력된 수를 문자열로 취급하지 않고 몫과 나머지 연산을 재귀호출로 실행하여 자릿수 출력<br><br><br><br>

## 05 디지털 숫자 표현 `Slide14~19`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/05%20Segment.png" width="500px" /><br>
0~9의 각 숫자에 대한 7세그먼트 표현 프리셋을 배열의 형태로 저장해 둔다.

입력받은 수를 가장 높은 자릿수에 도달할 때까지 `number_check`을 재귀호출하고,

최고 자릿수에 도달하면 인자로 전달된 `line`에 해당하는 줄을 출력한 후,

재귀를 빠져나가면서 그 다음 자릿수들도 차례로 line에 해당하는 줄을 출력한다.

`line`은 `main()`에서 관리되고, 0~4까지 for-loop으로 증가한다.

123456789가 입력되면 1을 출력하고, 2를 출력하고, ... 이렇게 진행되는 것이 아니라

1~9의 첫 번째 줄을 차례대로 출력하고 그 다음 줄을 출력하는 식으로 진행된다.<br><br><br><br>

## 06 슬라이드 바 `Slide20~28`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/06%20Slide_1.png" width="500px" /><br>
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/06%20Slide_2.png" width="500px" /><br>
수평 슬라이드 바의 길이 `h_slide_length`와 수직 슬라이드 바의 길이 `v_slide_length`를 각각 설정하고 시작한다.

사용자의 입력이 끝나면 `system("cls")`로 화면을 초기화하고,

`draw_vertical_slide()`와 `draw_horizontal_slide()`가 순서대로 실행된다.

두 함수의 로직은 거의 같다. 인자로 받은 `length`를 `draw_rectangle()`에 다시 전달하여 그 크기에 해당하는 직사각형 셀을 화면에 표시하고,

커서를 직사각형 내부로 이동시켜 문자열 "■"를 출력한 후 다시 커서를 주변으로 이동시켜 슬라이드의 현재 상하/좌우 값을 표시한다.

커서의 이동은 `gotoxy()`가 담당한다.

일련의 초기화 과정이 끝나면 각 슬라이드 바의 최상단/최좌측에 ■ 가 표시되고 슬라이드 파라미터 값은 1로 세팅되어 있을 것이다.

이때 `getch()`가 사용자의 입력(화살표)을 받아 `key`에 저장하고 `move_arrow_key()`가 그것을 인자로 받아 호출된다.

`move_arrow_key()` 내부에서는 `key`를 switch문으로 구별하고, `main()`에 선언된 `x` 또는 `y`에 포인터로 직접 접근하여 값을 변경한다.

switch문의 각 case에는 xy값을 제한하는 조건문이 있어 `x`와 `y`를 기반으로 하는 ■ 의 위치가 슬라이드 바를 벗어날 수 없게 되어있다.

여기까지 진행되면 다시 `main()`의 do-while문으로 돌아가 while에서 `key`값이 ESC인지 검사하고, 아니라면 본문의 세 번째 줄로 루프된다.

매 입력마다 `system("cls")`로 화면을 초기화해야 할 것 같지만, `draw_rectangle()`가 실행되는 과정에서

기존에 화면에 있던 모든 것이 덮어씌워짐으로써 부분적으로 cls가 실행되는 것과 같은 효과를 얻기 때문에 화면 초기화가 필요없다.<br><br><br><br>


## 07 도형 이동 및 변환 `Slide29~37`
<img src="https://github.com/schan-0/gamepgm/blob/main/0926/Report/%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4/07%20Arrow.png" width="500px" /><br>
`main()`에서는 2차원 배열 `shape1`의 초기값만 설정하고 모든 프로그램 흐름은 `move_control()`및 `move_shape()`에서 제어된다.

`move_contorl()`에서는 사용자가 입력한 `key`값에 따른 다음 행동을 switch문으로 제어한다.
|key|action|
|---|---|
|↑|iny = -1|
|←|inx = -1|
|↓|iny = 1|
|→|inx = 1|
|SpaceBar|rotation_right()|
