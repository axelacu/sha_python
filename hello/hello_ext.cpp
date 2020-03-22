#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// hello_ext.cpp
char const* greet() {
  return "hello, world";
}

std::string sha3_256(std::string input) {
	uint8_t output[32];
	char outputHex[65];

	SHA3_256( output, (const uint8_t*)input.c_str(), input.size());

	for (int i=0;i<32;i++) {
		sprintf(&outputHex[i * 2], "%02X", output[i]);
	}	
	return std::string(outputHex,64);

}


#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello_ext)
{
  using namespace boost::python;
  def("greet", greet);
}


std::string sha3_256(std::string input) {
	uint8_t output[32];
	char outputHex[65];

	SHA3_256( output, (const uint8_t*)input.c_str(), input.size());

	for (int i=0;i<32;i++) {
		sprintf(&outputHex[i * 2], "%02X", output[i]);
	}	
	return std::string(outputHex,64);

}
