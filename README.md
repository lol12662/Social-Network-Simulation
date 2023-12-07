# Social-Network-Simulation
  C++ program utilizing QT to build a UI simulating a social network, including a friend list, post list and a way to add friends

# Installation
**1.** Open terminal.

**2.** Install gcc (g++) the C++ compiler.
   ```
   $ sudo apt install g++
   ```
**3.** Install build-essential. This package will also install libraries as well as the gcc compiler.
   ```
   $ sudo apt-get install build-essential
   ```
**4.** Check the gcc version.
   ```
   $ gcc –version
   ```

**1.** Create an account on QT and download QT Installer: https://www.qt.io/download
  
**2.** Run the Installer, log in![Screenshot 2023-12-07 122423](https://github.com/lol12662/Social-Network-Simulation/assets/111735090/cf767b82-533b-49c6-88eb-7395129ff388)

**3.** There will be several steps like agreeing to terms and conditions. Get through those, and when you come across Installation Folder, install in the intended location
  
![Screenshot 2023-12-07 122725](https://github.com/lol12662/Social-Network-Simulation/assets/111735090/98d3a923-562d-4b82-8f30-cc65c70615ed)

**4.** Afterwards, you will come across a list. Pick the latest versions for both Qt and Qt design studio
![Screenshot 2023-12-07 123010](https://github.com/lol12662/Social-Network-Simulation/assets/111735090/a43bae5b-1f37-43ff-a833-e6e099a21dcf)

**5.** Afterwards it should go through all the procesess and notify you when finished installing

# Files

### social_network.txt
File conisists of a starting number of how many people are ina social network, then followed by each person's:
ID
Name
Year of Birth
Zip Code
And a list of people's ids that they are friends with
```
148
0
	Aled Montes
	2009
	47309
	81 125 106 110 28 80 114 26 62 71 93 113 126 129 131
1
	Sandhya Krish
	2000
	31153
	141 88 53 96 26 95 127 15 42 59 84 91 98 100 129 135 143
2
	Haaris George
	2009
	63181
	80 76 115 145 40 44 53 94 110 113
3
	Alysha Gray
	1983
	08762
	69 64 81 123 38 136 119 101 50 20 49 121 128 147

```
###posts (1).txt
File consists of a number of posts, which include two types
The first contains only four elements:
The post number
The message of the post
the recipient
the number of likes

The second contains 6 elements:
The post number
The message of the post
the recipient
the number of likes
whether it is public or private
the sender of the post

```
200
0
	The llama couldn't resist trying the lemonade.
	132
	6

1
	He decided to live his life by the big beats manifesto.
	47
	1

2
	They wandered into a strange Tiki bar on the edge of the small beach town.
	106
	2
	public
	Aled Montes
3
	Flash photography is best used in full sunlight.
	31
	3
	private
	Kirsty Golden
```
### Local Header files
Header Files:

User.h

Post.h

IncompingPost.h

Network.h

socialnetworkui.h

### **User.h**

Sets the variables of the users according to the file above

ID

Name

Year of Birth

Zip Code

And a list of people's ids that they are friends with

It also has a function to later add a friend given an ID input

### **Network.h**

Uses a vector to store User objects

Creates a graph with the vertex being a user and the edges being the connections between users

Has a function to create a list of people to reccomend as friends to a user

### **Post.h**

Has the variables of the first type of post:

The message of the post

the recipient

the number of likes

### **IncompingPost.h**

Inhereits from post, has the variables:

The message of the post

the recipient

the number of likes

whether it is public or private

the sender of the post


### **socialnetworkui.h**

Has functions to input into a Ui, called slots.

This includes: 

A function to log in a user

A function to add friends through a button

A function to go to another user's profile

A function to go back to the logged in User

A funciton to undo changes and go back

UI is created in Qt, and the Ui of this program looks like thiS:

![Screenshot 2023-12-07 130413](https://github.com/lol12662/Social-Network-Simulation/assets/111735090/872d6c77-808c-487a-a563-9a51f1ec4814)


