#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>


char* advice[] = {
                  "Take smaller bites \r\n",
                  "Go For the tight jeans. No they do not make you look fat. \r\n",
                  "One word inappropriate",
                  "Just for today, be honest. Tell your boss what you relly think\r\n",
                  "You might want to rethink that haircut\r\n"
};

int read_in(int socket, char *buf, int len);

void main() {
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t) htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1) {
    puts("Can not bind to the port. it's already in use");
    exit("port in use");
  }
  listen(listener_d, 10);

  puts("Waiting for connection");

  while(1) {
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *) &client_addr,
                           &address_size);
    char* msg = advice[rand() % 5];
    send(connect_d, msg, strlen(msg), 0);
    close(connect_d);
  }

}

int read_in(int socket, char *buf, int len) {
  char* storeinput = buf;
  int string_length = len;
  int inlength ;
  while((inlength = recv(socket, storeinput, string_length, 0)) > 0
        && storeinput[inlength-1] != '\n') {
    storeinput += inlength; // move pointer to next empty space
    string_length -= inlength; // update the number of empty space
  }

  if(inlength < 0) {
    //if error while reading 
    return inlength;
  } else if (inlength == 0) {
    //if no data is read
    buf[0] = '\0';
  } else {
    storeinput[inlength-1] = '\0';
  }
  return len - string_length; 
}
