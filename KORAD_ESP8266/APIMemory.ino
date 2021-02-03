/*
 * http://192.168.4.1/api/memory?recall=1
 * http://192.168.4.1/api/memory?recall=2
 * http://192.168.4.1/api/memory?recall=3
 * http://192.168.4.1/api/memory?recall=4
 * http://192.168.4.1/api/memory?recall=5
 * http://192.168.4.1/api/memory?save=1
 * http://192.168.4.1/api/memory?save=2
 * http://192.168.4.1/api/memory?save=3
 * http://192.168.4.1/api/memory?save=4
 * http://192.168.4.1/api/memory?save=5
 */
//Работа с памятью
void handleMemory() {
  String memory_recall = HTTP.arg("recall");
  String memory_save = HTTP.arg("save");

  if(memory_recall >= "1" && memory_recall <= "5") {
    Serial.print(COMMAND_RECALL + memory_recall);
    HTTP.send(200, "text/plain", "OK");
  }
  else if(memory_save >= "1" && memory_save <= "5") {
    Serial.print(COMMAND_SAVE + memory_save);
    HTTP.send(200, "text/plain", "OK");
  }
  else {
    HTTP.send(404, "text/plain", "FileNotFound");
  }
}
