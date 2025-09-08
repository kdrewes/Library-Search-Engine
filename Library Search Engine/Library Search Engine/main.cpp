/*
*************************************************************************
 
 Title: Library Design
                                                                        
 Author: Kyle Drewes
                    
 Date: 9/7/2025
 
 Description: This program is designed to implement a library search
 engine.  The user has the ability to select from four different
 searches:
 
 • Call number
 • Title
 • Subject
 • Other
 
 The search engine will traverse through the following media types:
 
 • Book
 • Periodical
 • Film
 • Video
 
 and retreive the user's desired results.  For further questions
 please view instructions.  Thank you.
 
 *********************************************************************
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Parse.hpp"
#include "Media.hpp"
#include "Book.hpp"
#include "Periodical.hpp"
#include "Film.hpp"
#include "Video.hpp"
#include "Enum.hpp"


// -------------------------------------------------------------------------------------------

int main(int argc, const char * argv[])
{
    // Call parse object
    Parse p;
    
    // Output parse object
    std::cout << p;
   
    return 0;
}

