#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main()
{
    std::map<char, int> val{{'X', 1}, {'Y', 2}, {'Z', 3}};
    std::map<char, char> cv{{'A', 'X'}, {'B', 'Y'}, {'C', 'Z'}};

    std::string txt;
    std::ifstream fl("input");

    int score {};
    while(getline(fl, txt)){
        int o = val[cv[txt[0]]];
        char y = txt[2];
        if(y=='X')
            score += (o==1 ? 3 : o-1 );
        if(y=='Y')
            score += o + 3;
        if(y=='Z')
            score += (o>=3 ? 1 : o+1 ) + 6;
    }

    std::cout << "score: " << score << std::endl;

    return 0;
}
