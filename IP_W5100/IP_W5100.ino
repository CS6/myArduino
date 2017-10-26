/*
OpenJumper WebServer Example
建立一個顯示傳感器信息的Arduino服務器
[url= http://www.openjumper.com/ ] http://www.openjumper.com/ [/url]
[url= http://x.openjumper.com/ethernet/ ] http://x.openjumper.com/ethernet/[/url]
*/
 
#include <SPI.h>
#include <Ethernet.h>
 
// 設定MAC地址、IP地址
// IP地址需要參考你的本地網絡設置
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,177);
 
// 初始化Ethernet庫
// HTTP默認端口為80
EthernetServer server(80);
 
void setup() {
// 初始化串口通信
  Serial.begin(9600);
 
  // 開始ethernet連接，並作為服務器初始化
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print( "server is at " );
  Serial.println(Ethernet.localIP());
}
 
void loop() {
  // 監聽客戶端傳來的數據
  EthernetClient client = server.available();
  if (client) {
    Serial.println( "new client" );
    // 一個Http請求結尾必須帶有回車換行
    boolean currentLineIsBlank = true ;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // 如果收到空白行，說明http請求結束，並發送響應消息
        if (c == '\n' && currentLineIsBlank) {
          // 發送標準的HTTP響應
          client.println( "HTTP/1.1 200 OK" );
          client.println( "Content-Type: text/html" );
          client.println( "Connection: close" );
          client.println();
          client.println( "<!DOCTYPE HTML>" );
          client.println( "<html>" );
          // 添加一個meta刷新標籤, 瀏覽器會每5秒刷新一次
          // 如果此處刷新頻率設置過高，可能會出現網頁的卡死的狀況
          client.println( "<meta http-equiv=\"refresh\" content=\"5\">" );
          // 輸出每個模擬口讀到的值
          for ( int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print( "analog input " );
            client.print(analogChannel);
            client.print( " is " );
            client.print(sensorReading);
            client.println( "<br />" );      
          }
          client.println( "</html>" );
          break ;
        }
        if (c == '\n' ) {
          // 已經開始一個新行
          currentLineIsBlank = true ;
        }
        else if (c != '\r' ) {
          // 在當前行已經得到一個字符
          currentLineIsBlank = false ;
        }
      }
    }
    // 等待瀏覽器接收數據
    delay(1);
    // 斷開連接
    client.stop();
    Serial.println( "client disonnected" );
  }
}
 
