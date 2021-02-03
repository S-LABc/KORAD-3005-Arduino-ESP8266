//Настрока режима работы WiFi
void initWIFI() {
  uint8_t tries = 10;
  WiFi.hostname(device_name);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid_sta, password_sta);
  while(--tries && WiFi.status() != WL_CONNECTED) { //Подключение к роутеру
    digitalWrite(STATUS_LED, !digitalRead(STATUS_LED));
    delay(500);
  }
  if(WiFi.status() != WL_CONNECTED) { //Запуск в режиме точки доступа
    WiFi.disconnect();
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid_ap, password_ap); //ssid_ap.c_str() password_ap.c_str()
    WiFi.softAPConfig(local_ip, gateway_ip, subnet);
    digitalWrite(STATUS_LED, LOW);
  }
  else {
    digitalWrite(STATUS_LED, HIGH);
  }
}
