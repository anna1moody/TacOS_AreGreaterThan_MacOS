
/*
//shell runs as a main.c

/*shell will:
	-print prompt
	-get a command
	-build a command table
	-execute the command
	-handle errors or exceptions
*/

/*shell runs in a loop and will never die. only exits when it
  it receives the bye command
*/

//code given by Helal
main() {
	shell_init();
	while (1) {
		printPrompt();
		Switch(CMD = getCommand()) {
		Case: BYE		exit();
		Case: ERRORS	recover_from_errors();
		Case: OK		processCommand();
		}
	}
}

shell_init() {
	//init all variables
	//define (allocate storage) for some var/tables
	//init all tables (alias table, command table)
	//get PATH environment variable (use getenv())
	//get HOME env variable (use getenv())
	//disable anything that can kill your shell
	//the shell should never die, only can be exit
	//do anything you feel should be done as init
}

getCommand() {
	init_scanner-and_parser(); //i wonder if he meant to do _ not -
	if (yyparse())
		understand_errors();
	else
		return(OK); //he put Return(OK)
}

recover_from_errors() {
	//find out if error occurred in middle of command,
	//that is, the command still has a "tail"
	//in this case you have to recover by "eating" the rest of command
	//to do this: you may want to use yylex() directly, or
	//handle clear things up in any other way
}

processCommand() {
	if (builtin)
		do_it(); //run built-in commands- no fork
				 //no exec; only you code + Unix
				 //system calls
	else
		execute_it(); //execute general commands
					  //using fork and exec
}

do_it() {
	//the cases are just what Helal tells you should be builtin
	switch (builtin) {
		case ALIAS...
		case CDHome...
		case CDPath...
		case UNALIAS...
		case SETENV...
	}
}

execute_it() {
	/*
	- Handle command execution, pipelining, i/o redirection,
	   and background processing
	- Utilize a command table whose components are
	   plugged in during parsing by yacc
	*/

	/* Check command accessibility and executability*/
	if (!Executable()) {
		//use access() system call
		nuterr("Command not Found");
		return;
	}

	/*Check io file existence in case of io-redirection*/
	if (check_in_file() == SYSERR) {
		nuterr("Can't read from: %s", srcf);
		return;
	}

	if (check_out_file() == SYSERR) {
		nuterr("Can't write to: %s", distf);
		return;
	}

	//Build up the pipeline (create and set up pipe end-points (using pipe, dup))
	//process background
}
