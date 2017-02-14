#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
using namespace std;

class Score
{
    string player;
    int score;
    int choose;

public:
    Score()
    {
        player = "bianbian";
        score = 0;
    }
    void setName(string name)
    {
        player = name;
    }
    void setScore(int s)
    {
        score = s;
    }
    void setChoose(int n)
    {
        choose = n;
    }
    int getChoose()
    {
        return choose;
    }
    void printMessage();
    void printQuit();
};

#endif
