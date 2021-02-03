//Загрузка и сохранение настроек .JSON
void loadConfig() {
  File config_file = SPIFFS.open(URL_CONFIG_FILE, "r");
  config_json = config_file.readString(); 
  DynamicJsonDocument doc_json(1024);
  DeserializationError error = deserializeJson(doc_json, config_json);
  device_name = doc_json["nameWiFi"].as<String>();
  ssid_sta = doc_json["ssidSTA"].as<String>();
  password_sta = doc_json["passwordSTA"].as<String>();
  ssid_ap = doc_json["ssidAP"].as<String>();
  password_ap = doc_json["passwordAP"].as<String>();
}

void saveConfig() {
  DynamicJsonDocument doc_json(1024);
  doc_json["nameWiFi"] = device_name;
  doc_json["ssidSTA"] = ssid_sta;
  doc_json["passwordSTA"] = password_sta;
  doc_json["ssidAP"] = ssid_ap;
  doc_json["passwordAP"] = password_ap;
  config_json = "";
  serializeJson(doc_json, config_json);
  File configFile = SPIFFS.open(URL_CONFIG_FILE, "w");
  configFile.print(config_json);
  configFile.close();
}
