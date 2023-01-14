#ifndef PACMAN_MINGL_CONFIGMANAGER_H
#define PACMAN_MINGL_CONFIGMANAGER_H

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;


class ConfigManager {

public:
    ConfigManager();
    ~ConfigManager();

    void parseConfig(const string& fileName);
    string getData(const string& key);
    vector<vector<unsigned>> getLevelData();
    string getPacmanSkin();

private:
    map<string, string> configData;
    vector<vector<unsigned>> levelOne;
    static vector<unsigned> split(string str, string delimiter);

};


#endif
