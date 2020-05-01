# Arduino Brew Timer
This arduino-based brew timer can be used to monitor the extraction time when preparing espresso thus helps to improve the reproducibility when making espresso.

# Required Hardware
In order to build this brew timer several hardware components are needed.
- Arduino Nano V3
- OLED Display I2C 0.96 LCD 128X64 SSD1306
- 1-Bit AC 220V Optokoppler Isolation Modul
- Netzteil 5V 220V

# Functionality
The brew timer monitors the microswitch on the lever of an espresso machine with E61 brewing group. As soon as the lever is actuated, the timer starts counting. After the brewing is finished, the timer stops and a coffee cup is displayed to indicate the end of the brewing process (only if the brewing time is abount a typical brew time). The brew timer then enters the standby mode. For this a tired smilie is displayed until a new espresso is brewed.

![Brew Timer Demo](demo/demo.gif)

# Contact person: 
[Fabian Christ](mailto:fabian.christ@tum.de).
