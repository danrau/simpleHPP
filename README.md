# simpleHPP
This add-on makes managing basic needs easier and simpler.

## wait_**
- This will cause the code to wait for a specific amount of time.
example: ```C++
  wait_sec(3);
  ```
also you may use:
* wait_mcsec -- macroseconds
* wait_mlsec -- miliseconds
* wait_min -- minutes
## randint
- It generates a random number (by default between 1 and 100, though you can change the range in the `simple.hpp` source code).
example ```C++
  int a = randint();
  ```
## randge
- Gets a random number from the range.
example: ```C++
  int a = randge(5, 10) // It will generate a random number between 5 and 10.
  ```
### simpleHPP
- will output a link to the original GitHub repository and the current version of simpleHPP
=== Thank you by using simpleHPP! Good luck!
