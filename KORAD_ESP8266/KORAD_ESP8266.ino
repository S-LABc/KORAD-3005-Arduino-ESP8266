/**
 * KORAD ESP8266
 * 
 * Алгоритм позволяет сделать надстройку HTTP API
 * над стандартным протоколом UART ЛБП KORAD
 * 
 * Copyright (C) 2020. v1.0 / Скляр Роман S-LAB
 * YouTube https://www.youtube.com/channel/UCbkE52YKRphgkvQtdwzQbZQ
 * 
 * Для использования плат на базе ESP8266EX добавить
 * https://arduino.esp8266.com/stable/package_esp8266com_index.json
 * 
 * Для работы с .JSON установить библиотеку (Ctrl+Shift+I)
 * arduinojson за авторством Benoit Blanchon
 * 
 * Для загрузки файлов в файловую систему установить плагин
 * https://github.com/esp8266/arduino-esp8266fs-plugin
 * 
 * COMPILED IN ARDUINO V1.8.13
 * 
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <FS.h>
#include <ArduinoJson.h> 
#include "Settings.h"

//Настройка сервера и обновлений
IPAddress local_ip(LOCAL_IP);
IPAddress gateway_ip(GATEWAY_IP);
IPAddress subnet(SUBNET_MASK);
ESP8266WebServer HTTP(HTTP_PORT);
ESP8266HTTPUpdateServer UPDATE;

void setup() {
  Serial.begin(SERIAL_BOUDRATE);
  pinMode(STATUS_LED, OUTPUT);
  initFileSystem();
  loadConfig();
  initWIFI();
  initHTTP();
}

void loop() {
  HTTP.handleClient();
  serialHTTP();
  delay(1);
}
