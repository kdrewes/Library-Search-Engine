/*
*************************************************************************
 Title: Library Design
                                                                        
 Author: Kyle Drewes
                    
 Date: 9/5/2025
 
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

#ifndef Film_hpp
#define Film_hpp

#include <stdio.h>
#include <iostream>
#include "Media.hpp"

typedef std::string field;

class Film : public Media
{
private:

// Film criteria
field director,
      year,
      notes;

public:
    
    // Paramaterized constructor
    Film(std::string callNumber, std::string title, std::string subject, std::string director, std::string notes, std::string year);
    
    // Determine if keyword is present in notes, director and year
    bool Contains_Other(std::string other) override;
    
    // Print criteria from film record(s)
    void Print(SEARCH_TYPE search, std::vector<Media*> Library_Records) override;
    
    //----------------------------- Accessor Functions -----------------------------
    
    std::string GetAuthor() const override;
    
    std::string GetDirector() const override;
    
    std::string GetDescription() const override;
    
    std::string GetPublisher() const override;
    
    std::string GetPublishingHistory() const override;
    
    std::string Get_Related_Titles() const override;
    
    std::string Other_Forms_Of_Titles() const override;
    
    std::string Get_Govt_Doc_Number() const override;
    
    std::string GetCity() const override;
    
    std::string GetYear() const override;
    
    std::string GetSeries() const override;
    
    std::string GetLabel() const override;
    
    std::string GetDistributor() const override;
    
    std::string GetNotes() const;
    
};


#endif 
