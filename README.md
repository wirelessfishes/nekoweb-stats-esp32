# the doohickey

Shows nekoweb site views and followers on a 16x2 LCD display utilizing an ESP32 Devboard.

# Setup

- Duplicate and rename `secrets.example.h` to `secrets.h` and your wifi ssid, password and nekoweb stats url
- Configure the `UPDATE_INTERVAL_MINUTES` in `main.cpp`
- Wire up the LCD display to the I2C bus
- [optional] Create an enclosure for the thing (cardboard not recommended)
- Enjoy!

![doohickey](doohickey.jpg)
