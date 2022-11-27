#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>
#include <vector>
int main()
{
    std::string path = "input.txt";
    std::fstream fs;
    std::map<char, int>alph;
    setlocale(LC_CTYPE, "Russian");

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
            else if (t >= 'А' && t <= 'Я') {
                alph[t] = 1;
            }
        }
    }
    fs.close();


    char temp;
    std::string mc_let;
    for (int i = 0; i < 8; ++i) {
        int maxim = 0;
        for (auto n : alph) {
            if (n.second > maxim) {
                maxim = n.second;
                temp = n.first;
            }
        }
        mc_let += temp;
        alph.erase(temp);
    }

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
            std::string temp_upper = msg;
            for (int i = 0; i < temp_upper.length(); ++i) {
                temp_upper[i] = toupper(temp_upper[i]);
            }
            ans[temp_upper] = temp;
        }
    }
    fs.close();
    std::string tmp;

    std::vector <std::string> text;
    fs.open(path, std::fstream::in);
    while (!fs.eof()) {
        std::getline(fs, tmp);
        text.push_back(tmp);
    }
    fs.close();
    path = "output.txt";
    fs.open(path, std::fstream::out);
    for (int i = 0; i < text.size(); ++i) {
        std::string msg;
        tmp = "";
        int last_change = 0;
        msg = text[i];
        for (int j = 0; j < text[i].length(); ++j) {
            if (text[i][j] != ' ') {
                tmp += std::toupper(text[i][j]);
            }
            else {
                tmp = "";
            }
            if (ans.find(tmp) != ans.end()) {
                std::string temp_msg = msg;
                msg = temp_msg.substr(0, last_change + j - tmp.length() +1);
                msg += ans.find(tmp)->first + "(" + ans.find(tmp)->second + ")";
                msg += temp_msg.substr(j + last_change + 1, temp_msg.length());
                last_change += ans.find(tmp)->second.length() + 2;
                tmp = "";
            }
        }
        fs << msg << std::endl;
    }
    fs.close();
    return 0;
}
