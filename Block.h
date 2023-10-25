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
    const std::string &getDay() const;
    const std::string &getStartHour() const;
    const std::string &getDuration() const;
    const std::string &getType() const;
    bool operator< (const Block& block) const;

private:
    std::string day;
    std::string  startHour;
    std::string  duration;
    std::string type;

};


#endif //SCHEDULE_PROJECT_BLOCK_H
