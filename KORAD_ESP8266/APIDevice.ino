/*
 * http://192.168.4.1/api/device?idn=true
 * http://192.168.4.1/api/device?status=true
 * http://192.168.4.1/api/device?mode=2
 * http://192.168.4.1/api/device?mode=1
 * http://192.168.4.1/api/device?mode=0
 * http://192.168.4.1/api/device?beeper=1
 * http://192.168.4.1/api/device?beeper=0
 * http://192.168.4.1/api/device?out=1
 * http://192.168.4.1/api/device?out=0
 */
//Базовые команды блока
void handleDevice() {
  String device_identification = HTTP.arg("idn");
  String device_status = HTTP.arg("status");
  String device_track = HTTP.arg("mode");
  String device_beeper = HTTP.arg("beeper");
  String device_out = HTTP.arg("out");
  
  if(device_identification == "true") {
    Serial.print(COMMAND_IDENTIFICATION);
  }
  else if(device_status == "true") {
    Serial.print(COMMAND_STATUS);
  }
  else if(device_track >= "0" && device_track <= "2") {
    Serial.print(COMMAND_TRACK + device_track);
  }
  else if(device_beeper == "0" || device_beeper == "1") {
    Serial.print(COMMAND_BEEPER + device_beeper);
  }
  else if(device_out == "0" || device_out == "1") {
    Serial.print(COMMAND_OUT + device_out);
    HTTP.send(200, "text/plain", "OK");
  }
  else {
    HTTP.send(404, "text/plain", "FileNotFound");
  }
}
