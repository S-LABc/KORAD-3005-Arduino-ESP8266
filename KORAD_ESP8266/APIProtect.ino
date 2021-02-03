/*
 * http://192.168.4.1/api/protect?ovp=1
 * http://192.168.4.1/api/protect?ovp=0
 * http://192.168.4.1/api/protect?ocp=1
 * http://192.168.4.1/api/protect?ocp=0
 */
//Работа с опциями защиты
 void handleProtect() {
  String protect_ovp = HTTP.arg("ovp");
  String protect_ocp = HTTP.arg("ocp");

  if(protect_ovp == "0" || protect_ovp == "1") {
    Serial.print(COMMAND_VOLTAGE_PROTECT + protect_ovp);
    HTTP.send(200, "text/plain", "OK");
  }
  else if(protect_ocp == "0" || protect_ocp == "1") {
    Serial.print(COMMAND_CURRENT_PROTECT + protect_ocp);
    HTTP.send(200, "text/plain", "OK");
  }
  else {
    HTTP.send(404, "text/plain", "FileNotFound");
  }
 }
