# TicTacToe

## Functionality

Inside of the `int main()` method is only an instance of the `Gamesetup_Handler`, which has the menu lead implemented and sets up the whole game. Playerinitialization and the playermanagement is taken by the `Game_Handler`. The `Playfield_Handler` takes care of printing the playfield and checks if a player has won.

---

## How to run the code

>Tip: If you want to play with a bigger field against some bots, then make the console a bit bigger

1. Open Visual Studio Code
2. Open the repo in Visual Studio Code
3. Open and compile `main.cpp`

>It's possible to run the code on other compilers than gnu, but some lines have to be changed and the overall structure has to be implemented a bit different depending on what IDE you want to run the code

---

## How to run the tests

1. Choose Kit of MinGW
2. Let it build
3. On the bottom of Visual Studio Code should now be a run button, click this one

---

## Player structure

> Based on simple abstraction: a method `player_move(...)` that has to be derived in every derived class of player

The structure of the players is quiet simple to understand, all I have done is to create a base class `Player` that needs to be derived and through pointers I can call the true virtual method `player_move(...)` in every derived class without to know what class was instanciated.

In the `Game_Handler` you set up a new `if` statement in the `initialize_players()` method.You also have to add the playertype in the menu so that the user can choose it.
The function to include that is in the `Gamesetup_Handler`: `set_player_type()`

> For refreshing what inheritance is in object-oriented programming:  [_Inheritance_](https://en.wikipedia.org/wiki/Inheritance_(object-oriented_programming))

---

## Extensions

* I implemented a complete menu lead, instead of opening and compiling it once you can play more games before you close it
* Outsourced code snippets in an only functional header, wanted to use [_modules_](https://en.cppreference.com/w/cpp/language/modules) but the gnu compiler isn't capable in using them
  
---

## Sources

* For the playfield I went through this tutorial: [_GeeksForGeeks_](https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/)
* Random number generator: [_Stackoverflow_](https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c)
* Console clearing: [_DelftStack_](https://www.delftstack.com/howto/cpp/how-to-clear-console-cpp/)
* Intended output delay on console: [_Stackoverflow_](https://stackoverflow.com/questions/27215705/how-to-delay-output-in-c)
