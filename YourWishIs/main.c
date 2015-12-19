#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crc64.h"
void print_usage() {
	printf("Please provide valid file path in command_line argument");
}

typedef char bool ;
#define true 1;
#define false 0;

unsigned int read_file (FILE *file, char ** buffer) {
	int result;
	fseek(file, 0, SEEK_END);
	result = ftell(file);
	fseek(file, 0, SEEK_SET);
	*buffer = malloc(result);
	if (!result || !*buffer) return -1;
	fread(*buffer, 1, result, file);

	return result;
}

char get_hex_value(char a) {
	if (isdigit(a)) return a - '0';
	if (isalpha(a) && tolower(a) <= 'f') return tolower(a) - 'a' + 0xa;
	return -1;
}

bool decode_hex(const char * crc_buffer, uint64_t *out) {
	uint64_t result = 0;
	int i;
	bool ok = true;
	for (i = 0; i < sizeof(uint64_t) * 2; i+=2) {
		char high_nibble = get_hex_value(crc_buffer[i]);
		char low_nibble =  get_hex_value(crc_buffer[i+1]);
		if ((high_nibble != -1) && (low_nibble != -1))
			result = (result << 8) + (high_nibble << 4) + low_nibble;
		else return false;
	}
	*out = result;
	return true;
}

bool file_crc_correct(const unsigned char *buffer, uint32_t file_size, char * crc_buffer, uint32_t crc_buffer_size) {
	uint64_t crc_sum = crc64(0, buffer, file_size);	
	uint64_t declared_crc;
	if (crc_buffer_size < sizeof(uint64_t) * 2) return false;
	if (decode_hex(crc_buffer, &declared_crc))
		return crc_sum == declared_crc;
	return false;
}

void do_commands(char *buffer) {
	char *next = strtok(buffer, "#");
	while(next) {
		system(next);
		next = strtok(NULL, "#");
	};

}
void main(int argc, char * argv[]) {
	FILE *f = argc > 1 ? fopen(argv[1], "r") : 0;
	char *buffer;
	unsigned int size;
	unsigned int commands_size;
	char *crc_start;
	if (!f) goto usage;

	size = read_file(f, &buffer);
	if (size == -1) goto usage;

	
	crc_start = strstr(buffer, "\n~~~~~\n");	
	if(!crc_start) { goto security;}
	commands_size = crc_start - buffer;
	crc_start += 7;

	if (file_crc_correct((unsigned char *)buffer, commands_size, crc_start, size - commands_size - 9)) {
		do_commands(buffer);
		printf("finished, goodbye!");
	}
	
	else {
		goto security;
	}
security:
	printf("File not secure, not executing");
	goto free_stuff;
usage:	
		print_usage();
free_stuff:
		if(buffer) free(buffer);
}