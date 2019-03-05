#include <KBChain_LED7SEG.h>   //ทำการ #include ไฟล์ .h ใช้กับ 7Segment

  //ประกาศ Class ที่สร้างใน Libraries ตามด้วย ชื่อตัวแปรใหม่(Display1) ที่จะใช้แทนตัว Class
  KBChain_7segment Display1 = KBChain_7segment(); 

void setup() {
  //ตั้งค่า I2C Address เป็น 0x70 ให้ Display1
  Display1.begin(0x70); 
}

void loop() {
  
  // การแสดงค่าตัวเลขฐาน 10
  Display1.print(8888, DEC);    //ใส่ค่าตัวเลขฐาน 10
  Display1.drawColon(true);     //แสดงโคลอน
  Display1.writeDisplay();      //ส่งค่า Display1 ไปแสดงที่ 7Segment 
  delay(2000);                  //หน่วงเวลาแสดงค่า 2 วินาที  

  // การแสดงค่าตัวเลขฐาน 16
  Display1.print(0x1A2B, HEX);  //ใส่ค่าตัวเลขฐาน 16
  Display1.writeDisplay();      //ส่งค่า Display1 ไปแสดงที่ 7Segment
  delay(2000);                  //หน่วงเวลาแสดงค่า 2 วินาที 

  // การแสดงค่าตัวเลขจุดทศนิยม
  Display1.print(12.34);        //ใส่ค่าตัวเลขจุดทศนิยม
  Display1.writeDisplay();      //ส่งค่า Display1 ไปแสดงที่ 7Segment
  delay(2000);                  //หน่วงเวลาแสดงค่า 2 วินาที 

  // ประกาศตัวแปรวนลูป counter แสดงการนับค่าตัวเลข 0-9999
  for (uint16_t counter = 0; counter < 9999; counter++) {  
  Display1.println(counter);    //ใส่ค่าตัวเลขการนับ
  Display1.writeDisplay();      //ส่งค่า Display1 ไปแสดงที่ 7Segment
  delay(10);                    //หน่วงเวลาแสดงค่า 0.01 วินาที 
  }                             
} 
