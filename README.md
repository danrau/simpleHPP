# simpleHPP | V0.2A

A lightweight, header-only C++ utility library designed to simplify common everyday tasks such as file I/O, console text input, benchmark timing, progress bar generation, random number generation, and cross-platform terminal control.

## 🚀 Features

- **Zero Dependencies**: Header-only library (`simple.hpp`). Just include and use.
- **File Utilities**: Simple functions to check file existence and read complete files into strings.
- **Safe Input**: Enhanced Python-like `input()` function with automatic stream clearing.
- **High-Resolution Timer**: Easy benchmarking with multi-unit support (Microseconds to Minutes).
- **Progress Bar**: Generate clean, text-based progress bars instantly.
- **Thread-Safe Randomization**: Quick pseudo-random integer and double generation using `std::mt19937`.
- **Cross-Platform Clear Screen**: Fast ANSI terminal clearing with automated Windows Virtual Terminal initialization.

## 📋 Installation

Since **simpleHPP** is a header-only library, you can simply drop the header file into your project directory and include it:

```cpp
#include "simple.hpp"
```

## 🛠️ Usage Examples

All features live inside the `simple` namespace.

### 1. Basic Info & Setup
```cpp
#include "simple.hpp"

int main() {
    simple::simpleHPP(); // Prints library version, GitHub repository, and contact email
    return 0;
}
```

### 2. Python-like User Input
```cpp
std::string name = simple::input("Enter your name: ");
std::string age_str = simple::input("Enter your age: ");
```

### 3. File Operations
```cpp
if (simple::hasfile("config.txt")) {
    std::string content = simple::readfile("config.txt");
    std::cout << "File Content:\n" << content << std::endl;
} else {
    std::cout << "File not found!" << std::endl;
}
```

### 4. Code Execution Benchmarking (Timer)
```cpp
simple::Timer timer;

timer.start();
simple::wait(500, simple::TimeUnit::Milliseconds); // Sleep for 500ms
timer.end();

std::cout << "Elapsed time: " << timer.getTime(simple::TimeUnit::Milliseconds) << " ms" << std::endl;
std::cout << "Elapsed time (seconds): " << timer.getTimeX() << " s" << std::endl;
```

### 5. Random Number Generation
```cpp
// Generates a thread-safe random integer between 10 and 50
int random_int = simple::randint(10, 50);

// Generates a thread-safe random double between 0.0 and 1.0
double random_double = simple::randouble(0.0, 1.0);
```

### 6. Terminal Progress Bar
```cpp
for (int i = 0; i <= 100; i += 20) {
    simple::ccls(); // Clear terminal screen cross-platform
    std::cout << "Downloading: " << simple::genProgressBar(i) << std::endl;
    simple::wait(200);
}
```

## 🗂️ API Reference

### Configuration & Namespace: `simple::`

| Function / Class | Description |
| :--- | :--- |
| `void simpleHPP()` | Prints library banner and metadata to the standard output. |
| `bool hasfile(const std::string& filename)` | Returns `true` if the file exists and is accessible. |
| `std::string readfile(const std::string& filename)` | Reads an entire file into a string. Returns `""` if the file doesn't exist. |
| `std::string input(const std::string& prompt)` | Displays an optional prompt and safely reads a full line from `std::cin`. |
| `int randint(int min, int max)` | Generates a random uniform integer in range `[min, max]`. |
| `double randouble(double min, double max)` | Generates a random uniform double in range `[min, max]`. |
| `void wait(int time, TimeUnit unit)` | Pauses execution thread for a given duration. |
| `void ccls()` | Clears the console window and resets cursor position using ANSI escape codes. |

### `simple::Timer` Class

* `void start()` — Starts or resets the timer checkpoint.
* `void end()` — Stops the timer checkpoint.
* `void clear()` — Resets internal time points.
* `long long int getTime(TimeUnit unit)` — Returns elapsed duration as an integer. Defaults to `TimeUnit::Milliseconds`.
* `double getTimeX()` — Returns elapsed duration in seconds as a high-precision `double`.

### `simple::TimeUnit` Enum

Used across `Timer` and `wait()` tools:
* `TimeUnit::Microseconds`
* `TimeUnit::Milliseconds`
* `TimeUnit::Seconds`
* `TimeUnit::Minutes`

## 📄 License

This project is open-source. Please check the repository structure or contact the author for licensing details.

---
**Author:** danrau  
**Email:** [blink.dagger1337@icloud.com](mailto:blink.dagger1337@icloud.com)  
**GitHub:** [danrau/simpleHPP](https://github.com/danrau/simpleHPP)