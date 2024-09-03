# Air Quality Monitoring System

This project is an IoT-based Air Quality Monitoring System that measures the concentration of various gases in the air using multiple sensors and provides real-time data monitoring via a mobile app. The system sends email alerts when gas levels exceed predefined thresholds, ensuring timely notifications for health and safety.

## Features

- **MQ Sensors**: Utilizes multiple MQ sensors to measure:
  - **MQ-35**: Measures Carbon Dioxide (CO2)
  - **MQ-7**: Measures Carbon Monoxide (CO)
  - **MQ-8**: Measures Hydrogen (H2)
  - **MQ-5**: Measures Liquefied Petroleum Gas (LPG) and Methane

- **Email Alert System**: Configured with a custom SMTP feature to send email alerts when gas levels exceed specified limits.

- **Remote Monitoring**: Access real-time air quality data through a mobile app, featuring a user-friendly dashboard that displays current sensor readings and status.

- **ESP32 Wi-Fi Module**: Integrates the ESP32 Wi-Fi module for wireless communication and data transmission to the Arduino IoT Cloud.

- **Arduino IoT Cloud**: Utilizes Arduino IoT Cloud for live monitoring, allowing users to access data from anywhere via the internet.

## Technologies Used

- **Microcontroller**: ESP32
- **Sensors**: MQ-35, MQ-7, MQ-8, MQ-5
- **Communication**: Wi-Fi
- **Cloud Platform**: Arduino IoT Cloud
- **Email Service**: Custom SMTP configuration

## Getting Started

### Prerequisites

- **Hardware**:
  - ESP32 development board
  - MQ-35, MQ-7, MQ-8, MQ-5 sensors
  - Jumper wires
  - Breadboard (optional)

- **Software**:
  - Arduino IDE
  - Arduino IoT Cloud account

### Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/yourusername/Air-Quality-Monitoring-System.git
   cd Air-Quality-Monitoring-System
Install Dependencies:

Open Arduino IDE and install necessary libraries for the ESP32 and sensors.
Configure the Code:

Update the code with your Wi-Fi credentials and SMTP settings in the appropriate sections.
Upload the Code:

Connect the ESP32 board to your computer and upload the code using Arduino IDE.
Set Up Arduino IoT Cloud:

Follow the instructions on the Arduino IoT Cloud to create a new device and link it to your ESP32.

Usage
Monitoring Air Quality:

Once the system is set up, you can monitor the air quality in real-time through the Arduino IoT Cloud dashboard.
Receiving Email Alerts:

Configure the thresholds in the code to receive email alerts when the gas levels exceed safe limits.
Mobile App Access:

Access the dashboard from your mobile device to view live readings and monitor air quality remotely.
Contributing
If you wish to contribute to this project, feel free to fork the repository and submit a pull request. Ensure that you follow the coding style and include appropriate tests.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Arduino
ESP32
MQ Sensors
Custom SMTP Libraries
