========================================================================
    CONSOLE APPLICATION : ConsoleApplication1 Project Overview
========================================================================

Write a C++ program according to the following: 

Use a struct (e.g., AccessRecord) that contains a username, filename, and a timestamp.
Prompt the user for the name of a file.
Read in a list of Access Records from the file and store it in an array of structs.
Prompt the user for a start time and an end time for consideration.
Display a list of all files that were accessed during that period along with the users that accessed them.
When parsing the file, look for the following kinds of problems: 
Timestamps that begin with characters.
Timestamps that are less than 1,000,000,000.
Timestamps that are greater than 10,000,000,000.
Lines that are missing filenames, usernames, or timestamps (i.e., only have 2 items instead of 3).
Create a function, parseLine that accepts a line (a string) and populates a struct for the AccessRecord.
Create a function, parseFile, that parses the file one line at a time and passes that line to your parseLine function.
If an error occurs, in the parseLine function, throw an exception that is a string with the text: "Error parsing line: xxxx xxxx xxxx" (where xxxx xxxx xxxx is replaced by the actual text of the line that had the error). 
In the parseFile function, catch any errors, display the message, and move on to the next line. 

A few hints
A complete line can be read into a string via: getline(fin, myStr);
If you include the string stream library "sstream", you can take a string, and treat it like a stream (think "cin" or "fin"). For example: 

string line;
getline(fin, line);

// The current line is now stored in the variable "line"

stringstream ss;
ss.str(line); // load the line into "ss"

// We can now use "ss" just like cin, and fin

// For example, we can read variables from it:
long timeStamp;
ss >> timeStamp;

// We can also check for failures:
if (ss.fail())
{
    ...
}


Sample Output
The following is an example of output for this program: 

Enter the access record file: /home/cs165new/assign03a.txt
Error parsing line: students.txt pricem 10
Error parsing line: users.txt kevin_tomlinson 1442001032999

Enter the start time: 1442000000
Enter the end time: 1442332025

The following records match your criteria:

      Timestamp                File                User
--------------- ------------------- -------------------
     1442000124           house.pdf             jatkins
     1442210121        accounts.mdb     kevin_tomlinson
     1442300125        vacation.jpg            smitty83
End of records

Here is another example:

Enter the access record file: /home/cs165new/assign03c.txt
Error parsing line: house.pdf jatkins
Error parsing line: users.txt 1442001032
Error parsing line: burtons 1442588012

Enter the start time: 1442000000
Enter the end time: 1442332025

The following records match your criteria:

      Timestamp                File                User
--------------- ------------------- -------------------
     1442210121        accounts.mdb     kevin_tomlinson
     1442300125        vacation.jpg            smitty83
End of records