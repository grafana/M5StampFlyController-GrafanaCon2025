# M5Atom Controller

## Monitor drone telemetry with Grafana

Build, flash, and fly your own IoT drone controller with live telemetry to **Grafana Cloud** using **ESP32 devices**.

**This repository contains the code for the controller (M5Atom Joystick).**
To complete the workshop, you’ll also need to flash a separate firmware to the drone itself (M5Stamp Fly).
👉 Get it here: [M5StampFly-GrafanaCon2025](https://github.com/grafana/M5StampFly-GrafanaCon2025)

See the full [presentation](https://docs.google.com/presentation/d/1gplOTQXUGFakvUzN_5wO11U3CwkT_uDoR_AfIqQhD4M/edit?usp=sharing) for more details.

## 🚀 What You’ll Do
- Flash two ESP32-based devices
- Pair joystick + drone
- Send telemetry to Grafana Cloud
- Visualize live data in a pre-built dashboard

## 🧰 Hardware
- [M5Stamp Fly](https://docs.m5stack.com/en/app/Stamp%20Fly) (drone)
- [M5Atom Joystick](https://docs.m5stack.com/en/app/Atom%20JoyStick) (controller)
- 2× 300mAh LiPo batteries (included)
- USB-C data cable (not charge-only)

## 💻 Setup
### 1. Install Tools

- **VS Code**: https://code.visualstudio.com/
- **PlatformIO Extension**: search for `PlatformIO IDE` in VS Code
- **Git**: https://git-scm.com/downloads

### 2. Clone Repos
```bash
mkdir grafana-iot-workshop
cd grafana-iot-workshop 
git clone https://github.com/grafana/M5StampFly-GrafanaCon2025.git
git clone https://github.com/grafana/M5StampFlyController-GrafanaCon2025.git
```

## Enviroment prep

### Linux

```bash
sudo usermod -aG dialout $USER
# Reboot required
```

### macOS

```bash
xcode-select --install
softwareupdate --install-rosetta  # if using Apple Silicon
```

### Windows

Windows may have built-in support for the devices.

If the device isn’t recognized, download and install the [CP210x driver](https://docs.m5stack.com/en/download).


## 📈 Grafana Cloud Setup

1. Sign up at grafana.com
1. Navigate to **grafana.com > My Account**
In your Grafana Cloud Portal, open up the details of your Grafana Instance
1. Open up the details of your **InfluxDB instance**
1. Note:

    - Remote Write URL
    - Username
    - API Token

1. Import dashboard:

    - In Grafana > Dashboards > Import Dashboard > enter ID: `23370`

## Flashing the devices

### M5Atom Joystick

1. In VsCode, open the M5StampFlyController-GrafanaCon2025 repo
1. Edit src/config.h:

    ```
    #define WIFI_SSID "your-ssid"
    #define WIFI_PASSWORD "your-password"
    #define GRAFANA_URL "your-url"
    #define GRAFANA_USER "your-user"
    #define GRAFANA_TOKEN "your-token"
    ```

1. Set the channel of your 2.4 GHz band wifi. The device only supports 2.4Ghz WiFi.

    ```
    uint8_t global_channel = 8;
    ```

    To check Wi-Fi channels:

    Linux/macOS: `iwlist wlan0 channel`

    Windows: `netsh wlan show networks mode=bssid`

1. Connect the controller via USB
1. Click ✅ to build, then ➡️ to upload

### M5Stamp Fly

1. Open the fly repo in VS Code
1. Edit `src/config.h` (only if changing Wi-Fi channel):

    ```
    uint8_t global_channel = 8;
    ```
1. Connect via USB and upload
    > ⚠️ Both devices must use 2.4GHz Wi-Fi and be on the same channel. You might need to enable Client-to-Client (P2P) on your router.

## 🛠 Assembly & Testing

- [Assembly Video](https://www.youtube.com/watch?v=cSGi8gdll2o&t=27s) (23s)
- [Pairing video](https://youtu.be/cSGi8gdll2o?feature=shared&t=43) (43s)

## Framework

Platfromio

## Base on project

[M5Fly-kanazawa/AtomJoy2024June (github.com)](https://github.com/M5Fly-kanazawa/AtomJoy2024June)

## Third-party libraries

m5stack/M5GFX @ ^0.1.16

fastled/FastLED @ ^3.7.0

lvgl @ ^8.3.10

M5AtomS3 @ ^0.0.3

Happy hacking!
