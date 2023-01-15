/*!
 * @file ConfigManger.h
 * @brief config.yaml parser
 */

#ifndef PACMAN_MINGL_CONFIGMANAGER_H
#define PACMAN_MINGL_CONFIGMANAGER_H

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*!
 * @brief Config Manager Class
 */
class ConfigManager {

public:
    /*!
     * @brief Constructor for ConfigManager Class
     * @fn ConfigManager();
     */
    ConfigManager();

    /*!
     * @brief Destructors for ConfigManager Class
     * @fn ~ConfigManager();
     */
    ~ConfigManager();

    /*!
     * @brief Parse config file
     * @param fileName
     * @fn void parseConfig(const string& fileName);
     */
    void parseConfig(const string& fileName);

    /*!
     * @brief Return config data
     * @param key
     * @return configData[key];
     */
    string getData(const string& key);

    /*!
     * @brief Return level data
     * @return levelOne;
     */
    vector<vector<unsigned>> getLevelData();

    /*!
     * @brief Return pacman skin from config
     * @return pacman skin
     */
    string getPacmanSkin();

private:
    /*!
     * @brief configData : Map containing parsed config data
     */
    map<string, string> configData;

    /*!
     * @bried levelOne : Level map
     */
    vector<vector<unsigned>> levelOne;

    /*!
     * @brief Split function to generate level map
     * @param str
     * @param delimiter
     * @return tmpVector;
     */
    static vector<unsigned> split(string str, string delimiter);

};


#endif
