#include <iostream>
#include <string>
int main(int argc, char *argv[]){
  if(argc!=3){
    std::cerr<< "Usage: "<<argv[0]<< " posx posy" <<std::endl;
    return -1;
  }
  std::string x = std::string(argv[1]);
  std::string y = std::string(argv[2]);
  int debugPixelX      = std::stoi(x);
  int debugPixelY      = std::stoi(y);
  int debugiCol        = debugPixelX/64;
  int debugiLin        = debugPixelY/64;
  int debugiLocalCol   = debugPixelX%64;
  int debugiLocalLin   = debugPixelY%64;
  printf("BlockIdx x y %d %d ThreadIdx x y %d %d\n", debugiCol, debugiLin, debugiLocalCol, debugiLocalLin);
  int DiffSecond4x8 = debugPixelX%8; 
  int DiffSecond8x4 = debugPixelY%8;
  printf("is Second 4x8 %d 8x4 %d\n", DiffSecond4x8, DiffSecond8x4);
  return 0;
}
