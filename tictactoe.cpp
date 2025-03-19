#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "tictactoe.h"

TicTacToe::TicTacToe() : _isgamewon{false}, 
_map(3, std::vector<char>(3, ' '))
{}


TicTacToe::~TicTacToe(){}


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
  std::cin.get(_player_one.letterplaying, 2);
  std::cout << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  //Player 2
  std::cout << "PlyareTwo, Choose the letter you'll be playing: ";
  std::cin.get(_player_two.letterplaying, 2);
  std::cout << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (_player_one.letterplaying[0] == _player_two.letterplaying[0]) std::cout << "cannot be playing as same letter\n", InitPlayers();

  //Locking in selections

  std::cout << "playerone: " << _player_one.letterplaying << '\n' << "playertwo: " << _player_two.letterplaying << '\n'
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
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), std::cout << std::endl;

  // Picking player that gets first move

  if (buffer[0] == '1')  
  {
    std::cout << "Player one is going first\n";
    _player_one.isturn = true;
  }
  else if (buffer[0] == '2') 
  {
    std::cout << "Player two will be going first\n";
    _player_two.isturn = true;
  }
  else
  {
    std::cout << "Random player will be chooses to go first\n";
    std::size_t randnum = rand() % 2 + 1;

    if (randnum == 1) std::cout << "Player one will be going first\n", _player_one.isturn = true;
    else std::cout << "PLayer two will be going first\n", _player_two.isturn = true;
  }

  // Calling turn for player choosen
  PlayTurn(whoseTurn());
}


void TicTacToe::PlayTurn(const Player& plr) {
  //getting pick & validating input
  std::size_t pick{};

  PrintMap();
  std::cout << "Player's " << plr << " turn" << '\n';

  std::cout << "Pick where you will be playing (1-9): ";
  std::cin >> pick;

  while ( !(pick <= 9 && pick >= 1) ) 
  {
    std::cout << "You have to pick within the vallid range: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> pick;
  }

  //positive message
  std::cout << "good choice! " << std::endl;

  //game loop
  bool iswon = CheckForWin(pick, plr);

  if (iswon) std::cout << "Player " << plr << " has one the game!" << std::endl;
  else PlayTurn(whoseTurn());
}


TicTacToe::Player& TicTacToe::whoseTurn() 
{
  if (_player_one.isturn) 
  {
    _player_one.isturn = !_player_one.isturn;
    return _player_one;

  }
  _player_two.isturn = !_player_two.isturn;
  return _player_two;
}


bool TicTacToe::CheckForWin(const std::size_t & pick, const Player & plr)
{

  for (int i = 0; i < pick; ++i)
  {
    _map[i] = plr.letterplaying[0];
  }
  switch (pick) 
  {
    case 1:

    case 2:

    case 3:

    case 4:

    case 5: 

    case 6:

    case 7:

    case 8:

    case 9:
  }
}


std::ostream& operator<<(std::ostream& os, const TicTacToe::Player& plr)
{
  std::cout << plr.letterplaying;
  return os;
}

