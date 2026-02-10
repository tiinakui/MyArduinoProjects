// 全局变量定义区域
int i;                    // 用于打印按钮状态监测的临时变量
int buttonState;          // 存储当前读取到的按钮状态（0或1）
int lastButtonState = 0;  // 存储上一次循环中读取到的按钮状态，用于边缘检测
int ledState = 0;         // 存储LED灯的当前状态（0表示关闭，1表示开启）

// 初始化函数，Arduino上电或复位后只执行一次
void setup() {
  pinMode(3, INPUT);      // 将数字引脚3设置为输入模式，用于连接按钮
  pinMode(6, OUTPUT);     // 将数字引脚6设置为输出模式，用于连接LED灯
  Serial.begin(9600);     // 初始化串口通信，波特率为9600，用于调试输出
}

// 主循环函数，会不断重复执行
void loop() {
  i = buttonState = digitalRead(3);  // 读取引脚3的电平状态，赋值给buttonState和i
  Serial.println(i);                 // 通过串口打印当前按钮状态，便于调试观察
  
  // 边缘检测逻辑：只在按钮从未按下(0)变为按下(1)的瞬间执行一次
  if (buttonState == 1 && lastButtonState == 0) {  
    // 当检测到按钮按下边缘时，翻转LED灯的状态
    ledState = !ledState;            // 使用逻辑非运算(!)翻转ledState的值（0变1，1变0）
    digitalWrite(6, ledState);       // 将新的LED状态写入引脚6，控制LED灯的亮灭
  }
  
  lastButtonState = buttonState;  // 更新lastButtonState为当前按钮状态，为下一次边缘检测做准备
}
