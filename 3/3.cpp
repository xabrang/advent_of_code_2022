#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string txt;
    std::ifstream fl("input"); 

    int sum {0};

    while(getline(fl, txt)){
        int sz = txt.size();
        int hl[52] = {0};
        bool part_2 {false};

        for(int i = 0; i < sz; i++){
            int dc = (txt[i] > 96) ? txt[i] - 97 : (txt[i] - 65) + 26;

            if(i==sz/2)
                part_2 = true;
            if((hl[dc] == 0 && !part_2) || hl[dc] != 0 && part_2 )
                hl[dc] += 1;
        }

        for(int i = 0; i < 52; i++)
            sum += (hl[i] > 1) ? i+1 : 0;
    }

    std::cout << sum << std::endl;
    fl.close();

    return 0;
}
