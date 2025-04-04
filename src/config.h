#include <sys/types.h>
#include <WString.h>

// Set to your WiFi channel
// You can use the following commands to find your WiFi channel:
// Windows:     netsh wlan show networks mode=bssid
// Linux/MacOS: iwlist wlan0 channel
u_int8_t global_channel = 9;

// Wi-Fi credentials
const char* ssid = "";      // Use a 2.4Ghz Wi-Fi hotspot
const char* password = "";

// Grafana Cloud Credentials
// Visit https://grafana.com and register for a free account!
String grafana_username = "";
String grafana_password = "";
String grafana_url = ""; // example: influx-blocks-prod-us-central1.grafana.net