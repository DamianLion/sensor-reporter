<img src="https://raw.githubusercontent.com/blimpify/animations/master/gif.gif" width="100%">

# Sensor Reporter

esp2866 (wemos/nodemcuv2) programm for posting data to the blimpify api

# Upload

```bash

# Build project
platformio run

# Upload firmware
platformio run --target upload

# Build specific environment
platformio run -e nodemcuv2
platformio run -e d1_mini

# Upload firmware for the specific environment
platformio run -e nodemcuv2 --target upload
platformio run -e d1_mini --target upload

# Clean build files
> platformio run --target clean

```
