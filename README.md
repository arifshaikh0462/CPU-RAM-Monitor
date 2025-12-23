# CPU & RAM Monitor (Windows + Linux)

A simple **CPU and RAM monitoring tool written in C**, compatible with **both Windows and Linux** using a **single source file**.  
This project demonstrates **system programming** and **OS-level resource monitoring**.

---

## 📌 Features
- Real-time CPU usage (%)
- Real-time RAM usage (MB)
- Works on **Windows** and **Linux**
- Single source code using **conditional compilation**
- Lightweight terminal-based tool

---

## 🛠 Technologies Used
- Language: **C**
- Compiler: **GCC**
- Windows API (`GetSystemTimes`, `GlobalMemoryStatusEx`)
- Linux `/proc` filesystem

---

## 📂 Project Structure
CPU-RAM-Monitor/
│
├── monitor.c
└── README.md


---

## ⬇️ Clone the Repository
Use the following command to download the project:

```bash
git clone https://github.com/arifshaikh462/CPU-RAM-Monitor.git
cd CPU-RAM-Monitor
▶️ How to Run on Windows
✅ Requirements

Windows OS

MinGW / MinGW-w64

GCC added to PATH

Git installed (optional)

🔧 Compile
gcc monitor.c -o monitor.exe

▶️ Run
monitor.exe

🛑 Stop Program

Press:

Ctrl + C

▶️ How to Run on Linux (Ubuntu / WSL)
✅ Requirements

Linux OS or WSL

GCC

Git (optional)
🔧 Install GCC
sudo apt update
sudo apt install build-essential

🔧 Compile
gcc monitor.c -o monitor

▶️ Run
./monitor

🛑 Stop Program

Press:

Ctrl + C

🧠 How It Works

Uses conditional compilation (#ifdef _WIN32) to detect OS.

Windows uses Windows API for CPU & RAM statistics.

Linux uses /proc filesystem for system information.

🎓 Use Case

OS Internals & System Programming

Cyber Security / Ethical Hacking Learning

College Mini Project

⚠️ Disclaimer

This project is intended only for educational purposes.

👤 Author

Arif Shaikh

⭐ Support

If you find this project useful, please give it a ⭐ on GitHub.


---

