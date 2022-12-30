#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
    std::ifstream fl("input");
    std::string ln {};
    std::getline(fl, ln);
    std::map<char, int> m{};
    bool found {false};
    int i {};

    for(; i < ln.size(); i++){
        if(found)
            break;
        for(int t=0; t < 14; t++){
            if(m.find(ln[i+t]) != m.end())
                break;
            if(t==13)
                found = true;
            m.insert({ln[i+t], 1});
        }
        m.clear();
    }

    std::cout << i+13 << std::endl;

    return 0;
}
