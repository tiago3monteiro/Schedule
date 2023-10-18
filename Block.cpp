//
// Created by tiagomonteiro on 10/11/23.
//

#include "Block.h"

Block::Block(std::string day, float startHour, float duration, std::string type) {
    this->day=day;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;

}
