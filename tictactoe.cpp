#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

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

TicTacToe::~TicTacToe()
{

}

void TicTacToe::GameRun()
{
  //Seed RNG
  srand(time(0));

  PrintGameStartMessage();
  PrintMap();
  InitPlayers();
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

void TicTacToe::InitPlayers() 
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

  if (_playerone.letterplaying[0] == _playertwo.letterplaying[0]) std::cout << "cannot be playing as same letter\n", InitPlayers();

  //Locking in selections

  std::cout << "playerone: " << _playerone.letterplaying << '\n' << "playertwo: " << _playertwo.letterplaying << '\n'
            << "Are these Selections correct?: " << "[yes][no]\n\n>";

  std::cin.get(buffer, 2);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  switch (buffer[0])
  {
    case 'n':
      InitPlayers();
      break;
    case 'y':
      std::cout << "SELECTIONS LOCKED IN\n";
      break;
    default:
      std::cout << "Imma just assume thats's a yes\n";
  }

  // Choosing who goes first 

  std::cout << "who wants to go first? enter [1] or [2]" << '\n';
  std::cin.get(buffer, 2);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // Picking player that gets first move

  if (buffer[0] == '1')  
  {
    std::cout << "Player one is going first\n";
    _playerone.isturn = true;
  }
  else if (buffer[0] == '2') 
  {
    std::cout << "Player two will be going first\n";
    _playertwo.isturn = true;
  }
  else
  {
    std::cout << "Random player will be chooses to go first\n";
    std::size_t randnum = rand() % 2 + 1;

    if (randnum == 1) std::cout << "Player one will be going first\n", _playerone.isturn = true;
    else std::cout << "PLayer two will be going first\n", _playertwo.isturn = true;
  }

  // Calling turn for player choosen
  if (_playerone.isturn) PlayTurn(_playerone);
  PlayTurn(_playertwo);
}

void TicTacToe::PlayTurn(const Player& plr) {
  PrintMap();
  std::cout << "Player " << plr << "turn";
}
 

std::ostream& operator<<(std::ostream& os, const TicTacToe::Player& plr)
{
  std::cout << plr.letterplaying;
  return os;
}

