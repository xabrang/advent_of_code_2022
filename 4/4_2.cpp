#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream fl("input");
    std::string txt {};
    int sum {};

    while(getline(fl, txt)){
        int h[4] {0};
        int di = txt.find(",");
        std::string f{}, s{};
        f = txt.substr(0, di);
        s = txt.substr(di+1);

        h[0] = stoi(f.substr(0,f.find("-")));
        h[1] = stoi(f.substr(f.find("-")+1));

        h[2] = stoi(s.substr(0,s.find("-")));
        h[3] = stoi(s.substr(s.find("-")+1));

        if(std::max(h[0], h[2]) <= std::min(h[1], h[3]))
            sum += 1;
    }

    std::cout << sum << std::endl;

    return 0;
}
