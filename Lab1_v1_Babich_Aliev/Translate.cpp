#include <iostream>
#include "FileManager.h"
#include <map>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    FileManager fm1;
    FileManager fm2;
    FileManager fm3;
    FileManager fm4;

    fm1.path = "RUS.txt"; // Введённые нами слова на русском
    fm2.path = "BEL.txt"; // Введённые нами слова на белорусском
    fm3.path = "RUS_VC.txt"; // Русские слова для словаря
    fm4.path = "BEL_VC.txt"; // Белорусские слова для словаря

    string* words1 = fm1.readFromFile();
    string* words2 = fm2.readFromFile();

    // Русские и белорусские слова (по парам: слово - перевод)
    string* rus_words = fm3.readFromFile();
    string* bel_words = fm4.readFromFile();

    map <string, string> rus_bel;
    map <string, string> bel_rus;
    for (int i = 0; i < fm3.length(); i++)
    {
        rus_bel[rus_words[i]] = bel_words[i];
        bel_rus[bel_words[i]] = rus_words[i];
    }

    for (int i = 0; i < fm1.length(); i++)
    {
        char** buff;
        char buf[256];
        strcpy_s(buf, words1[i].c_str());
        const char* SEPARATORS = "!?.,;/*-+\n\t ";
        char* istr = strtok_s(buf, SEPARATORS, buff);
        while (istr != NULL)
        {
            map<string, string> ::iterator it;
            it = rus_bel.find(istr);
            fm2.writeToFile(it->second);
            istr = strtok_s(NULL, SEPARATORS, buff);
        }
        buf[0] = 0;
    }

    /*std::cout << "Choose translation:" << endl;
    std::cout << "1. RUS -> BEL" << endl << "2. BEL -> RUS" << endl;
    std::cout << "Input: ";
    int choose;
    std::cin >> choose;

    if (choose == 1)
    {
        for (int i = 0; i < fm1.length(); i++)
        {
            fm2.writeToFile(rus_bel[words1[i]]);
        }
    }
    else
    {
        for (int i = 0; i < fm2.length(); i++)
        {
            fm1.writeToFile(bel_rus[words2[i]]);
        }
    }*/

}