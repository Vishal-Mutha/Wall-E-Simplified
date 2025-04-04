# Wall-E Simplified

This repository is a beginner-friendly adaptation of [SRA-VJTI's Wall-E project](https://github.com/SRA-VJTI/Wall-E). It aims to make the original project's codebase more accessible by providing clearer function definitions and calls, facilitating easier understanding for newcomers.

## Overview

Wall-E is a robotic project developed by SRA-VJTI that focuses on line-following and self-balancing capabilities using the ESP32 microcontroller. While the original project offers a comprehensive implementation, its complexity can be challenging for absolute beginners. This simplified version retains the core functionalities but presents them with enhanced readability and comprehensible function structures.

## Features

- **Readable Codebase:** Functions and their calls are explicitly defined and documented to aid understanding.
- **Core Functionalities Retained:** Maintains the essential features of line-following and self-balancing.
- **ESP32-Based Implementation:** Utilizes the ESP32 microcontroller, known for its inbuilt Wi-Fi and BLE support.

## Getting Started

To get started with this project:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Vishal-Mutha/Wall-E-Simplified.git
   ```

2. **Set Up the Development Environment:**

   Ensure you have the [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html) framework installed and configured.

3. **Build and Flash the Project:**

   Navigate to the project directory and run:

   ```bash
   idf.py build
   idf.py -p [PORT] flash
   ```

   Replace `[PORT]` with the appropriate serial port for your ESP32 device.

## Contributing

Contributions are welcome to further enhance the clarity and functionality of this project. Please ensure that your contributions align with the goal of making the codebase accessible to beginners.

## Acknowledgments

This project is based on the original [Wall-E repository by SRA-VJTI](https://github.com/SRA-VJTI/Wall-E). All credits for the foundational work go to their development team.

---

For more details and to explore the code, visit the [Wall-E Simplified GitHub repository](https://github.com/Vishal-Mutha/Wall-E-Simplified).


