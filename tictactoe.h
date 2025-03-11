class TicTacToe {
  struct Player {
    char letterplaying[2];
  };

  public:

    //default constructor
    TicTacToe();

    //Game Handler
    void GameRun(); 

  private:

    //Helper Member functions
    void PrintGameStartMessage() const;
    bool CheckForWin();
    void PlayTurn();
    void PrintMap() const;
    void ChoosePlayers();

    bool _isgamewon;
    std::string _map;
    Player _playerone;
    Player _playertwo;

};

//what happens when you play tictactoe:
// take turns
//map is updated everyturn and we check for a win
//two players, x and o


