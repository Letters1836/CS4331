#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <sys/wait.h>

// most printf() statements are comments are for testing

int main(int argc, char *argv[])
{
	// getting current directory
	char _curDir[PATH_MAX];
	getcwd(_curDir, sizeof(_curDir));

	while (1)
	{
		printf("fsh> ");

		char *_buffer = NULL;
		size_t _bufSize = 32;
		size_t _characters;
		getline(&_buffer, &_bufSize, stdin);

		// printf("%s", buffer);

		// getting arguments from shell
		_buffer[strlen(_buffer) - 1] = 0; // remove \n from end of _buffer
		if (strcmp(_buffer, "") == 0) // if there is no input, go to the end
		{
			goto end;
		}

		int _argc = 0;
		char _delims[] = " \t";
		char *_token = strtok(_buffer, _delims);

		if (_token == NULL) // if there are only spaces, go to the end
		{
			goto end;
		}

		char *_cmd; // command
		char *_args[10]; // arguments
		memset(_args, 0, sizeof _args); // reset arguments

		while (_token != NULL)
		{
			if (_argc == 0)
			{
				_cmd = _token;
				// printf("command: %s\n", _cmd);
			}
			_args[_argc] = _token;
			// printf("argument: %s\n", _args[argc - 1]);

			_token = strtok(NULL, " ");
			_argc++;
		}

		// recognized commands
		char *_exit = "exit";
		char *_cd = "cd";

		if (strcmp(_cmd, _exit) == 0)
		{
			exit(0);
		}
		else if (strcmp(_cmd, _cd) == 0)
		{
			char _newPath[PATH_MAX] = ""; // prepare input
			strcat(_newPath, _args[1]); // get argument from user
			// printf("%s\n", _newPath);
			// printf("%d\n", chdir(_newPath));
			chdir(_newPath); // change directory
			getcwd(_curDir, sizeof(_curDir)); // replace current directory with new directory
			printf("New directory: %s\n", _curDir);
		}
		else
		{
			int _pid = fork(); // set child process PID

			if (_pid == 0) // if the child is running
			{
				execvp(_cmd, _args); // execute the inputted command with arguments
				fprintf(stderr, "Child process failed.\n");
			}
			else // if the child is over or the parent process
			{
				wait(NULL);
				// printf("Child exited\n");
			}
		}

		end: ; // goto point for error handling purposes
	}
}
