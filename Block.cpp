//
// Created by tiagomonteiro on 10/11/23.
//

#include "Block.h"

Block::Block(std::string day, std::string  startHour, std::string duration, std::string type) {
    this->day=day;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;

}

const std::string &Block::getStartHour() const {
    return startHour;
}

const std::string &Block::getDay() const {
    return day;
}

const std::string &Block::getDuration() const {
    return duration;
}

const std::string &Block::getType() const {
    return type;
}

bool Block::operator< (const Block& block) const
{
    if(this->getDay() < block.getDay()) return true;


}