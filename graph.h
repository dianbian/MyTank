#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cubePoint.h"
using namespace std;

#define DOWN 0
#define LEFT 1
#define RIGHT 2

class Gbase{
protected:
    int x;
    int y;
    int a[3][3];
public:
    Gbase()
    {
        int i,j;
        x = 0;
        y = 0;
        for(j=0;j<3;j++)
            for(i=0;i<3;i++)
                a[i][j] = 0;
    }
    virtual ~Gbase(){}
    int move(int dir);//移动方块的位置
    //实现方块的旋转
    virtual void roll();//虚函数子类继承可覆盖，实现多态

    //画出方块的形状在子函数中实现
    virtual void draw(){}//虚函数

    void setLocate(int a,int b)
    {
        x = a;
        y = b;
    }
    void getLocate(int *a,int *b)
    {
        *a = x;
        *b = y;
    }
    void printG(int color);//打印方块的图标

    void *getArray()
    {
        return (void *)a;
    }
};

class Zgraph : public Gbase//Z字行
{
public:
    void draw()
    {
        a[0][0] = 1;
        a[0][1] = 1;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        a[1][2] = 1;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 0;
    }
};

class Ngraph : public Gbase//反Z字型
{
public:
    void draw()
    {
        a[0][0] = 0;
        a[0][1] = 1;
        a[0][2] = 1;
        a[1][0] = 1;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 0;
    }
};
class Tgraph : public Gbase//T字型
{
public:
    void draw()
    {
        a[0][0] = 1;
        a[0][1] = 1;
        a[0][2] = 1;
        a[1][0] = 0;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 0;
    }
};
class Ograph : public Gbase//田字型
{
public:
    void draw()
    {
        a[0][0] = 1;
        a[0][1] = 1;
        a[0][2] = 0;
        a[1][0] = 1;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 0;
    }
    virtual void roll(){}//只有这个类继承了翻转虚函数
};

class Igraph : public Gbase//竖字型
{
public:
    void draw()
    {
        a[0][0] = 0;
        a[0][1] = 1;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 1;
        a[2][2] = 0;
    }
};

class Lgraph : public Gbase//L字型
{
public:
    void draw()
    {
        a[0][0] = 0;
        a[0][1] = 1;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 1;
        a[2][2] = 1;
    }
};

class Jgraph : public Gbase//反L字型
{
public:
    void draw()
    {
        a[0][0] = 0;
        a[0][1] = 1;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 1;
        a[2][1] = 1;
        a[2][2] = 0;
    }
};
class Vgraph : public Gbase//一字型
{
public:
    void draw()
    {
        a[0][0] = 0;
        a[0][1] = 0;
        a[0][2] = 0;
        a[1][0] = 1;
        a[1][1] = 1;
        a[1][2] = 1;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 0;
    }
};
class Wgraph : public Gbase//反T字型
{
public:
    void draw()
    {
        a[0][0] = 0;
        a[0][1] = 0;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 1;
        a[2][1] = 1;
        a[2][2] = 1;
    }
};
class Context
{
private:
    Gbase *gbase;//把其他类的指针当作自己类的私有变量，这样就可以访问其他类的公有成员函数和变量
    color clr;

public:
    ~Context()
    {
        delete gbase;
    }
    Context(char cType)
    {
        switch(cType)
        {
        case 'Z':
            gbase = new Zgraph();clr = YELLOW;
            break;
        case 'N':
            gbase = new Ngraph();clr = WHITE;
            break;
        case 'T':
            gbase = new Tgraph();clr = GREEN;
            break;
        case 'O':
            gbase = new Ograph();clr = PURPLE;
            break;
        case 'I':
            gbase = new Igraph();clr = DEEP_GREEN;
            break;
        case 'L':
            gbase = new Lgraph();clr = BLUE;//暂时修改,修改不了？
            break;
        case 'J':
            gbase = new Jgraph();clr = PURPLE;
            break;
        case 'V':
            gbase = new Vgraph();clr = WHITE;
            break;
        case 'W':
            gbase = new Wgraph();clr = RED;
            break;
        default:
            printf("no %c type\n",cType);
            break;
        }
    }
    int  move(int dir)
    {
        return gbase->move(dir);
    }
    void roll()
    {
        return gbase->roll();
    }
    void draw()
    {
        gbase->draw();
    }
    void setLocate(int a,int b)
    {
        gbase->setLocate(a,b);
    }
    void getLocate(int *a,int *b)
    {
        gbase->getLocate(a,b);
    }
    void* getArray()
    {
        return gbase->getArray();
    }
    void printG(int color)
    {
        if(color == CLEAR)
            gbase->printG(CLEAR);
        else
            gbase->printG(clr);
    }
    void setColor(color clr)
    {
        this->clr = clr;
    }
    color getColor()
    {
        return clr;
    }
};
