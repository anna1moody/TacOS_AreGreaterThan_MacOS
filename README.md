# TacOS_AreGreaterThan_MacOS

features we haven't implemented
	Regarding the features we haven't implemented, the major two include the extra credit tilde expansion 
and file name completion. Also, we were unable to create a string that handles both alias and variable 
expansion at the same time. The alias and variable expansion also doesn't work when there are other characters 
in the string because the scanner returns the string when found. If there was more time, we would have tried to 
get this to work correctly. Another feature we were unable to include is running an executable via './filename' 
without using system().

features we have implemented
	We were able to include wildcard matching both in the cd command and with non-builtin. This works (in accordance
to the specs) by replacing the wildcarded word with an alphabetically sorted list (array) of the matching files in the 
current directory. Environment variable expansion was also implemented in strings and within commands. The built-in 
commands regarding these environment variables: setenv, printenv, and unsetenv, were included in the nutshell to allow 
the user to create a new environment variable, print a list of the variables, and change a variable (except for HOME and PATH).
The cd command was also implemented to allow arguements, tilde, or no arguements, all working correctly, which can be seen
by the PWD environment variable equalling the return of the function pwd. Alias features were also included to be able 
to create an alias, delete an alias, change an existing alias, and print the available aliases. Within these alias commands,
alias expansion was implemented solely to check for looping; this was done by creating a graph of each alias component and 
using a depth first search to look for a cycle/loop when the new alias is added. If the user were to complete the following 
commands: "alias a b", "alias b c", "unalias a", only alias a=b would be deleted. The creation of a graph for looping and implementing 
the expansion principles (for the first word and within strings) all combined to make this feature hard to complete.

	A simple feature that was included was the interpretation of PATH to be a list of colon-separated words.
Pipes and I/O redirection, however, were also difficult to include within the shell. The shell uses 2>&1 to connect the 
standard error.

The features in the second paragraph were completed by Anna and the features in the third paragraph were completed by Darby.