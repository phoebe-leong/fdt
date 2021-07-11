#include <iostream>
#include <fstream>

int main(int charc, char* charv[]) {

    if (charc < 2 || charc > 3) {
        std::cout << "Usage: ~/ftd <param> <param>\n";
        return -1;
    }

    #define maxfilelines 1000
    std::string fileonedata[maxfilelines + 1];
    std::string filetwodata[maxfilelines + 1];
    std::string fileonepath = charv[1], filetwopath = charv[2];

    std::ifstream fileone(fileonepath);
    std::ifstream filetwo(filetwopath);

    if (!fileone || !filetwo) {
        fileone.close();
        filetwo.close();
        std::cout << "Invalid path!\n";
        return -1;
    }

    if (fileonepath == filetwopath) {
        std::cout << "Your files are the same\n";
        return 0;
    }

    for (int i = 0; !fileone.eof() && i <= maxfilelines; i++) {
        getline(fileone, fileonedata[i]);
    }
    for (int i = 0; !filetwo.eof() && i <= maxfilelines; i++) {
        getline(filetwo, filetwodata[i]);
    }

    int fileonedatasize = 0, filetwodatasize = 0;

    for (int i = 0; i < sizeof(fileonedata) / sizeof(fileonedata[0]); i++) {
        if (!fileonedata[i].empty()) {
            fileonedatasize++;
        }
    }
    for (int i = 0; i < sizeof(filetwodata) / sizeof(filetwodata[0]); i++) {
        if (!filetwodata[i].empty()) {
            filetwodatasize++;
        }
    }

    if (fileonedatasize != filetwodatasize) {
        std::cout << "Your two files aren't the same\n";
        return 0;
    }

    int duplicatelines = -1;
    for (int i = 0; i <= fileonedatasize; i++) {
        if (fileonedata[i] == filetwodata[i]) {
            duplicatelines++;
        }
    }

    if (duplicatelines == fileonedatasize) {
        std::cout << "Your two files are the same\n";
        return 0;
    } else {
        std::cout << "Your two files aren't the same\n";
        return 0;
    }
}