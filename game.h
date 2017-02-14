#include "graph.h"
#include "rand.h"
#include "score.h"

enum MARK{
    GAME_STOP = - 1,
    GAME_PAUSE = 0,
    GAME_RUN = 1,
    GAME_QUIT = 2
};

class Game
{
private:
    int m_penal[24][31];//游戏面板
    color m_color[24][31];//颜色面板，根据(x,y)坐标的标志位显示颜色和空白
    Context *m_graph;
    Context *nextGraph;
    MARK mark;
    long int spd;
public:
    int x;
    int y;
private:
    Score s;
private:
    bool recoverPenal();
    bool isAttachBottom();
    bool isAttachLeft();
    bool isAttachRight();
    char getShape();
    bool setPenal();
    bool erasePenal();
public:
    Game();
    ~Game();
    void createCube();//随机创建方块的方法
    void move(int dir);//移动的方法,移动的过程中对m_penal的改变
    void roll();
    void stop();
    void erase();
    void down(int level);
    void printNextCube(Context *m_graph);
    void gameInit();
    MARK getMark();
    void setMark(MARK);
    void printHelep();
    char keyLoop();
    void speed();
    void setSpeed(long int sp)
    {
        spd = sp;
    }
    long int getSpeed()
    {
        return spd;
    }
};
