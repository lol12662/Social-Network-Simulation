#pragma once
#include "User.h"
#ifndef NETWORK_H
#define NETWORK_H

#pragma once

class Network
{
private:

    std::vector<User*> users_;


public:
    Network();
    ~Network();

    void add_user(User* a);
    int add_connection(std::string s1, std::string s2);
    int remove_connection(std::string s1, std::string s2);
    int get_id(std::string name);
    int read_users(std::string fname);
    int write_users(char* fname);
    std::size_t num_users();
    void print_users();
    void print_friends(std::size_t id);
    std::vector<User*> get_users();
    User* get_user(std::size_t id);
    std::vector<int> shortest_path(int from, int to);
    std::vector<int> distance_user(std::size_t from, std::size_t& to, std::size_t distance);
    std::vector<std::vector<std::size_t> > groups();
    std::vector<int> suggest_friends(std::size_t who, std::size_t& score);
    void add_post(std::size_t ownerId, std::string message, std::size_t likes, bool incoming, std::size_t author, bool isPublic);
    std::string display_posts(std::string name, std::size_t howmany, bool showonlypublic);
    int read_posts(std::string filename);

};

#endif



