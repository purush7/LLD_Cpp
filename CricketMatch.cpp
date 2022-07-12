//author: purush7
//question: https://leetcode.com/discuss/interview-question/990227/udaan-assignment-cricket-match-dashboard




#include <bits/stdc++.h>

using namespace std;

class Player {
  string name;
  int score;
  int ballsFaced;
  int fours;
  int sixes;
  int status;//0 -> not played, 1 -> curr, 2->wicket

  public:
    Player(string name){
      this->name = name;
      this->score = 0;
      this->ballsFaced = 0;
      this->fours = 0;
      this->sixes = 0;
      this->status = 0;
    }

    void addScore(int n){
      this->score += n;
      if(n==4){
        this->fours++;
      }else if(n==6){
        this->sixes++;
      } 
    }

    void addBallFaced(){
      this->ballsFaced++;
    }

    string getName(){
      return this->name;
    }
    
    int getScore(){
       return this->score;
    }

    int getFours(){
      return this->fours;
    }

    int getSixes(){
      return this->sixes;
    }

    int getStatus(){
      return this->status;
    }

}

class Over{
  int overNo;
  vector<string> scores;
  int extras;
  int totalScore;

  public:

  void setScores(vector<string> scores){
   this->scores = scores;
   int sz = scores.size();
   for(int i=0;i<sz;i++){
      if(scores[i]=="Wd" || scores[i]=="Nb"){
        extras++;
        continue;
      }
      if(scores[i]=="W") continue;
      this->totalScore += stoi(scores[i]);
   }
   this->totalScore += this->extras;
  }

  vector<string> getScores(){
    return this->scores;
  }

  int getExtrasGiven(){
    return this->extras;
  }
}

class Team {
  string teamName;
  vector<string>players;
  int score;
  int wickets;
  string result;
  int index;

  public:
    Team(string name, vector<string> players){
      this->teamName = name;
      this->players = players;
      this->wickets = 0;
      this->score = 0;
      this->index=0;
    }

    void addScore(int n){
      this->score += n;
    }

    string nextPlayer(){
      if(this->index>=this->players.size()){
        return "";
      }
      string player = this->players[this->index];
      this->wickets++;
      this->index++;
    }

    int totalScore(){
      return this->score;
    }

    int totalWickets(){
      return this->wickets;
    }

}


