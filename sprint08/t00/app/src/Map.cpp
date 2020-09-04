#include "Map.h"
#include "Player.h"
#include <iostream>

Map::Map(size_t width, size_t height, std::shared_ptr<Player> &player) : m_width(width), m_height(height), m_player(player) {
    generateMap();
}

void Map::generateMap() {
    m_map = std::make_unique<char[]>(m_width * m_height);

    for (int i = 0; i < m_width * m_height; i++) {
        if (rand() % 3 == 0) {
            if (rand() % 2 == 0)
                m_map[i] = '@';
            else
                m_map[i] = 'T';
        } else
            m_map[i] = '.';
    }
}

void Map::outputMap() const {
    int X = m_player->posX();
    int Y = m_player->posY();
    for (int i = 0; i < m_width * m_height; i++) {
        if (i % m_width == 0 && i != 0)
            std::cout << "\n";

        
        if (i == Y * m_height + X)
            std::cout << "P" << " ";
       
        else
            std::cout << m_map[i] << " ";
    }
    std::cout << "\n";
}

size_t Player::posX() const {
    return m_posX;
};
size_t Player::posY() const {
    return m_posY;
};

void MoveManager::processInputAndMove(const std::string &inputStr) {
    Direction dir;
    if (inputStr == "l")
        dir = MoveManager::Direction::Left;
    else if (inputStr == "d")
        dir = MoveManager::Direction::Down;
    else if (inputStr == "r")
        dir = MoveManager::Direction::Right;
    else if (inputStr == "u")
        dir = MoveManager::Direction::Up;
    else if (inputStr == "e")
        exit(1);
    else {
        std::cerr << "Invalid input\n";
        return;
    }
    if (checkMove(dir)) {
        m_player->movePlayer(dir);
        m_map->outputMap();

    } else
        std::cerr << "Invalid direction\n";
}

bool MoveManager::checkMove(Direction dir) const {
    if (dir == Direction::Down && m_player->posY() < m_map->height() - 1)
        return true;
    if (dir == Direction::Left && m_player->posX() > 0)
        return true;
    if (dir == Direction::Right && m_player->posX() < m_map->width() - 1)
        return true;
    if (dir == Direction::Up && m_player->posY() > 0)
        return true;
    return false;
}

size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}
MoveManager::MoveManager(std::shared_ptr<Player> &player, std::shared_ptr<Map> &map) : m_map(map), m_player(player){};

void Player::movePlayer(MoveManager::Direction dir) {
    if (dir == MoveManager::Direction::Down)
        m_posY++;
    if (dir == MoveManager::Direction::Left)
        m_posX--;
    if (dir == MoveManager::Direction::Right)
        m_posX++;
    if (dir == MoveManager::Direction::Up)
        m_posY--;
}
