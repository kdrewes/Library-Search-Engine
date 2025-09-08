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

#ifndef Parse_hpp
#define Parse_hpp

#include <iostream>
#include <sstream>
#include <vector>
#include "Enum.hpp"

class Media;

// --------------------- Typedef ---------------------

// input = User input used to select menu options

// iterator = Used to traverse through data sets

// increment = Used as counter

typedef int input, iterator, incrementer;

// stringInput = User input in string format used to select menu options

// fileString = string utilized in file

typedef std::string stringInput, fileString;

class Parse
{
    
private:
    
    // Struct containing all field elements of book, periodicals, film & video
    struct FieldStruct
    {
        // Declare main field elements
        std::string callNumber,
        notes,
        subject,
        title,
        
        // Declare additional field elements
        author,
        city,
        description,
        director,
        distibutor,
        gov_doc_number,
        label,
        other_forms_of_titles,
        publisher,
        publishing_history,
        related_titles,
        series,
        year;
        
        // ------- Miscellaneous criteria -------
        
        // Key word inputted by user
        std::string keyword;
        
        // Determines if vertical bar has been detected
        bool isVerticalBar = false;
        
        // Determines switch statement should be skipped
        bool skipSwitchStatement = false;
        
        // Count # of matches detected in keyword
        int countMatches = 0,
        
        // Count spaces to see if record has ended
        countSpaces = 0;
        
    }   fieldPackage;
    
    // Declare keyword variable
    stringInput keyword;
    
    // Extract field from each record
    std::string field;
    
    // Used to select option from menu
    input selection;
    
    // Counter used to keep track of field indices in record demonstrated below:
    
    // Call Number, Title, Subjects, Author, Description, Publisher, City, Year, Series, Notes
    // |    0     |   1   |    2   |   3   |      4     |     5    |   6  |  7  |   8  |   9  |
    incrementer countIndex;
    
    //Boolean logic to determine if do-while loop is valid
    bool isValid;
    
    // Declare ifstream variable
    std::ifstream read;
    
    // Contains all library records containing keyword
    // Prints results in the following order: book.txt, film.txt. periodic.txt and video.txt
    std::vector <Media*> Library_Records;
    
    // Declare SEARCH_TYPE variable as class member
    SEARCH_TYPE search;
    
    // Declare MEDIA_TYPE variable as class member
    MEDIA_TYPE media;
    
    // Declare media object
    Media * m;
    
public:
    
    // Default constructor;
    Parse();
    
    // Initiate application
    void Boot();
    
    // Reset variables
    void Clear();
    
    // Displays header of application
    void Header();

    // Specifies the type of search user wishes to select
    void Menu();

    // Implements configurations
    void Router();

    // Executes logic
    void Controller();

    // Criteria is extracted from: book.txt, film.txt, periodic.txt and video.txt
    void Read_Media();
    
    // End application
    void End();

    // Input validation used to handle file discrepencies
    void Verify_Record(char character, FieldStruct & fieldPackage);

    // Determine if record is read.  Simultaneously, criteria is extracted when book.txt, film.txt, periodic,txt or video.txt is read
    bool isRecord(char isCharacter);

    // Determine if key word is detected in record
    bool keyWordFound();

    // Determine label utilized through SEARCH_TYPE enum
    void searchType(int selection);

    // Determine label utilized through MEDIA_TYPE enum
    void mediaType(const std::string fileName);

    // Determine label utilized through FIELD_TYPE enum
    FIELD_TYPE fieldType(const std::string fieldName);
    
    // Output object
    friend std::ostream & operator << (std::ostream &, Parse &);

    
};

#include <stdio.h>

#endif /* Parse_hpp */
