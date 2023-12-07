/**
 * Network Class
 *
 * Network Class Emulates a social network
 *
 */
#pragma once
#include "Network.h"
#include <unordered_map>



/*
Default Constructor
*/
Network::Network() {

}
/*
Default Destructor
*/
Network::~Network() {


}
/*
Method: read_users

param: Name of a file
reads and inputs all users in the file to the Network
*/
int Network::read_users(std::string fname) {
    std::ifstream input(fname);
    if (input.is_open() == false) {
        std::cout << "No file exists";
        return -1;
    }

    std::string tmp;
    std::getline(input,tmp);
    int nUser = stoi(tmp);

    for(int i = 0; i < nUser; i++){
        std::string id,byear,zip;
        std::string name, fstring;

        std::getline(input,id);
        std::getline(input,name);
        std::getline(input,byear);
        std::getline(input,zip);
        std::getline(input,fstring);

        std::stringstream sn(name);
        std::string fname,lname;
        sn >> fname >> lname;
        std::string fullname = fname+" "+lname;
        std::stringstream sf(fstring);

        std::vector<int> v;
        int tmp;
        while(sf >> tmp){
            v.push_back(tmp);
        }
        add_user(new User(stoi(id),fullname, stoi(byear),stoi(zip),v));
    }
    return nUser;
}
/*
Method: write_users

param: Name of a file
Writes all users in the Network to the file
*/
int Network::write_users(char* fname) {
    std::ofstream myfile;
    std::vector<int>  connections;
    myfile.open(fname);
    if (myfile.is_open()) {
        myfile << users_.size() << std::endl;
        for (int i = 0; i < users_.size(); i++) {
            connections = users_[i]->get_connections();
            myfile << users_[i]->get_id() << std::endl <<
                "\t" << users_[i]->get_fullName() << std::endl <<
                "\t" << users_[i]->get_birthYear() << std::endl <<
                "\t" << users_[i]->get_zipCode() << std::endl;
            for (int j = 0; j < connections.size(); j++) {
                myfile << connections[j] << " ";
            }
            myfile << std::endl;
        }


        myfile.close();
        return 0;
    }
    else {
        myfile.close();
        return -1;
    }
}
/*
Method: add_user

param: a User object
Adds user to the Network

*/
void Network::add_user(User* a) {
    users_.push_back(a);
}
/*
Method: add_connection

param: name of the first user, name of the second user
Adds a conenction between these two users if they do not have one

*/
int Network::add_connection(std::string s1, std::string s2) {
    int firstID =0;
    if (s1 != s2) {
        for (int i = 0; i < Network::users_.size(); i++) {
            if (Network::users_[i]->get_fullName() == s1) {
                firstID = i;
                break;
            }
            else if(i == Network::users_.size()-1) {
                std::cout << "first name exists";
                return -1;
            }
        }
        for (int i = 0; i < Network::users_.size(); i++) {
            if (Network::users_[i]->get_fullName() == s2) {
                Network::users_[i]->add_friend(Network::users_[firstID]->get_id());
                Network::users_[firstID]->add_friend(Network::users_[i]->get_id());
                return 0;
            }

            else if (i == users_.size() - 1) {
                std::cout << "second name exists";
                return -1;
            }
        }
        return -1;

    }
    return -1;
}
/*
Method: remove_connection

param: name of the first user, name of the second user
Remove a conenction between these two users

*/
int Network::remove_connection(std::string s1, std::string s2) {
    int firstID = 0;
    if (s1 != s2) {
        for (int i = 0; i < Network::users_.size(); i++) {
            if (Network::users_[i]->get_fullName() == s1) {
                firstID = i;
                break;
            }
            else if (i = Network::users_.size() - 1) {
                std::cout << "first name exists";
                return -1;
            }
        }
        for (int i = 0; i < Network::users_.size(); i++) {
            if (Network::users_[i]->get_fullName() == s2) {
                Network::users_[i]->delete_friend(Network::users_[firstID]->get_id());
                Network::users_[firstID]->delete_friend(Network::users_[i]->get_id());
                return 0;
            }

            else if (i = Network::users_.size() - 1) {
                std::cout << "second name exists";
                return -1;
            }
        }

        return -1;
    }
    return -1;
}
/*
Method: get_id

param: name of User
returns ID of User
*/
int Network::get_id(std::string name) {
    for (int i = 0; i < Network::users_.size(); i++) {
        //std::cout<<Network::users_[i]->get_id()<<std::endl;
        if (Network::users_[i]->get_fullName() == name) {
            return Network::users_[i]->get_id();
        }
    }
    return -1;
}

/*
Method: num_users

param: none
returns the number of users
*/
std::size_t Network::num_users() {
    return users_.size();
}
/*
Method: print_users

param: none
prints out all the Users in the Network
*/
void Network::print_users() {
    for (int i = 0; i < users_.size(); i++) {
        std::cout << users_[i]->get_id() << " " << users_[i]->get_fullName() << " "
                  << users_[i]->get_birthYear() << " " << users_[i]->get_zipCode() << " " << std::endl;
        for(int j=0; j<users_[i]->get_connections().size();j++)
            std::cout <<users_[i]->get_connections()[j]<<" ";

        std::cout<<std::endl;

    }
}
void Network::print_friends(std::size_t id) {
    for (int i = 0; i < users_.size(); i++) {
        if (users_[i]->get_id() == id) {
            for (int j = 0; j < users_[i]->get_connections().size(); j++) {
                for (int k = 0; k < users_.size(); k++) {
                    if (users_[k]->get_id() == users_[i]->get_connections()[j]) {
                        std::cout << users_[k]->get_id() << " " << users_[k]->get_fullName() << " "
                                  << users_[k]->get_birthYear() << " " << users_[k]->get_zipCode() << " " << std::endl;
                    }
                }

            }
            break;
        }
    }
}
/*
Method: get_users

param: none
returns a list of all the Users in the Network
*/
std::vector<User*> Network::get_users()
{
    return Network::users_;
}/*
Method: get_user

param: ID of a User
returns the User if they exist, otherwise returns an empty User
*/

User* Network::get_user(std::size_t id) {
    for(auto it : users_){
 //       std::cout<<it.get_id()<<std::endl;
        if(it->get_id()== id){
            return it;
        }
    }
    return new User();
}
/*
Method: shortest_path

param: from which ID to what ID
returns a vector of the IDs of the shortest path of people to said User. Otherwise if there is no path returns an empty vector
*/
std::vector<int> Network::shortest_path(int from, int to) {
    std::set<size_t> visited;
    std::queue<size_t> q;
    std::vector<int> path;
    q.push(from);
    int predecessor;
    visited.insert(from);
    if (from == to) {
        std::vector<int> one;
        one.push_back(1);
        return one;
    }
    for (int i = 0; i < users_.size(); i++) {
        if (users_[i]->get_id() == from) {
            while (!q.empty()) {
                int value = q.front();
                for (int i = 0; i < users_.size(); i++) {
                    if (value == users_[i]->get_id()) {
                        value = i;
                        break;
                    }
                    if (i = users_.size() - 1) {
                        return path;
                    }
                }
                q.pop();
                for (auto vx : users_[value]->get_connections()) {
                    int vxsub;
                    for (int i = 0; i < users_.size(); i++) {
                        if (vx == users_[i]->get_id()) {
                            vxsub = i;
                            break;
                        }
                    }
                    if (vx == to) {
                        users_[vxsub]->change_depth(users_[value]->get_depth() + 1);
                        users_[vxsub]->change_predecessor(value);
                        break;
                    }
                    else if (visited.count(vx) == 0) {
                        q.push(vx);
                        std::cout << std::endl<<vx;
                        visited.insert(vx);
                        users_[vxsub]->change_depth(users_[value]->get_depth() + 1);
                        users_[vxsub]->change_predecessor(value);
                    }


                }

            }

            break;
        }
        else {
            std::cout << "None" << std::endl;
            return path;
        }

    }
    int toInt;
    for (int i = 0; i < users_.size(); i++) {
        if (to == users_[i]->get_id()) {
            toInt = i;
            break;
        }
    }
    path.push_back(users_[toInt]->get_id());
    predecessor = users_[toInt]->get_predecessor();
    for (int j = 0; j < users_[toInt]->get_depth() - 1; j++) {

        path.push_back(users_[predecessor]->get_id());
        predecessor = users_[predecessor]->get_predecessor();

    }
    return path;
}
/*
Method: distance_user

param: Starting ID, Id of someone in that distance, and the distance to go to
returns a vector with a path of that person
*/
std::vector<int> Network::distance_user(size_t from, std::size_t& to, std::size_t distance) {
    std::set<size_t> visited;
    int id = -1;
    std::queue<size_t> q;
    std::vector<int> path;
    q.push(from);
    bool notF = false;
    int predecessor;
    visited.insert(from);
    if (from == to) {
        std::vector<int> one;
        one.push_back(1);
        return one;
    }


    while (!q.empty()) {
        size_t value = q.front();
        for (int i = 0; i < users_.size(); i++) {
            if (value == users_[i]->get_id()) {
                value = i;
                break;
            }
            if (i = users_.size() - 1) {
                to = -1;
                return path;
            }
        }
        q.pop();
        for (auto vx : users_[value]->get_connections()) {
            int vxsub;
            for (int i = 0; i < users_.size(); i++) {
                if (vx == users_[i]->get_id()) {
                    vxsub = i;
                    break;
                }
            }
            if (visited.count(vx) == 0) {
                q.push(vx);
                visited.insert(vx);
                users_[vxsub]->change_depth(users_[value]->get_depth() + 1);
                users_[vxsub]->change_predecessor(value);
            }


            if (users_[vxsub]->get_depth() == distance) {
                for (int j = 0; j < users_[vxsub]->get_connections().size(); j++) {
                    if (users_[vxsub]->get_connections()[j] == from) {
                        bool notF = false;
                        break;
                    }
                    bool notF = true;


                }
                if (bool notF = true) {
                    id = users_[vxsub]->get_id();
                    break;
                }
            }


        }
        if (id > -1) {
            break;
        }

    }

    for (int i = 0; i < users_.size(); i++) {
        if (id == users_[i]->get_id()) {
            id = i;
            break;
        }
    }
    path.push_back(users_[id]->get_id());
    int toInt;
    for (int i = 0; i < users_.size(); i++) {
        if (to == users_[i]->get_id()) {
            toInt = i;
            break;
        }
    }
    predecessor = users_[toInt]->get_predecessor();
    for (int j = 0; j < users_[toInt]->get_depth() - 1; j++) {

        path.push_back(users_[predecessor]->get_id());
        predecessor = users_[predecessor]->get_predecessor();

    }
    return path;
}
/*
Method: groups

param: none
returns a vector of vectors of groups of people that have no link to each other.
*/
std::vector<std::vector<std::size_t> > Network::groups() {
    std::set<size_t> visited;
    std::vector<std::vector<std::size_t> > groups;
    std::vector<std::size_t> subgroup;
    std::queue<size_t> q;
    std::vector<User> path;
    q.push(0);
    int predecessor;
    while (visited.size() != users_.size()) {
        if (q.empty()) {
            for (int i = 0; i < users_.size(); i++) {
                if (visited.count(i) == 0) {
                    q.push(i);
                    break;
                }

            }

        }
        while (!q.empty()) {
            size_t value = q.front();

            q.pop();
            for (auto vx : users_[value]->get_connections()) {

                if (visited.count(vx) == 0) {
                    q.push(vx);
                    visited.insert(vx);
                    subgroup.push_back(vx);
                }


            }

        }
        groups.push_back(subgroup);
        subgroup.clear();

    }
    return groups;
}
/*
Method: suggest_friends

param: which person to suggest and how far down the line of aquantences
returns a vector of IDs for suggested friends.
*/
std::vector<int> Network::suggest_friends(std::size_t who, std::size_t& score) {
    std::unordered_map<int,int> m;
    m[who] = -1;
    int mx = -1;
   std::vector<int> ret;

    User* source = get_user(who);
   for(auto it:source->get_connections()) m[it] = -1;
   for(auto it:source->get_connections()){
        for(auto it2:get_user(it)->get_connections()){
            if(m.find(it2) != m.end()){
                if(m[it2] == -1) continue;
                m[it2]++;
            } else{
                m[it2] = 1;
            }
            if(mx <= m[it2]){
                if(mx != m[it2]) ret.clear();
                mx = m[it2];
                ret.push_back(it2);
            }
        }
    }
    score = mx;
    return ret;
}
/*
Method: groups

param: Id of the user the post is being sent to, the message, how many likes, whether it is an incoming message, the name of the author, and whether it is public
adds a post to the user.
*/
void Network::add_post(std::size_t ownerId, std::string message, std::size_t likes, bool incoming, std::size_t author, bool isPublic) {
    if (incoming == false) {

        Post* newPost = new Post(ownerId, message, likes);
        get_user(ownerId)->add_post(newPost);
        if(get_user(author)->get_fullName()=="Leo Griffin")
            std::cout<<get_user(ownerId)->display_posts(1,false)<<" check"<<std::endl;
    }
    else {
           // std::cout<<message<<" check"<<std::endl;
        //IncomingPost a(ownerId, message, likes, isPublic, get_user(author)->get_fullName());
        Post* newPost = new IncomingPost(ownerId, message, likes, isPublic, get_user(author)->get_fullName());
        get_user(ownerId)->add_post(newPost);
        if(get_user(author)->get_fullName()=="Leo Griffin")
        std::cout<<get_user(ownerId)->display_posts(1,true)<<" check"<<std::endl;
    }
}
/*
Method: display_posts

param: whose posts to show, how many posts and whether to only show public
returns a string of all messages.
*/
std::string Network::display_posts(std::string name, std::size_t howmany, bool showonlypublic) {
    for (int i = 0; i < users_.size(); i++) {
        if (users_[i]->get_fullName() == name) {
            return users_[i]->display_posts(howmany, showonlypublic);
        }
    }
    return "Failed to get User";
}
/*
Method: read_posts

param: the filename
reads the file of messages and writes it to the users.
*/
int Network::read_posts(std::string filename) {
    std::ifstream input(filename);
    if (input.is_open() == false) {
        std::cout << "No file exists";
        return -1;
    }
    std::string x;
    std::string nummsg;
    std::size_t ownerId;
    std::string message;
    std::size_t likes;
    std::string author;
    bool isPublic = true;
    getline(input, nummsg);
    int i = stoi(nummsg);
    for (int j = 0; j < i; j++) {
        getline(input, x);
        getline(input, message);
        getline(input, x);
     //   std::cout<<x<<" what the fuck"<<std::endl;
        likes = stoi(x);
        getline(input, x);
       // std::cout<<x<<" what the fuck"<<std::endl;
        ownerId = stoi(x);
        getline(input, x);
        std::stringstream sn(x);
        std::string isP;
        sn>>isP;
        //std::cout<<isP<<std::endl;
        //  std::cout<<x<<" what the fuck"<<std::endl;
        if (isP == "public"){
            isPublic == true;
        getline(input, author);
            std::stringstream fn(author);
            std::string fname,lname;
            fn >> fname >> lname;
            std::string fullname = fname+" "+lname;
          //  std::cout<<author<<" what the fuck"<<std::endl;
            add_post(ownerId, message, likes, true, get_id(fullname), isPublic);
        }
        else if (isP == "private"){
            isPublic == false;
        getline(input, author);
            std::stringstream fn(author);
            std::string fname,lname;
            fn >> fname >> lname;
            std::string fullname = fname+" "+lname;
              //std::cout<<fullname<<" ."<<std::endl;
            add_post(ownerId, message, likes, true, get_id(fullname), isPublic);
              //std::cout<<get_id(fullname)<<" ."<<std::endl;

        }
        else{
        add_post(ownerId, message,likes, false, 0, true);
        }

    }

    return i;

}




