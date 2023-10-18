//
// Created by tiagomonteiro on 10/18/23.
//

#ifndef SCHEDULE_PROJECT_SCHEDULEUC_H
#define SCHEDULE_PROJECT_SCHEDULEUC_H


#include <string>
#include <vector>
#include "Block.h"
#include "ClassForUc.h"

class ScheduleUC {
public:
    ScheduleUC(ClassForUc classForUc, std::vector<Block> UcClassSchedule):classForUc(classForUc),UcClassSchedule(UcClassSchedule){ };
    bool operator< (const ScheduleUC& scheduleUc) const;
    const std::vector<Block> &getUcClassSchedule() const;
    const ClassForUc &getClassForUc() const;
    void addBlock(Block block);

private:
    ClassForUc classForUc;
    std::vector<Block> UcClassSchedule;

};


#endif //SCHEDULE_PROJECT_SCHEDULEUC_H
