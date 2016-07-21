#include <serial/out.hpp>

using namespace power::serial;

#include <chrono>
#include <thread>


int main()
{
  serial << "Start\n";

  std::this_thread::sleep_for(std::chrono::seconds( 5 ) );

  serial << "Stop\n";

  return 0;
}
