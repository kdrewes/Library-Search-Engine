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

#include "Media.hpp"
#include "Book.hpp"
#include <vector>

// ----------------------------------------------------------------------------------------------------

// Paramaterized Constructor
Book :: Book (const std::string callNumber, const std::string title, const std::string subject, const std::string auth, const std::string desc,
              
              const std::string pub,        const std::string cty,   const std::string yr,      const std::string ser,  const std::string notes)

: Media(callNumber, title, subject, notes),

  author(auth), description(desc), publisher(pub), city(cty), year(yr), series(ser) {}

// ----------------------------------------------------------------------------------------------------
// Determine if keyword is present in description, notes and year
bool Book :: Contains_Other(const std::string keyword)
{
    if(description.find(keyword) != std::string::npos)
        return true;
    
    if(notes.find(keyword) != std::string::npos)
        return true;
    
    if(year.find(keyword) != std::string::npos)
        return true;
    
    return false;
}

// ----------------------------------------------------------------------------------------------------
// Print criteria from book record(s)
void Book :: Print(SEARCH_TYPE search, std::vector<Media*> Library_Records)
{
    switch(search)
    {
        case CALL_NUMBER:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Book ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n\n";
                    
                    if(i != Library_Records.size() - 1)
                       std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
            
        case TITLE:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Book ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n\n";
                    
                    if(i != Library_Records.size() - 1)
                       std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
            
        case SUBJECT:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Book ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n\n";
                    
                    if(i != Library_Records.size() - 1)
                       std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }

            
            break;
        }
            
        case OTHER:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Book ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n\n";
                    
                    
                    if(i != Library_Records.size() - 1)
                       std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
    }
    
}

//----------------------------- Accessor Functions -----------------------------

std::string Book :: GetAuthor() const
{
    return author;
}

std::string Book :: GetDescription() const
{
    return description;
}

std::string Book :: GetPublisher() const
{
    return publisher;
}

std::string Book :: GetCity() const
{
    return city;
}

std::string Book :: GetYear() const
{
    return year;
}

std::string Book :: GetSeries() const
{
    return series;
}

std::string Book :: GetNotes() const
{
    return notes;
}

std::string Book :: GetDirector() const
{
    return "";
}

std::string Book :: GetPublishingHistory() const
{
    return "";
}

std::string Book :: Get_Related_Titles() const
{
    return "";
}

std::string Book :: Other_Forms_Of_Titles() const
{
    return "";
}

std::string Book :: Get_Govt_Doc_Number() const
{
    return "";
}

std::string Book :: GetLabel() const
{
    return "";
}

std::string Book :: GetDistributor() const
{
    return "";
}

//------------------------------------------------------------------------
