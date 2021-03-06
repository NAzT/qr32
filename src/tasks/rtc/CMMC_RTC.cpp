#include "CMMC_RTC.h"
#include <TinyGPS++.h>

// extern CMMC_GPS *gps;
// extern CMMC_GPS *gps;
CMMC_RTC::CMMC_RTC() {
}

void CMMC_RTC::configLoop() {
  yield();
}

void CMMC_RTC::configSetup() {
  yield();
}

void CMMC_RTC::setup() {
  this->rtc = new RTC_DS1307();
  prev = millis();
  if (!rtc->begin()) {
    _ready = false;
    Serial.println("RTC Fail to initialize.");
  }
  else {
    _ready = true;
    // rtc->adjust(DateTime(F(__DATE__), F(__TIME__)));
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    Serial.println("RTC initialize OK.");
  }
}

String CMMC_RTC::getDateTimeString() {
  // char tmp[60] = "";
  // strcat(tmp, dateTimeCharArrray);
  return String(dateTimeCharArrray);
}

String print_time(DateTime timestamp) {
  char message[120];

  int Year = timestamp.year();
  int Month = timestamp.month();
  int Day = timestamp.day();
  int Hour = timestamp.hour();
  int Minute = timestamp.minute();
  int Second= timestamp.second();

  sprintf(message, "%d/%d/%d %02d:%02d:%02d", Day, Month,Year,Hour%24,Minute%60,Second%60);

  return message;
}

uint32_t CMMC_RTC::getCurrentTimestamp() {
  return _now.unixtime();
}

void CMMC_RTC::loop() {
    if(!_ready) {
      Serial.println("RTC FAILED.");
      return;
    }
      DateTime now = rtc->now();
      // Serial.println(now.unixtime());
      if (now.year() > 2000 && now.year() <= 2021) { // work around
        _now = now;
        strcpy(dateTimeCharArrray, print_time(now).c_str());
      }
      // else {
      //
      // }
      // sprintf(dateTimeCharArrray, "%02u/%02u/%02u %02u:%02u:%02u",
      // now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());
      // Serial.println(dateTimeCharArrray);
      // this->serial
      // Serial.println(dateTimeCharArrray);
      // Serial.print(now.year(), DEC);
      // Serial.print('/');
      // Serial.print(now.month(), DEC);
      // Serial.print('/');
      // Serial.print(now.day(), DEC);
      // Serial.print(" - ");
      // Serial.print(" (");
      // Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
      // Serial.print(") ");
      // Serial.print(now.hour(), DEC);
      // Serial.print(':');
      // Serial.print(now.minute(), DEC);
      // Serial.print(':');
      // Serial.print(now.second(), DEC);
      // Serial.println();
      // prev = millis();
      // Serial.println(dateTimeCharArrray);
}

void CMMC_RTC::adjust(const DateTime& dt) {
  // Serial.print("ADJUST RTC.. with ");
  // Serial.println(print_time(dt));
  _rtc_locked = true;
  rtc->adjust(dt);
  loop();
  _rtc_locked = false;
}

DateTime CMMC_RTC::getDateTime() {
  return _now;
}
