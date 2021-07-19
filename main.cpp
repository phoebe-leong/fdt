#include <iostream>
#include <fstream>
#include <vector>

int main(int charc, char* charv[]) {

    if (charc != 3) {
        std::cout << "Usage: " << charv[0] << " <file-one> <file-two>\n";
        return -1;
    }

    std::vector<std::string> fileonedata;
    std::vector<std::string> filetwodata;

    std::ifstream fileone(charv[1]);
    std::ifstream filetwo(charv[2]);

    if (!fileone || !filetwo) {
        fileone.close();
        filetwo.close();
        std::cout << "Invalid path\\s!\n";
        return -1;
    }

    if (charv[1] == charv[2]) {
        std::cout << "Your files are the same\n";
        return 0;
    }

    for (int i = 0; !fileone.eof(); i++) {
        std::string line;
        getline(fileone, line);
        fileonedata.push_back(line);
    }
    for (int i = 0; !filetwo.eof(); i++) {
        std::string line;
        getline(filetwo, line);
        filetwodata.push_back(line);
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
    } else {
        std::cout << "Your two files aren't the same\n";
    }
    return 0;
}
