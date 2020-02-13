#include <iostream>
#include <cstdlib>
#include <cstring>

#define GREET "hello"

static const char *
greetMsg(const char *name)
{
  const std::size_t len = strlen(GREET) + 1 + strlen(name);
  char *msg = new char[len + 1];
  strcpy(msg, GREET); strcat(msg, " "); strcat(msg, name);
  char* message = msg;
  delete[] msg;
  return message;
}

int 
main(int argc, const char *argv[])
{
  if (argc == 1) {
    std::cerr << "usage: " << argv[0] << " NAME..." << std::endl;
    std::exit(1);
  }
  else {
    for (int i = 1; i < argc; i++) {
      std::cout << greetMsg(argv[i]) << std::endl;
      delete[] argv[i];
    }
  }
}