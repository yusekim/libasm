#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

char *ft_strcpy(char *dest, const char *src);
size_t ft_strlen(const char *str);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

void test_ft_strlen() {
	printf("Running strlen tests...\n");

	// Test Case 1: 정상 문자열
	{
		const char *str = "Hello, Assembly!";
		size_t result = ft_strlen(str);

		printf("\n===================================================================\n");
		printf("Test 1 - Normal String:\n");
		printf("Input: \"%s\"\n", str);
		printf("Expected: %zu\n", strlen(str));
		printf("Result: %zu\n", result);
		printf("Pass: %s\n\n", (result == strlen(str)) ? "Yes" : "No");
	}

	// Test Case 2: 빈 문자열
	{
		const char *str = "";
		size_t result = ft_strlen(str);

		printf("\n===================================================================\n");
		printf("Test 2 - Empty String:\n");
		printf("Input: \"%s\"\n", str);
		printf("Expected: %zu\n", strlen(str));
		printf("Result: %zu\n", result);
		printf("Pass: %s\n\n", (result == strlen(str)) ? "Yes" : "No");
	}

	// Test Case 3: 문자열에 특수 문자 포함
	{
		const char *str = "Line1\nLine2\tTabbed!";
		size_t result = ft_strlen(str);

		printf("\n===================================================================\n");
		printf("Test 3 - String with Special Characters:\n");
		printf("Input: \"%s\"\n", str);
		printf("Expected: %zu\n", strlen(str));
		printf("Result: %zu\n", result);
		printf("Pass: %s\n\n", (result == strlen(str)) ? "Yes" : "No");
	}

	// Test Case 4: 매우 짧은 문자열 (1글자)
	{
		const char *str = "A";
		size_t result = ft_strlen(str);

		printf("\n===================================================================\n");
		printf("Test 4 - Single Character String:\n");
		printf("Input: \"%s\"\n", str);
		printf("Expected: %zu\n", strlen(str));
		printf("Result: %zu\n", result);
		printf("Pass: %s\n\n", (result == strlen(str)) ? "Yes" : "No");
	}

	printf("All tests completed.\n");
}


void test_ft_strcpy() {
	printf("Running strcpy tests...\n");

	// Test Case 1: 정상 복사
	{
		char dest[100] = {0};
		const char *src = "Hello, Assembly!";
		char *result = ft_strcpy(dest, src);

		printf("\n===================================================================\n");
		printf("Test 1 - Normal Copy:\n");
		printf("Expected: %s\n", src);
		printf("Result: %s\n", dest);
		printf("Return Value: %s\n", result);
		printf("Pass: %s\n\n", (strcmp(dest, src) == 0 && result == dest) ? "Yes" : "No");
	}

	// Test Case 2: 빈 문자열 복사
	{
		char dest[100] = {0};
		const char *src = "";
		char *result = ft_strcpy(dest, src);

		printf("\n===================================================================\n");
		printf("Test 2 - Empty String:\n");
		printf("Expected: %s\n", src);
		printf("Result: %s\n", dest);
		printf("Return Value: %s\n", result);
		printf("Pass: %s\n\n", (strcmp(dest, src) == 0 && result == dest) ? "Yes" : "No");
	}

	// Test Case 3: 긴 문자열 복사
	{
		char dest[1000] = {0};
		const char *src = "This is a very long string to test the behavior of ft_strcpy for longer inputs.";
		char *result = ft_strcpy(dest, src);

		printf("\n===================================================================\n");
		printf("Test 3 - Long String:\n");
		printf("Expected: %s\n", src);
		printf("Result: %s\n", dest);
		printf("Return Value: %s\n", result);
		printf("Pass: %s\n\n", (strcmp(dest, src) == 0 && result == dest) ? "Yes" : "No");
	}

	printf("All tests completed.\n");
}

void test_ft_strcmp() {
	printf("Running strcmp tests...\n");

	// Test Case 1: 두 문자열이 동일한 경우
	{
		const char *s1 = "Hello, World!";
		const char *s2 = "Hello, World!";
		int result = ft_strcmp(s1, s2);

		printf("\n===================================================================\n");
		printf("Test 1 - Identical Strings:\n");
		printf("Input: \"%s\", \"%s\"\n", s1, s2);
		printf("Expected: %d\n", strcmp(s1, s2));
		printf("Result: %d\n", result);
		printf("Pass: %s\n\n", (result == strcmp(s1, s2)) ? "Yes" : "No");
	}

	// Test Case 2: 첫 번째 문자열이 더 큰 경우
	{
		const char *s1 = "Hello, Zorld!";
		const char *s2 = "Hello, World!";
		int result = ft_strcmp(s1, s2);

		printf("\n===================================================================\n");
		printf("Test 2 - First String Larger:\n");
		printf("Input: \"%s\", \"%s\"\n", s1, s2);
		printf("Expected: %d\n", strcmp(s1, s2));
		printf("Result: %d\n", result);
		printf("Pass: %s\n\n", (result == strcmp(s1, s2)) ? "Yes" : "No");
	}

	// Test Case 3: 첫 번째 문자열이 더 작은 경우
	{
		const char *s1 = "Hello, World!";
		const char *s2 = "Hello, Zorld!";
		int result = ft_strcmp(s1, s2);

		printf("\n===================================================================\n");
		printf("Test 3 - First String Smaller:\n");
		printf("Input: \"%s\", \"%s\"\n", s1, s2);
		printf("Expected: %d\n", strcmp(s1, s2));
		printf("Result: %d\n", result);
		printf("Pass: %s\n\n", (result == strcmp(s1, s2)) ? "Yes" : "No");
	}

	// Test Case 4: 빈 문자열 비교
	{
		const char *s1 = "";
		const char *s2 = "";
		int result = ft_strcmp(s1, s2);

		printf("\n===================================================================\n");
		printf("Test 4 - Empty Strings:\n");
		printf("Input: \"%s\", \"%s\"\n", s1, s2);
		printf("Expected: %d\n", strcmp(s1, s2));
		printf("Result: %d\n", result);
		printf("Pass: %s\n\n", (result == strcmp(s1, s2)) ? "Yes" : "No");
	}

	// Test Case 5: 첫 번째 문자열이 빈 문자열
	{
		const char *s1 = "";
		const char *s2 = "Non-empty";
		int result = ft_strcmp(s1, s2);

		printf("\n===================================================================\n");
		printf("Test 5 - First String Empty:\n");
		printf("Input: \"%s\", \"%s\"\n", s1, s2);
		printf("Expected: %d\n", strcmp(s1, s2));
		printf("Result: %d\n", result);
		printf("Pass: %s\n\n", (result == strcmp(s1, s2)) ? "Yes" : "No");
	}

	// Test Case 6: 두 번째 문자열이 빈 문자열
	{
		const char *s1 = "Non-empty";
		const char *s2 = "";
		int result = ft_strcmp(s1, s2);

		printf("\n===================================================================\n");
		printf("Test 6 - Second String Empty:\n");
		printf("Input: \"%s\", \"%s\"\n", s1, s2);
		printf("Expected: %d\n", strcmp(s1, s2));
		printf("Result: %d\n", result);
		printf("Pass: %s\n\n", (result == strcmp(s1, s2)) ? "Yes" : "No");
	}

	printf("All tests completed.\n");
}

void compare_with_write(int fd, const char *buf, size_t count) {
	errno = 0; // 기존 errno 초기화
	ssize_t result_ft = ft_write(fd, buf, count);
	int errno_ft = errno; // ft_write 실행 후 errno 저장
	printf("\n");
	errno = 0; // 다시 errno 초기화
	ssize_t result_sys = write(fd, buf, count);
	int errno_sys = errno; // 실제 write 실행 후 errno 저장

	// 결과 출력
	printf("\nFile Descriptor: %d\n", fd);
	printf("Buffer: \"%s\"\n", buf ? buf : "(null)");
	printf("Count: %zd\n", count);
	printf("\nResults:\n");
	printf("ft_write: %zd, errno: %d (%s)\n", result_ft, errno_ft, strerror(errno_ft));
	printf("write   : %zd, errno: %d (%s)\n", result_sys, errno_sys, strerror(errno_sys));
	printf("Pass: %s\n\n", (result_ft == result_sys && errno_ft == errno_sys) ? "Yes" : "No");
}

void test_ft_write() {
	printf("Running ft_write tests...\n");

	// Test Case 1: 정상적인 표준 출력
    printf("\n===================================================================\n");
	printf("Test Case 1: Normal stdout\n");
	compare_with_write(1, "Test 1: Hello, stdout!", 22);

	// Test Case 2: 표준 에러 출력
    printf("\n===================================================================\n");
	printf("Test Case 2: Normal stderr\n");
	compare_with_write(2, "Test 2: Hello, stderr!", 22);

	// Test Case 3: 파일 쓰기
    printf("\n===================================================================\n");
	printf("Test Case 3: File write\n");
	int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
		return;
	}
	compare_with_write(fd, "Test 3: Hello, file!", 20);
	close(fd);

	// Test Case 4: 잘못된 파일 디스크립터
    printf("\n===================================================================\n");
	printf("Test Case 4: Invalid file descriptor\n");
	compare_with_write(-1, "Test 4: Invalid FD", 18);

	// Test Case 5: NULL 버퍼
    printf("\n===================================================================\n");
	printf("Test Case 5: NULL buffer\n");
	compare_with_write(1, NULL, 10);
}

void compare_with_read(int fd, size_t count) {
	char buf_ft[1024] = {0};
	char buf_sys[1024] = {0};

	// ft_read 테스트
	errno = 0;
	ssize_t result_ft = ft_read(fd, buf_ft, count);
	int errno_ft = errno;

	// read 테스트
	errno = 0;
	ssize_t result_sys = read(fd, buf_sys, count);
	int errno_sys = errno;

	// 결과 출력
	printf("File Descriptor: %d\n", fd);
	printf("Requested Count: %zd\n", count);
	printf("\nResults:\n");
	printf("ft_read: %zd, errno: %d (%s)\n", result_ft, errno_ft, strerror(errno_ft));
	printf("Buffer (ft_read): \"%s\"\n", buf_ft);
	printf("read   : %zd, errno: %d (%s)\n", result_sys, errno_sys, strerror(errno_sys));
	printf("Buffer (read): \"%s\"\n", buf_sys);

	// 비교 결과
	int pass = (result_ft == result_sys && errno_ft == errno_sys && strcmp(buf_ft, buf_sys) == 0);
	printf("Pass: %s\n\n", pass ? "Yes" : "No");
}

void test_ft_read() {
	printf("Running ft_read tests...\n");

	// Test Case 1: 표준 입력에서 읽기
    printf("\n===================================================================\n");
	printf("Test Case 1: Standard input (stdin)\n");
	printf("Enter text (up to 10 characters): ");
	fflush(stdout); // 즉시 출력
	compare_with_read(STDIN_FILENO, 10);

	// Test Case 2: 파일에서 읽기
    printf("\n===================================================================\n");
	printf("Test Case 2: File read\n");
	int fd = open("test_output.txt", O_RDONLY);
	if (fd < 0) {
		perror("open");
		return;
	}
	compare_with_read(fd, 20);
	close(fd);

	// Test Case 3: 빈 파일 읽기
    printf("\n===================================================================\n");
	printf("Test Case 3: Empty file read\n");
	fd = open("empty_file.txt", O_RDONLY | O_CREAT, 0644); // 빈 파일 생성
	if (fd < 0) {
		perror("open");
		return;
	}
	compare_with_read(fd, 10);
	close(fd);

	// Test Case 4: 잘못된 파일 디스크립터
    printf("\n===================================================================\n");
	printf("Test Case 4: Invalid file descriptor\n");
	compare_with_read(-1, 10);

	// Test Case 5: NULL 버퍼
    printf("\n===================================================================\n");
	printf("Test Case 5: NULL buffer\n");
	char *null_buf = NULL;
	fd = open("test_output.txt", O_RDONLY);
	ssize_t result_ft = ft_read(fd, null_buf, 10);
	int errno_ft = errno;
	close(fd);

	fd = open("test_output.txt", O_RDONLY);
	errno = 0; // reset errno
	ssize_t result_sys = read(fd, null_buf, 10);
	int errno_sys = errno;
	close(fd);

	printf("File Descriptor: %d\n", STDIN_FILENO);
	printf("Requested Count: 10\n\n");
	printf("ft_read: %zd, errno: %d (%s)\n", result_ft, errno_ft, strerror(errno_ft));
	printf("read   : %zd, errno: %d (%s)\n", result_sys, errno_sys, strerror(errno_sys));
	printf("Pass: %s\n\n", (result_ft == result_sys && errno_ft == errno_sys) ? "Yes" : "No");
}

void compare_with_strdup(const char *input) {
	char *result_sys = strdup(input);
	char *result_ft = ft_strdup(input);

	// 결과 출력
	printf("Input String: \"%s\"\n", input ? input : "(null)");
	printf("\nResults:\n");
	printf("ft_strdup : \"%s\" (Address: %p)\n", result_ft ? result_ft : "(null)", result_ft);
	printf("strdup	: \"%s\" (Address: %p)\n", result_sys ? result_sys : "(null)", result_sys);

	// 비교 결과
	int pass = (result_ft && result_sys && strcmp(result_ft, result_sys) == 0) || (!result_ft && !result_sys);
	printf("Pass: %s\n\n", pass ? "Yes" : "No");

	// 메모리 해제
	free(result_ft);
	free(result_sys);
}

void test_ft_strdup() {
	printf("Running ft_strdup tests...\n");

	// Test Case 1: 정상적인 문자열 복사
    printf("\n===================================================================\n");
	printf("Test Case 1: Normal string\n");
	compare_with_strdup("Hello, strdup!");

	// Test Case 2: 빈 문자열 복사
    printf("\n===================================================================\n");
	printf("Test Case 2: Empty string\n");
	compare_with_strdup("");

	// Test Case 3: NULL 입력
	// printf("Test Case 3: NULL input\n");
	// compare_with_strdup(NULL);

	// Test Case 4: 긴 문자열 복사
    printf("\n===================================================================\n");
	printf("Test Case 4: Long string\n");
	const char *long_string =
		"This is a very long string to test the strdup function implementation. Let's see if it works correctly.";
	compare_with_strdup(long_string);

	// // Test Case 5: 특수 문자 포함 문자열
    printf("\n===================================================================\n");
	printf("Test Case 5: String with special characters\n");
	compare_with_strdup("String with \t tab, \n newline, and \0 null terminator.");
}

int main() {
	// test_ft_strlen();
	// test_ft_strcpy();
	// test_ft_strcmp();
	// test_ft_write();
	// test_ft_read();
	test_ft_strdup();
	return 0;
}
