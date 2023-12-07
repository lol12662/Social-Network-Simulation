#pragma once
#include "Post.h"
class IncomingPost :
                     public Post
{
private:

    bool isPublic;
    std::string author;

public:
    IncomingPost();
    IncomingPost(std::size_t id_, std::string message_, std::size_t likes, bool isPublic, std::string author);
    std::string display_post();
    bool get_is_public();


};

