# The nekoweb site stats display box

Shows nekoweb site views and followers on a 16x2 LCD display utilizing an ESP32 Devboard. Powered by a USB cable.

# Do It Yourself

- Duplicate and rename `config.example.h` to `config.h` and configure your wifi ssid, password and nekoweb stats url.
- Wire up the LCD display to the I2C bus.
- _[optional] Create an enclosure for the thing, OR feel free to 3D print the box I've made titled `nekoweb_box.3mf`. I've also provided the autodesk fusion source file for the design. (Beware, unless you have the very specific board I got from aliexpress, your esp is unfortunately probably not going to fit)_

![doohickey](doohickey.jpg)
