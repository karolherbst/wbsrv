/*
compile with:
./build.sh
*/

#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

static int SOCKADDR_IN_SIZE = sizeof(struct sockaddr_in);
static char BODY[] = "HTTP/1.1 200 OK\r\nContent-Length: 3\r\n\r\nok\n";

int main() {
	struct sockaddr_in client;
	int c, read_size;
	char c_msg[2000];

	struct sockaddr_in server = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = INADDR_ANY,
		.sin_port = htons(8080)
	};
	int s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	bind(s, (struct sockaddr *)&server, sizeof(server));
	// like we will ever be too slow to answer all clients....
	listen(s, 10000);

	while (1) {
		c = accept(s, (struct sockaddr *)&client, (socklen_t*)&SOCKADDR_IN_SIZE);
		write(c, BODY, strlen(BODY));
		close(c);
	}
	return 0;
}
