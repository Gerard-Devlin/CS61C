# Lab 5

**IMPORTANT: Do not move staff-provided input and output pins. This will break the testing framework and harness. If your circuit doesn’t pass the tests and you think it is correct, ensure your circuit fits in the corresponding harness in `testing/circ_files/exX_test.circ`.**

## Objectives

- TSWBAT practice designing and debugging basic digital logic circuits in Logisim
- TSW gain more experience designing and debugging circuits with both combinational logic and stateful elements
- TSW gain experience designing FSMs and implementing them as digital logic

## Setup

Pull the Lab 5 files from the lab starter repository with

All the work in this lab will be done from the digital logic simulation program **Logisim Evolution**, which is included in the lab starter files.

**IMPORTANT: Please use the .jar file we’ve given you, not the version of Logisim that is downloaded on the lab computers! And a note: Logisim does not save your work as you go along, and it does not automatically create a new .circ file when you open it! Save when you start, and save frequently as you work.**

You can open Logism via:

```text
java -jar logisim-evolution.jar
```



**IMPORTANT: Logism is a Java program that requires a GUI, so doing the lab over terminal won’t work (without window forwarding, detailed below). If you wish to work on the lab locally, ensure you have Java installed on your local machine, and pull the latest lab starter files to your local machine. Then, you should open the program as above.** If you wish to run the program over the terminal, you will need to add the `-X` flag to your `SSH` command to enable window forwarding (for example, `ssh -X cs61c-xxx@...`). On Windows machines, you may need to additionally install Xming. On OSX, you may need to install XQuartz.

## Introduction Video

For this lab, we created an optional [intro video](https://inst.eecs.berkeley.edu/~cs61c/fa20/lectures/videos?ytvid=yCyKAXPWGE4)! This video covers the introduction to logisim features described in exercises 0 to 3, so you can skip some of the introductory text in those sections if you watch it. You still have to do the action items in exercises 1 to 5 though!

## Introduction

### Part 0: Warm Up

We’ll begin by creating a very simple circuit just to get the feel for placing gates and wires. Before you start, take note of a useful feature: the zoom function! It’s in the bottom left corner, and will make your life much easier for the next couple weeks.

![img](https://www.learncs.site/assets/images/zoom_button-21992c1180dc2625c227ec55f9560c0a.png)

1. ![img](data:image/gif;base64,R0lGODlhFgAWALMAAP////T09O3t7crKysXFxZCQkEdHRx4eHhoaGhAQEA8PDwsLCwkJCQAAAAAAAAAAACwAAAAAFgAWAAAERBDISau9OOvNu2RNKDZLp1xEuJ2XYDQa28KZfBX0ZVtDbu0WXyWxEVKAlF5Ng1tiBMbj8xWzBHBRCmh0QGQ94LB4jIkAADs=) Start by clicking the `AND` gate button. This will cause the shadow of an `AND` gate to follow your cursor around. Click once within the main schematic window to place an `AND` gate.

2. ![img](data:image/gif;base64,R0lGODlhFgAWALMAAKXdnqXcns3dyxzYAB3YABzXABzTABvSABzSAKbdniS/ACW/ACS+AFnaN////wAAACwAAAAAFgAWAAAEU9DJSau9OOvNu9dPKI4haGaPBDAGsgBSijrJQRT3ActYyuCFIGHRKJgMNyABGZwdgLglcLaA4hQC4wzwHBAIOgfvIguwDK/YqQciuT/wuHxO10QAADs=) Click the `Input Pin` button. Now, place two input pins somewhere to the left of your `AND` gate.

3. ![img](data:image/gif;base64,R0lGODlhFgAWALMAAAZXAAVWAKXdnqXcnh3YABzXABzTABvSABzSAFrbN1naN1rbOP///0BAQAAAAAAAACwAAAAAFgAWAAAEVZDJSau9OOvNu/dO6HxMSJmc0zDCYQhMM27jUhQEoZQbEQg33G3AwxBwiKOwcChejgSDUGlwPgECaI5AnGVGiWAhYcWoWAYDUdZBSdxtEWlOr9vvmAgAOw==) Click the `Output Pin` button. Then place an output pin somewhere to the right of your `AND` gate. Your schematic should look something like this at this point:

   ![img](data:image/gif;base64,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)

4. ![img](data:image/gif;base64,R0lGODlhFgAWAJEAAAQEA////wAAAAAAACwAAAAAFgAWAAACKYyPqcvtDyMScgla583nbi4AHuh9UjmeqPmgZMBGGDy/XFdn8c33flQAADs=) Click the `Select tool` button. Click and drag to connect the input pins to the left side of the `AND` gate. This will take several steps, as you can only draw vertical and horizontal wires. Just draw a wire horizontally, release the mouse button, then click and drag starting from the end of the wire to continue vertically. You can attach the wire to any pin on the `AND` gate on the left side. Repeat the same procedure to connect the output of the `AND` Gate (right side) to the output pin. After completing these steps your schematic should look roughly like this:

   ![img](data:image/gif;base64,R0lGODlh4QBLAPcAAAAAAIAAAACAAICAAAAAgIAAgACAgICAgMDAwP8AAAD/AP//AAAA//8A/wD//////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMwAAZgAAmQAAzAAA/wAzAAAzMwAzZgAzmQAzzAAz/wBmAABmMwBmZgBmmQBmzABm/wCZAACZMwCZZgCZmQCZzACZ/wDMAADMMwDMZgDMmQDMzADM/wD/AAD/MwD/ZgD/mQD/zAD//zMAADMAMzMAZjMAmTMAzDMA/zMzADMzMzMzZjMzmTMzzDMz/zNmADNmMzNmZjNmmTNmzDNm/zOZADOZMzOZZjOZmTOZzDOZ/zPMADPMMzPMZjPMmTPMzDPM/zP/ADP/MzP/ZjP/mTP/zDP//2YAAGYAM2YAZmYAmWYAzGYA/2YzAGYzM2YzZmYzmWYzzGYz/2ZmAGZmM2ZmZmZmmWZmzGZm/2aZAGaZM2aZZmaZmWaZzGaZ/2bMAGbMM2bMZmbMmWbMzGbM/2b/AGb/M2b/Zmb/mWb/zGb//5kAAJkAM5kAZpkAmZkAzJkA/5kzAJkzM5kzZpkzmZkzzJkz/5lmAJlmM5lmZplmmZlmzJlm/5mZAJmZM5mZZpmZmZmZzJmZ/5nMAJnMM5nMZpnMmZnMzJnM/5n/AJn/M5n/Zpn/mZn/zJn//8wAAMwAM8wAZswAmcwAzMwA/8wzAMwzM8wzZswzmcwzzMwz/8xmAMxmM8xmZsxmmcxmzMxm/8yZAMyZM8yZZsyZmcyZzMyZ/8zMAMzMM8zMZszMmczMzMzM/8z/AMz/M8z/Zsz/mcz/zMz///8AAP8AM/8AZv8Amf8AzP8A//8zAP8zM/8zZv8zmf8zzP8z//9mAP9mM/9mZv9mmf9mzP9m//+ZAP+ZM/+ZZv+Zmf+ZzP+Z///MAP/MM//MZv/Mmf/MzP/M////AP//M///Zv//mf//zP///ywAAAAA4QBLAAAI/wAfCBxIsKDBgwgTKlzIsKHDhxAjSpxIsaLFixgzatzIsaPHjyBDihxJsqTJkyhTqhQIoKXLlzBjJjwwsyZCmjdtHsS5U6dBnj99FgQ6VChBokeNDkSKMKbTpyujSp2qsWVEq1Szat2aEOtDr1zDipUKdiCNswfLjqX4tG3btVHLnp2LlqBauFfd6n2LlyRYuoDtAuhb8W5eqIQ7eqVrdu5Aw4kXQmYLM/LGxWgdOxZY17LDs4NBvvR8EStjzagBq17NurXr17Bj0xjpknTh0Kczp5bNu7fv37N75hxecLTw40GJJ0detKHp1A8YRwdOvXr10H4n206LHfrmB9q3s//Enp28eIWYZ0Mff16yedrhz//t/B38+/aCU8YXL1d18fv4sacfgAHeVd9jBOK3H0e1BWjQggI6+N9KEFpWYYWRXXFFgiJhSNhefEkokIYaxuUhXiAixlxSyjW34lJKkXhFiyy+KBBSVjF1o1I7cgegjg8AKaJHGnLYoZEYuTXkWidWheRto8m0JFdNZlSle3cZN2VWV5b2pET9BYfgllx++VGXPjYW2HhmkukRmred+dxqY7ppIlVw5jcdfd/laedDRVLVWUag4aabep35+SdDMk5lHWyD5YZoXV0CaSmPQWJ6KY0wGtSojZly2mNBj77GmXebQSbkohQF6mipq1n/JemewSnKqnt4tumcoZPuyeatJ9ma15u8+pqqsMByN5WwDX53rK7JUrYstLuqKZ191EY7LFnZ4krQgchqOyG3ITX4oLnihuTqneWWVVm6In1KYbcO6aVYilKCuqm+mh4kr4vLBQwwe/sKXCOC7x48cFf4JjzkugNOeSG9cIWLnsXzbisxxRNhnLFBB0a4pMfnkhnmtSIPSbJgHI81H511bhyxyd0522fLYq2c8sg192rzlqCZpOWWc/q8G6xIJz1ouzhXzKvRhyotdamihrri0At3ym/VBV986qG0fj312L81fa7ZKPZsbKJoa4Us1n+mt7aYOqOUp1Pavqymnhs3adxwuieD23aZfisJb8zfLr3z4Yx7+9XgjcsMUd2Ry1c45ZVvd7mq/XLd+dagG6y16KOSbrXpq2au+uqst+7667DHLvvstNdu++2456677V0r7PvoWZce/OnD9w7878IjT7zyxid//EABAQA7)

5. ![img](data:image/gif;base64,R0lGODlhFgAWALMAALxwUbxxUbtwUbxxUqNhR6NgR6JgR6NhSP///wAAAAAAAAAAAAAAAAAAAAAAAAAAACwAAAAAFgAWAAAEYhDJSau9OOudU+JXQgQfSCUDUZpSIqjslADHyiYBDHptUHjADkDwwakGOB5GRHQZkiRSR4AMDARWoi5EqA4C2ZzN4vqaweINjmodDp7qAvgLSHMSBsCgPvjtCGxgWzGEhYQRADs=) Finally, click the `Poke` tool and try clicking on the input pins in your schematic. Observe what happens. Does this match with what you think an `AND` Gate should do? Note that poking the wires themselves tells you the current value on that wire; this will be very useful later when you build more complex circuits.

### Part 1: Sub-Circuits

Just as C programs can contain helper functions, a schematic can contain subcircuits. In this part of the lab, we will create several subcircuits to demonstrate their use.

**IMPORTANT NOTE**: Logisim Evolution guidlines say you cannot name a subcircuit after a keyword (e.g. `NAND`), also circuit names must start with “A-Za-z”, so no numbers.

#### Action Item

Follow the steps below and show your final circuit to your TA at checkoff (remember to save!):

**Do not move staff-provided input and output pins. This will break the testing framework and harness. If your circuit doesn’t pass the tests and you think it is correct, ensure your circuit fits in the testing harness in `testing/circ_files/ex1_test.circ`.**

1. Open up the Exercise 1 schematic (`File->Open->ex1.circ`).
2. Open up the NAND1 empty subcircuit by double clicking on the name `NAND1` in the circuit selector in the left menu. (note the `1` at the end; because there is a component called `NAND`, we cannot call it `NAND`).

1. In the new schematic window that you see create a simple `NAND` circuit with the 2 input pins on the left side and the output pin on the right side. Do this without using the built-in `NAND` gate from the Gates folder (i.e. only use the `AND`, `OR`, and `NOT` gates provided next to the selection tool icon). You can change the labels for the inputs and output by selecting the input/output using the select tool and changing the property `Label` in the bottom left of the window.
2. Repeat these steps to create several more subcircuits: `NOR`, `XOR`, `2-to-1 MUX`, and `4-to-1 MUX` in the given skeletons. Please do not change the names of the subcircuits or create new ones; do you work in the respectively named circuit or else the autograder will not work properly. Do not use any built-in gates other than `AND`, `OR`, and `NOT`. Once you’ve built a subcircuit, you may (and are encouraged to) use it to build others. You can do this by clicking and placing your created subcircuit like you would any other component. Note: for the `4-to-1 MUX`, `Sel0` and `Sel1` correspond to the 0th and 1st bits of the 2-bit selector, respectively. Hint: Try writing a truth table. You might also find the lecture slides useful for a refresher on how to build these. *You may want to consider using some of your custom subcircuits when designing the others.*

#### Checkpoint

At this point, make sure that you are comfortable with the Logisim environment, creating sub-circuits, and re-using such circuits in other circuits.

### Part 2: Storing State

Let’s implement a circuit that increments a value ad infinitum. The difference between this circuit and the circuits you’ve built for lab so far is that it will **store** this value in the **state** of a **register**.

#### Action Item

The following steps will show you how to add registers to your circuit. Complete the steps and show the final circuit to your TA (remember to save!):

**Do not move staff-provided input and output pins. This will break the testing framework and harness. If your circuit doesn’t pass the tests and you think it is correct, ensure your circuit fits in the testing harness in `testing/circ_files/ex2_test.circ`.**

1. Open up the Exercise 2 schematic (`File->Open->ex2.circ`) and go to the empty AddMachine circuit.

2. Load in the `Arithmetic` Library if it is not already loaded (go to `Project->Load Library->Built` in `Library` and select `Arithmetic`). This library contains elements that will perform basic mathematical operations. When you load the library, the circuit browser at left will have a new `Arithmetic` folder.

   ![img](https://www.learncs.site/assets/images/arithmetic-d5934c14d4d03e3bfe5720fae875ee08.png)

3. Select the adder subcircuit from the `Arithmetic` library and place the adder into your `AddMachine` subcircuit.

4. Load in the `Memory` Library if it is not already loaded (go to `Project->Load Library->Built` in `Library` and select `Memory`). This library contains memory elements used to keep state in a circuit. A new `Memory` folder will appear in the circuit browser.

5. Select the register from the `Memory` folder and place one register into your subcircuit. Below is an image diagraming the parts of a register.

   ![img](https://www.learncs.site/assets/images/register-096078e48ca8919b7c1efd1aeea2b424.gif)

6. Connect a `clock` to your register. You can find the clock circuit element in the `Wiring` folder in the circuit browser.

7. Connect the output of the adder to the input of the register, and the output of the register to the input of the adder.

   - You may get a “Incompatible widths” error when you try to connect components. This means that your wire is trying to connect two pins together with different bit widths. If you click on the adder with the `Selection` tool, you will notice that there is a `Data Bit Width` property in the bottom left field of the window. This value determines the number of bits each input and output the adder has. Change this field to `8` and the “Incompatible widths” error should be resolved.

8. Wire an 8-bit constant `1` to the second input of the adder. You can find the `Constant` circuit element in the `Wiring` library.

9. Connect the two output pins to your circuit so that you may monitor what comes out of the adder and the register. The output of the adder should be connected to `ADD_OUT` and the output of the register to `REG_OUT`. Thus, by the end, your circuit should look like as follows:

   ![img](https://www.learncs.site/assets/images/AddMachine-97dd99453050d955b57784fb22c4bb11.png)

1. Now start running your circuit by going to `Simulate->Ticks Enabled` (or `Command/Control + K`). Your circuit should now be outputting a counter in binary form.
2. If you want to run your circuit faster, you can change the tick frequency in `Simulate->Tick Frequency`.

#### Checkpoint

At this point, make sure that you are comfortable with designing and simulating simple digital logic circuits in Logisim environment that use a mix of *combinational logic* and *state elements* (registers).

### Part 3: FSMs to Digital Logic

Now we’re ready to do something really cool: translate a FSM into a digital logic circuit.

For those of you who need a reminder, FSM stands for Finite State Machine. FSM’s keep track of inputs given, moves between states based on these inputs, and outputs something everytime something is input.

We use a register to store the state of the FSM we’re currently in, and combinational logic to map FSM input & current register state to FSM output & next register state.

#### Action Item

Load the given starter file `ex3.circ` into Logism. Modify this circuit’s subcircuits `StateBitZero` and `StateBitOne` to implement the following FSM:

**If two ones in a row or two zeroes in a row have ever been seen, output zeros forever. Otherwise, output a one.**

**Do not move staff-provided input and output pins. This will break the testing framework and harness. If your circuit doesn’t pass the tests and you think it is correct, ensure your circuit fits in the testing harness in `testing/circ_files/ex3_test.circ`.**

Show this completed circuit to your TA (remember to save!)

1. Note that the FSM is implemented by the following diagram (the four state names `00`, `01`, `10`, `11` are just names written in binary - they have no direct relationship with the actual zeros and ones of the FSM input/output). Take some time to understand how this diagram implements the FSM:

   ![img](https://www.learncs.site/assets/images/FSM-c35a840800746d6e9cae7f8614d55086.png)

2. Observe that the following is a truth table for the FSM (convince yourself of this):

   | st1  | st0  | input | next st1 | next st0 | output |
   | ---- | ---- | ----- | -------- | -------- | ------ |
   | 0    | 0    | 0     | 0        | 1        | 1      |
   | 0    | 0    | 1     | 1        | 0        | 1      |
   | 0    | 1    | 0     | 1        | 1        | 0      |
   | 0    | 1    | 1     | 1        | 0        | 1      |
   | 1    | 0    | 0     | 0        | 1        | 1      |
   | 1    | 0    | 1     | 1        | 1        | 0      |
   | 1    | 1    | 0     | 1        | 1        | 0      |
   | 1    | 1    | 1     | 1        | 1        | 0      |

3. We’ve provided you with a starter Logisim circuit to start out in `ex3.circ`.

4. Note that the top level of the circuit looks almost exactly the same as our previous adder circuit, but now there’s a `FSMLogic` block instead of an adder block. `FSMLogic` is the combinational logic block for this FSM. We have handled the output bit for you, as it’s the most complicated to simplify and implement. You should complete the circuit by completing the `StateBitOne` and `StateBitZero` subcircuits, which produces the next state bits.

#### Checkpoint

At this point, you should have more familiarity with designing and implementing FSMs, and the close relationship between FSMs and digital logic.

## Advanced Logisim

### Setup

Feel free to do each part as separate sub-circuits in the same Logisim file.

The following parts will introduce you to more advanced techniques/concepts in Logisim.

### Advanced Features

Here are three Logisim features that should both save you a lot of time and make your circuits look much cleaner.

#### Splitters

Splitters allow you to take a multi-bit value and split it up into smaller parts, or (despite the name) combine multiple values that are one or more bits into a single value. Here, we split the 4-bit binary number `1001` into `10` and `01`, then recombine it with `11` into the final 5-bit number `111001`:

![img](https://www.learncs.site/assets/images/splitter_intro-7b90fc895a4fe2d38a150a3f42cd5885.png)

Click on a splitter to get its menu in the sidebar. You can use this menu to determine the number of arms on your splitter and how many bits should go on each arm. For the circuit above, the left splitter’s menu looks like this:

![img](https://www.learncs.site/assets/images/left_split_menu-d94fba0d89a9d820020859a06c74e277.png)

While the right splitter’s menu looks like this:

![img](https://www.learncs.site/assets/images/right_split_menu-077aa5ab9b1722b0a1b812408c887054.png)

**Notice that there’s an option called** `facing`. You can use this to rotate your splitter. Above, see that the splitter on the right is facing West while the splitter on the left is facing East.

If you see an error wire that is orange, this means that your bit width in does not match your bit width out. Make sure that if you’re connecting two components with a wire, you correctly set the bit width in that component’s menu.

![img](data:image/png;base64,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)

#### Tunnels

A tunnel allows you draw an “invisible wire” to bind two points together. Tunnels are grouped by case-sensitive labels give to a wire. They are used to connect wires like so:

![img](data:image/png;base64,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)

Which has an effect such as the following:

![img](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAASEAAABICAIAAAA289RqAAAACXBIWXMAAAsTAAALEwEAmpwYAAABhmlDQ1BQaG90b3Nob3AgSUNDIHByb2ZpbGUAAHjarZGxSiNRFIa/m8RVMWBYglqIXFDEYiLRLTTRJkYwioVEhSTdZDLGhUlymVxRH8DORgvRRlFfQbSxsBQLLQRBCD6DIAgiMhZTTLPsNvtV3/mLw+H8ENKmUk4EqNW1m5+bkYViSba36CLKT9L0mlZTZZaWFvkzAt6fEACPCVMpZ23+43l6Z/Pk4sfC0UBaG/ydrordtEB0AFaladVAOIBhKVeDOAQSm1ppELdA3C0USyBaQLzq+ysQLxeKJQhFgLi7ks9CqA+IlX0fAWJV3yeBmLVuViCUAwz/BgA6c7NyIplKZPjP1JwNK/gZUbu+ugzEgH5yzCKZIEmKBBltb2mAbENtu7+r61pmlHJsmW3U1Ia2XUPO161RQ44nx5IAhWJJ+qvf8ghA9DwEWeMUUoMQ3g2y8gFcXUPfXZANHUP3FFzeK9M1g4bfI/+am2u/xn2PzkDbi+e9DUP7Pnzted7nmed9nUO4BTfONyaoaeGNvFbIAAAAIGNIUk0AAG2YAABzjgAA9jMAAIFAAABwbgAA42IAADF4AAATcpTB5EwAAALUSURBVHja7N1BTxpBGAZgBrEJJHqsJt48GC818exf8Z/4L9sYz6Z68OpF0jRMD1SkuF0UGGZmeZ4TQYlm93v3mx0GJsQYe0AyfYcAZAxkDJAxkDGQMUDGQMZAxoANGWT5qyGEdV5ubQotRVVaeQycGzqQq5LDljNjKxyCNRsg3Q5YjHH+yenj7EnTx6g+YPMpmj2e/UIIIW/MSpzzCD80K5YHLL5qrJz5n+Yd/uSJeGMTb4xW/BaXvpDd7GBvLau1crLfnpXSx2aHaT/sX42ubr7eHPYP9bRaY7DFs7a0crJfkYvoY7PDMewPH84f7n/dXw4vj++On34/NV6T9LFaorUwDNl48VRROWXdj40n45O7k+uf1+pVQ+tM5ZQ1rxh7cRzHjafq7wXpu0kRMVupcvLpV3QORIvpdXZhoFi4/Bn7+GUm+wWJIly83lxVUg91vAf9djQvej1zHvUMC5PMefTCZysn7/tj1t2Takhi3FFQxtpPhlNVb8wS9swPDBcXmliu4U9Z6zxG/dHj+eNe2DvoHzxPnl8mL0eDo6UvpMwRY7q8vX9/taVyZOxzZ0jGZKy3bC1eaevvipvzMDJkeZHEGEJYCE9jtPJ2MHMe1B2z91maPVNOwDL3MR+4ZP1u1l5IJdxW+Iwm1XezxoyVc9M+yHhoYBfKyf0YyBjIGCBjIGMgY4CMgYzBLrHOg46wbwskzFXJYTNWpDsBW/xE2b8L8PUxWDFg9m2BJAGrZd8WfYzqh4jz0Wr5xoFd37cFVoycfVvY2aJP9NUs1e3bYqxIF0z3bTn9cnp7dlva/yZjJG9oW2DfFtgc+7ZAWvZtYcelLn37tgAyRv3s2wLpA2bfFthOxmZJa7whzL5vi4xRccxawlPOthIyRtditjCLaL0ibCBm/1NCecsY3UxaOYUtY5CW98dAxkDGABkDGQMZA2QMZAxkDJAxqMMfAAAA//8DAPxFz7OJqakSAAAAAElFTkSuQmCC)

Some care should be taken as to which wires are connected with tunnels to which other wires, such as in this case:

![img](data:image/png;base64,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)

Which in turn has the following effect:

![img](data:image/png;base64,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)

We *strongly* recommend you use tunnels with Logisim, because they make your circuits much cleaner looking, and therefore easier to debug.

#### Extenders

When changing the width of a wire, you should use a bit extender for clarity. For example, consider the following implementation of extending an 8-bit wire into a 16-bit wire:

![img](data:image/png;base64,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)

Whereas the following is much simpler, easier to read, and less error-prone:

![img](data:image/png;base64,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)

Additionally consider the case of throwing out bits. In this example, an 8-bit wire is being converted into a 4-bit wire by throwing out the other bits:

![img](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAOAAAABMCAIAAAD7kSwjAAAACXBIWXMAAAsTAAALEwEAmpwYAAABhmlDQ1BQaG90b3Nob3AgSUNDIHByb2ZpbGUAAHjarZGxSiNRFIa/m8RVMWBYglqIXFDEYiLRLTTRJkYwioVEhSTdZDLGhUlymVxRH8DORgvRRlFfQbSxsBQLLQRBCD6DIAgiMhZTTLPsNvtV3/mLw+H8ENKmUk4EqNW1m5+bkYViSba36CLKT9L0mlZTZZaWFvkzAt6fEACPCVMpZ23+43l6Z/Pk4sfC0UBaG/ydrordtEB0AFaladVAOIBhKVeDOAQSm1ppELdA3C0USyBaQLzq+ysQLxeKJQhFgLi7ks9CqA+IlX0fAWJV3yeBmLVuViCUAwz/BgA6c7NyIplKZPjP1JwNK/gZUbu+ugzEgH5yzCKZIEmKBBltb2mAbENtu7+r61pmlHJsmW3U1Ia2XUPO161RQ44nx5IAhWJJ+qvf8ghA9DwEWeMUUoMQ3g2y8gFcXUPfXZANHUP3FFzeK9M1g4bfI/+am2u/xn2PzkDbi+e9DUP7Pnzted7nmed9nUO4BTfONyaoaeGNvFbIAAAAIGNIUk0AAG2YAABzjgAA9jMAAIFAAABwbgAA42IAADF4AAATcpTB5EwAAAHWSURBVHja7NwxihpRAMfhNzErNipaLdisF1gQxFLQxrHxAjZ6CRtP4jWsVLyCiJaCgoWtg7jVNqYILBIDWbKbmMD3lTLVn5/zHhZGl8slwL/qiwkQKAgUgYJAQaAIFASKQEGgIFAECgJFoCBQECgCBYEiUBAoCBSBgkARKAgUBIpAQaAgUAQKAr2vKIqiKLLDH1zYBJ/C36wKVKOOeD523N8mezqdbp88HA5JkljsXav63n9ikdfv0ePxOBwOy+VyqVTqdrvXdc5ms9Vq1Ww2O52OGb1B/+qZ/lbtfD5vt9uDwWAymVw/UCqV4jjO5/OPj482/KWvJvhgo7fv0SiKLpfLZrOJ4ziEcD6fl8vlYrEIITw/P9dqtel0ut/vHx4eDCjQuzU6mUx2u121Wi0Wi09PT9lsNoRQKBRCCL1er1arjUajSqViQHfQ+9xHX15ehsNhJpNpNBqtVuvt8/V6PR6Pt9ttv9+v1+umE+h9Gv0+7Ovrazqd/uHJJElyuVwqlTKaQO8cKO6g/82hz2/wMxMCBXdQvEFBoCBQBAoCRaAgUBAoAgWBIlAQKAgUgYJAESgIFASKQEGgCNQECBQEikBBoCBQBAoCRaAgUPipbwAAAP//AwALOYCbdB5WLgAAAABJRU5ErkJggg==)

Despite the implications of its name, a bit extender can also do this same operation:

![img](data:image/png;base64,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)

### Part 4: Practice with Splitters

We’re going to construct a circuit that manipulates an 8-bit number.

#### Action Item

Complete the following steps to create the splitter circuit, and show this to your TA (remember to save). When you’ve completed the circuit, answer the question in step 11.

**Do not move staff-provided input and output pins. This will break the testing framework and harness. If your circuit doesn’t pass the tests and you think it is correct, ensure your circuit fits in the testing harness in `testing/circ_files/ex4_test.circ`.**

1. Open up the Exercise 4 schematic (`File->Open->ex4.circ`) and go to the empty Split circuit.

2. Go to the `Wiring` folder and select the `Splitter` circuit. This circuit will take a wire and split it into a set of wires of smaller width. Conversely, it can also take many sets of wires and combine them into one.

3. Change the `Bit Width In` property (bus width) to `8`, and `Fan Out` property (# of branches) to `3`. Your splitter should now look as follows:

   ![img](data:image/gif;base64,R0lGODlhIwAjAJEAAAAAAP///3d3d////yH5BAEAAAMALAAAAAAjACMAAAJ5jI+pyx0Ao5zRHXGonlbtD3TJhlSix4XjiUqG+bBjusqlC925/bi8xfk5QKQO5kWk2JJKWTGj4gWjMWGvktvtpD7qS/i8gn3WRbDcYm4dx6va23nDTikqmaVhwOOfXmZZZAfYtFZFl4eG1JToNpe4eNHQNuTI+MdYAAA7)

4. Now, select which bits to send out to which part of your fan. The least significant bit is bit `0` and the most significant bit is bit `7`. Bit `0` should come out on fan arm `0`, bits `1`, `2`, `3`, `4`, `5` and `6` should come out on fan arm `1`, and bit `7` should come out on fan arm `2`. FYI: the `None` option means that the selected bit will not come out on ANY of the fan arms.

5. Route `In1` to the splitter. Attach a 2-input `AND` gate to fan arms `0` and `2` and route the output of the `AND` gate to `Out1`.

6. Now, interpret the input as a “sign and magnitude” number. Place logic gates and other circuits to prepare `Out2` to be the negative “sign and magnitude” value of the input. [Sign and magnitude](https://en.wikipedia.org/wiki/Signed_number_representations#Signed_magnitude_representation) is an alternate way of representing signed values - like 2’s Complement, but simpler! The combinational logic should be straight-forward.

7. We will need another splitter to recombine the fans into a single 8-bit bus. Place another splitter with the proper properties (Bit Width In: 8, Fan Out: 3, correct fan widths). Play with the `Facing` and `Appearance` properties to make your final circuit as clean-looking as possible. At this point, `Out2` should be the negation of the input (interpreting the input as a “sign and magnitude” value).

8. Answer the following question:

   > If we decide to take the input and interpret it as a 2’s Complement number, what inputs will produce `Out1 = 1`? *Hint: What do the first and last bits of a 2’s Complement number being 1 tell you about the number?*

### Part 5: Rotate Right

With your knowledge of splitters and your knowledge and experience with multiplexers, you are ready to implement a non-trivial combinational logic block: `rotr`, which stands for “Rotate Right”. The idea is that `rotr A,B` will “rotate” the bit pattern of input `A` to the right by `B` bits. So, if `A` were `0b1011010101110011` and `B` were `0b0101` (`5` in decimal), the output of the block would be `0b1001110110101011`. Notice that the rightmost `5` bits were rotated off the right end of the value and back onto the left end. In RTL, the operation would be something like `R = A >> B | A << (16 - B)`.

#### Action Item

Implement a subcircuit named `rotr` with the following inputs:

- `A` (16-bit), the 16-bit input to be rotated
- `B` (4-bit), the rotation amount (why 4 bits?) You can find the starter subcircuit in `ex5.circ`.

**Do not move staff-provided input and output pins. This will break the testing framework and harness. If your circuit doesn’t pass the tests and you think it is correct, ensure your circuit fits in the testing harness in `testing/circ_files/ex5_test.circ`.**

The output should be `A` rotated right by `B` bit positions, as outlined above. You are **NOT** allowed to use Logisim shifters in your solution, though all other combinational logic (MUXes, constants, gates, adders, etc.) is allowed. Logisim’s built-in MUXes (find them under the `Plexers` menu) might be especialy helpful. Your solution shouldn’t involve a clock or any clocked elements, like registers.

**Hint 1**: Before you start wiring, you should think very carefully about how you might decompose this problem into smaller ones and join them together. You should feel very free to use subcircuits when implementing `rotr`. If you don’t, expect to regret it.

**Hint 2**: Just because we gave you an RTL representation doesn’t mean it’s the best way to look at this problem. Think about the input bits of `B` and think about how to effectively use splitters! Can you do something with the binary form? Remember why binary is good for use in computers: a `1` is easy to represent as an `ON` signal, and a `0` is easy to represent as an `OFF` signal. Let’s say we want to rotate `9` times. `9` is `1001` in binary, or `1*8 + 0*4 + 0*2 + 1*1`. Can you use this to make a cleaner circuit? Making use of the rot* circuits we have provided is a good idea that will keep things clean!

## Testing

To test, run the testing script via:

Since Logisim will be running in one terminal window already, make sure to open up a new window to run the testing script. If it says you don’t have permission, run:

This script will copy your circuits into a testing harness, run your circuits on different inputs, and compare your results to ours. Therefore, please do not touch anything in the `testing` folder unless a TA instructs you to do so. However, you are more than welcome to check out the circuitry involved in testing your code as you will encounter it again when working on Project 3.

## Checkoff

Please submit to the Lab Autograder assignment (same as last week!).

Show your working `2-to-1 MUX`, `4-to-1 MUX`, `AddMachine`, `StateBitZero`, `StateBitOne`, `Split`, and `rotr` circuits to your TA. Be ready to explain how they work.