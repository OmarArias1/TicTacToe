#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
  public: 

  struct Player {
      char letterplaying[2];
      bool gamewon{};
      bool isturn{};
      
      public: 
        friend std::ostream& operator<<(std::ostream& os, const Player& plr);
  };

    //default constructor
    TicTacToe();
    ~TicTacToe();

    //Game Handler
    void GameRun(); 

  private:

    //Helper Member functions
    void PrintGameStartMessage() const;
    bool CheckForWin();
    void PlayTurn(const Player& plr);
    void PrintMap() const;
    void InitPlayers();

    bool _isgamewon;
    std::string _map;
    char _map_array[5][5];
    Player _playerone;
    Player _playertwo;

};

//what happens when you play tictactoe:
// take turns
//map is updated everyturn and we check for a wi
//two players, x and o


#endif TICTACTOE_H