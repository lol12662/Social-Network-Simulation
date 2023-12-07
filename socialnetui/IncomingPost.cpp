#include "IncomingPost.h"
/**
 * IncomingPost Class
 *
 * IncomingPost Class Emulates a post with privacy settings of a User of a Network
 * Subclass of Post
 *
 */



/*
 Default Constructor
 */
IncomingPost::IncomingPost():Post() {
    isPublic = false;

}
/*
Constructor

param:
Id of the Post
Body of the Post
Likes of the post
If the Post is public
Author of the Post
*/
IncomingPost::IncomingPost(std::size_t id_, std::string message_, std::size_t likes, bool isPublic, std::string author): Post(id_, message_, likes){
    IncomingPost::isPublic = isPublic;
    IncomingPost::author = author;
}
/*
Method: display_post

param: none
displays Post with message and likes
*/
std::string IncomingPost::display_post() {
    std::cout<< get_message()<<std::endl;
    std::string newmsg = get_message().append("\nFrom: " + author + "\n");
    std::cout<< newmsg<<std::endl;

    if (get_is_public()) {
        return  "Public: \n" + newmsg + " Liked by " + std::to_string(get_likes()) + " people";;
    }

    else {
        return "Private: \n" + newmsg; +" Liked by " + std::to_string(get_likes()) + " people";;
    }

}
/*
Method: get_is_public

param: none
returns if the post is public
*/
bool IncomingPost::get_is_public() {
    return isPublic;
}
