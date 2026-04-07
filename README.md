# ⚡ SystemZero: Native Linux Optimizer

**SystemZero** is a high-performance, low-level optimization tool written in C++ for Linux systems. Designed specifically for machines with extremely limited resources, it bypasses the overhead of traditional shell scripts to interact directly with the Kernel.

If your hardware is old or your RAM is scarce, SystemZero ensures your system stays lean and fast.

---

## 🚀 Why C++?
Unlike common bash scripts, SystemZero is compiled into machine code. 
- **Zero Overhead:** No interpreter needed.
- **Kernel Intervener:** Uses native POSIX calls (`sync`) and direct file streams to manage memory.
- **Silent & Efficient:** Designed to work in the background without cluttering your terminal.

## 🛠️ Features
- **Native RAM Wipe:** Forces the Kernel to drop unnecessary caches and buffer memory.
- **System Purge:** Automatically identifies and removes orphaned dependencies and APT junk.
- **Resource Focused:** Optimized with the `-O3` flag for maximum execution speed.

## 📥 Installation

You need `g++` (GNU C++ Compiler) installed on your Linux distribution.

```bash
# Clone the repository
git clone [https://github.com/ortiz10m/SystemZero.git](https://github.com/ortiz10m/SystemZero.git)

# Enter the directory
cd SystemZero

# Compile the native binary
g++ -O3 systemzero.cpp -o systemzero

## 🧠 Philosophy
In a world of bloated software, efficiency is a revolutionary act. SystemZero is built on the principle that **if code runs fast on a decade-old machine, it runs fast anywhere.**

---
*Developed by [David Santiago Ortiz Rincon](https://github.com/ortiz10m) - Software Engineering Student*
