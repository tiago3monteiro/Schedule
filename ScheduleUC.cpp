//
// Created by tiagomonteiro on 10/18/23.
//

#include <iostream>
#include "ScheduleUC.h"

bool ScheduleUC::operator< (const ScheduleUC& scheduleUc) const
{
    return this->classForUc.getUcCode() < scheduleUc.classForUc.getUcCode();
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

void ScheduleUC::printSchedule()
{
    std::cout << "Schedule for: " << this->classForUc.getUcCode() << " for class " << this->classForUc.getUcClass()<< std::endl;
    for(auto classes: UcClassSchedule)
    {
        std::cout << classes.getDay() << "/" << classes.getStartHour() << "/" << classes.getDuration() << "/" << classes.getType();

    }

}