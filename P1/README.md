Project 1 - Unix Utilities
Christian Hakim
September 30, 2020
CS4331


ffcat

The ffcat function reads the contents of a specified file(s) and prints it to the terminal.
To use ffcat, type:

	prompt> ./ffcat [fileName]
	
More files can be read with one command.  To do so, append the file names to the end of the command as follows:

	prompt> ./ffcat [fileName1] [fileName2]

If no files are input, ffcat will return a message and the value 0.
If a file throws an error or does not exist, ffcat will return a message and the value 1.
Upon successful completion of the command, ffcat will return 0.


ffwc

The ffwc function returns the number of characters, words, and lines from a specified file(s).
To use ffwc, type:

	prompt> ./ffwc [fileName]

More files can be read with one command.  To do so, append the file names to the end of the command as follows:

	prompt> ./ffwc [fileName1] [fileName2]

When more than one file is read, ffwc will also include the total values for all the specified files.

If no files are input, ffwc will return a message and the value 0.
If a file throws an error or does not exist, ffwc will return a message and the value 1.
Upon successful completion of the command, ffwc will return 0.
