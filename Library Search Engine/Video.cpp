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

#include "Video.hpp"

// ----------------------------------------------------------------------------------------------------

// Paramaterized constructor
Video :: Video(std::string cn, std::string t, std::string sub, std::string desc,
             std::string distr, std::string nts, std::string ser, std::string labl)

: Media(cn, t, sub, nts),
description(desc), distributor(distr), notes(nts), series(ser), label(labl) {}

// ----------------------------------------------------------------------------------------------------
// Determine if keyword is present in description, notes and distributor
bool Video :: Contains_Other(std::string keyword)
{
    if(notes.find(keyword) != std::string::npos)
        return true;
    
    if(description.find(keyword) != std::string::npos)
        return true;
    
    if(distributor.find(keyword) != std::string::npos)
        return true;
    
    return false;
}

// ----------------------------------------------------------------------------------------------------
// Print criteria from video record(s)
void Video :: Print(SEARCH_TYPE search, std::vector <Media*> Library_Records)
{
    switch(search)
    {
        case CALL_NUMBER:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Video ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Label: " << Library_Records[i] -> GetLabel() << "\n\n";
                    
                    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
            
        case TITLE:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Video ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Label: " << Library_Records[i] -> GetLabel() << "\n\n";
                    
                    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
            
        case SUBJECT:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Video ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Label: " << Library_Records[i] -> GetLabel() << "\n\n";
                    
                    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
            
        case OTHER:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Video ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Distributor: " << Library_Records[i] -> GetDistributor() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Label: " << Library_Records[i] -> GetLabel() << "\n\n";
                    
                    if(i != Library_Records.size() - 1)
                        std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }
            
            break;
        }
    }
}

//----------------------------- Accessor Functions -----------------------------

std::string Video :: GetDescription() const
{
    return description;
}

std::string Video :: GetDistributor() const
{
    return distributor;
}

std::string Video :: GetNotes() const
{
    return notes;
}

std::string Video :: GetSeries() const
{
    return series;
}

std::string Video :: GetLabel() const
{
    return label;
}

std::string Video :: GetYear() const
{
    return "";
}

std::string Video :: GetDirector() const
{
    return "";
}

std::string Video :: GetAuthor() const
{
    return "";
}
std::string Video :: GetPublisher() const
{
    return "";
}

std::string Video :: GetCity() const
{
    return "";
}

std::string Video :: GetPublishingHistory() const
{
    return "";
}
std::string Video :: Get_Related_Titles() const
{
    return "";
}

std::string Video :: Other_Forms_Of_Titles() const
{
    return "";
}

std::string Video :: Get_Govt_Doc_Number() const
{
    return "";
}

//-------------------------------------------------------------------------
