#include<iostream>
#include<stdint.h>
#include<bitset>
using namespace std;

//Usual way
uint32_t reverseBits(uint32_t n) {
	unsigned int  NO_OF_BITS = sizeof(n) * 8;
	uint32_t r=0;
	for (int i=0; i<NO_OF_BITS; i++) {
		int temp = n & (1 << i);
		if (temp)
			r = r | (1 << ((NO_OF_BITS-1)-i));
	}
	return r;
}

//Smart bit math
uint32_t reverseBits_opt(uint32_t n) {
	n = (n << 16) | (n >> 16);
	n = ((n & 0xff00ff00)>>8) | ((n & 0x00ff00ff)<<8);
	n = ((n & 0xf0f0f0f0)>>4) | ((n & 0x0f0f0f0f)<<4);
	n = ((n & 0xcccccccc)>>2) | ((n & 0x33333333)<<2);
	n = ((n & 0xaaaaaaaa)>>1) | ((n & 0x55555555)<<1);
	return n;
}



int main(){
	uint32_t n= 17, r, r_opt;
	
	r = reverseBits(n);
	r_opt = reverseBits_opt(n);
	cout << bitset<32>(n) <<endl;
	cout << bitset<32>(r)<<endl;
	cout << bitset<32>(r_opt);

	return 0;
}

