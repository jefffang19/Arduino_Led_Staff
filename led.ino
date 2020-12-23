#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>

#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"

#define data_pin1 3
#define num_led 59
#define hhnum 7
#define hnum 14
#define bs (60000.0/148.0)
// 1 小節 3 beats
#define BEATS 3
// the delay of arduino
#define INIT_DELAY 1620
#define SONG_BEGIN 20150

int x,y,z;
double temp;
CRGB leds[num_led];

//歌曲: 不老夢

void setup() {
  // put your setup code here, to run once:
FastLED.addLeds<WS2812,data_pin1,GRB>(leds, num_led);
FastLED.setBrightness(0);
for(int i=0;i<num_led;i++) leds[i].setRGB(0,0,0);
FastLED.show();
delay(bs*3*16 - INIT_DELAY);   // 前奏   

}

void loop() {
  // put your main code here, to run repeatedly:

  // 主歌1
/************************************/
  // one side blue turn dark
  // 39 83 96 dark blue
  // 69 83 96 light blue
  // 45 ~ 58  14 ~ 0 arduino
  // 44 ~ 30  15 ~ 29
  for(int i = 0, c=0; i < 14 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
    
  for(int i = 15, c=0; i < 29 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }

  FastLED.setBrightness(20);
  FastLED.show();
  delay(bs*3*16);
/*****************************************/



// 主歌一 樂器增加
/************************************/
  // two side blue
  // 39 83 96 dark blue
  // 69 83 96 light blue
  // 45 ~ 58  14 ~ 0 arduino
  // 44 ~ 30  15 ~ 29
  for(int i = 0, c=0; i < 14 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
    
  for(int i = 15, c=0; i < 29 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }
  for(int i = 30, c=0; i < 44 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }
  for(int i = 45, c=0; i < 58 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
  
  FastLED.setBrightness(20);
  FastLED.show();
  delay(bs*3*16);
/*****************************************/

//主歌一 過度
/************************************/
  // two side blue, yellow
  // 39 83 96 dark blue
  // 69 83 96 light blue
  // 45 ~ 58  14 ~ 0 arduino
  // 44 ~ 30  15 ~ 29

  //blue
  for(int i = 0, c=0; i < 8 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
  //yellow
  for(int i = 8, c=0; i < 15 ; ++i, ++c){
    leds[i].setRGB(95, 93, 44 - c * 4);
  }

  // yellow
  for(int i = 15, c=0; i < 22 ; ++i, ++c){
    leds[i].setRGB(95, 93, 12 + c * 4);
  }
  // blue
  for(int i = 22, c=0; i < 30 ; ++i , ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }

  // yellow
  for(int i = 30, c=0; i < 38 ; ++i, ++c){
    leds[i].setRGB(95, 93, 12 + c * 4);
  }
  // blue
  for(int i = 38, c=0; i < 45 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }

  // blue
  for(int i = 45, c=0; i < 52 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
  //yellow
  for(int i = 52, c=0; i < 59 ; ++i, ++c){
    leds[i].setRGB(95, 93, 44 - c * 4);
  }
  FastLED.show();
  delay(bs*3*16);
/*****************************************/

//副歌一
/************************************/
  // two side red, yellow
  // 86 62 51 dark red
  // 86 76 51 light red
  // 45 ~ 58  14 ~ 0 arduino
  // 44 ~ 30  15 ~ 29

  //red
  for(int i = 0, c=0; i < 8 ; ++i, ++c){
    leds[i].setRGB(86, 62 + c*2, 51);
  }
  //yellow
  for(int i = 8, c=0; i < 15 ; ++i, ++c){
    leds[i].setRGB(95, 93, 44 - c * 4);
  }

  // yellow
  for(int i = 15, c=0; i < 22 ; ++i, ++c){
    leds[i].setRGB(95, 93, 12 + c * 4);
  }
  // red
  for(int i = 22, c=0; i < 30 ; ++i , ++c){
    leds[i].setRGB(86, 76 - c*2, 51);
  }

  // yellow
  for(int i = 30, c=0; i < 38 ; ++i, ++c){
    leds[i].setRGB(95, 93, 12 + c * 4);
  }
  // red
  for(int i = 38, c=0; i < 45 ; ++i, ++c){
    leds[i].setRGB(86, 76 - c*2, 51);
  }

  // red
  for(int i = 45, c=0; i < 52 ; ++i, ++c){
    leds[i].setRGB(86, 62 + c*2, 51);
  }
  //yellow
  for(int i = 52, c=0; i < 59 ; ++i, ++c){
    leds[i].setRGB(95, 93, 44 - c * 4);
  }
  FastLED.show();
  delay(bs*3*16);
/*****************************************/

//間奏1
/*****************************************/
// two side blue, yellow
  // 39 83 96 dark blue
  // 69 83 96 light blue
  // 45 ~ 58  14 ~ 0 arduino
  // 44 ~ 30  15 ~ 29
  for(int i = 0, c=0; i < 14 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
    
  for(int i = 15, c=0; i < 29 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }
  for(int i = 30, c=0; i < 44 ; ++i, ++c){
    leds[i].setRGB(95, 93, 44 - c);
  }
  for(int i = 45, c=0; i < 58 ; ++i, ++c){
    leds[i].setRGB(95, 93, 12 + c);
  }
  FastLED.show();
  delay(bs*3*16);
/*****************************************/

//主歌2
//此刻開始會漸暗，重拍亮
/************************************/
  // one side blue turn dark
  // 39 83 96 dark blue
  // 69 83 96 light blue
  // 45 ~ 58  14 ~ 0 arduino
  // 44 ~ 30  15 ~ 29
  for(int i = 0, c=0; i < 15 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
    
  for(int i = 15, c=0; i < 30 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }

  for(int i = 15, c=0; i < 30 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }

  // one section 6 beats
  for(int sec = 0 ; sec < 8 ; ++sec){
    FastLED.setBrightness(20);
    FastLED.show();
    delay(bs);
    for(int b=0; b<20 ; b++){
      FastLED.setBrightness(20-b);
      FastLED.show();
      delay(bs/4);
    }
  }
/*****************************************/

// 主歌2 樂器增加
/************************************/
  // two side blue
  // 39 83 96 dark blue
  // 69 83 96 light blue
  // 45 ~ 58  14 ~ 0 arduino
  // 44 ~ 30  15 ~ 29
  for(int i = 0, c=0; i < 14 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
    
  for(int i = 15, c=0; i < 29 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }
  for(int i = 30, c=0; i < 44 ; ++i, ++c){
    leds[i].setRGB(39+c*2, 83, 96);
  }
  for(int i = 45, c=0; i < 58 ; ++i, ++c){
    leds[i].setRGB(69-c*2, 83, 96);
  }
  
  // one section 6 beats
  for(int sec = 0 ; sec < 8 ; ++sec){
    FastLED.setBrightness(20);
    FastLED.show();
    delay(bs);
    for(int b=0; b<20 ; b++){
      FastLED.setBrightness(20-b);
      FastLED.show();
      delay(bs/4);
    }
  }
/*****************************************/



  
}
