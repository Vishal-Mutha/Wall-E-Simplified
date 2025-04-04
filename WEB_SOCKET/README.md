# 🌐 ESP32 Web Server - Input Form Project

This project sets up an **ESP32** as a Wi-Fi client (station mode), connects it to your Wi-Fi network, and starts a **web server**. The server hosts a simple web page where you can submit a **string** and an **integer** using HTML forms. Submitted data is logged on the ESP32.

---

## 📋 What This Project Does

- Connects ESP32 to a Wi-Fi network (as a client).
- Runs a lightweight **HTTP server** on the ESP32.
- Serves an HTML page with two input forms:
  - One for integers.
  - One for strings.
- When you submit either form, the data is sent back to the ESP32 via a `GET` request.
- The ESP32 receives the data, logs it, and stores it in a variable.

---

## 🛠️ Prerequisites

- ESP32 board
- ESP-IDF development environment installed
- USB cable to connect ESP32 to your computer
- Wi-Fi network to connect to

---

## 🧠 Key Concepts

### 🛱 Wi-Fi Station Mode

ESP32 connects to an existing Wi-Fi network using your provided `SSID` and `PASSWORD`. You must change these:

```c
#define SSID "your ssid"
#define PASS "your password"
```

---

### 🌍 Web Server (HTTP)

- Uses ESP-IDF's built-in HTTP server.
- Listens for `GET` requests at `/` and `/get`.

---

### 🧾 HTML Page

When you access the ESP32's IP address from a browser, you see a form with:

- **Text input for an integer**
- **Text input for a string**
- JavaScript sends this data back using AJAX (asynchronous request)

---

## 🧪 What Happens Internally

1. ESP32 boots up.
2. It connects to your Wi-Fi network.
3. It starts the HTTP server.
4. You access the ESP32 via its IP address in your browser.
5. You submit a value through one of the forms.
6. ESP32 receives and logs:
   - `int` value → stored in global `int integer;`
   - `str` value → stored in global `char stringg[64];`
7. The server replies with `"The data was sent ..."`.

---

## 🗅️ Output Example

Serial monitor output (via `idf.py monitor`) when a value is submitted:

```
WiFi connecting ...
WiFi connected ...
WiFi got IP ...

Found URL query: int=42
42
The int value = 42

Found URL query: str=hello
hello
The string value = hello
```

---

## 🚀 How to Run

1. Clone this project or copy the code into your ESP-IDF environment.

2. Open `main.c` and update your Wi-Fi credentials.

3. Build and flash the firmware:

   ```bash
   idf.py build
   idf.py -p /dev/ttyUSB0 flash monitor
   ```

4. After boot, find the ESP32 IP address (from logs).

5. Open that IP in your browser — you'll see the input forms!

6. Start sending values 🎉

---

## 🛀 Notes & Tips

- ESP32 must be on the **same network** as the device accessing it.
- Avoid sending too long strings (limited buffer size).
- You can modify the HTML to improve UI or add more fields.

---

## 📦 Future Ideas

- Add a POST endpoint with JSON support
- Display values dynamically on the web page
- Save inputs to NVS flash

---

Feel free to fork and expand on it!
