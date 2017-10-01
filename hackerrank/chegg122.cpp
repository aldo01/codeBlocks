#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>

 using namespace std;
/* function main begins program execution */
int selectSixthNum();
int selectFiveNum();


int main(void) {
     selectFiveNum();
     selectSixthNum();
	return 0;
}

int selectFiveNum(){
std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, 75);
    for(int n=0; n<5; ++n)
        std::cout << distr(eng) << ' ';

        return 0;

}

int selectSixthNum(){
  std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, 15);
     std::cout << distr(eng) << ' ';

     return 0;
}
