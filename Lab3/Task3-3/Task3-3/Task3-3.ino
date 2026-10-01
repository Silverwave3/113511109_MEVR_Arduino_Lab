#include <SoftwareSerial.h>

// 建立軟體序列埠物件，定義 RX 為 Pin 10, TX 為 Pin 11
SoftwareSerial BTSerial(13, 12); 
const int ledPin = 2;

void setup() {
  Serial.begin(9600);   // 保留硬體序列埠，供電腦 USB 監控除錯用
  BTSerial.begin(9600); // 啟動與 HC-05 的藍牙序列通訊 (HC-05 預設鮑率通常為 9600)
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 改為監聽藍牙序列埠 (BTSerial) 是否有資料傳入
  if (BTSerial.available() > 0) {
    String command = BTSerial.readStringUntil('\n');
    command.trim(); 

    if (command == "ON") {
      digitalWrite(ledPin, HIGH);
      Serial.println("Received from BT: ON"); // 印到 USB 監控視窗方便除錯
    } 
    else if (command == "OFF") {
      digitalWrite(ledPin, LOW);
      Serial.println("Received from BT: OFF");
    }
  }
}
