/*
 * Board:             Generic ESP8266 module
 * Builtin LED:       2
 * Upload Speed:      921600
 * CPU Frequency:     160 MHz
 * Crystal Frequency: 26 MHz
 * Flash Mode:        DOUT(compatible)
 * Flash Size:        4MB(FS:2MB OTA:~1019KB)
 * Flash Frequency:   80 MHz
 * Reset Metod:       DTR(aka NodeMCU)
 * Debug Port:        Disabled
 * Debug Level:       None
 * LwIP Variant:      v2 Lower Memory
 * VTables:           Flash
 * Exceptions:        Legacy(new can return nullprt)
 * Erase Flash:       Only Sketch
 * ESPressiv FW:      nonos-sdk2.2.1+100(190703)
 * SSL Support:       All SSL Chiphers(most compatible)
 */
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

//Светодиод состояния подключения
#define STATUS_LED 2
//Настройки сервера и модуля
#define HTTP_PORT 80
#define SERIAL_BOUDRATE 9600
#define LOCAL_IP 192,168,4,1
#define GATEWAY_IP 192,168,5,2
#define SUBNET_MASK 255,255,255,0
//Адреса страниц и файлов модуля
#define URL_DEVICE "/api/device"
#define URL_MEMORY "/api/memory"
#define URL_PROTECT "/api/protect"
#define URL_VOLTAGE "/api/voltage"
#define URL_CURRENT "/api/current"
#define URL_UPDATE "/api/update"
#define URL_RESTART "/api/reboot"
#define URL_CONFIG "/api/config"
#define URL_CONFIG_FILE "/config.json"
//Команды по serial
#define COMMAND_IDENTIFICATION "*IDN?"
#define COMMAND_STATUS "STATUS?"
#define COMMAND_TRACK "TRACK"
#define COMMAND_BEEPER "BEEP"
#define COMMAND_OUT "OUT"
#define COMMAND_VOLTAGE_PROTECT "OVP"
#define COMMAND_CURRENT_PROTECT "OCP"
#define COMMAND_RECALL "RCL"
#define COMMAND_SAVE "SAV"
#define COMMAND_VOLTAGE_SET "VSET1:"
#define COMMAND_VOLTAGE_REQUEST "VSET1?"
#define COMMAND_VOLTAGE_OUT "VOUT1?"
#define COMMAND_CURRENT_SET "ISET1:"
#define COMMAND_CURRENT_REQUEST "ISET1?"
#define COMMAND_CURRENT_OUT "IOUT1?"
//Переменные основных настроек
String device_name;
String ssid_sta;
String password_sta;
String ssid_ap;
String password_ap;
String config_json;

#endif
