#include "shell.h"
#include <string.h>

extern char **environ;
/**
 * execute - executes the command
 * @cmd: command to run
 * Return: 0 on success1 -1 if cmd is exit and 1 on any other error
 */
int execute(char **cmd, char *main_path)
{
	char *command = (char *)*(cmd + 0);

	pid_t child_pid;
	int status;
	//main_path = (char *)malloc(sizeof(char *));

	if (strncmp("exit", cmd[0], 4) == 0)
		return (-1);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		strcat(main_path, "/");
		strcat(main_path, cmd[0]);
		execve(main_path, cmd, NULL);

		if (execve(main_path, cmd, NULL) == -1)
		{
			perror("Error");
		}
		/* if (strcmp("env", cmd[0]) == 0)
		{
			cmd = environ;
			for (; *cmd; cmd++)
			{
				_puts(*cmd);
				_puts("\n");
			}
		}
		if (strcmp("ls", cmd[0]) == 0)
		{
			cmd[0] = "/bin/ls";
			execve(cmd[0], cmd, NULL);
		}
		if (strcmp("echo", cmd[0]) == 0)
		{
			cmd[0] = "/bin/echo";
			execve(cmd[0], cmd, NULL);
		}
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error");
			exit(-1);
			} */
	}
	else
		wait(&status);

	return (0);
}
char* get_path(char* path)
{
	char *main_path;
	char* cutpath;
	cutpath = strtok(path, ":");
	while (cutpath != NULL)
	{
		if (!strcmp(cutpath, "/usr/bin"))
			main_path = cutpath;
		cutpath = strtok(NULL, ":");
	}
	return (main_path);
}


/**
 * main - main simple shell
 * @argc: number of arguments
 * @argv: list of command line arguments
 * Return: Always 0, -1 on error.
 */

int main(int argc, char **argv)
{

	int response;
	size_t bufsize = BUFSIZ;
	char **tokens = (char **)malloc(sizeof(char **) * bufsize);
	int isPipe = 0;
	char *buffer;
	char *path;
	char *main_path = (char *)malloc(sizeof(char *) * bufsize);

	if (argc >= 2)
	{
		/*TODO: Handle cases where there is no argument, only the command*/
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	path = getenv("PATH");
	main_path = get_path(path);

	do {
		if (isatty(fileno(stdin)))
		{
			isPipe = 1;
			_puts("cisfun#: ");
		}

		getline(&buffer, &bufsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		tokens = stringToTokens(buffer);
		//path = getenv("PATH");

		//main_path = get_path(path);
		//printf("%s", main_path);
		response = execute(tokens, main_path);
	} while (isPipe && response != -1);
	free(buffer);
	free(main_path);
	free(tokens);

	return (0);
}
