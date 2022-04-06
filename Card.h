#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <string.h>
#include <windows.h>
#include <algorithm>
#include <fstream>

using namespace std;

class Card{
private:
    map<string,int> suit;
    map<int,string> ConvertNum;
    string num[14]={"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    vector< pair<int,int> > player[4],index,Fold[4],CanPlay[4];//︹ 计
    int screen[3][4],FoldTotal[4],End=0;
public:
    Card();
    void Spade(string a,int n);
    void Heart(string a,int n);
    void Diamond(string a,int n);
    void Club(string a,int n);
    void Firstplay();
    bool run();//祘Α
    bool decide(int a);//耞琌礟
    bool Save(pair<int,int> deck);//礟
    bool FoldCard(pair<int,int> deck);//籠礟
    void SetColor(int = 7);
    void Print();
    void PrintHuman();
    void Count();//计程逞礟翴计
    void read();//盢file柑狥﹁弄秈祘Α
    bool Endfun();
};

#endif // CARD_H_INCLUDED
