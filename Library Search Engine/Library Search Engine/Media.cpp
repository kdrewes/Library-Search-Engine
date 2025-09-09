/*
*************************************************************************
 
 Title: Library Design
                                                                        
 Author: Kyle Drewes
                    
 Date: 9/8/2025
 
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

#include "Media.hpp"
#include <iostream>

//--------------------------------------------------------------------------------

// Paramaterized constructor
Media :: Media(const std::string cn, const std::string t, const std::string s, const std::string n)
: callNumber(cn), title(t), subject(s), notes(n) {}

Media :: ~Media()
{}

//--------------------------------------------------------------------------------

// Determine if keyword is present in call number
bool Media :: Contains_Call_Number(std::string keyword)
{
    return callNumber.find(keyword) != std::string::npos;
}

// Determine if keyword is present in title
bool Media :: Contains_Title(std::string keyword)
{
    return title.find(keyword) != std::string::npos;
}

// Determine if keyword is present in subject
bool Media :: Contains_Subject(std::string keyword)
{
    return subject.find(keyword) != std::string::npos;
}

//----------------------------- Accessor Functions -----------------------------

std::string Media :: GetCallNumber() const
{
    return callNumber;
}

std::string Media :: GetTitle() const
{
    return title;
}

std::string Media :: GetSubject() const
{
    return subject;
}

std::string Media :: GetNotes() const
{
    return notes;
}

//--------------------------------------------------------------------------------

