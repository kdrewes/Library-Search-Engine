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

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <iostream>
#include "Media.hpp"

typedef std::string field;

class Book : public Media
{
    
private:

// Book criteria
field author,
      description,
      publisher,
      city,
      year,
      series,
      notes;

public:
    
    // Paramaterized constructor
    Book(const std::string callNumber, const std::string title, const std::string subject, const std::string author, const std::string description,
         
         const std::string publisher,  const std::string city,  const std::string year,    const std::string series, const std::string notes);
    
    // Determine if keyword is present in description, notes and year
    bool Contains_Other(const std::string other) override;
    
    // Print criteria from book record(s)
    void Print(SEARCH_TYPE search, std::vector<Media*> Library_Records) override;
    
    //----------------------------- Accessor Functions -----------------------------
    
    std::string GetAuthor() const override;
    
    std::string GetDescription() const override;
    
    std::string GetDirector() const override;
    
    std::string GetPublisher() const override;
    
    std::string GetPublishingHistory() const override;
    
    std::string Get_Related_Titles() const override;
    
    std::string Other_Forms_Of_Titles() const override;
    
    std::string Get_Govt_Doc_Number() const override;
    
    std::string GetCity() const override;
    
    std::string GetYear() const override;
    
    std::string GetSeries() const override;
    
    std::string GetDistributor() const override;
    
    std::string GetLabel() const override;
    
    std::string GetNotes() const;
    
    friend class Parse;
 
};

#endif
