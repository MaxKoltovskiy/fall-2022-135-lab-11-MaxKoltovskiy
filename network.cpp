#include "network.h"
// Returns user ID (index in the 'profiles' array) by their username
// (or -1 if username is not found)
int Network::findID (std::string usrn) {
    for(int i = 0; i< numUsers; i++) {
        if(usrn.compare(profiles[i].getUsername()) == 0) {
            return i;
        }
    }
    return -1;
}

// Constructor, makes an empty network (numUsers = 0)
Network::Network() {
    numUsers = 0;
}

// Attempts to sign up a new user with specified username and displayname
// return true if the operation was successful, otherwise return false
bool Network::addUser(std::string usrn, std::string dspn) {
    if(usrn == "") {
        return false;
    }

    for(int i = 0; i< usrn.length(); i++) {
        if(!(isalpha(usrn[i]) || isdigit(usrn[i]))) {
            return false;
        }
    }

    if(findID(usrn) != -1) {
        return false;
    }

    if(numUsers < MAX_USERS) {
        Profile newprof(usrn, dspn);
        profiles[numUsers] = newprof;
        numUsers++;
        return true;
    }
    return false;
}