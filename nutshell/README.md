Regarding the features we haven't implemented, the major two include the extra credit tilde expansion 
and file name completion. Also, we were unable to create a string that handles both alias and variable 
expansion at the same time. The alias and variable expansion also doesn't work when there are other characters.

The features in the second paragraph were completed by Anna Moody and the features in the third paragraph were completed by Darby Laurvick.

We were able to include wildcard matching both in the cd command and with non-builtin commands. This works (in accordance
to the spec) by replacing the wildcarded word with an alphabetically sorted list (array) of the matching files in the 
current directory. Environment variable expansion was also implemented in strings and within commands. The built-in 
commands regarding these environment variables: setenv, printenv, and unsetenv, were included in the nutshell to allow 
the user to create a new environment variable, print a list of the variables, and change a variable (except for HOME and PATH).
The cd command was also implemented to allow arguements, tilde, or no arguements, all working correctly, which can be seen
by the PWD environment variable equalling the return of the function pwd. Alias features were also included to be able 
