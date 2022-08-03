# TicTacToe

## Functionality

Inside of the `int main()` method is only an instance of the `Gamesetup_Handler`, which has the menu lead implemented and sets up the whole game. Playerinitialization is taken by the `Game_Handler` and the playermanagement itself. `Playfield_Handler` takes care of printing the playfield and if a player has won.

---

## How to run the code

1. Open Visual Studio Code
2. Open the repo in Visual Studio Code
3. Open `main.cpp`
4. Compile the `main.cpp` file

>It's possible to run the code on other compilers than gnu, but some lines have to be changed and the overall structure has to be implemented a bit different depending on what IDE you want to run the code

---

## Player structure

> Based on simple abstraction: a method `player_move(...)` that has to be derived in every derived class of player

The structure of the players is quiet simple to understand, all I have done is to create a base class `Player` that needs to be derived and through pointers I can call the true virtual method `player_move(...)` in every derived class without to know what class was instanciated.

> For refreshing what inheritance is in object-oriented programming:  [Inheritance](https://en.wikipedia.org/wiki/Inheritance_(object-oriented_programming))

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
