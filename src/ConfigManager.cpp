/*!
 * @file ConfigManager.cpp
 * @brief config.yaml parser
 */

#include "ConfigManager.h"


ConfigManager::ConfigManager() {}

ConfigManager::~ConfigManager() {};

vector<unsigned> ConfigManager::split(string str, string delimiter) {
    vector<unsigned> tmpVector;
    if (!str.empty()) {
        int start = 0;
        do {
            int idx = str.find(delimiter, start);
            if (idx == string::npos) {
                break;
            }
            int length = idx - start;
            tmpVector.push_back(stoi(str.substr(start, length)));
            start += (length + delimiter.size());
            } while (true);
        tmpVector.push_back(stoi(str.substr(start)));
    }

    return tmpVector;
}

void ConfigManager::parseConfig(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) throw runtime_error("Can't open config.yaml file!");

    levelOne.resize(16);
    for (auto& c : levelOne) c.resize(21);

    string firstCfgKey;
    unsigned levelIndex = 0;

    while (!file.eof()) {
        string line;
        getline(file, line);

        unsigned currentLineIndex = 0;
        while (line[currentLineIndex] == ' ') ++currentLineIndex;

        if (line[currentLineIndex] == '-'){
            string value = line.substr(currentLineIndex + 2);

            levelOne[levelIndex] = ConfigManager::split(value, ",");
            ++levelIndex;
        } else {
            auto match = line.find(':');

            string configKey = line.substr(0, match);
            string configKeyValue = line.substr(match + 1);

            configKey.erase(0, configKey.find_first_not_of(' '));
            configKeyValue.erase(0, configKeyValue.find_first_not_of(' '));

            if (configKeyValue.empty()) {
                firstCfgKey = configKey;
            } else {
                string fullKey;
                fullKey.append(firstCfgKey);
                fullKey.append(".");
                fullKey.append(configKey);
                configData[fullKey] = configKeyValue;
            }
        }
    }

    // For Debug
//    auto it = configData.begin();
//
//    while (it != configData.end()) {
//        cout << it->first << "=" << it->second << endl;
//        ++it;
//    }
//
//    for (auto& t : levelOne) {
//        for (auto& tt : t) cout << tt;
//        cout << endl;
//    }

    file.close();
}

string ConfigManager::getData(const string &key) {
    return configData[key];
}

vector<vector<unsigned>> ConfigManager::getLevelData() {
    return levelOne;
}

string ConfigManager::getPacmanSkin() {
    if (configData["player.skin"] == "pacmanSkin") return "pacmanSkin";
    else if (configData["player.skin"] == "pacman") return "pacman";
    return "pacman"; // Default skin
}
