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

#ifndef Enums_h
#define Enums_h

#include<iostream>

// Labels used for media type
enum MEDIA_TYPE { BOOK, PERIODICAL, FILM, VIDEO, MEDIA_TYPE_ERROR };

// Labels used for search type
enum SEARCH_TYPE { CALL_NUMBER, TITLE, SUBJECT, OTHER, EXIT, SEARCH_TYPE_ERROR };

// Labels used for field type
enum FIELD_TYPE
{
    // Main enum fields
    CALL_NUMBER_FIELD,
    TITLE_FIELD,
    SUBJECT_FIELD,
    OTHER_FIELD,
    
    // Additional enum fields
    AUTHOR_FIELD,
    CITY_FIELD,
    DESCRIPTION_FIELD,
    DIRECTOR_FIELD,
    DISTRIBUTOR_FIELD,
    GOVT_DOC_NUMBER_FIELD,
    LABEL_FIELD,
    NOTES_FIELD,
    OTHER_FORMS_OF_TITLES_FIELD,
    PUBLISHER_FIELD,
    PUBLISHING_HISTORY_FIELD,
    RELATED_TITLE_FIELD,
    SERIES_FIELD,
    YEAR_FIELD,
    
    // Indicate error was detected
    FIELD_TYPE_ERROR
};

#endif
