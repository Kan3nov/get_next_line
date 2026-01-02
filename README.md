*This activity has been created as part of the 42 curriculum by klafi*

# Description
Repeated calls (e.g., using a loop) to get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
# Instructions
You can use the function get_next_line(int fd) by compiling both get_next_line.c and get_next_line_utils.c with your main.c file.
# Resources
- 42-Curriculum PDFs
- Peer collaboration
- AI; it was used mildly for explaining some somewhat ambiguous ideas. **_No code was written by it_**.
# Algorithm Used
The main data structure used in the code is Doubly Linked List. Each node contains a read string (of BUFFER_SIZE size) from the file. In each function call, it looks for the end of the current line or the end of the file, then it returns the line in string form. If EOF or \n haven't been found, new node that contains a read amount of bytes stored in a string is appended.

Linked List was used because of its dynamic nature; the length of the file and the length of the line aren't known, thus we need to dynamically extend our buffer to store the read line.