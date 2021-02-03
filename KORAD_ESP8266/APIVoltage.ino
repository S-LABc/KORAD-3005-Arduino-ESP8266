/*
 * http://192.168.4.1/api/voltage?set1=12.34
 * http://192.168.4.1/api/voltage?req1=true
 * http://192.168.4.1/api/voltage?out1=true
 */
//Работа с опциями напряжения
void handleVoltage() {
  String voltage_set_1 = HTTP.arg("set1");
  String voltage_request_1 = HTTP.arg("req1");
  String voltage_out_1 = HTTP.arg("out1");

  if(voltage_set_1 >= "0.00" && voltage_set_1 <= "31.00") {
    Serial.print(COMMAND_VOLTAGE_SET + voltage_set_1);
    HTTP.send(200, "text/plain", "OK");
  }
  else if(voltage_request_1 == "true") {
    Serial.print(COMMAND_VOLTAGE_REQUEST);
  }
  else if(voltage_out_1 == "true") {
    Serial.print(COMMAND_VOLTAGE_OUT);
  }
  else {
    HTTP.send(404, "text/plain", "FileNotFound");
  }
}
