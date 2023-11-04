//
// Created by tiagomonteiro on 10/11/23.
//

#ifndef SCHEDULE_PROJECT_BLOCK_H
#define SCHEDULE_PROJECT_BLOCK_H


#include <string>
enum Day {
    Monday, Tuesday, Wednesday, Thursday, Friday};  //this is a cool way to organize the days of the week

class Block {
public:


    Block(std::string day, float  startHour, float  duration, std::string type);
    const std::string getDay() const;
    const float &getStartHour() const;
    const float &getDuration() const;
    const std::string &getType() const;
    bool operator< (const Block& block) const;
    bool overlapping(const Block& block) const;

private:
    Day day;
    float  startHour;
    float  duration;
    std::string type;

};


#endif //SCHEDULE_PROJECT_BLOCK_H
