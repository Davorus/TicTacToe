# TicTacToe

## Functionality

Inside of the `int main()` method is only an instance of the `Gamesetup_Handler`, which has the menu lead implemented and sets up the whole game. Playerinitialization is taken by the `Game_Handler` and the playermanagement itself. `Playfield_Handler` takes care of printing the playfield and if a player has won.

---

## How to run the code

1. Open Visual Studio Code
2. Open the repo in Visual Studio Code
3. Open `main.cpp`
4. Compile the `main.cpp` file

---

## Extensions

* I implemented a complete menu lead, instead of opening and compiling it once you can play more games before it closes
* Outsourced code snippets in only functional header, wanted to use `modules` but the gnu compiler isn't capable in using them
  
---

## Sources

* For the playfield I went through this tutorial: [_GeeksForGeeks_](https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/)
* Random number generator: [_Stackoverflow_](https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c)
* Console clearing: [_DelftStack_](https://www.delftstack.com/howto/cpp/how-to-clear-console-cpp/)
* Intended output delay on console: [_Stackoverflow_](https://stackoverflow.com/questions/27215705/how-to-delay-output-in-c)
