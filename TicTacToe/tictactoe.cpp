#include <iostream>
#include <string>
#include <limits>

#include "tictactoe.h"

TicTacToe::TicTacToe() : _isgamewon{false}, 
_map
{
"   |  |  \n"
" --------\n"
"   |  |  \n"
" --------\n"
"   |  |  \n"
}
{}

void TicTacToe::GameRun()
{
  PrintGameStartMessage();
  PrintMap();
  ChoosePlayers();
  PlayTurn();

}

void TicTacToe::PrintGameStartMessage() const 
{
  std::cout << "Welcome to tic tao toe, I don't feel like explaing any rules\n"
            << "so search them up if you don't know how to play\n";
}

void TicTacToe::PrintMap() const
{
  std::cout << _map;
}

void TicTacToe::ChoosePlayers() 
{
  char buffer[2];

  //Plyaer 1 
  std::cout << "PlayerOne, Choose the letter you'll be playing: ";
  std::cin.get(_playerone.letterplaying, 2);
  std::cout << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  //Player 2
  std::cout << "PlyareTwo, Choose the letter you'll be playing: ";
  std::cin.get(_playertwo.letterplaying, 2);
  std::cout << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (_playerone.letterplaying[0] == _playertwo.letterplaying[0]) std::cout << "cannot be playing as same letter\n", ChoosePlayers();

  std::cout << "playerone: " << _playerone.letterplaying << '\n' << "playertwo: " << _playertwo.letterplaying << '\n'
            << "Are these Selections correct?: " << '\n' << "[yes]\n[no]\n\n>";

  std::cin.get(buffer, 2);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (buffer[0])
  {
    case 'n':
      ChoosePlayers();
      break;
    case 'y':
      std::cout << "SELECTIONS LOCKED IN\n";
      break;
    default:
      std::cout << "Imma just assume thats's a yes\n";
  }

}
 


