/*
  ESP32 4WD Wi-Fi Controlled Car
  Board: classic 38-pin ESP32 DevKit-style board
  Driver: L298N dual H-bridge
  Left motor pair: OUT1 / OUT2
  Right motor pair: OUT3 / OUT4

  Access point:
    SSID: ESP32_CAR
    Password: car12345
    URL: http://192.168.4.1

  IMPORTANT:
  - Verify the actual battery pack, polarity, BMS, charger and motor ratings.
  - Keep ESP32 logic power separate from motor power.
  - Connect ESP32 GND to L298N GND.
  - Test with wheels raised before placing the car on the floor.
*/

#include <WiFi.h>
#include <WebServer.h>

const char* AP_SSID = "ESP32_CAR";
const char* AP_PASSWORD = "car12345";

const int ENA = 25;
const int IN1 = 26;
const int IN2 = 27;
const int ENB = 14;
const int IN3 = 32;
const int IN4 = 33;

WebServer server(80);

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void forwardCar() {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backwardCar() {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void leftCar() {
  // Pivot turn: left side reverse, right side forward.
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void rightCar() {
  // Pivot turn: left side forward, right side reverse.
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

const char PAGE[] PROGMEM = R"rawliteral(
<!doctype html>
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>ESP32 Car Control</title>
<style>
body{font-family:Arial,sans-serif;background:#101827;color:#f4f7fb;text-align:center;margin:0;padding:24px}
h1{margin:10px 0 6px}p{color:#b8c5d6}
.grid{display:grid;grid-template-columns:repeat(3, minmax(75px,110px));gap:12px;justify-content:center;margin:28px auto}
button{height:70px;border:0;border-radius:14px;background:#2479c8;color:white;font-size:18px;font-weight:bold}
button.stop{background:#d64b4b}button:active{filter:brightness(1.25);transform:scale(.98)}
.note{font-size:13px;max-width:420px;margin:22px auto;color:#aebdd0}
</style>
</head>
<body>
<h1>ESP32 4WD Car</h1>
<p>Connect to the ESP32 access point to control the car.</p>
<div class="grid">
  <span></span><button onclick="cmd('F')">▲<br>Forward</button><span></span>
  <button onclick="cmd('L')">◀<br>Left</button>
  <button class="stop" onclick="cmd('S')">STOP</button>
  <button onclick="cmd('R')">▶<br>Right</button>
  <span></span><button onclick="cmd('B')">▼<br>Backward</button><span></span>
</div>
<div class="note">Lift the wheels before the first test. Press STOP before changing wiring.</div>
<script>
function cmd(c){fetch('/'+c,{cache:'no-store'}).catch(()=>{});}
window.addEventListener('pagehide',()=>{navigator.sendBeacon('/S');});
</script>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send_P(200, "text/html", PAGE);
}

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  stopCar();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASSWORD);
  Serial.println();
  Serial.print("Wi-Fi AP started: ");
  Serial.println(AP_SSID);
  Serial.print("Connect at: http://");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_GET, handleRoot);
  server.on("/F", HTTP_GET, [](){ forwardCar(); server.send(200, "text/plain", "FORWARD"); });
  server.on("/B", HTTP_GET, [](){ backwardCar(); server.send(200, "text/plain", "BACKWARD"); });
  server.on("/L", HTTP_GET, [](){ leftCar(); server.send(200, "text/plain", "LEFT"); });
  server.on("/R", HTTP_GET, [](){ rightCar(); server.send(200, "text/plain", "RIGHT"); });
  server.on("/S", HTTP_ANY, [](){ stopCar(); server.send(200, "text/plain", "STOP"); });
  server.onNotFound([](){ stopCar(); server.send(404, "text/plain", "Not found"); });
  server.begin();
  Serial.println("HTTP server ready");
}

void loop() {
  server.handleClient();
}
