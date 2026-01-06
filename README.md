*This activity has been created as part of the 42 curriculum by klafi*

# Description
Repeated calls (e.g., using a loop) to get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
# Instructions
You can use the function `char *get_next_line(int fd)` by compiling both get_next_line.c and get_next_line_utils.c with your main.c file.
To modify the value of the buffer size whom `read` writes onto add this flag to your cc statement : `-D BUFFER_SIZE=n`.
# Resources
- 42-Curriculum PDFs
- Peer collaboration
- AI; it was used mildly for debugging and mere explanation of some ideas. **_No code was written by it_**.
# Algorithm Used
GNL uses a static buffer(with a fixed size of a macro called BUFFER_SIZE) whom `read` writes onto, a dynamically allocated char pointer is used to store each line content(including the \n).  
If BUFFER_SIZE is bigger than the line's length, the line is returned, and the rest of read bytes are still stored in the buffer.\
If BUFFER_SIZE is smaller than the line's length, multiple iterations occur until the whole line is stored in the dynamically allocated char pointer.\
If BUFFER_SIZE is equal to the line's length, then the line is returned with no remnant bytes in the buffer.  
A struct of the following structure :
```
typedef struct meow
{
    char    s[BUFFER_SIZE];
    int     len;
    int     idx;
}   t_buf;
```
s is the the buffer we use to which `read` writes all read bytes, len is the number of bytes read and stored into s, idx is used to know where are the remnants of the last function call.
> [!NOTE]
> s is not NULL-terminated
