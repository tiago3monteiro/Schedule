//
// Created by tiagomonteiro on 10/11/23.
//

#ifndef SCHEDULE_PROJECT_BLOCK_H
#define SCHEDULE_PROJECT_BLOCK_H


#include <string>
//A block represents a class
class Block {
public:
    Block(std::string day, std::string  startHour, std::string  duration, std::string type);
    friend std::ostream& operator << (std::ostream& os, const Block& obj) {
        os << obj.day << std::string("/");
        os << obj.startHour << std::string("/");
        os << obj.duration << std::string("/");
        os << obj.type;
        return os;
    }

private:
    std::string day;
    std::string  startHour;
    std::string  duration;
    std::string type;

};


#endif //SCHEDULE_PROJECT_BLOCK_H
