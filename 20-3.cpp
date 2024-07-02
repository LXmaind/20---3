
#include <iostream>
#include <fstream>

int main()
{

    std::ifstream river("river.txt");
    std::ofstream bask("basket.txt", std::ios::app);
    std::string fish1;
    std::string fish2;
    int num;

    if (river.is_open() && bask.is_open()) {

        std::cout << "How many times will you fish: ";
        std::cin >> num;

        for (int i = 0; i < num; i++) {

            std::cout << "What kind of fish do you want to catch?: ";
            std::cin >> fish1;

            while (!river.eof()) {

                river >> fish2;

                if (fish2 == fish1) {

                    bask << fish2 << std::endl;
                    std::cout << "You caught a fish, now it's in your bucket!" << std::endl;
                    break;

                }

            }

            if (river.eof()) {

                std::cout << "There is no such fish species!" << std::endl;

            }

            river.seekg(0);

        }
        
        bask.close();
        river.close();

        std::ifstream bask("basket.txt");
        bask.seekg(0);

        std::cout << "Fish in a bucket: " << std::endl;

        while (bask >> fish2) {

            std::cout << fish2 << std::endl;

        }

    }
    else {

        std::cout << "No files found";

    }

    bask.close();
    river.close();

}
