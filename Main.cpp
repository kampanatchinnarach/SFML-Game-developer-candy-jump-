#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<time.h>
#include<vector>
#include<String.h>
#include<windows.h>
#include<sstream>
#include<stdlib.h>
#include<conio.h>

using namespace sf;
using namespace std;

//jump
float jumpForce = 80;
float gravity = 9.8;
float mass = 50;
float dy = 0;

float deltatime;
float delaypress=0.f;

struct TopPlayer {
    Text title;
    Text nametitle;
    Text scoretitle;
    Text P1;
    Text score1;
    Text P2;
    Text score2;
    Text P3;
    Text score3;
    Text P4;
    Text score4;
    Text P5;
    Text score5;
    

}topfive;
struct Leader {
    string name;
    string strscore;
    int score;
   
};
Leader leader;
Leader read;

struct Hight
{
    string strscore;
    string name;
    int score;
  
}hight[5];
struct EnterName {
    bool state = false;
    string name;

}entername;
struct point
{
    int x, y;
};
struct candyPoint
{
    int x, y;
};
struct  ItemPointx2
{
    int x, y;
};
struct BadCandy {
    int x, y;
};

void recordscore();
void Readscore();
int main()
{
bool gamestart = false;
bool NightState = false;
bool jump = false;
bool itemstate = false;
bool gameover = false;
bool pimname = false;
bool uimenu = true;
bool topplayer = false;
int delay_move;
    srand(time(0));

    RenderWindow window(VideoMode(400, 533), "Doodle Game!");
    window.setFramerateLimit(60);
    Texture pimName;
    Texture backgrounds;
    Texture Night;
    Texture platform;
    Texture peaky;
    Texture Item;
    Texture candyP;
    Texture Badcandy;
    Texture Bgmenu;
    Texture GOver;
    Texture TopPlayer;

    GOver.loadFromFile("over.png");
    pimName.loadFromFile("enter.png");
    Night.loadFromFile("nightBg.png");
    backgrounds.loadFromFile("jumpingbg.png");
    platform.loadFromFile("ccandy.png");
    peaky.loadFromFile("PeakySP.png");
    Item.loadFromFile("item2.png");
    candyP.loadFromFile("candyE.png");
    Badcandy.loadFromFile("Bcandy2.png");
    Bgmenu.loadFromFile("ui.png");
    TopPlayer.loadFromFile("menu2.png");

    Sprite sMenu(Bgmenu);
    Sprite sTopplayer(TopPlayer);
    Sprite sNight(Night);
    Sprite sBackground(backgrounds);
    Sprite sPlat(platform);
    Sprite sPeaky(peaky);
    Sprite sItem(Item);
    Sprite sCandy(candyP);
    Sprite sBadcandy(Badcandy);
    Sprite sPimname(pimName);
    Sprite sGO(GOver);


    point plat[20];
    ItemPointx2 item[5];
    candyPoint candy[20];
    BadCandy Bcandy[20];

    
   
    //time
    int spriteSizeX = peaky.getSize().x / 6;
    int spriteSizeY = peaky.getSize().y;

    if (itemstate == true) {
        sPeaky.setTextureRect(sf::IntRect(spriteSizeX * 3, 0, spriteSizeX, spriteSizeY));
    }
    else
    {
        sPeaky.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
    }
    
    //menu button
    Font Ninja;
    Ninja.loadFromFile("JSNinjaAllcaps-Bold.otf");

    Text Tstart("START", Ninja, 40);
    Text Tleaderboard("LEADER BOARD", Ninja, 40);
    Text Texist("EXIST", Ninja, 40);
    Text Tback("Back", Ninja, 30);
    Text Name;

    topfive.nametitle.setFont(Ninja);
    topfive.P1.setFont(Ninja);
    topfive.P2.setFont(Ninja);
    topfive.P3.setFont(Ninja);
    topfive.P4.setFont(Ninja);
    topfive.P5.setFont(Ninja);
    topfive.score1.setFont(Ninja);
    topfive.score2.setFont(Ninja);
    topfive.score3.setFont(Ninja);
    topfive.score4.setFont(Ninja);
    topfive.score5.setFont(Ninja);
    topfive.scoretitle.setFont(Ninja);
    topfive.title.setFont(Ninja);


    topfive.title.setFillColor(sf::Color::Magenta);
    topfive.nametitle.setFillColor(sf::Color::Blue);
    topfive.scoretitle.setFillColor(sf::Color::Blue);
    topfive.P1.setFillColor(sf::Color::Blue);
    topfive.P2.setFillColor(sf::Color::Cyan);
    topfive.P3.setFillColor(sf::Color::Cyan);
    topfive.P4.setFillColor(sf::Color::Cyan);
    topfive.P5.setFillColor(sf::Color::Cyan);

    topfive.score1.setFillColor(sf::Color::Blue);
    topfive.score2.setFillColor(sf::Color::Cyan);
    topfive.score3.setFillColor(sf::Color::Cyan);
    topfive.score4.setFillColor(sf::Color::Cyan);
    topfive.score5.setFillColor(sf::Color::Cyan);

    topfive.P1.setOrigin(topfive.P1.getLocalBounds().width / 2, topfive.P1.getLocalBounds().height / 2);
    topfive.P2.setOrigin(topfive.P2.getLocalBounds().width / 2, topfive.P2.getLocalBounds().height / 2);
    topfive.P3.setOrigin(topfive.P3.getLocalBounds().width / 2, topfive.P3.getLocalBounds().height / 2);
    topfive.P4.setOrigin(topfive.P4.getLocalBounds().width / 2, topfive.P4.getLocalBounds().height / 2);
    topfive.P5.setOrigin(topfive.P5.getLocalBounds().width / 2, topfive.P5.getLocalBounds().height / 2);

    topfive.score1.setOrigin(topfive.P1.getLocalBounds().width / 2, topfive.score1.getLocalBounds().height / 2);
    topfive.score2.setOrigin(topfive.P2.getLocalBounds().width / 2, topfive.score2.getLocalBounds().height / 2);
    topfive.score3.setOrigin(topfive.P3.getLocalBounds().width / 2, topfive.score3.getLocalBounds().height / 2);
    topfive.score4.setOrigin(topfive.P4.getLocalBounds().width / 2, topfive.score4.getLocalBounds().height / 2);
    topfive.score5.setOrigin(topfive.P5.getLocalBounds().width / 2, topfive.score5.getLocalBounds().height / 2);

    topfive.score1.setPosition(300, 120);
    topfive.score2.setPosition(300, 150);
    topfive.score3.setPosition(300, 180);
    topfive.score4.setPosition(300, 210);
    topfive.score5.setPosition(300, 240);

    topfive.P1.setPosition(100, 120);
    topfive.P2.setPosition(100, 150);
    topfive.P3.setPosition(100, 180);
    topfive.P4.setPosition(100, 210);
    topfive.P5.setPosition(100, 240);



    topfive.title.setString("Leader board");
    topfive.scoretitle.setString("Score");
    topfive.nametitle.setString("Name");
    topfive.title.setPosition(200, 50);
    topfive.scoretitle.setPosition(300, 80);
    topfive.nametitle.setPosition(100, 80);
    topfive.title.setOrigin(topfive.title.getLocalBounds().width / 2, topfive.title.getLocalBounds().height / 2);
    topfive.nametitle.setOrigin(topfive.nametitle.getLocalBounds().width / 2, topfive.nametitle.getLocalBounds().height / 2);
    topfive.scoretitle.setOrigin(topfive.scoretitle.getLocalBounds().width / 2, topfive.scoretitle.getLocalBounds().height / 2);


    Tback.setOrigin(Tback.getLocalBounds().width / 2, Tback.getLocalBounds().height / 2);
    Tback.setPosition(50, 10);
    Tstart.setOrigin(Tstart.getLocalBounds().width / 2, Tstart.getLocalBounds().height / 2);
    Tstart.setPosition(200, 100);
    
    Tleaderboard.setOrigin(Tstart.getLocalBounds().width / 2, Tstart.getLocalBounds().height / 2);
    Tleaderboard.setPosition(150, 200);
   
    Texist.setOrigin(Tstart.getLocalBounds().width / 2, Tstart.getLocalBounds().height / 2);
    Texist.setPosition(200, 300);
    
    //Score Objects:

    int score = 0;

    Font arial;
    arial.loadFromFile("FC Subject.otf");

    std::ostringstream ssScore;

    ssScore << "Score: " << score;

    Text lblScore;
    lblScore.setCharacterSize(15);
    lblScore.setPosition({ 10, 10 });
    lblScore.setFillColor(sf::Color::Black);
    lblScore.setFont(arial);
    lblScore.setString(ssScore.str());




    Time dt;
    Time dn;
    Time Delay;
    Clock C;
    Clock clock2;
    Clock clock;
    int t1 = 0;
    int t2=0;
    clock2.restart();
    clock.restart();
    
    //set x y 
    for (int i = 0; i < 8; i++) // plat
    {
        plat[i].x = rand() % 400;
        plat[i].y = rand() % 533;
    }
    for (int i = 0; i < 1; i++) //item
    {
        item[i].x = rand() % 400;
        item[i].y = rand() % 533;
    }
    for (int i = 0; i < 7; i++)//candy
    {
        candy[i].x = rand() % 400;
        candy[i].y = rand() % 533;
    }
    for (int i = 0; i < 3; i++) //Bad candy
    {
        Bcandy[i].x = rand() % 400;
        Bcandy[i].y = rand() % 533;
    }

    int x = 100, y = 100, y2 = 100, h = 200;
    float dx = 0, dy = 0, dy2=0;

        
    while (window.isOpen())
    {
       
        deltatime = C.restart().asSeconds();
       
        delaypress += deltatime;
       
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

        }
        ///////////////////////Menu
            
        if (uimenu) {
            
            if (Tstart.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                Tstart.setFillColor(sf::Color::Blue);
                Tstart.setStyle(sf::Text::Underlined);

            }
            else if (Tleaderboard.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                Tleaderboard.setFillColor(sf::Color::Blue);
                Tleaderboard.setStyle(sf::Text::Underlined);
                
              
            }
            else if (Texist.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                Texist.setFillColor(sf::Color::Blue);
                Texist.setStyle(4);
            }
            else
            {
                Tstart.setFillColor(sf::Color::Cyan);
                Texist.setStyle(0);
                Tleaderboard.setFillColor(sf::Color::Cyan);
                Tleaderboard.setStyle(0);
                Texist.setFillColor(sf::Color::Cyan);
                Tstart.setStyle(0);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (Tstart.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    pimname = true;
                    uimenu = false;

                }
                else if (Tleaderboard.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    Tleaderboard.setFillColor(sf::Color::Green);
                    topplayer = true;
                    uimenu = false;

                }
                else if (Texist.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    window.close();
                }

            }
        }
        ////ถ้าพิมชื่อ
        if (pimname == true) {
           
            Name.setString(entername.name);
            Name.setFont(arial);
            Name.setOrigin(Vector2f(Name.getGlobalBounds().width / 2, Name.getGlobalBounds().height / 2));
            Name.setPosition(200, 175);
            Name.setFillColor(sf::Color::Black);  
            if (e.type == sf::Event::TextEntered&&delaypress>=0.2f) {  


                if (e.text.unicode == '\b'&&entername.name.size()>0) {
                    entername.name.erase(entername.name.size() - 1, 1); 

                }
                else if (e.text.unicode < 128 && e.text.unicode != 27 && e.text.unicode != '\b' && entername.name.size() < 15) {
                    entername.name += e.text.unicode;  

                }
                delaypress = 0.f;
            }
            if (Keyboard::isKeyPressed(Keyboard::Enter) && entername.name.size() > 0) { 
                leader.name = entername.name;
                cout << entername.name;
                pimname = false;
                gamestart = true;
  

            }

        }
        
        ////Leader board
        if (topplayer) {
            printf("top");
            Readscore();
            topfive.P1.setString(hight[0].name);
            topfive.P2.setString(hight[1].name);
            topfive.P3.setString(hight[2].name);
            topfive.P4.setString(hight[3].name);
            topfive.P5.setString(hight[4].name);
            hight[0].strscore = to_string(hight[0].score);
            hight[1].strscore = to_string(hight[1].score);
            hight[2].strscore = to_string(hight[2].score);
            hight[3].strscore = to_string(hight[3].score);
            hight[4].strscore = to_string(hight[4].score);
            topfive.score1.setString(hight[0].strscore);
            topfive.score2.setString(hight[1].strscore);
            topfive.score3.setString(hight[2].strscore);
            topfive.score4.setString(hight[3].strscore);
            topfive.score5.setString(hight[4].strscore);

             if (Tback.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
             {
            Tback.setFillColor(sf::Color::Blue);
            Tback.setStyle(4);
            
           
             }
             else
             {
                 Tback.setFillColor(sf::Color::Green);
                 Tback.setStyle(0);
             }
             if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                 if (Tback.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                     topplayer = false;
                     uimenu = true;

                 }

             }
             


        }
            //////////////////////Gameplay
        if (gamestart == true) {
           
           // gameover = false;
            dt = clock.getElapsedTime();
            t1 = (int)dt.asSeconds();
            dn = clock2.getElapsedTime();
            t2 = (int)dn.asSeconds();

            if (t2 / 120 == 1) {
                NightState = !NightState;
                clock2.restart();
            }


            //move peaky
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                if (sPeaky.getPosition().x < 320)
                    x += 3;
                if (itemstate == true) {
                    sPeaky.setTextureRect(sf::IntRect(spriteSizeX * 5, 0, spriteSizeX, spriteSizeY));
                }
                else
                {
                    sPeaky.setTextureRect(sf::IntRect(spriteSizeX * 2, 0, spriteSizeX, spriteSizeY));
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                if (sPeaky.getPosition().x > 0)
                    x -= 3;
                if (itemstate == true) {
                    sPeaky.setTextureRect(sf::IntRect(spriteSizeX * 4, 0, spriteSizeX, spriteSizeY));
                }
                else
                {
                    sPeaky.setTextureRect(sf::IntRect(spriteSizeX * 1, 0, spriteSizeX, spriteSizeY));
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::W) && !jump)
            {
                jump = true;
                if (jump)
                {
                    dy = -11;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                gamestart = false;
                uimenu = true;
            }

            //jump
            dy += 0.2;
            dy2 += 0.2;
            y += dy;
            y2 += dy;

            //check gameOver
            if (y2 > 500) { 
                
                gameover = true;
                dy = 0;
                y2 = dy;
                
            }

            //plat move
            if (y2 < h) {
                for (int i = 0; i < 8; i++)
                {
                    y2 = h;
                    plat[i].y = plat[i].y - dy; //move
                    if (plat[i].y > 533) //spawn new
                    {
                        plat[i].y = 0;
                        plat[i].x = rand() % 400;
                    }
                }
                //move item
                for (int i = 0; i < 1; i++)
                {
                    y2 = h;
                    item[i].y = item[i].y - dy; //move
                    if (item[i].y > 533) //spawn new
                    {
                        item[i].y = 0;
                        item[i].x = rand() % 400;

                    }
                }
                //move candy
                for (int i = 0; i < 7; i++)
                {
                    y2 = h;
                    candy[i].y = candy[i].y - dy; //move
                    if (candy[i].y > 533) //spawn new
                    {
                        candy[i].y = 0;
                        candy[i].x = rand() % 400;
                    }
                }
                for (int i = 0; i < 3; i++) {
                    Bcandy[i].y = Bcandy[i].y - dy;

                    if (Bcandy[i].y > 533) //spawn new
                    {
                        Bcandy[i].y = 0;
                        Bcandy[i].x = rand() % 400;
                    }
                }
            }
            //check collison plat
            for (int i = 0; i < 8; i++)
            {
                if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) && (y2 + 70 > plat[i].y) && (y2 + 70 < plat[i].y + 14) && (dy > 0))
                {
                    dy = -2;
                    if (itemstate == true) {
                        sPeaky.setTextureRect(sf::IntRect(spriteSizeX * 3, 0, spriteSizeX, spriteSizeY));
                    }
                    else
                    {
                        sPeaky.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
                    }
                    jump = false;
                }
            }
            sPeaky.setPosition(x, y2);
            //check collison item
            for (int i = 0; i < 1; i++) {
                if ((x + 80 > item[i].x) && (x + 20 < item[i].x + 68) && (y2 + 80 > item[i].y) && (y2  < item[i].y + 30) && (dy > 0) || (x + 80 > item[i].x) && (x  < item[i].x + 68) && (y2 > item[i].y) && (y2 < item[i].y + 30)) {
                    //printf("I");
                    item[i].y = 0;
                    item[i].x = rand() % 400;
                    itemstate = true;
                    clock.restart();
                }

            }
            //กำหนดระยะเวลาของไอเทม
            if (itemstate == true) {
                if (t1 >= 5) {
                    itemstate = false;

                }
            }
            //check colison candy
            for (int i = 0; i < 7; i++) {
                if ((x + 80 > candy[i].x) && (x + 20 < candy[i].x + 68) && (y2 + 80 > candy[i].y) && (y2  < candy[i].y +30) && (dy > 0) || (x + 80 > candy[i].x) && (x  < candy[i].x + 68) && (y2 > candy[i].y) && (y2 < candy[i].y +30)) {
                    //printf("C");
                    candy[i].y = 0;
                    candy[i].x = rand() % 400;
                    if (itemstate == true) {
                        score += 5;

                    }
                    else
                    {

                        score++;
                    }
                    ssScore.str("");
                    ssScore << "Score " << score;
                    lblScore.setString(ssScore.str());
                }

            }
            //check colison Badcandy
            for (int i = 0; i < 7; i++) {
                if ((x + 50 > Bcandy[i].x) && (x + 20 < Bcandy[i].x + 68) && (y2 + 70 > Bcandy[i].y) && (y2 + 70 < Bcandy[i].y + 14) && (dy > 0) || (x + 50 > Bcandy[i].x) && (x + 20 < Bcandy[i].x + 68) && (y2 > Bcandy[i].y) && (y2 < Bcandy[i].y + 14)) {
                   // printf("B");
                    Bcandy[i].y = 0;
                    Bcandy[i].x = rand() % 400;
                    if (score < 5) {
                        score = 0;
                    }
                    else
                    {
                        score -= 5;
                    }  

                    ssScore.str("");
                    ssScore << "Score " << score;
                    lblScore.setString(ssScore.str());
                }

            }

            
        }
        ///gameOver
        if (gameover == true) {
            
                gamestart = false;
                leader.score = score;
                recordscore();
                entername.name.clear();
                leader.strscore = to_string(score);
                score = 0;
               // cout << leader.strscore;
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                gameover = false;
                uimenu = true;
            }
        }
        
            window.clear();
            if (uimenu==true) {
                window.draw(sMenu);
                window.draw(Tstart);
                window.draw(Tleaderboard);
                window.draw(Texist);
               // window.draw(Name);
            }
            if (pimname==true) {
                window.draw(sPimname);
                window.draw(Name);
            }
           
            if (topplayer==true)
            {   
                window.draw(sTopplayer);
                window.draw(Tback);
                window.draw(topfive.title);
                window.draw(topfive.nametitle);
                window.draw(topfive.scoretitle);
                window.draw(topfive.P1);
                window.draw(topfive.P2);
                window.draw(topfive.P3);
                window.draw(topfive.P4);
                window.draw(topfive.P5);
                window.draw(topfive.score1);
                window.draw(topfive.score2);
                window.draw(topfive.score3);
                window.draw(topfive.score4);
                window.draw(topfive.score5);

            }
        ///////////////DrawGameplay
            if (gamestart == true) {

                if (NightState == false) {
                    window.draw(sBackground);
                }
                else if (NightState == true)
                {
                    window.draw(sNight);
                }
                window.draw(sPeaky);
                for (int i = 0; i < 8; i++)//draw plat
                {
                    sPlat.setPosition(plat[i].x, plat[i].y);
                    window.draw(sPlat);
                }
                for (int i = 0; i < 3; i++)//draw plat
                {
                    sBadcandy.setPosition(Bcandy[i].x, Bcandy[i].y);
                    window.draw(sBadcandy);
                }
                for (int i = 0; i < 1; i++)//draw badcandy
                {
                    sItem.setPosition(item[i].x, item[i].y);
                    window.draw(sItem);
                }

                for (int i = 0; i < 7; i++)//draw candy
                {
                    sCandy.setPosition(candy[i].x, candy[i].y);
                    window.draw(sCandy);
                }
                window.draw(lblScore);
            }
            if (gameover == true) {
                window.draw(sGO);
            }
            window.display();
        
    }

    return 0;
}

void recordscore() {
    FILE* towrite;
    towrite = fopen("leader.txt", "a");
    if (towrite == NULL) {
        printf("error to write");
        exit(1);
    }
    fwrite(&leader, sizeof(struct Leader), 1, towrite);
    fclose(towrite);
}
void Readscore() {
    FILE* toread;
    toread = fopen("leader.txt", "r");
    if (toread == NULL) {
        printf("error to read");
        exit(1);
    }
 
   while (fread(&read, sizeof(struct Leader), 1, toread)) {
        if (hight[0].score < read.score) {
            hight[0].score = read.score;
            hight[0].name = read.name;
            hight[0].strscore = read.strscore;

        }
        if (hight[1].score < read.score && read.score <= hight[0].score && read.name != hight[0].name) {
            hight[1].score = read.score;
            hight[1].name = read.name;
            hight[1].strscore = read.strscore;
        }
        if (hight[2].score < read.score && read.score <= hight[1].score  && read.name != hight[0].name && read.name != hight[1].name) {
            hight[2].score = read.score;
            hight[2].name = read.name;
            hight[2].strscore = read.strscore;
        }
        if (hight[3].score < read.score && read.score <= hight[2].score && read.name != hight[0].name && read.name != hight[1].name && read.name != hight[2].name) {
            hight[3].score = read.score;
            hight[3].name = read.name;
            hight[3].strscore = read.strscore;
        }
        if (hight[4].score < read.score && read.score <= hight[3].score && read.name != hight[0].name && read.name != hight[1].name && read.name != hight[2].name && read.name != hight[3].name) {
            hight[4].score = read.score;
            hight[4].name = read.name;
            hight[4].strscore = read.strscore;
        }
       
        
        
    }
    fclose(toread);
}