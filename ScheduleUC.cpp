//
// Created by tiagomonteiro on 10/18/23.
//

#include <iostream>
#include "ScheduleUC.h"
#include <set>

bool ScheduleUC::operator < (const ScheduleUC& scheduleUc) const
{
    if(this->classForUc.getUcCode() < scheduleUc.classForUc.getUcCode())
    {
        return true;
    }
    if(this->classForUc.getUcCode() > scheduleUc.classForUc.getUcCode())
    {
        return false;
    }

    return this->classForUc.getUcClass() < scheduleUc.classForUc.getUcClass();
}

const std::vector<Block> &ScheduleUC::getUcClassSchedule() const {
    return UcClassSchedule;
}

void ScheduleUC::addBlock(Block block) {
    UcClassSchedule.push_back(block);
}

const ClassForUc &ScheduleUC::getClassForUc() const {
    return classForUc;
}
/*
void ScheduleUC::printSchedule() {
    std::set<Block> res;
    for (auto block: UcClassSchedule) res.insert(block);

    for (auto block: res) {
        int begin = std::stof(block.getStartHour());
        int duration = std::stof(block.getDuration());
        std::cout << block.getDay() << " " << block.getStartHour() << "-" << begin + duration << " " << block.getType()
                  << std::endl;
    }
}
*/
