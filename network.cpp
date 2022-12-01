#include "network.h"
#include <iostream>
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
    for(int i = 0; i< MAX_USERS; i++) {
        for(int j = 0; j< MAX_USERS; j++) {
            following[i][j] = false;
        }
    }
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

// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
bool Network::follow(std::string usrn1, std::string usrn2) {
    if(findID(usrn1) == -1 || findID(usrn2) == -1) {
        return false;
    }

    following[findID(usrn1)][findID(usrn2)] = true;
    return true;
}

bool Network::isfollowing(std::string usrn1, std::string usrn2) {
    return following[findID(usrn1)][findID(usrn2)];
}

 // Print Dot file (graphical representation of the network)
void Network::printDot() {
    std::string digraph = "digraph {\n";
    for(int i = 0; i< numUsers; i++) {
        digraph += "  \"@" + profiles[i].getUsername() + "\"\n";
    }

    for(int i = 0; i< numUsers; i++) {
        for(int j = 0; j< numUsers; j++){
            if(following[i][j]) {
                digraph += "\n  \"@" + profiles[i].getUsername() + "\"";
                digraph += " -> ";
                digraph += "\"@" + profiles[j].getUsername() + "\"";
            }
        }
    }

    digraph += "\n}\n";
    std::cout<< digraph;
    //return digraph;
}
