//
// Created by tiagomonteiro on 10/11/23.
//

#include "Block.h"

Block::Block(std::string day, float  startHour, float duration, std::string type) {
    if(day == "Monday") this->day = Day::Monday;
    if(day == "Tuesday") this->day = Day::Tuesday;
    if(day == "Wednesday") this->day = Day::Wednesday;
    if(day == "Thursday") this->day = Day::Thursday;
    if(day == "Friday") this->day = Day::Friday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;

}

const float &Block::getStartHour() const {
    return startHour;
}

const std::string Block::getDay() const {
    if(day == 0) return "Monday";
    if(day == 1) return "Tuesday";
    if(day == 2) return "Wednesday";
    if(day == 3) return "Thursday";
    if(day == 4) return "Friday";
}

const float &Block::getDuration() const {
    return duration;
}

const std::string &Block::getType() const {
    return type;
}

bool Block::operator< (const Block& block) const {
    if (this->day < block.day) return true;

    else if (this->day > block.day) return false;

    return this->getStartHour() < block.getStartHour();
}

bool Block::overlapping(const Block& block) const
{
    if(this->day != block.day || this->getType() == "T" ||block.getType() == "T") return false;
    float startTime = this->getStartHour();
    float endTime = startTime + this->getDuration();
    float startTime1 = block.getStartHour();
    float endTime1 = startTime1 + block.getDuration();
    if (endTime <= startTime1  || startTime >= endTime1) return false;
    return true;

}
