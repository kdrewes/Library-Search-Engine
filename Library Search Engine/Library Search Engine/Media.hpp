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

#ifndef Media_hpp
#define Media_hpp

#include <stdio.h>
#include <iostream>
#include "Enum.hpp"

class Media
{
    
private:
  
// Media criteria used in each class
std::string callNumber,
            title,
            subject,
            notes;
    
public:
    
    // Paramaterized constructor
    Media(const std::string callNumber, const std::string title, const std::string subjects, const std::string notes);
    
    
    virtual ~Media();
    
    // Determine if keyword is present in call number
    bool Contains_Call_Number(std::string callNumber),
    
    // Determine if keyword is present in title
         Contains_Title(std::string title),
    
    // Determine if keyword is present in subject
         Contains_Subject(std::string subject);
    
    //----------------------------- Virtual Functions -----------------------------
    virtual bool Contains_Other(std::string other) = 0;
    
    virtual void Print(SEARCH_TYPE search, std::vector<Media*> Library_Records) = 0;
    
    virtual std::string GetAuthor() const = 0;
    
    virtual std::string GetDescription() const = 0;
    
    virtual std::string GetDirector() const = 0;
    
    virtual std::string GetPublisher() const = 0;
    
    virtual std::string GetPublishingHistory() const = 0;
    
    virtual std::string GetCity() const = 0;
    
    virtual std::string GetYear() const = 0;
    
    virtual std::string GetSeries() const = 0;
    
    virtual std::string Get_Related_Titles() const = 0;
    
    virtual std::string Other_Forms_Of_Titles() const = 0;
    
    virtual std::string Get_Govt_Doc_Number() const = 0;
    
    virtual std::string GetDistributor() const = 0;
    
    virtual std::string GetLabel() const = 0;
    
    //----------------------------- Accessor Functions -----------------------------
    
    std::string GetCallNumber() const;
    
    std::string GetTitle() const;
    
    std::string GetSubject() const;
    
    std::string GetNotes() const;

};

#endif /* Media_hpp */
