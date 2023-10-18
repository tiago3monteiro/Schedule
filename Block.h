//
// Created by tiagomonteiro on 10/11/23.
//

#ifndef SCHEDULE_PROJECT_BLOCK_H
#define SCHEDULE_PROJECT_BLOCK_H


#include <string>
//A block represents a class
class Block {
public:
    Block(std::string day, float startHour, float duration, std::string type);

private:
    std::string day;
    float startHour;
    float duration;
    std::string type;

};


#endif //SCHEDULE_PROJECT_BLOCK_H
