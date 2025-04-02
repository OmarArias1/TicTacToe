#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "tictactoe.h"

TicTacToe::TicTacToe() : 
_isgamewon{false},
_ROWS{3},
_COLUMNS{3}
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
  std::cout << "\n\n";

  std::cout << " " << _map[0][0] << " | " << _map[0][1] << " | " << _map[0][2] << '\n';
  std::cout << "-----------\n";
  std::cout << " " << _map[1][0] << " | " << _map[1][1] << " | " << _map[1][2] << '\n';
  std::cout << "-----------\n";
  std::cout << " " << _map[2][0] << " | " << _map[2][1] << " | " << _map[2][2] << '\n';
  }


void TicTacToe::InitPlayers() 
{
  char buffer[2];

  //Plyaer 1 
  std::cout << "PlayerOne, Choose the letter you'll be playing (only the first character is choosen): ";
  std::cin >> _player_one.letterplaying;
  std::cout << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  //Player 2
  std::cout << "PlyareTwo, Choose the letter you'll be playing: ";
  std::cin >> _player_two.letterplaying;
  std::cout << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (_player_one.letterplaying == _player_two.letterplaying) std::cout << "cannot be playing as same letter\n", InitPlayers();

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

  std::cout << "who wants to go first? enter [1] or [2]" << "\n\n" << '>';
  std::cin.get(buffer, 2);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), std::cout << std::endl;

  // Picking player that gets first move

  if (buffer[0] == '1')  
  {
    std::cout << "Player one is going first";
    _player_one.isturn = true;
  }
  else if (buffer[0] == '2') 
  {
    std::cout << "Player two will be going first";
    _player_two.isturn = true;
  }
  else
  {
    std::cout << "Random player will be chooses to go first";
    std::size_t randnum = rand() % 2 + 1;

    if (randnum == 1) std::cout << "Player one will be going first", _player_one.isturn = true;
    else std::cout << "PLayer two will be going first\n", _player_two.isturn = true;
  }

  std::cout << "\n\n\n";

  // Calling turn for player choosen
  PlayTurn(whoseTurn());
}


void TicTacToe::PlayTurn(const Player& plr) {
  //getting pick & validating input
  std::size_t pick{};
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
  PrintMap();

  if (iswon) std::cout << "Player " << plr << " has one the game!" << std::endl;
  else PlayTurn(whoseTurn());
}


TicTacToe::Player& TicTacToe::whoseTurn() 
{
  if (_player_one.isturn) 
  {
    _player_one.isturn = false;
    _player_two.isturn = true;
    return _player_one;

  }
  else 
  {
    _player_two.isturn = false;
    _player_one.isturn = true;
    return _player_two;
  }
}


bool TicTacToe::CheckForWin(const std::size_t & pick, const Player & plr)
{ 
  const int row = (pick -1) / _COLUMNS;
  const int col = (pick -1) % _COLUMNS;

  _map[row][col] = plr.letterplaying;

  //check rows
  if ( _map[0][0] == plr.letterplaying && _map[0][1] == plr.letterplaying && _map[0][2] == plr.letterplaying )
  {
    return true;
  }
  if ( _map[1][0] == plr.letterplaying && _map[1][1] == plr.letterplaying && _map[1][2] == plr.letterplaying )
  {
    return true;
  }
  if ( _map[2][0] == plr.letterplaying && _map[2][1] == plr.letterplaying && _map[2][2] == plr.letterplaying )
  {
    return true;
  }

  //check columns
  if ( _map[0][0] == plr.letterplaying && _map[1][0] == plr.letterplaying && _map[2][0] == plr.letterplaying )
  {
    return true;
  }
  if ( _map[0][1] == plr.letterplaying && _map[1][1] == plr.letterplaying && _map[2][1] == plr.letterplaying )
  {
    return true;
  }
  if ( _map[0][2] == plr.letterplaying && _map[1][2] == plr.letterplaying && _map[2][2] == plr.letterplaying )
  {
    return true;
  }

  //check diagonals 
  if ( _map[0][0] == plr.letterplaying && _map[1][1] == plr.letterplaying && _map[2][2] == plr.letterplaying )
  {
    return true;
  }
  if ( _map[0][2] == plr.letterplaying && _map[1][1] == plr.letterplaying && _map[2][0] == plr.letterplaying )
  {
    return true;
  }

  return false;
}


std::ostream& operator<<(std::ostream& os, const TicTacToe::Player& plr)
{
  std::cout << plr.letterplaying;
  return os;
}

