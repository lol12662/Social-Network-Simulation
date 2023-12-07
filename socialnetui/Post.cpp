# include "Post.h"
/**
 * Post Class
 *
 * Post Class Emulates a post of a User of a Network
 *
 */



/*
 Default Constructor
 */
Post::Post() {

}
/*
Constructor

param:
Id of Post
Body of the Post
Likes of the post

*/
Post::Post(std::size_t id_, std::string message_, std::size_t likes) {
    Post::id_ = id_;
    Post::message_ = message_;
    Post::likes = likes;
}
/*
Method: display_post

param: none
displays Post with message and likes
*/
    std::string Post::display_post() {
    std::string text = "\n" + Post::message_ + " Liked by " + std::to_string(likes) + " people";

    return text;
}
/*
Method: get_id

param: none
returns Id of post
*/
std::size_t Post::get_id() {
    return Post::id_;
}
/*
Method: get_message

param: none
returns message of post
*/
std::string Post::get_message() {
    return Post::message_;
}
/*
Method: get_likes

param: none
returns likes of post
*/
std::size_t Post::get_likes() {
    return Post::likes;
}
/*
Method: get_is_public

param: none
returns if the post is public(Note: inheireited function)
*/
bool Post::get_is_public() {
    return true;
}


