#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

class TicTacToe {
  public: 

  struct Player {
      char letterplaying;
      bool gamewon{};
      bool isturn = false;
    
      friend std::ostream& operator<<(std::ostream& os, const Player& plr);
      void Flip();
  };

    //default constructor
    TicTacToe();
    ~TicTacToe();

    //Game Handler
    void GameRun(); 

  private:

    //Helper Member functions
    void PrintGameStartMessage() const;
    bool CheckForWin(const std::size_t & pick, const Player & plr);
    void PlayTurn(const Player& plr);
    Player& whoseTurn();
    void PrintMap() const;
    void InitPlayers();
    void UpdateMap(const std::size_t & pick);

    const std::size_t _ROWS;
    const std::size_t _COLUMNS;
    bool _isgamewon;
    char _map[3][3] = {};
    Player _player_one;
    Player _player_two;

};

#endif 