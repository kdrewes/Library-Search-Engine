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

#include "Film.hpp"

// ----------------------------------------------------------------------------------------------------

// Paramaterized constructor
Film :: Film(const std::string cn, const std::string t, const std::string sub, const std::string dir, const std::string nts, const std::string yr)
: Media(cn, t, sub, nts),
director(dir), year(yr), notes(nts) {}

// ----------------------------------------------------------------------------------------------------
// Determine if keyword is present in notes, director and year
bool Film :: Contains_Other(const std::string keyword)
{
    if(notes.find(keyword) != std::string::npos)
        return true;
    
    if(year.find(keyword) != std::string::npos)
        return true;
    
    if(notes.find(keyword) != std::string::npos)
        return true;
    
    return false;
}
// ----------------------------------------------------------------------------------------------------
// Print criteria from film record(s)
void Film :: Print(SEARCH_TYPE search, std::vector<Media*> Library_Records)
{
    switch(search)
    {
        case CALL_NUMBER:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Film ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Director: " << Library_Records[i] -> GetDirector() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n\n";
                    
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
                std::cout << "\n---------------------------------------------------------------------- Film ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Director: " << Library_Records[i] -> GetDirector() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n\n";
                    
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
                std::cout << "\n---------------------------------------------------------------------- Film ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Director: " << Library_Records[i] -> GetDirector() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n\n";
                    
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
                std::cout << "\n---------------------------------------------------------------------- Film ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Director: " << Library_Records[i] -> GetDirector() << "\n";
                    
                    std::cout << "Year: " << Library_Records[i] -> GetYear() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n\n";
                    
                    if(i != Library_Records.size() - 1)
                       std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
    }
    
}

//----------------------------- Accessor Functions -----------------------------

std::string Film :: GetYear() const
{
    return year;
}

std::string Film :: GetDirector() const
{
    return director;
}

std::string Film :: GetAuthor() const
{
    return "";
}

std::string Film :: GetDescription() const
{
    return "";
}

std::string Film :: GetPublisher() const
{
    return "";
}

std::string Film :: GetCity() const
{
    return "";
}

std::string Film :: GetSeries() const
{
    return "";
}

std::string Film :: GetNotes() const
{
    return "";
}

std::string Film :: GetPublishingHistory() const
{
    return "";
}
std::string Film :: Get_Related_Titles() const
{
    return "";
}

std::string Film :: Other_Forms_Of_Titles() const
{
    return "";
}

std::string Film :: Get_Govt_Doc_Number() const
{
    return "";
}

std::string Film :: GetLabel() const
{
    return "";
}

std::string Film :: GetDistributor() const
{
    return "";
}

//------------------------------------------------------------------------
