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

#include "Periodical.hpp"
#include "Media.hpp"

//--------------------------------------------------------------------------------

// Paramaterized constructor
Periodical :: Periodical(const std::string cn,    const std::string t,          const std::string sub, const std::string auth,  const std::string desc,
                         
                         const std::string pub,   const std::string pubHistory, const std::string ser, const std::string notes, const std::string rt,
                         
                         const  std::string ofot, const std::string gdn )

            : Media(cn, t, sub, notes),

            author(auth), description(desc), publisher(pub), publishing_history(pubHistory),
            series(ser), related_titles(rt), other_forms_of_title(ofot), govt_doc_number(gdn) {}

// ----------------------------------------------------------------------------------------------------
// Determine if keyword is present in description, notes, series and related titles
bool Periodical :: Contains_Other(std::string other)
{
    return true;
}

// ----------------------------------------------------------------------------------------------------
// Print criteria from periodical record(s)
void Periodical :: Print(SEARCH_TYPE search, std::vector<Media*> Library_Records)
{
    switch(search)
    {
        case CALL_NUMBER:
        {
            if(!Library_Records.empty())
            {
                std::cout << "\n---------------------------------------------------------------------- Periodical ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Publishing History: " << Library_Records[i] -> GetPublishingHistory() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Related Titles: " << Library_Records[i] -> Get_Related_Titles() << "\n";
                    
                    std::cout << "Other Forms Of Titles: " << Library_Records[i] -> Other_Forms_Of_Titles() << "\n";
                    
                    std::cout << "Govt Doc Number: " << Library_Records[i] -> Get_Govt_Doc_Number() << "\n\n";
                    
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
                std::cout << "\n---------------------------------------------------------------------- Periodical ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Publishing History: " << Library_Records[i] -> GetPublishingHistory() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Related Titles: " << Library_Records[i] -> Get_Related_Titles() << "\n";
                    
                    std::cout << "Other Forms Of Titles: " << Library_Records[i] -> Other_Forms_Of_Titles() << "\n";
                    
                    std::cout << "Govt Doc Number: " << Library_Records[i] -> Get_Govt_Doc_Number() << "\n\n";
                    
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
                std::cout << "\n---------------------------------------------------------------------- Periodical ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Publishing History: " << Library_Records[i] -> GetPublishingHistory() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Related Titles: " << Library_Records[i] -> Get_Related_Titles() << "\n";
                    
                    std::cout << "Other Forms Of Titles: " << Library_Records[i] -> Other_Forms_Of_Titles() << "\n";
                    
                    std::cout << "Govt Doc Number: " << Library_Records[i] -> Get_Govt_Doc_Number() << "\n\n";
                    
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
                std::cout << "\n---------------------------------------------------------------------- Periodical ----------------------------------------------------------------------\n\n";
                
                for(std::vector<Media*> :: size_type i = 0; i < Library_Records.size(); i++)
                {
                    std::cout << "Description: " << Library_Records[i] -> GetDescription() << "\n";
                    
                    std::cout << "Notes: " << Library_Records[i] -> GetNotes() << "\n";
                    
                    std::cout << "Series: " << Library_Records[i] -> GetSeries() << "\n";
                    
                    std::cout << "Related Titles: " << Library_Records[i] -> Get_Related_Titles() << "\n";
                    
                    std::cout << "Call Number: " << Library_Records[i] -> GetCallNumber() << "\n";
                    
                    std::cout << "Title: " << Library_Records[i] -> GetTitle() << "\n";
                    
                    std::cout << "Subject: " << Library_Records[i] -> GetSubject() << "\n";
                    
                    std::cout << "Author: " << Library_Records[i] -> GetAuthor() << "\n";
                    
                    std::cout << "Publisher: " << Library_Records[i] -> GetPublisher() << "\n";
                    
                    std::cout << "Publishing History: " << Library_Records[i] -> GetPublishingHistory() << "\n";
                    
                    std::cout << "Other Forms Of Titles: " << Library_Records[i] -> Other_Forms_Of_Titles() << "\n";
                    
                    std::cout << "Govt Doc Number: " << Library_Records[i] -> Get_Govt_Doc_Number() << "\n\n";
                    
                    if(i != Library_Records.size() - 1)
                        std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                }

                break;
            }
        }
    }
}

//----------------------------- Accessor Functions -----------------------------

std::string Periodical :: GetAuthor() const
{
    return author;
}

std::string Periodical :: GetPublisher() const
{
    return publisher;
}

std::string Periodical :: GetPublishingHistory() const
{
    return publishing_history;
}

std::string Periodical :: GetSeries() const
{
    return series;
}

std::string Periodical :: GetDescription() const
{
    return description;
}

std::string Periodical :: Get_Related_Titles() const
{
    return related_titles;
}

std::string Periodical :: Other_Forms_Of_Titles() const
{
    return other_forms_of_title;
}

std::string Periodical :: Get_Govt_Doc_Number() const
{
    return govt_doc_number;
}

std::string Periodical :: GetCity() const
{
    return "";
}

std::string Periodical :: GetDirector() const
{
    return "";
}

std::string Periodical :: GetYear() const
{
    return "";
}

std::string Periodical :: GetLabel() const
{
    return "";
}

std::string Periodical :: GetDistributor() const
{
    return "";
}

//-------------------------------------------------------------------------
