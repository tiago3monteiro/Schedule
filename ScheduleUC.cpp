//
// Created by tiagomonteiro on 10/18/23.
//

#include <iostream>
#include "ScheduleUC.h"


bool ScheduleUC::operator < (const ScheduleUC& scheduleUc) const
{
    if(this->classForUc.getUcCode() < scheduleUc.classForUc.getUcCode()) return true;
    if(this->classForUc.getUcCode() > scheduleUc.classForUc.getUcCode()) return false;
    return this->classForUc.getUcClass() < scheduleUc.classForUc.getUcClass();
}

const std::vector<Block> ScheduleUC::getUcClassSchedule() const {
    return UcClassSchedule;
}

void ScheduleUC::addBlock(Block block) {
    UcClassSchedule.push_back(block);
}

const ClassForUc &ScheduleUC::getClassForUc() const {
    return classForUc;
}
