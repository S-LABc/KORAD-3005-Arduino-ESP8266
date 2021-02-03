/*
 * http://192.168.4.1/api/current?set1=0.125
 * http://192.168.4.1/api/current?req1=true
 * http://192.168.4.1/api/current?out1=true
 */
//Работа с опциями тока
void handleCurrent() {
  String current_set_1 = HTTP.arg("set1");
  String current_request_1 = HTTP.arg("req1");
  String current_out_1 = HTTP.arg("out1");
  
  if(current_set_1 >= "0.000" && current_set_1 <= "5.100") {
    Serial.print(COMMAND_CURRENT_SET + current_set_1);
    HTTP.send(200, "text/plain", "OK");
  }
  else if(current_request_1 == "true") {
    Serial.print(COMMAND_CURRENT_REQUEST);
  }
  else if(current_out_1 == "true") {
    Serial.print(COMMAND_CURRENT_OUT);
  }
  else {
    HTTP.send(404, "text/plain", "FileNotFound");
  }
}
