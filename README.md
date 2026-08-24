# simpleHPP
This add-on makes managing basic needs easier and simpler.

## wait_**
- This will cause the code to wait for a specific amount of time.
example: `wait_sec(3);`
also you may use:
* wait_mcsec -- macroseconds
* wait_mlsec -- miliseconds
* wait_min -- minutes
## randint
 It generates a random number (by default between 1 and 100, though you can change the range in the 'simple.hpp' source code).
- example: `int a = randint();`
## randge
Gets a random number from the range.
- example: `int a = randge(5, 10) // It will generate a random number between 5 and 10.`
## gen_progres_bar
Generate a progress bar (It's beta-version).
- example: `string bar = gen_progres_bar(5) // 5 - push there a num from 0 to 100. `
## Timer
> Need to count time? Easy-to-use Timer will help.
1. Create timer-device. `Timer w;`
2. Start counting time. `w.start();`
3. End counting time. `w.end();`
4. Get a result! `w.get_time();`;
> I haven't gotten around to clearing the timer yet, but I definitely will in the next version!
## input
The input() function displays a prompt and reads a string in a single command. It can accept strings containing spaces. The function automatically checks the buffer and clears the leftover "Enter" character after numeric input, protecting the code from bugs.
- example: `std::string name = input("How are you? ");`
> [!WARNING]
> For now, the function *must* receive a prompt; if you don't need to display a prompt, simply leave the double quotes empty (`std::string name = input("");`). I’ll fix this minor issue in the next version.
### simpleHPP
- will output a link to the original GitHub repository and the current version of simpleHPP

---
_Thank you for using **simpleHPP**! Good luck!_
