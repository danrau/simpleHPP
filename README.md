# simpleHPP | v0.1a

A single-header C++ utility library (`simple.hpp`) providing streamlined functions for input, delays, random numbers, and execution timing.

---

## Namespace Configuration

All library components are defined within the `simple` namespace. The header automatically includes `using namespace simple;` at the bottom of the file.

### Directly calling functions
Because of the automatic namespace activation, you can call all library features directly without any prefixes:

```cpp
#include "simple.hpp"

int main() {
    wait(1000); 
    Timer w;    
}
```

### Using explicit qualification
If you prefer explicit qualification in your codebase, you can still access every feature using the `simple::` prefix:

```cpp
#include "simple.hpp"

int main() {
    simple::wait(1000); 
    simple::Timer w;    
}
```

---

## Detailed API Usage & Examples

### 1. Delay Function (`wait`)
Suspends program execution. By default, the integer passed represents **milliseconds**. You can optionally specify a custom time unit using `WaitUnit`.

* **Available Units:** `WaitUnit::Microseconds`, `WaitUnit::Milliseconds`, `WaitUnit::Seconds`, `WaitUnit::Minutes`

```cpp
#include "simple.hpp"

int main() {
    // Delays execution for 3000 milliseconds (3 seconds)
    wait(3000); 

    // Delays execution for 5 seconds explicitly
    wait(5, WaitUnit::Seconds);

    // Delays execution for 100 microseconds
    wait(100, WaitUnit::Microseconds);

    // Delays execution for 2 minutes
    wait(2, WaitUnit::Minutes);
}
```

### 2. Random Numbers (`randint`)
Generates a random integer within a specified range using a reliable pseudo-random number generator engine under the hood.

```cpp
#include "simple.hpp"
#include <iostream>

int main() {
    // Generates a random number between 1 and 100 (Default range)
    int rand_num = randint(); 

    // Generates a random number between 5 and 15 (Custom inclusive range)
    int custom_rand = randint(5, 15); 
}
```

### 3. Safe Console Input (`input`)
Prints an optional prompt string to the console and reads a line of text (including spaces). It automatically detects and clears any residual characters or trailing newlines (`\n`) from previous extractions in the input stream, preventing input skipping bugs.

```cpp
#include "simple.hpp"
#include <string>

int main() {
    // Displays a prompt and reads the string
    std::string name = input("Enter text: ");

    // Reads a string without displaying any prompt message
    std::string response = input(); 
}
```

### 4. Code Execution Profiler (`Timer`)
A high-precision stopwatch class measuring intervals in microseconds. It tracks time dynamically, allowing you to inspect elapsed intervals without resetting or halting the stopwatch state.

```cpp
#include "simple.hpp"
#include <iostream>

int main() {
    Timer w;
    
    // Starts the execution timer
    w.start();
    
    // ... code execution ...
    
    // Retrieves the current elapsed time in microseconds without stopping the timer
    std::cout << "Elapsed: " << w.get_time() << " microseconds" << std::endl; 
    
    // Halts the timer and locks the final execution duration
    w.end();   
    
    // Resets internal start and end checkpoints back to zero
    w.clear(); 
}
```

### 5. Progress Bar Generator (`gen_progres_bar`)
Accepts an integer input representing a percentage (0 to 100) and returns a graphical loading bar formatted as a string.

```cpp
#include "simple.hpp"
#include <iostream>

int main() {
    // Generates a 50% state progress bar string
    std::string bar = gen_progres_bar(50); 
    
    std::cout << bar << std::endl; // Output: [#####-----] 50%
}
```

### 6. Quick Utilities
* `ccls()` — A cross-platform macro-driven function to clear the terminal screen (`cls` on Windows, `clear` on POSIX systems).
* `simpleHPP()` — Prints out version metadata along with the link to the official source repository.
