
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
#ifndef POST_H
#define POST_H

#pragma once

class Post {
private:
    std::size_t id_;
    std::string message_;
    std::size_t likes;

public:
    Post();
    Post(std::size_t id_, std::string message_,  std::size_t likes);
    virtual std::string display_post();
    std::size_t get_id();
    std::string get_message();
    std::size_t get_likes();
    virtual bool get_is_public();

};
#endif
