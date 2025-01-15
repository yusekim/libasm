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

// BONUS PART

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

int ft_list_size(t_list *begin_list);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_atoi_base(char* str, char *base);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *));

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
		const char *src = "This is a very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very long string to test the behavior of ft_strcpy for longer inputs.";
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

	// Test Case 3: 긴 문자열 복사
	printf("\n===================================================================\n");
	printf("Test Case 3: Long string\n");
	const char *long_string =
		"This is a very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very long string to test the strdup function implementation. Let's see if it works correctly.";
	compare_with_strdup(long_string);

	// // Test Case 4: 특수 문자 포함 문자열
	printf("\n===================================================================\n");
	printf("Test Case 4: String with special characters\n");
	compare_with_strdup("String with \t tab, \n newline, and \0 null terminator.");
}

void test_ft_list_size() {
	printf("Running ft_list_size tests...\n");

	t_list head, n1, n2, n3, n4, n5;
	int res;

	// Test Case 1: 단일 노드 테스트
	printf("\n===================================================================\n");
	printf("Test Case 1: single node\n");
	head.next = NULL;
	printf("Expected return value: 1\n");
	res = ft_list_size(&head);
	printf("ft_list_size returns: %d\n", res);
	printf("Pass: %s\n\n", res == 1 ? "Yes" : "No");

	// Test Case 2: 노드 3개 테스트
	printf("\n===================================================================\n");
	printf("Test Case 1: three-linked lists\n");
	head.next = &n1;
	n1.next = &n2;
	n2.next = NULL;
	printf("Expected return value: 3\n");
	res = ft_list_size(&head);
	printf("ft_list_size returns: %d\n", res);
	printf("Pass: %s\n\n", res == 3 ? "Yes" : "No");

	// Test Case 3: 노드 6개 테스트
	printf("\n===================================================================\n");
	printf("Test Case 1: six-linked lists\n");
	head.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;
	printf("Expected return value: 6\n");
	res = ft_list_size(&head);
	printf("ft_list_size returns: %d\n", res);
	printf("Pass: %s\n\n", res == 6 ? "Yes" : "No");

	// Test Case 4: NULL 포인터
	printf("\n===================================================================\n");
	printf("Test Case 1: NULL as an argument\n");
	printf("Expected return value: 0\n");
	res = ft_list_size(NULL);
	printf("ft_list_size returns: %d\n", res);
	printf("Pass: %s\n\n", res == 0 ? "Yes" : "No");
}

// 리스트 출력 함수
void print_list(t_list *head, int flag)
{
	t_list *current = head;
	int index = 0;

	printf("\nLinked List Contents:\n");
	while (current != NULL) {
		if (flag)
		{
			char *value = (char *)(current->data);
			printf("[Node %d] Data: %s\n", index, value);
		}
		else
		{
			int value = *(int *)(current->data);
			printf("[Node %d] Data: %d\n", index, value);
		}
		current = current->next;
		index++;
	}

	if (index == 0) {
		printf("The list is empty.\n");
	}
}

void free_list(t_list *head) {
	t_list *temp;
	while (head != NULL) {
		temp = head->next;
		free(head);
		head = temp;
	}
}

void test_ft_list_push_front() {
	printf("Running ft_list_push_front tests...\n");

	t_list *head = malloc(sizeof(t_list));
	int data = 42;
	int dummy = 1;

	// Test Case 1: 단일 노드 테스트
	printf("\n===================================================================\n");
	printf("Test Case 1: single node\n");
	head->next = NULL;
	head->data = &dummy;
	printf("linked list status before\n");
	print_list(head, 0);
	ft_list_push_front(&head, &data);
	printf("linked list status after\n");
	print_list(head, 0);

	if (head && head->data == &data) {
		printf("Test Case 1 Passed: New node added successfully!\n");
	} else {
		printf("Test Case 1 Failed: New node not added as expected.\n");
	}

	// Test Case 2: 이전 테스트 결과에 노드 하나 더 추가
	printf("\n===================================================================\n");
	printf("Test Case 2: push another node to Case 1\n");
	printf("linked list status before\n");
	int data2 = 4242;
	print_list(head, 0);
	ft_list_push_front(&head, &data2);
	printf("linked list status after\n");
	print_list(head, 0);

	if (head && head->data == &data2) {
		printf("Test Case 2 Passed: New node added successfully!\n");
	} else {
		printf("Test Case 2 Failed: New node not added as expected.\n");
	}

	// Test Case 3: begin_list가 NULL 일때
	printf("\n===================================================================\n");
	printf("Test Case 3: begin_list is NULL\n");
	printf("linked list status before\n");
	print_list(NULL, 0);
	t_list *empty_head = NULL;
	ft_list_push_front(&empty_head, &data);
	printf("linked list status after\n");
	print_list(empty_head, 0);

	if (empty_head && empty_head->data == &data) {
		printf("Test Case 3 Passed: New node added successfully!\n");
	} else {
		printf("Test Case 3 Failed: New node not added as expected.\n");
	}

	free_list(head);
	free_list(empty_head);
}

void test_ft_atoi_base()
{
	printf("Running ft_atoi_base tests...\n");
	printf("\n===================================================================\n");
	printf("Test Case 1: normal execution\n");
	char *str = "2a";
	char *base = "0123456789abcdef";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	int res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == 42) ? "Yes" : "No");

	printf("\n===================================================================\n");
	printf("Test Case 2: positive number execution\n");
	str = "+52";
	base = "01234567";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == 42) ? "Yes" : "No");

	printf("\n===================================================================\n");
	printf("Test Case 3: negative number execution\n");
	str = "-101010";
	base = "01";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == -42) ? "Yes" : "No");

	printf("\n===================================================================\n");
	printf("Test Case 4: base length is 1 or 0\n");
	str = "1";
	base = "1";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == 0) ? "Yes" : "No");

	str = "0";
	base = "";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == 0) ? "Yes" : "No");

	printf("\n===================================================================\n");
	printf("Test Case 5: base including '-' or '+'\n");
	str = "2a";
	base = "0123456789+abcdef";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == 0) ? "Yes" : "No");

	str = "2a";
	base = "012-3456789abcdef";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == 0) ? "Yes" : "No");

	printf("\n===================================================================\n");
	printf("Test Case 6: base including same character twice\n");
	str = "2a";
	base = "0123456789abcdef0";
	printf("str: \"%s\"\n", str);
	printf("base: \"%s\"\n", base);

	res = ft_atoi_base(str, base);
	printf("Result: %d\n", res);
	printf("Pass: %s\n\n", (res == 0) ? "Yes" : "No");
}

int intcmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

void test_ft_list_sort()
{
	t_list *head = malloc(sizeof(t_list));
	t_list n1, n2, n3;
	int idata1 = 42;
	int idata2 = -42;
	int idata3 = 4242;
	int idata4 = -4242;

	char cdata1[] = "BAR";
	char cdata2[] = "hello";
	char cdata3[] = "YUSEKIM";
	char cdata4[] = "foo";
	void* f = intcmp;


	printf("Running test_ft_list_sort tests...\n");
	printf("\n===================================================================\n");
	printf("Test Case 1: single node with int data\n");
	head->data = &idata1;
	head->next = NULL;
	print_list(head, 0);
	ft_list_sort(&head, intcmp);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~AFTERSORT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	print_list(head, 0);

	printf("\n===================================================================\n");
	printf("Test Case 2: four node with int data\n");
	head->next = &n1;

	n1.data = &idata2;
	n1.next = &n2;

	n2.data = &idata3;
	n2.next = &n3;

	n3.data = &idata4;
	n3.next = NULL;
	print_list(head, 0);
	ft_list_sort(&head, intcmp);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~AFTERSORT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	print_list(head, 0);

	printf("\n===================================================================\n");
	printf("Test Case 3: four node with string data\n");
	head->data = &cdata1;
	head->next = &n1;

	n1.data = &cdata2;
	n1.next = &n2;

	n2.data = &cdata3;
	n2.next = &n3;

	n3.data = &cdata4;
	n3.next = NULL;
	print_list(head, 1);
	ft_list_sort(&head, strcmp);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~AFTERSORT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	print_list(head, 1);

	printf("\n===================================================================\n");
	printf("Test Case 4: first argument is NULL\n");
	ft_list_sort(NULL, strcmp);
	printf("Call complete!\n");

	printf("\n===================================================================\n");
	printf("Test Case 5: *(first argument) is NULL\n");
	t_list *dump = NULL;
	ft_list_sort(&dump, strcmp);
	printf("Call complete!\n");

	printf("\n===================================================================\n");
	printf("Test Case 6: second argument is NULL\n");
	ft_list_sort(&head, NULL);
	printf("Call complete!\n");
}

void fake_free()
{
	return;
}

void test_ft_list_remove_if()
{
	printf("Running ft_list_remove_if tests...\n");

	{
		printf("\n===================================================================\n");
		printf("Test Case 1: empty list\n");
		t_list *head = NULL;
		int target = 100;

		printf("Before remove: ");
		print_list(head, 0);

		ft_list_remove_if(&head, &target, intcmp, free);

		printf("After remove(target is %d):  ", target);
		print_list(head, 0);

		if (head == NULL)
			printf("Test Case 1 Passed: handle empty list gracefully.\n");
		else
			printf("Test Case 1 Failed.\n");
	}

	{
		printf("\n===================================================================\n");
		printf("Test Case 2: single node == target\n");
		t_list *head = malloc(sizeof(t_list));
		int data = 42;
		head->data = &data;
		head->next = NULL;

		int target = 42;

		printf("Before remove: ");
		print_list(head, 0);

		ft_list_remove_if(&head, &target, intcmp, fake_free);

		printf("After remove(target is %d):  ", target);
		print_list(head, 0);

		if (head == NULL)
			printf("Test Case 2 Passed: single node removed.\n");
		else
			printf("Test Case 2 Failed.\n");
	}

	{
		printf("\n===================================================================\n");
		printf("Test Case 3: single node != target\n");
		t_list *head = malloc(sizeof(t_list));
		int data = 42;
		head->data = &data;
		head->next = NULL;

		int target = 999;

		printf("Before remove: ");
		print_list(head, 0);

		ft_list_remove_if(&head, &target, intcmp, fake_free);

		printf("After remove(target is %d):  ", target);
		print_list(head, 0);

		if (head != NULL && *((int *)head->data) == 42)
			printf("Test Case 3 Passed: no removal.\n");
		else
			printf("Test Case 3 Failed.\n");

		free_list(head);
	}

	{
		printf("\n===================================================================\n");
		printf("Test Case 4: multiple nodes, partial match\n");

		// 리스트 구성: [42] -> [999] -> [42] -> [7] -> NULL
		t_list *head = malloc(sizeof(t_list));
		int data1 = 42;
		head->data = &data1;

		t_list *node2 = malloc(sizeof(t_list));
		int data2 = 999;
		node2->data = &data2;
		head->next = node2;

		t_list *node3 = malloc(sizeof(t_list));
		int data3 = 42;
		node3->data = &data3;
		node2->next = node3;

		t_list *node4 = malloc(sizeof(t_list));
		int data4 = 7;
		node4->data = &data4;
		node3->next = node4;

		node4->next = NULL;

		int target = 42;

		printf("Before remove: ");
		print_list(head, 0);

		ft_list_remove_if(&head, &target, intcmp, fake_free);

		printf("After remove(target is %d):  ", target);
		print_list(head, 0);

		if (head && *((int *)head->data) == 999 && head->next && *((int *)head->next->data) == 7 && head->next->next == NULL)
			printf("Test Case 4 Passed: only target nodes removed.\n");
		else
			printf("Test Case 4 Failed.\n");

		free_list(head);
	}

	{
		printf("\n===================================================================\n");
		printf("Test Case 5: all nodes match target\n");

		// 리스트 구성: [42] -> [42] -> [42] -> NULL
		t_list *head = NULL;

		for (int i = 0; i < 3; i++)
		{
			t_list *new_node = malloc(sizeof(t_list));
			int *ndata = malloc(sizeof(int)); // <-- 여기서는 data를 실제 malloc
			*ndata = 42;
			new_node->data = ndata;
			new_node->next = head;
			head = new_node;
		}

		int target = 42;

		printf("Before remove: ");
		print_list(head, 0);

		ft_list_remove_if(&head, &target, intcmp, free);

		printf("After remove(target is %d):  ", target);
		print_list(head, 0);

		if (head == NULL)
			printf("Test Case 5 Passed: all matching nodes removed.\n");
		else
			printf("Test Case 5 Failed.\n");

		free_list(head);
	}
}

int main() {
	test_ft_strlen();
	// test_ft_strcpy();
	// test_ft_strcmp();
	// test_ft_write();
	// test_ft_read();
	// test_ft_strdup();
	// test_ft_atoi_base();
	// test_ft_list_size();
	// test_ft_list_push_front();
	// test_ft_list_sort();
	// test_ft_list_remove_if();
	return 0;
}

