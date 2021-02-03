/*
 * http://192.168.4.1/api/reboot
 * http://192.168.4.1/api/update
 * http://192.168.4.1/api/config?wifiname=KORAD&ssidsta=SSID_WIFI&passwordsta=PASS_WIFI&ssidap=KORAD&passwordap=0
 */
//Инициализация HTTP и Update
void initHTTP() {
  HTTP.on(URL_RESTART, handleRestart);
  HTTP.on(URL_DEVICE, handleDevice);
  HTTP.on(URL_CONFIG, handleConfig);
  HTTP.on(URL_MEMORY, handleMemory);
  HTTP.on(URL_PROTECT, handleProtect);
  HTTP.on(URL_VOLTAGE, handleVoltage);
  HTTP.on(URL_CURRENT, handleCurrent);
  UPDATE.setup(&HTTP, URL_UPDATE);
  HTTP.begin();
}
//Перезагрузка
void handleRestart() {
  ESP.restart();
}
//Получение новых настроек
void handleConfig() {
  device_name = HTTP.arg("wifiname");
  ssid_sta = HTTP.arg("ssidsta");
  password_sta = HTTP.arg("passwordsta");
  ssid_ap = HTTP.arg("ssidap");
  password_ap = HTTP.arg("passwordap");
  saveConfig();
  HTTP.send(200, "text/plain", "OK");
}
//Конвертирование ответа от блока в HTTP
void serialHTTP() {
  if(Serial.available()) {
    String temp = Serial.readString();
    HTTP.send(200, "text/plain", temp);
  }
}
