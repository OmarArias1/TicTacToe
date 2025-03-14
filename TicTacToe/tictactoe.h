class TicTacToe {
  struct Player {
    char letterplaying[2];
    bool gamewon{};
    bool isturn{};
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
    void InitPlayers();

    bool _isgamewon;
    std::string _map;
    Player _playerone;
    Player _playertwo;

};

//what happens when you play tictactoe:
// take turns
//map is updated everyturn and we check for a wi
//two players, x and o


