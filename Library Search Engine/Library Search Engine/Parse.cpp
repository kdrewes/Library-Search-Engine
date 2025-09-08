//
//  Parse.cpp
//  Library Search Engine
//
//  Created by kdrewes on 9/8/25.
//

#include <fstream>
#include <sstream>
#include "Parse.hpp"
#include "Media.hpp"
#include "Book.hpp"
#include "Periodical.hpp"
#include "Film.hpp"
#include "Video.hpp"

Parse :: Parse()
{
    keyword = "";
    
    selection = 0;
    
    bool isValid = false;
    
    Media * m = nullptr;
}

// -------------------------------------------------------------------------------------------
// Initiate application
void Parse :: Boot()
{
    
    // Repeat any input errors made by user
    do
        
    // Invoke input validation
        try
    {
        // Call router
        Router();
        
        // Indicate input validation has successfully passed
        isValid = true;
    }
    
    // Invalid argument which can still be corrected
    catch(std::invalid_argument exception)
    {
        std::cout << exception.what();
    }
    
    // Graceful degradation
    catch(std::ios_base::failure exception)
    {
        std::cout << exception.what();
        
        exit(1);
    }
    
    // Graceful degradation
    catch(std::runtime_error exception)
    {
        std::cout << exception.what();
        
        exit(1);
    }
    
    while(!isValid);
    
    // Extra spaces
    std::cout << std::endl << std::endl;
}

// -------------------------------------------------------------------------------------------
// Displays header of application
void Parse :: Header()
{
    // Determine if header was already displayed
    static bool isHeader = true;
    
    if(isHeader)
    {
        std::cout << "\n-----------------------------------------\n";
        std::cout << std::setw(35) << "Gavelton Library Search Engine\n";
        std::cout << "-----------------------------------------\n\n";
        
        isHeader = false;
    }
}

// -------------------------------------------------------------------------------------------
// Specifies the type of search user wishes to select
void Parse :: Menu()
{
    
    std::cout << "\t1) Call Number\t\t2) Title\n\n\t3) Subject\t\t\t4) Other\n\n\t5) Exit\n\n";
    
    std::cout << "-----------------------------------------\n";
}

// -------------------------------------------------------------------------------------------
// Implements configurations
void Parse :: Router()
{
    // Display header
    Header();
    
    // Display menu
    Menu();
    
    // Prompt user for selection
    std::cout << "Select: ";
    std::cin >> selection;
    
    // Implement controller
    Controller();
}

// -------------------------------------------------------------------------------------------
// Executes logic
void Parse :: Controller()
{
    // Assign value to search enum
    searchType(selection);
    
    // If user selects to exit program, or if exception is encountered
    switch(search)
    {
        case EXIT:
            std::cout << "\n\nProgram aborting\n\n";
            std::exit(0);
            
        case SEARCH_TYPE_ERROR:
            throw std::invalid_argument("\n\nError - invalid option\n\nPlease re-enter below:\n\n");
            
}
    // Add spacer
    std::cout << "\n-----------------------------------------\n\n";
    
    // Prompt user for selection
    std::cout << "Search keyword: ";
    std::cin >> this -> keyword;
    
    // Store file name in array
    const std::string fileName[] = {"book.txt", "periodic.txt", "film.txt", "video.txt"};
    
    // Traverse through fileName dataset
    for(iterator index = 0; index < sizeof(fileName) / sizeof(fileName[0]); index++)
    {
        // Read file
       read.open(fileName[index]);
        
       mediaType(fileName[index]);
        
        if(read.is_open())
            Read_Media();
        
        else
            throw std::runtime_error("\nError - " + std::string(fileName[index]) + " is unable to open\n\n");
    }
}

// -------------------------------------------------------------------------------------------
// Criteria is extracted from each Media Type: book.txt, film.txt, periodic.txt, video.txt
void Parse :: Read_Media()
{
    // Extract field from each record
    std::string field = "";
    
    // Counter used to keep track of field indices in record demonstrated below:
    
    // Call Number, Title, Subjects, Author, Description, Publisher, City, Year, Series, Notes
    // |    0     |   1   |    2   |   3   |      4     |     5    |   6  |  7  |   8  |   9  |
    incrementer countIndex = 0;
    
    // Traverse through file
    for(char character = ' '; !read.eof(); read.get(character))
    {
        // Criteria is extracted from: book.txt, film.txt, periodic.txt and video.txt based on search type
        if(isRecord(read, fieldPackage, media, character, field, countIndex))
            if(keyWordFound(fieldPackage, m, countIndex))
                Library_Records.push_back(m);

    }
    
    // Print records for each media type
    m -> Print (search,Library_Records);
    
    // Clear file
    Library_Records.clear();

    // Close file
    read.close();
}

// -------------------------------------------------------------------------------------------
// Input validation used to handle file discrepancies
void Parse :: Verify_Record(char character, Parse :: FieldStruct & fieldPackage)
{
    if (character == '|')
        fieldPackage.isVerticalBar = true;
    
    else if (fieldPackage.isVerticalBar)
    {
        if (character == ' ' || character == '|')
        {
            if (!fieldPackage.skipSwitchStatement)
                fieldPackage.skipSwitchStatement = true;
        }
        
        else
        {
            fieldPackage.isVerticalBar = false;
            
            if (fieldPackage.skipSwitchStatement)
                fieldPackage.skipSwitchStatement = false;
        }
    }
    
}

// -------------------------------------------------------------------------------------------
// Determine if full record is read.  Simultaneously, criteria is extracted when book.txt, film.txt, periodic,txt or video.txt is read
bool Parse :: isRecord(std::ifstream &read, FieldStruct & fieldPackage, MEDIA_TYPE media, char character, std::string & field, incrementer & countIndex)
{
    switch(media)
    {
        case BOOK:
        {
            // Input validation used to handle file discrepancies
            Verify_Record(character, fieldPackage);
            
            // Declare field names for media type: book
            const std::string fieldName[] =
            {
                "call number",
                "title",
                "subject",
                "author",
                "description",
                "distributor",
                "publisher",
                "city",
                "year",
                "series",
                "notes"
            };
            
            // End record after all data has been evaluated
            if (countIndex >= (sizeof(fieldName) / sizeof(fieldName[0])))
                return true;
            
            if (!fieldPackage.skipSwitchStatement)
            {
                switch (fieldType(fieldName[countIndex]))
                {
                    case CALL_NUMBER_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.callNumber = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.callNumber = field;
                            field = "";
                            return true;
                        }
                        else field += character;
                        return false;
                        
                    case TITLE_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.title = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.title = field;
                            field = "";
                            
                            return true;
                        }
                        else
                            field += character;
                        
                            return false;
                        
                    case SUBJECT_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.subject = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.subject = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else field += character;
                            return false;
                            
                    case AUTHOR_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.author = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.author = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                            return false;
                        
                    case DESCRIPTION_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.description = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.description = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                            return false;
                        
                    case DISTRIBUTOR_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.distibutor = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.distibutor = field;
                            
                            field = "";
                            return true;
                        }
                        
                        else
                            field += character;
                        
                            return false;
                        
                    case PUBLISHER_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.publisher = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.publisher = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case CITY_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.city = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.city = field;
                            
                            field = "";
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case YEAR_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.year = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.year = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case SERIES_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.series = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.series = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case NOTES_FIELD:
                        
                        if (character == '\n' || read.peek() == '\n')
                        {
                            fieldPackage.notes = field;
                            countIndex = 0;
                            
                            field = "";
                            
                            return true;
                        }
                        
                        else if (character == '|')
                        {
                            fieldPackage.notes = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case FIELD_TYPE_ERROR:
                        throw std::ios_base::failure
                        ("\n\nError - field, " + std::string(fieldName[countIndex]) +
                         ", not found during runtime\n\nPlease correct runtime error.\n\n"
                                                     );
                }
            }
            
            break;
        }
            
        case PERIODICAL:
        {
            // Input validation used to handle file discrepancies
            Verify_Record(character, fieldPackage);
            
            // Declare field names for media type: periodical
            const std::string fieldName[] =
            {
                "call number",
                "title",
                "subject",
                "author",
                "description",
                "publisher",
                "publishing history",
                "series",
                "notes",
                "related titles",
                "other forms of titles",
                "gov doc number"
            };
            
            // End record after all data has been evaluated
            if (countIndex >= (sizeof(fieldName) / sizeof(fieldName[0])))
                return true;
            
            if (!fieldPackage.skipSwitchStatement)
            {
                switch (fieldType(fieldName[countIndex]))
                {
                    case CALL_NUMBER_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.callNumber = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.callNumber = field;
                            field = "";

                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case TITLE_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.title = field;
                            countIndex += 1;
                            field = "";
                        }
                        else if (character == '\n')
                        {
                            fieldPackage.title = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case SUBJECT_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.subject = field;
                            countIndex+= 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.subject = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case AUTHOR_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.author = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.author = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case DESCRIPTION_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.description = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.description = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case PUBLISHER_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.publisher = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.publisher = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case PUBLISHING_HISTORY_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.publishing_history = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.publishing_history = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case SERIES_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.series = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.series = field;
                            
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case NOTES_FIELD:
                        
                        if (character == '\n' || read.peek() == '\n')
                        {
                            fieldPackage.notes = field;
                            countIndex = 0;
                            field = "";
                            
                            return true;
                        }
                        
                        else if (character == '|')
                        {
                            fieldPackage.notes = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case RELATED_TITLE_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.related_titles = field;
                            countIndex++;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.related_titles = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case OTHER_FORMS_OF_TITLES_FIELD:
                        
                        if (character == '|')
                        {
                            fieldPackage.other_forms_of_titles = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else if (character == '\n')
                        {
                            fieldPackage.other_forms_of_titles = field;
                            field = "";
                            
                            return true;
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case GOVT_DOC_NUMBER_FIELD:
                        
                        if (character == '\n' || read.peek() == '\n')
                        {
                            fieldPackage.gov_doc_number = field;
                            countIndex = 0;
                            field = "";
                            
                            return true;
                        }
                        
                        else if (character == '|')
                        {
                            fieldPackage.gov_doc_number = field;
                            countIndex += 1;
                            field = "";
                        }
                        
                        else
                            field += character;
                        
                        return false;
                        
                    case FIELD_TYPE_ERROR:
                        
                        throw std::ios_base::failure("\n\nError - field, " + std::string(fieldName[countIndex]) +
                        ", not found during runtime\n\nPlease correct runtime error.\n\n");
                }
            }
            
            break;
        }
            
        case FILM:
        {
            // Input validation used to handle file discrepancies
            Verify_Record(character, fieldPackage);
            
            // Declare field names for media type: Book
            const std::string fieldName [] =
            {
                "call number",
                "title",
                "subject",
                "director",
                "notes",
                "year"
            };
            
            // End record after all data has been evaluated
            if (countIndex >= (sizeof(fieldName) / sizeof(fieldName[0])))
                return true;
            
            
            switch(fieldType(fieldName[countIndex]))
            {
                case CALL_NUMBER_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.callNumber = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.callNumber = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else field += character;
                        return false;
                }
                    
                case TITLE_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.title = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.title = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                    
                        return false;
                }
                    
                case SUBJECT_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.subject = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.subject = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
                    
                case DIRECTOR_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.director = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.director = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
                    
                case NOTES_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.notes = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.notes = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
                    
                case YEAR_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.year = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.year = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
            }
            
            break;
        }
            
        case VIDEO:
        {
            // Input validation used to handle file discrepancies
            Verify_Record(character, fieldPackage);
            
            // Declare field names for media type: Book
            const std::string fieldName [] =
            {
                "call number",
                "title",
                "subject",
                "description",
                "distributor",
                "notes",
                "series",
                "label"
            };
            
            // End record after all data has been evaluated
            if (countIndex >= (sizeof(fieldName) / sizeof(fieldName[0])))
                return true;
            
            switch(fieldType(fieldName[countIndex]))
            {
                case CALL_NUMBER:
                {
                    if (character == '|')
                    {
                        fieldPackage.callNumber = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.callNumber = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;

                }
                    
                case TITLE:
                {
                    if (character == '|')
                    {
                        fieldPackage.title = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.title = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                    
                    break;
                }
                    
                case SUBJECT:
                {
                    if (character == '|')
                    {
                        fieldPackage.subject = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.subject = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
                    
                case DESCRIPTION_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.description = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.description = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
                    
                case DISTRIBUTOR_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.distibutor = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.distibutor = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
                    
                case NOTES_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.notes = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.notes = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
                    
                case SERIES_FIELD:
                {
                    if (character == '|')
                    {
                        fieldPackage.series = field;
                        countIndex += 1;
                        field = "";
                    }
                    
                    else if (character == '\n')
                    {
                        fieldPackage.series = field;
                        field = "";
                        
                        return true;
                    }
                    
                    else
                        field += character;
                        
                    return false;
                }
            }
            
            break;
        }
    }
    
    return true;
}

// -------------------------------------------------------------------------------------------
// Determine option through SEARCH_TYPE enum
bool Parse :: keyWordFound(FieldStruct &fieldPackage, Media * &m, incrementer &countIndex)
{
    // Update counter variable
    countIndex = 0;
    
    switch(media)
    {
        case BOOK:
        {
            
            switch(search)
            {
                case CALL_NUMBER:
                {
                    
                    // Instantiate Book object
                    m = new Book(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,
                                 fieldPackage.publisher, fieldPackage.city, fieldPackage.year, fieldPackage.series, fieldPackage.notes);
                    
                    // Determine if keyword contains call number from record
                    if(m -> Contains_Call_Number(keyword))
                        return true;
                    
                    break;
                }
   
                case TITLE:
                {
                    // Instantiate Book object
                    m = new Book(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,
                                 fieldPackage.publisher, fieldPackage.city, fieldPackage.year, fieldPackage.series, fieldPackage.notes);
                    
                    // Determine if keyword contains title from record
                    if(m -> Contains_Title(keyword))
                        return true;
     
                    break;
                }
                    
                case SUBJECT:
                {
                    // Instantiate Book object
                    m = new Book(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,
                                 fieldPackage.publisher, fieldPackage.city, fieldPackage.year, fieldPackage.series, fieldPackage.notes);
                    
                    // Determine if keyword contains subject from record
                    if(m -> Contains_Subject(keyword))
                        return true;
                    
                    break;
                }
                    
                
                    
                case OTHER:
                {
                    // Instantiate Book object
                    m = new Book(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,
                                 fieldPackage.publisher, fieldPackage.city, fieldPackage.year, fieldPackage.series, fieldPackage.notes);
                    
                    // Determine if keyword contains notes, description or year
                    if(m -> Contains_Other(keyword))
                        return true;
                    
                    break;
                }
                   
                    
                case SEARCH_TYPE_ERROR:
                    
                    throw std::runtime_error("\n\nError - unable to detect keyword " + std::string(keyword) + "\n\nError detected while reading book.txt\n\nPlease correct runtime error.\n\n");
            }
            
            break;
        }
            
        case PERIODICAL:
        {
            switch(search)
            {
                    
                case CALL_NUMBER:
                {
                    
                    // Instantiate Periodical object
                    m = new Periodical(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,fieldPackage.publisher, fieldPackage.publishing_history, fieldPackage.series, fieldPackage.notes, fieldPackage.title, fieldPackage.other_forms_of_titles, fieldPackage.gov_doc_number);
                    
                    // Determine if keyword contains call number from record
                    if(m -> Contains_Call_Number(keyword))
                        return true;

                    break;
                }
                case TITLE:
                {
                    // Instantiate Periodical object
                    m = new Periodical(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,fieldPackage.publisher, fieldPackage.publishing_history, fieldPackage.series, fieldPackage.notes, fieldPackage.title, fieldPackage.other_forms_of_titles, fieldPackage.gov_doc_number);
                    
                    // Determine if keyword contains title from record
                    if(m -> Contains_Title(keyword))
                        return true;
                    
                    break;
                }
                    
                case SUBJECT:
                {
                    // Instantiate Periodical object
                    m = new Periodical(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,fieldPackage.publisher, fieldPackage.publishing_history, fieldPackage.series, fieldPackage.notes, fieldPackage.title, fieldPackage.other_forms_of_titles, fieldPackage.gov_doc_number);
                    
                    // Determine if keyword contains title from record
                    if(m -> Contains_Subject(keyword))
                        return true;
                    
                    break;
                }
                    
                case OTHER:
                {
                    // Instantiate Periodical object
                    m = new Periodical(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.author, fieldPackage.description,fieldPackage.publisher, fieldPackage.publishing_history, fieldPackage.series, fieldPackage.notes, fieldPackage.title, fieldPackage.other_forms_of_titles, fieldPackage.gov_doc_number);
                    
                    // Determine if keyword contains notes, description or year
                    if(m -> Contains_Other(keyword))
                        return true;
                    
                    break;
                    
                case SEARCH_TYPE_ERROR:
                    
                    throw std::ios_base::failure( "\n\nError - unable to detect keyword " + std::string(keyword) + "\n\nError detected while reading periodic.txt\n\nPlease correct runtime error.\n\n");
                }
            }
            
            break;
        }
            
        case FILM:
        {
            switch(search)
            {
                case CALL_NUMBER:
                {
                    // Instantiate Periodical object
                    m = new Film(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.director, fieldPackage.notes, fieldPackage.year);
                    
                    // Determine if keyword contains title from record
                    if(m -> Contains_Call_Number(keyword))
                        return true;
                    
                    break;
                }
                    
                case TITLE:
                {
                    // Instantiate Periodical object
                    m = new Film(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.director, fieldPackage.notes, fieldPackage.year);
                    
                    // Determine if keyword contains title from record
                    if(m -> Contains_Title(keyword))
                        return true;
                    
                    break;
                }
                    
                case SUBJECT:
                    {
                        // Instantiate Periodical object
                        m = new Film(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.director, fieldPackage.notes, fieldPackage.year);
                        
                        // Determine if keyword contains title from record
                        if(m -> Contains_Subject(keyword))
                            return true;
                        
                        break;
                    }
                    
                case OTHER:
                {
                    // Instantiate Periodical object
                    m = new Film(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.director, fieldPackage.notes, fieldPackage.year);
                    
                    // Determine if keyword contains notes, description or year
                    if(m -> Contains_Other(keyword))
                        return true;
                    
                    break;
                }
                    
                case SEARCH_TYPE_ERROR:
                    
                    throw std::ios_base::failure( "\n\nError - unable to detect keyword " + std::string(keyword) + "\n\nError detected while reading film.txt\n\nPlease correct runtime error.\n\n");
                }
                    break;
            }
            
        case VIDEO:
            {
                switch(search)
                {
                    case CALL_NUMBER:
                    {
                        
                        // Instantiate Periodical object
                        m = new Video(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.description, fieldPackage.distibutor, fieldPackage.notes, fieldPackage.series, fieldPackage.label);
                        
                        // Determine if keyword contains title from record
                        if(m -> Contains_Call_Number(keyword))
                            return true;
                        
                        break;
                    }
                        
                    case TITLE:
                    {
                        // Instantiate Periodical object
                        m = new Video(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.description, fieldPackage.distibutor, fieldPackage.notes, fieldPackage.series, fieldPackage.label);
                        
                        // Determine if keyword contains title from record
                        if(m -> Contains_Title(keyword))
                            return true;
                        
                        break;
                    }
                        
                    case SUBJECT:
                    {
                        // Instantiate Periodical object
                        m = new Video(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.description, fieldPackage.distibutor, fieldPackage.notes, fieldPackage.series, fieldPackage.label);
                        
                        // Determine if keyword contains title from record
                        if(m -> Contains_Subject(keyword))
                            return true;
                        
                        break;
                    }
                        
                    case OTHER:
                    {
                        // Instantiate Periodical object
                        m = new Video(fieldPackage.callNumber, fieldPackage.title, fieldPackage.subject, fieldPackage.description, fieldPackage.distibutor, fieldPackage.notes, fieldPackage.series, fieldPackage.label);
                        
                        // Determine if keyword contains notes, description or year
                        if(m -> Contains_Other(keyword))
                            return true;
                        
                        break;
                    }
                        
                    case SEARCH_TYPE_ERROR:
                        
                        throw std::ios_base::failure( "\n\nError - unable to detect keyword " + std::string(keyword) + "\n\nError detected while reading video.txt\n\nPlease correct runtime error.\n\n");
                }
                
                break;
            }
            
        case MEDIA_TYPE_ERROR:
            {
                throw std::ios_base::failure( "\n\nError - unable to detect keyword " + std::string(keyword) + "\n\nPlease correct runtime error.\n\n");
            }
        }
    return false;
}

// -------------------------------------------------------------------------------------------
// Print records
void Parse :: Print()
{
    m -> Print(this -> search, this -> Library_Records);
}

// -------------------------------------------------------------------------------------------
// Determine option through SEARCH_TYPE enum
void Parse :: searchType(int selection)
{
    if(selection == 1)
        this -> search = SEARCH_TYPE :: CALL_NUMBER;
    
    else if(selection == 2)
        this -> search = TITLE;
    
    else if(selection == 3)
        this -> search = SEARCH_TYPE :: SUBJECT;
    
    else if(selection == 4)
        this -> search = SEARCH_TYPE :: OTHER;
    
    else if(selection == 5)
        this -> search = SEARCH_TYPE :: EXIT;
    
    else
        this -> search = SEARCH_TYPE :: SEARCH_TYPE_ERROR;
    
}

// -------------------------------------------------------------------------------------------
// Determine selected field through MEDIA_TYPE enum
void Parse :: mediaType(const std::string fileName)
{
    if(fileName == "book.txt")
        media = MEDIA_TYPE :: BOOK;
    
    else if(fileName == "periodic.txt")
        media = MEDIA_TYPE :: PERIODICAL;
    
    else if(fileName == "film.txt")
        media = MEDIA_TYPE :: FILM;
    
    else if(fileName == "video.txt")
        media = MEDIA_TYPE :: VIDEO;
    
    else
        media = MEDIA_TYPE :: MEDIA_TYPE_ERROR;
    
}

// -------------------------------------------------------------------------------------------
// Determine label utilized through FIELD_TYPE enum
FIELD_TYPE Parse :: fieldType(const std::string fieldName)
{
    // const std::string fieldName [] = {"call number", "title", "subject", "author", "description", "pubilsher", "city", "year", "series", "notes"};
    
    if(fieldName == "call number")
        return CALL_NUMBER_FIELD;
    
    else if(fieldName == "title")
        return TITLE_FIELD;
    
    else if(fieldName == "subject")
        return SUBJECT_FIELD;
    
    else if(fieldName == "author")
        return AUTHOR_FIELD;
    
    else if(fieldName == "city")
        return CITY_FIELD;
    
    else if(fieldName == "director")
        return DIRECTOR_FIELD;
    
    else if(fieldName == "distributor")
        return DISTRIBUTOR_FIELD;
    
    else if(fieldName == "description")
        return DESCRIPTION_FIELD;
    
    else if(fieldName == "gov doc number")
        return GOVT_DOC_NUMBER_FIELD;
    
    else if(fieldName == "label")
        return LABEL_FIELD;
    
    else if(fieldName == "notes")
        return NOTES_FIELD;
    
    else if(fieldName == "other forms of titles")
        return OTHER_FORMS_OF_TITLES_FIELD;
    
    else if(fieldName == "publisher")
        return PUBLISHER_FIELD;
    
    else if(fieldName == "publishing history")
        return PUBLISHING_HISTORY_FIELD;
    
    else if(fieldName == "related titles")
        return RELATED_TITLE_FIELD;
    
    else if(fieldName == "series")
        return SERIES_FIELD;
    
    else if(fieldName == "year")
        return YEAR_FIELD;
    
    return FIELD_TYPE_ERROR;
}
// -------------------------------------------------------------------------------------------
std::ostream & operator << (std::ostream &output, Parse &parser)
{
    parser.Boot();
    
    parser.Print();
    
    return output;
    
}
// -------------------------------------------------------------------------------------------
