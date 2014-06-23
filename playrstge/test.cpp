#include <libplayerc++/playerc++.h>

#include <iostream>

int main(int argc, char** argv)
{
  

  try
  {
    PlayerCc::PlayerClient client("localhost",6665);
    PlayerCc::CameraProxy cp(&client, 1);

    for (uint i=0; i<10; ++i)
    {
      client.Read();
      cp.SaveFrame("camera");
      std::cout << cp << std::endl;
    }

  }
  catch (PlayerCc::PlayerError e)
  {
    std::cerr << e << std::endl;
    return -1;
  }
  return 1;
}
