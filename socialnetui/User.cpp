/**
 * User Class
 *
 * User Class Emulates a User of a Network
 *
 */
#include "User.h"

/*
Default Constructor
*/
User::User() {
}
/*
Constructor

Param:
std::size_t id								The ID of the User
std::string fullName						The Name of the User
int birthYear								The Birth Year of teh User
int zipCode									The Zip Code of the User
std::vector<std::size_t>  connections		A list of all teh connections the User intially has
*/
User::User(std::size_t id, std::string fullName, int birthYear, int zipCode, std::vector<int>  connections) {
    User::id = id;
    User::fullName = fullName;
    User::birthYear = birthYear;
    User::zipCode = zipCode;
    User::connections = connections;
};

/*
Method: add_friend

param: an ID of a User
Adds friend to the User

*/
void User::add_friend(int ID) {
    if (find(connections.begin(), connections.end(), ID) != connections.end()) {

    }
    else {
        connections.push_back(ID);
    }
}
/*
Method: delete_frien

param: an ID of a User
Deletes friend to the User

*/
void User::delete_friend(int ID) {
    for(int i = 0;i<connections.size();i++){
        if(connections[i]==ID){
            connections.erase(connections.begin()+i);
        }
    }
}
/*
Method: get_connections

param: none
returns a list of connections of the User
*/
std::vector<int> User::get_connections() {
    return connections;
}
/*
Method: get_id

param: none
returns ID
*/
std::size_t User::get_id() {
    return id;
}
/*
Method: get_fullName

param: none
returns name
*/
std::string User::get_fullName() {
    return fullName;
}
/*
Method: get_birthYear

param: none
returns birth year
*/
int User::get_birthYear() {
    return birthYear;
}
/*
Method: get_zipCode

param: none
returns Zip Code
*/
int User::get_zipCode() {
    return zipCode;
}
/*
Method: get_depth

param: none
returns current Depth
*/
int User::get_depth() {
    return depth;
}
/*
Method: get_predecessor

param: none
returns proceeding User
*/
int User::get_predecessor() {
    return predecessor;
}
/*
Method: change_depth

param: none
changes to current depth
*/
void User::change_depth(int i) {
    depth = i;
}
/*
Method: change_predecessor

param: none
changes predeccesor
*/
void User::change_predecessor(int i) {
    predecessor = i;
}
/*
Method: add_post

param: Post* a
Adds a post to the User
*/
void User::add_post(Post* a) {
   // std::cout<<User::posts.size()<<std::endl;
    posts.push_back(*a);
    //std::cout<<User::posts.size()<<std::endl;
}
/*
Method: display_posts

param: how many posts, a bool for whether to show public or not
displays a certain number of posts that are either public and private or only public
*/
std::string User::display_posts(std::size_t howmany, bool showonlypublic) {
    std::string text;
    int count = 0;
//    std::cout<<posts.size()<<std::endl;
    for (int i = posts.size() - 1; i >= 0; i--) {
//        std::cout<<User::posts[i]->display_post()<<std::endl;
        if(i<0){
            return text;
        }
        if (showonlypublic == true) {
            if (posts[i].get_is_public()) {
                count++;
                text.append("\n"+posts[i].display_post());
            }
            else {
            }
        }
        else {
            count++;
            text.append("\n" + posts[i].display_post());
        }
        if (count == howmany) {
            i = 0;
        }

    }
    return text;

}

