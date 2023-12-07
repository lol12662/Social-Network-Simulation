#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <assert.h>
#include <vector>
#include <ctime>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <typeinfo>
#include "Post.h"
#include "IncomingPost.h"

#pragma once
class User
{
private:
    std::size_t id;
    std::string fullName;
    int birthYear;
    int zipCode;
    std::vector<int> connections;
    int depth;
    int predecessor;
    std::vector<Post> posts;

public:
    User();
    User(std::size_t id, std::string fullName, int birthYear, int zipCode, std::vector<int>  connections);
    void add_friend(int id);
    void delete_friend(int id);
    std::size_t get_id();
    std::string get_fullName();
    int get_birthYear();
    int get_zipCode();
    std::vector<int> get_connections();
    int get_depth();
    int get_predecessor();
    void change_depth(int i);
    void change_predecessor(int i);
    void add_post(Post* a);
    std::string display_posts(std::size_t howmany, bool showonlypublic);

};



