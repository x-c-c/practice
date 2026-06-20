#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
int main()
{
	const std::string fileName = "example.txt";
	const std::string chipherFileName = "chipher.txt";
	
	const size_t readBufferSize = 65536;	// 64 KB
	const size_t writeBufferSize = 65536;	// 64 KB
	
	std::ifstream file(fileName, std::ios::binary);
	std::ofstream chipherFile(chipherFileName, std::ios::binary);
	
	std::vector<uint8_t> inputBuffer(readBufferSize);
	std::vector<uint8_t> outputBuffer(writeBufferSize);
	
	bool lastBlock = false;
	while(!lastBlock)
	{
		file.read(reinterpret_cast<char*>(inputBuffer.data()), inputBuffer.size());
		size_t bytesReaded = file.gcount();
		lastBlock = (bytesReaded < readBufferSize) || file.eof();
		if (bytesReaded == 0)	//empty file on firts read
			{
				break;
			}
		//compress ===later===
		//chipher  ===later===
		chipherFile.write( /*===compresed and chipherd Block===*/ );
	}
	
	
	
	return 0;
}
