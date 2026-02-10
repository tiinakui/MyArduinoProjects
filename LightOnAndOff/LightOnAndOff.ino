int i;                    //打印状态监测
int buttonState;          // 当前按钮状态
int lastButtonState = 0;  // 上一次按钮状态
int ledState = 0;         // 灯当前状态

void setup() {
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  i = buttonState = digitalRead(3);
  Serial.println(i);
  if (buttonState == 1 && lastButtonState == 0) {  
    //边缘检测：只在按钮从0变为1的瞬间执行一次。
    //当前按钮状态为1（按下），并且上一次按钮状态为0（未按下）
    ledState = !ledState;                // LED灯状态翻转
    digitalWrite(6, ledState);
  }
  lastButtonState = buttonState;  // 更新按钮状态
}