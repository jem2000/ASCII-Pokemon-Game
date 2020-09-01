//
// Created by justi on 12/2/2019.
//

#ifndef PA3_INPUT_HANDLING_H
#define PA3_INPUT_HANDLING_H

#include <string>

using namespace std;


class Invalid_Input {
public :
    Invalid_Input(string in_ptr) : msg_ptr (in_ptr) { }
    const string msg_ptr;
private :
    Invalid_Input ();
    // no default construction
};


#endif //PA3_INPUT_HANDLING_H
