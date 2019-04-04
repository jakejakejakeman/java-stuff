#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <array>
#include <fstream>
#include <map>
#include "Object.h"
using namespace std;
using std::map;
int flagcount;
int counter;
bool lose;
vector <Object> tiles;
vector <int> mines;
vector <Object> bombs;
vector <int> non;
vector <int> flags;
map <int, Object> back;
map <int, Object> flaggies;
Object mine("images/mine.png");
Object tile("images/tile_hidden.png");
Object one("images/number_1.png");
Object two("images/number_2.png");
Object three("images/number_3.png");
Object four("images/number_4.png");
Object five("images/number_5.png");
Object six("images/number_6.png");
Object seven("images/number_7.png");
Object eight("images/number_8.png");
Object none("images/tile_revealed.png");
Object flag("images/flag.png");
Object good("images/face_happy.png");
Object bad("images/face_lose.png");
Object t1("images/test_1.png");
Object t2("images/test_2.png");
Object t3("images/Test_3.png");
Object debug("images/debug.png");
Object best("images/face_win.png");
int Square(int x, int y)
{
    return ((x/32+1)+(y/32)*25);
}
void Click(int choice)
{
    bool decision=false;
    for (int i=0; i<non.size(); i++)
        if (choice==non[i])
            decision = true;
    int counts=0;
    if ((decision==false)&&(choice<401)) {
        non.push_back(choice);
        for (int i = 0; i < mines.size(); i++) {
            if ((choice - 25 == mines[i])&&(choice>25))
                counts++;
            if ((choice + 25 == mines[i])&&(choice<376))
                counts++;
            if ((choice - 1 == mines[i])&&(choice%25!=1))
                counts++;
            if ((choice + 1 == mines[i])&&(choice%25!=0))
                counts++;
            if ((choice - 24 == mines[i])&&(choice%25!=0))
                counts++;
            if ((choice + 24 == mines[i])&&(choice%25!=1))
                counts++;
            if ((choice - 26 == mines[i])&&(choice%25!=1))
                counts++;
            if ((choice + 26 == mines[i])&&(choice%25!=0))
                counts++;
        }
        sf::Vector2f pos = tiles[choice - 1].GetSprite().getPosition();
        if (counts == 1) {
            one.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = one;
        } else if (counts == 2) {
            two.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = two;
        } else if (counts == 3) {
            three.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = three;
        } else if (counts == 4) {
            four.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = four;
        } else if (counts == 5) {
            five.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = five;
        } else if (counts == 6) {
            six.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = six;
        } else if (counts == 7) {
            seven.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = seven;
        } else if (counts == 8) {
            eight.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = eight;
        } else {
            none.SetPosition(pos.x, pos.y);
            tiles[choice - 1] = none;
            if (choice < 26) {
                Click(choice + 25);
                if (choice != 1) {
                    Click(choice - 1);
                    Click(choice + 24);
                }
                if (choice != 25) {
                    Click(choice + 1);
                    Click(choice + 26);
                }
            } else if (choice > 375) {
                Click(choice - 25);
                if (choice != 376) {
                    Click(choice - 1);
                    Click(choice - 26);
                }
                if (choice != 400) {
                    Click(choice + 1);
                    Click(choice - 24);
                }
            } else if (choice % 25 == 1) {
                Click(choice + 1);
                Click(choice + 25);
                Click(choice + 26);
                Click(choice - 25);
                Click(choice - 24);
            } else if (choice % 25 == 0) {
                Click(choice - 1);
                Click(choice + 25);
                Click(choice + 24);
                Click(choice - 25);
                Click(choice - 26);
            } else
            {
                Click(choice - 1);
                Click(choice + 1);
                Click(choice + 26);
                Click(choice + 25);
                Click(choice + 24);
                Click(choice - 24);
                Click(choice - 25);
                Click(choice - 26);
            }
        }
        none.SetPosition(pos.x, pos.y);
        back[choice-1]=none;
        for (int i = 0; i < flags.size(); i++)
            if (choice == flags[i]) {
                sf::Vector2f pos = tiles[choice - 1].GetSprite().getPosition();
                tile.SetPosition(pos.x, pos.y);
                flaggies[choice - 1] = tiles[choice-1];
                flagcount++;
                flags.erase(flags.begin() + i);
            }
        counter--;
    }
}
void New(int x)
{
    int count=0;
    float posx=0;
    float posy=0;
    float var;
    lose=false;
    srand(time(NULL));
    mines.clear();
    bombs.clear();
    tiles.clear();
    non.clear();
    flags.clear();
    flaggies.clear();
    if (x==0) {
        for (int i = 0; i < 50; i++) {
            mines.push_back(rand() % 400 + 1);
            for (int j = 0; j < mines.size(); j++)
                if (mines[i] == mines[j]) {
                    count++;
                    if (count == 2) {
                        mines.pop_back();
                        i--;
                    }
                }
            count = 0;
        }
    }
    if (x==1)
    {
        ifstream file("boards/testboard1.brd");
        if (file.is_open()) {
            char value;
            for (int i = 0; i < 400; i++) {
                file >> value;
                if ((int)value-48 == 1)
                    mines.push_back(i + 1);
            }
            file.close();
        }
    }
    if (x==2)
    {
        ifstream file("boards/testboard2.brd");
        if (file.is_open()) {
            char value;
            for (int i = 0; i < 400; i++) {
                file >> value;
                if ((int)value-48 == 1)
                    mines.push_back(i + 1);
            }
            file.close();
        }
    }
    if (x==3)
    {
        ifstream file("boards/testboard3.brd");
        if (file.is_open()) {
            char value;
            for (int i = 0; i < 400; i++) {
                file >> value;
                if ((int)value-48 == 1)
                    mines.push_back(i + 1);
            }
            file.close();
        }
    }
    count=1;
    for (int i=0; i<16;i++)
    {
        for (int j=0; j<25; j++)
        {
            for (int k=0; k<mines.size(); k++) {
                if (mines[k] == count) {
                    mine.SetPosition(posx, posy);
                    bombs.push_back(mine);
                }
            }
            tile.SetPosition(posx,posy);
            tiles.push_back(tile);
            posx+=tile.GetSprite().getGlobalBounds().width;
            var=tile.GetSprite().getGlobalBounds().height;
            count++;
        }
        posx=0;
        posy+=var;
    }
    flagcount=mines.size();
    counter=400-mines.size();
}
int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "Project 3");
    sf::Sprite nums;
    sf::Texture tnums;
    sf::Sprite nums2;
    sf::Texture tnums2;
    sf::Sprite nums3;
    sf::Texture tnums3;
    bool guy=false;
    bool flagger=false;
    int deeb=-1;
    New(0);
    while (window.isOpen())
    {
        sf::Event event;
        tnums.loadFromFile("images/digits.png", sf::IntRect((abs(flagcount)/10)*21,0,21, 32));
        tnums2.loadFromFile("images/digits.png", sf::IntRect((abs(flagcount)%10)*21,0,21, 32));
        tnums3.loadFromFile("images/digits.png", sf::IntRect(0,0,21,32));
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)
                window.close();
            if (event.type==sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button==sf::Mouse::Left) {
                    int choices=Square(event.mouseButton.x, event.mouseButton.y);
                    for (int i = 0; i< flags.size(); i++)
                        if (choices == flags[i])
                            flagger=true;
                    for (int i = 0; i < mines.size(); i++)
                        if (choices == mines[i])
                            lose=true;
                    if ((choices==412)||(choices==413)||(choices==437)||(choices==438))
                        New(0);
                    if ((choices==416)||(choices==417)||(choices==441)||(choices==442))
                        deeb*=-1;
                    if ((choices==418)||(choices==419)||(choices==443)||(choices==444))
                        New(1);
                    if ((choices==420)||(choices==421)||(choices==445)||(choices==446))
                        New(2);
                    if ((choices==422)||(choices==423)||(choices==447)||(choices==448))
                        New(3);
                    if ((lose==false)&&(flagger==false))
                        Click(choices);
                    if (counter==0)
                    {
                        for (int i=0; i<mines.size(); i++) {
                            sf::Vector2f pos = bombs[i].GetSprite().getPosition();
                            flag.SetPosition(pos.x, pos.y);
                            flaggies[mines[i]] = flag;
                        }
                    }
                    flagger=false;
                }
                if ((lose==false)&&(counter!=0)) {
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        int choices = Square(event.mouseButton.x, event.mouseButton.y);
                        for (int i = 0; i < non.size(); i++)
                            if (choices == non[i])
                                guy = true;
                        for (int i = 0; i < flags.size(); i++)
                            if (choices == flags[i]) {
                                sf::Vector2f pos = tiles[choices - 1].GetSprite().getPosition();
                                tile.SetPosition(pos.x, pos.y);
                                flaggies.erase(choices-1);
                                flagcount++;
                                flags.erase(flags.begin() + i);
                                guy = true;
                            }
                        if (guy == false) {
                            sf::Vector2f pos = tiles[choices - 1].GetSprite().getPosition();
                            flag.SetPosition(pos.x, pos.y);
                            flaggies[choices-1]=flag;
                            flagcount--;
                            flags.push_back(choices);
                        }
                        guy = false;

                    }
                }
            }
        }

        window.clear();
        auto iter2=back.begin();
        for (; iter2!=back.end(); ++iter2)
            window.draw((iter2->second).GetSprite());
        if (deeb==-1)
        {
            for (int i=0; i<bombs.size(); i++)
                window.draw(bombs[i].GetSprite());
            for (int i=0; i<tiles.size(); i++)
                window.draw(tiles[i].GetSprite());
        }
        if (deeb==1) {
            for (int i = 0; i < tiles.size(); i++)
                window.draw(tiles[i].GetSprite());
            for (int i = 0; i < bombs.size(); i++)
                window.draw(bombs[i].GetSprite());
        }
        auto iter=flaggies.begin();
        for (; iter!=flaggies.end(); ++iter)
            window.draw((iter->second).GetSprite());
        if (flagcount<0)
            tnums3.loadFromFile("images/digits.png", sf::IntRect(210,0,21,32));
        nums3.setTexture(tnums3);
        nums.setTexture(tnums);
        nums2.setTexture(tnums2);
        nums3.setPosition(0, 512);
        nums.setPosition(21, 512);
        nums2.setPosition(42, 512);
        window.draw(nums3);
        window.draw(nums);
        window.draw(nums2);
        if (counter==0)
        {
            best.SetPosition(368,512);
            window.draw(best.GetSprite());
        }
        else if (lose==false) {
            good.SetPosition(368, 512);
            window.draw(good.GetSprite());
        }
        else if (lose==true)
        {
            bad.SetPosition(368, 512);
            window.draw(bad.GetSprite());
            for (int i = 0; i < bombs.size(); i++)
                window.draw(bombs[i].GetSprite());
        }
        debug.SetPosition(496, 512);
        t1.SetPosition(560, 512);
        t2.SetPosition(624, 512);
        t3.SetPosition(688, 512);
        window.draw(debug.GetSprite());
        window.draw(t1.GetSprite());
        window.draw(t2.GetSprite());
        window.draw(t3.GetSprite());
        window.display();
    }
    return 0;
}