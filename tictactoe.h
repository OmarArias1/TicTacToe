#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
  public: 

  struct Player {
      char letterplaying[2];
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

    bool _isgamewon;
    std::string _map;
    Player _player_one;
    Player _player_two;

};

//what happens when you play tictactoe:
// take turns
//map is updated everyturn and we check for a wi
//two players, x and o


#endif 