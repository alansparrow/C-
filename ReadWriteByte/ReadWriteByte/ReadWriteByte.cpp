// ReadWriteByte.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdint>

#define WRITE_4_BYTES(val, buf) *((std::uint8_t*)buf + 0) = *((std::uint8_t*)&val + 0); \
								*((std::uint8_t*)buf + 1) = *((std::uint8_t*)&val + 1); \
								*((std::uint8_t*)buf + 2) = *((std::uint8_t*)&val + 2); \
								*((std::uint8_t*)buf + 3) = *((std::uint8_t*)&val + 3)

#define WRITE_4_BYTES_V1(val, buf) *((std::uint8_t*)buf + 0) = ((val >> 0) & 0xff); \
								   *((std::uint8_t*)buf + 1) = ((val >> 8) & 0xff); \
								   *((std::uint8_t*)buf + 2) = ((val >> 16) & 0xff); \
								   *((std::uint8_t*)buf + 3) = ((val >> 24) & 0xff)

#define READ_4_BYTES(buf) (std::uint32_t) *(((std::uint8_t*)buf + 0)) << 0 | \
						  (std::uint32_t) *(((std::uint8_t*)buf + 1)) << 8 | \
						  (std::uint32_t) *(((std::uint8_t*)buf + 2)) << 16 | \
						  (std::uint32_t) *(((std::uint8_t*)buf + 3)) << 24

#define WRITE_8_BYTES(val, buf) *((std::uint8_t*)buf + 0) = ((val >> 0) & 0xff); \
								*((std::uint8_t*)buf + 1) = ((val >> 8) & 0xff); \
								*((std::uint8_t*)buf + 2) = ((val >> 16) & 0xff); \
								*((std::uint8_t*)buf + 3) = ((val >> 24) & 0xff); \
								*((std::uint8_t*)buf + 4) = ((val >> 32) & 0xff); \
								*((std::uint8_t*)buf + 5) = ((val >> 40) & 0xff); \
								*((std::uint8_t*)buf + 6) = ((val >> 48) & 0xff); \
								*((std::uint8_t*)buf + 7) = ((val >> 56) & 0xff)

#define READ_8_BYTES(buf) (std::uint64_t) *(((std::uint8_t*)buf + 0)) << 0 | \
						  (std::uint64_t) *(((std::uint8_t*)buf + 1)) << 8 | \
						  (std::uint64_t) *(((std::uint8_t*)buf + 2)) << 16 | \
						  (std::uint64_t) *(((std::uint8_t*)buf + 3)) << 24 | \
						  (std::uint64_t) *(((std::uint8_t*)buf + 4)) << 32 | \
						  (std::uint64_t) *(((std::uint8_t*)buf + 5)) << 40 | \
						  (std::uint64_t) *(((std::uint8_t*)buf + 6)) << 48 | \
						  (std::uint64_t) *(((std::uint8_t*)buf + 7)) << 56

void PrintBuffer(char* buf, char size)
{
	printf("Buffer:			");
	for (int i = 0; i <= size - 1; i++)
	{
		std::uint8_t c = *(((char*)buf) + i);
		printf("%2x ", c);
	}

	printf("\n");
}

void PrintLittleEndian(void* ptr, char byte_size)
{
	printf("Little Endian:		");
	switch (byte_size)
	{
	case 1:
		for (int i = 0; i < byte_size; i++) printf("%2x ", (char)(*((char*)ptr) >> i * 8) & 0xff);
		break;
	case 4:
		for (int i = 0; i < byte_size; i++) printf("%2x ", (char)(*((int*)ptr) >> i * 8) & 0xff);
		break;
	case 8:
		for (int i = 0; i < byte_size; i++) printf("%2x ", (char)(*((long long*)ptr) >> i * 8) & 0xff);
		break;
	default:
		break;
	}

	printf("\n");
}

void PrintBigEndian(void* ptr, char byte_size)
{
	printf("Big Endian:		");
	switch (byte_size)
	{
	case 1:
		for (int i = byte_size - 1; i >= 0; i--) printf("%2x ", (char)(*((char*)ptr) >> i * 8) & 0xff);
		break;
	case 4:
		for (int i = byte_size - 1; i >= 0; i--) printf("%2x ", (char)(*((int*)ptr) >> i * 8) & 0xff);
		break;
	case 8:
		for (int i = byte_size - 1; i >= 0; i--) printf("%2x ", (char)(*((long long*)ptr) >> i * 8) & 0xff);
		break;
	default:
		break;
	}

	printf("\n");
}

int main()
{
	int val = 0x0bcdefa8;
	char* buf = new char[4];
	char* buf1 = new char[4];


	WRITE_4_BYTES(val, buf);
	WRITE_4_BYTES_V1(val, buf1);

	PrintLittleEndian(&val, sizeof(val));
	PrintBigEndian(&val, sizeof(val));

	PrintBuffer(buf, 4);
	PrintBuffer(buf1, 4);

	long long val_long = 0x0accffbb11223344;
	PrintBigEndian(&val_long, sizeof(val_long));
	PrintLittleEndian(&val_long, sizeof(val_long));

	PrintBuffer(buf, 4);
	int out_val = READ_4_BYTES(buf);
	printf("out_val:		%d\n", out_val);
	for (int i = 0; i < 4; i++)
	{
		//int x = (*(((char*)buf + i)) << i * 8);
		int x = (*(((std::uint8_t*)buf + i)) << i * 8);
		PrintLittleEndian(&x, 4);
	}
		
	printf("\n\n===== 8 bytes =====\n\n");

	printf("val_long:		%lld\n", val_long);
	PrintLittleEndian(&val_long, sizeof(val_long));
	PrintBigEndian(&val_long, sizeof(val_long));
	char* buf_ll = new char[sizeof(long long)];
	WRITE_8_BYTES(val_long, buf_ll);
	PrintBuffer(buf_ll, 8);
	long long out_val_long = READ_8_BYTES(buf_ll);
	printf("out_val_long:		%lld\n", out_val_long);


	printf("\n\n\n");
}


/*

Little Endian:          a8 ef cd  b
Big Endian:              b cd ef a8
Buffer:                 a8 ef cd  b
Buffer:                 a8 ef cd  b
Big Endian:              a cc ff bb 11 22 33 44
Little Endian:          44 33 22 11 bb ff cc  a
Buffer:                 a8 ef cd  b
out_val:                198045608
Little Endian:          a8  0  0  0
Little Endian:           0 ef  0  0
Little Endian:           0  0 cd  0
Little Endian:           0  0  0  b


===== 8 bytes =====

val_long:               778278014539674436
Little Endian:          44 33 22 11 bb ff cc  a
Big Endian:              a cc ff bb 11 22 33 44
Buffer:                 44 33 22 11 bb ff cc  a
out_val_long:           778278014539674436

*/