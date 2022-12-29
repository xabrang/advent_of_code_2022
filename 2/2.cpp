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
        int y = val[txt[2]];

        score += y;

        if(o == y)
            score += 3;
        
        if(abs(o-y)==1 && (std::max(o,y) == y))
            score += 6;

        if(abs(o-y)==2 && (std::min(o,y) == y))
            score += 6;
    }

    std::cout << "score: " << score << std::endl;

    return 0;
}
