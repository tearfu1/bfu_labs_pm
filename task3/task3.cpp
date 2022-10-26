#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>
int main()
{
    //для корректной работы следует сохранить input.txt в кодировке ANSI
    std::string path = "input.txt";
    std::fstream fs;
    std::map<char, int>alph;
    setlocale(LC_CTYPE, "Russian");
    //чтение из файла, подсчет количетсва встреч букв в файле
    fs.open(path, std::fstream::in);
    while (!fs.eof()) {
        std::string msg;
        fs >> msg;
        for (int i = 0; i < msg.size(); ++i) {
            char t;
            t = toupper(msg[i]);
            if (alph.find(t) != alph.end()) {
                alph[t] += 1;
            }
            else if(t >= 'А' && t <= 'Я') {
                alph[t] = 1;
            }
        }
    }
    fs.close();

    //нахождение восьми наиболее встречаемых
    char temp;
    std::string mc_let;
    for (int i = 0; i < 8;++i) {
        int maxim = 0;
        for (auto n:alph) {
            if (n.second > maxim) {
                maxim = n.second;
                temp = n.first;
            }
        }
        mc_let += temp;
        alph.erase(temp);
    }
    //проверка по заданию
    std::map<std::string, std::string> ans;
    fs.open(path, std::fstream::in);
    while (!fs.eof()) {
        std::string msg;
        fs >> msg;
        std::string temp;
        for (int i = 0; i < msg.size(); ++i) {
            char t;
            t = toupper(msg[i]);
            if ((mc_let.find(t) != std::string::npos) && (temp.find(t) == std::string::npos)) {
                temp += t;
            }
        }
        if (temp.length() >= 5) {
            ans[msg] = temp;
        }
    }
    fs.close();
    //вывод
    path = "output.txt";
    fs.open(path, std::fstream::out);
    for (auto now : ans) {
        std::string temp = now.first;
        for (int i = 0; i < temp.length(); ++i) {
            temp[i] = toupper(temp[i]);
        }
        fs << temp << " " << "(" << now.second << ")";
        fs << std::endl;
    }
    return 0;
}

