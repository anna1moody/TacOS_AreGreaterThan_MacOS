Regarding the features we haven't implemented, the major three include piping, the extra credit tilde expansion 
and file name completion. Also, we were unable to create a string that handles both alias and variable 
expansion at the same time. The alias and variable expansion also doesn't work when there are other characters.

The features in the second paragraph were completed by Anna Moody and the features in the third paragraph were completed by Darby Laurvick.

Anna Moody:
We were able to include wildcard matching both in the cd command and with non-builtin commands. This works (in accordance
to the spec) by replacing the wildcarded word with an alphabetically sorted list (array) of the matching files in the 
current directory. Environment variable expansion was also implemented in strings and within commands. The built-in 
commands regarding these environment variables: setenv, printenv, and unsetenv, were included in the nutshell to allow 
the user to create a new environment variable, print a list of the variables, and change a variable (except for HOME and PATH).
The cd command was also implemented to allow arguements, tilde, or no arguements, all working correctly, which can be seen
by the PWD environment variable equalling the return of the function pwd. Alias features were also included to be able 
to create an alias, delete an alias, change an existing alias, and print the available aliases (all corresponding to the commands
in the spec). Within these alias commands, alias expansion was implemented solely to check for looping; this was done by creating 
a graph of each alias component and using a depth first search to look for a cycle/loop when the new alias is added. If the user were 
to complete the following commands: "alias a b", "alias b c", "unalias a", only alias a=b would be deleted.

Darby Laurvick:
A simple feature that was included was the interpretation of PATH to be a list of colon-separated words.
We implemented non-built-in commands using recursion in our parser file. Essentially, our scanner recognizes words, passes them to 
the parser, which in turn places them in a table. Due to it's recursive nature, the table must be resorted to organize the commands 
and any arguments in the correct order to be executed. All of the non-built-in commands run through once function, named runBasic(), 
which searches the PATH variable for the paths to execute and implements forking to execute the commands and catches some errors - 
especially when a command does not exist. I/O redirection was easy to implement with non-built-in commands, with our scanner recognizing 
the carrot tokens and our table flagging for input and output, while specifying the files for input and output for executing the commands. 
In the same way, the >>, 2>file.txt, and 2>&1 constructs work, with specific handling occurring in our forking processes.
We attempted pipes, but did not get them to properly execute. We did all the ground work to make it happen but could not finish in time.
