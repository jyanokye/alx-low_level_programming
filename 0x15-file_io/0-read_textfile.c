#include "main.h"

/**
 *read_textfile - reads a textfile and prints
 * it to the POSIX standard output
 * @filename: path to the file to the textfile
 * @letters: number of letters to be read and printed out
 *
 * Return: The actual number of letters it could read and print.
 * if the file can not be opened or read, return 0.
 * if filename is NULL, return 0.
 * if write fails or does not write the expected amount of bytes,
 * return 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t rd, wr;
	char *buff;

	int fd = open(filename, O_RDWR);

	if (filename == NULL)
		return (0);

	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);
			
	rd = read(fd, buff, letters);

	if (rd == -1)
		return (0);

	wr = write(STDOUT_FILENO, buff, rd)
	
	if (wr == -1 || wr != rd)
		return (0);
	close(fd);
	free(buff);
	return (wr);
}
