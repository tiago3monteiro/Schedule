//
// Created by tiagomonteiro on 10/31/23.
//

#ifndef SCHEDULE_PROJECT_REQUEST_H
#define SCHEDULE_PROJECT_REQUEST_H


#include <queue>
#include <string>

class Request {
public:
    Request(int type, std::string name, std::string UC, std::string aCLass = "default", int key = 2, int undo = 0);

    int getType() const;

    const std::string &getUc() const;

    const std::string &getAClass() const;

    const std::string &getName() const;

    int getKey() const;

    int getUndo() const;

private:
    //type 1 = Add Request type 2= Remove Request type 3 = Switch Request
    std::string UC; //might be uc that wants to add/remove or to switch class
    std::string aClass; //might be the class we want to switch to, or the class for the
    std::string name;
    int key;
    int type;
    int undo;


};


#endif //SCHEDULE_PROJECT_REQUEST_H
