#include <bits/stdc++.h>
#define ROUND 6
int IP[] = {58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9,  1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
           };
int IPREV[] = {40, 8, 48, 16, 56, 24, 64, 32,
               39, 7, 47, 15, 55, 23, 63, 31,
               38, 6, 46, 14, 54, 22, 62, 30,
               37, 5, 45, 13, 53, 21, 61, 29,
               36, 4, 44, 12, 52, 20, 60, 28,
               35, 3, 43, 11, 51, 19, 59, 27,
               34, 2, 42, 10, 50, 18, 58, 26,
               33, 1, 41,  9, 49, 17, 57, 25
              };
int SBOX[8][4][16] = {
    {
        {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
    },
    {
        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
        {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
        {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
    },
    {
        {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
        {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
        {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
    },
    {
        {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
        {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
        {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
    },
    {
        {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
        {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
        {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
    },
    {
        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
    },
    {
        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
    },
    {
        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
    }
};
int E[] = {32,  1,  2,  3,  4,  5,
           4,  5,  6,  7,  8,  9,
           8,  9, 10, 11, 12, 13,
           12, 13, 14, 15, 16, 17,
           16, 17, 18, 19, 20, 21,
           20, 21, 22, 23, 24, 25,
           24, 25, 26, 27, 28, 29,
           28, 29, 30, 31, 32,  1
          };
int P[] = {16,  7, 20, 21,
           29, 12, 28, 17,
           1, 15, 23, 26,
           5, 18, 31, 10,
           2,  8, 24, 14,
           32, 27,  3,  9,
           19, 13, 30,  6,
           22, 11,  4, 25
          };
int SUBKEY64[] = {57, 49, 41, 33, 25, 17, 9,
              1, 58, 50, 42, 34, 26, 18,
              10,  2, 59, 51, 43, 35, 27,
              19, 11,  3, 60, 52, 44, 36,
              63, 55, 47, 39, 31, 23, 15,
              7, 62, 54, 46, 38, 30, 22,
              14,  6, 61, 53, 45, 37, 29,
              21, 13,  5, 28, 20, 12,  4
             };
int SUBKEY56[] = {14, 17, 11, 24,  1,  5,
              3, 28, 15,  6, 21, 10,
              23, 19, 12,  4, 26,  8,
              16,  7, 27, 20, 13,  2,
              41, 52, 31, 37, 47, 55,
              30, 40, 51, 45, 33, 48,
              44, 49, 39, 56, 34, 53,
              46, 42, 50, 36, 29, 32
             };
int SHIFT[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};


std::vector<std::bitset<48>> getsubkey(std::bitset<64> key){
	for (int i = 0; i < 32; i ++ ){
		int t = key[i];
		key[i] = key[63 - i];
		key[63 - i] = t;
	}
	std::vector<std::bitset<48>> res;
	std::bitset<28> l, r;
	for (int i = 0; i < 28; i ++ ){
		l[i] = key[SUBKEY64[i] - 1];
		r[i] = key[SUBKEY64[i + 28] - 1];
	}
	for (int i = 0; i < ROUND; i ++ ){
		auto t = l;
		for (int j = 0; j < 28; j ++ )
			l[j] = t[(j + SHIFT[i]) % 28];
		t = r;
		for (int j = 0; j < 28; j ++ )
			r[j] = t[(j + SHIFT[i]) % 28];
		std::bitset<48> subkey;
		for (int j = 0; j < 48; j ++ )
			subkey[j] = SUBKEY56[j] > 28 ? r[SUBKEY56[j] - 29] : l[SUBKEY56[j] - 1];
		res.push_back(subkey);
		//std::cout << i + 1 << ":	" << subkey << std::endl;
	}
	return res;
}

std::bitset<32> f_func(std::bitset<32> r, std::bitset<48> key){
	std::bitset<48> rr;
	for (int i = 0; i < 48; i ++ )
		rr[i] = r[E[i] - 1];
	rr ^= key;
	std::bitset<32> res(0);
	for (int i = 0; i < 8; i ++ ){
		int resst = i * 4;
		int rrst = i * 6;
		int num = SBOX[i][rr[rrst] * 2 + rr[rrst + 5]][rr[rrst + 1] * 8 + rr[rrst + 2] * 4 + rr[rrst + 3] * 2 + rr[rrst + 4]];
		res[resst] = num / 8;
		res[resst + 1] = (num / 4) & 1;
		res[resst + 2] = (num / 2) & 1;
		res[resst + 3] = num & 1;
	}
	std::bitset<32> resp;
	for (int i = 0; i < 32; i ++ )
		resp[i] = res[P[i] - 1];
	return resp;
}

unsigned long long DESblock(std::bitset<64> input, std::vector<std::bitset<48>> subkeys){
	std::bitset<32> l, r, temp;
	//std::cout << input << std::endl;
	for (int i = 0; i < 32; i ++ ){
		l[i] = input[IP[i] - 1];
		r[i] = input[IP[i + 32] - 1];
	}
	for (int i = 0; i < ROUND; i ++ ){
		temp = f_func(r, subkeys[i]) ^ l;
		l = r;
		r = temp;
		//std::cout << i + 1 << ":	" << l << ' ' << r << std::endl;
	}
	unsigned long long res = 0;
	for (int i = 0; i < 64; i ++ )
		res = res * 2 + (IPREV[i] > 32 ? l[IPREV[i] - 33] : r[IPREV[i] - 1]);
	//printf("%llx\n", res);
	return res;
}

std::map<char, int> char2numrevmap, char2nummap;
std::map<int, char> num2charmap;
int char2numrev(char c){
	if (char2numrevmap.size() == 0){
		char2numrevmap['0'] = 0;
		char2numrevmap['1'] = 8;
		char2numrevmap['2'] = 4;
		char2numrevmap['3'] = 12;
		char2numrevmap['4'] = 2;
		char2numrevmap['5'] = 10;
		char2numrevmap['6'] = 6;
		char2numrevmap['7'] = 14;
		char2numrevmap['8'] = 1;
		char2numrevmap['9'] = 9;
		char2numrevmap['a'] = 5;
		char2numrevmap['b'] = 13;
		char2numrevmap['c'] = 3;
		char2numrevmap['d'] = 11;
		char2numrevmap['e'] = 7;
		char2numrevmap['f'] = 15;
		char2numrevmap['A'] = 5;
		char2numrevmap['B'] = 13;
		char2numrevmap['C'] = 3;
		char2numrevmap['D'] = 11;
		char2numrevmap['E'] = 7;
		char2numrevmap['F'] = 15;
	}
	return char2numrevmap[c];
}

std::string DESECB_Enc(std::string plainstring, std::string keystring){
	for (; plainstring.size() % 16 != 0; plainstring += '0');
	std::bitset<64> key;
	if (keystring.size() == 8){
		for (int i = 0; i < 8; i ++ ){
			char c = keystring[i];
			for (int j = 0; j < 8; j ++ ){
				key[i * 8 + j] = c & 1;
				c /= 2;
			}
		}
	}
	else if (keystring.size() == 16){
		unsigned long long tull;
		sscanf(keystring.c_str(), "%llx", &tull);
		key = tull;
	}
	auto subkeys = getsubkey(key);
	std::string res = "";
	for (int i = 0; i < plainstring.size(); i += 16){
		unsigned long long input = 0;
		for (int j = 15; j >= 0; j -- )
			input = (input << 4) + char2numrev(plainstring[i + j]);
		auto blockres = DESblock(input, subkeys);
		char buffer[100] = {0};
		sprintf(buffer, "%016llx", blockres);
		res += buffer;
	}
	return res;
}

std::string DESECB_Dec(std::string plainstring, std::string keystring){
	for (; plainstring.size() % 16 != 0; plainstring += '0');
	std::bitset<64> key;
	if (keystring.size() == 8){
		for (int i = 0; i < 8; i ++ ){
			char c = keystring[i];
			for (int j = 0; j < 8; j ++ ){
				key[i * 8 + j] = c & 1;
				c /= 2;
			}
		}
	}
	else if (keystring.size() == 16){
		unsigned long long tull;
		sscanf(keystring.c_str(), "%llx", &tull);
		key = tull;
	}
	auto subkeys = getsubkey(key);
	for (int i = 0; i < ROUND / 2; i ++ ){
		auto t = subkeys[i];
		subkeys[i] = subkeys[ROUND - i - 1];
		subkeys[ROUND - i - 1] = t;
	}
	std::string res = "";
	for (int i = 0; i < plainstring.size(); i += 16){
		unsigned long long input = 0;
		for (int j = 15; j >= 0; j -- )
			input = (input << 4) + char2numrev(plainstring[i + j]);
		auto blockres = DESblock(input, subkeys);
		char buffer[100] = {0};
		sprintf(buffer, "%016llx", blockres);
		res += buffer;
	}
	return res;
}

std::string DESCBC_Enc(std::string plainstring, std::string keystring, std::string IVstring){
	int tint = 8 - plainstring.size() % 16 / 2;
	for (int i = 0; i < tint; i ++ ){
		plainstring += '0';
		plainstring += tint + '0';
	}	
	std::bitset<64> key, IV;
	unsigned long long tull;
	sscanf(keystring.c_str(), "%llx", &tull);
	key = tull;
	for (int j = 15; j >= 0; j -- )
		tull = (tull << 4) + char2numrev(IVstring[j]);
	IV = tull;
	auto subkeys = getsubkey(key);
	std::string res = "";
	for (int i = 0; i < plainstring.size(); i += 16){
		unsigned long long input = 0;
		for (int j = 15; j >= 0; j -- )
			input = (input << 4) + char2numrev(plainstring[i + j]);
		input ^= tull;
		//printf("|%016llx||%016llx||%016llx|\n", input, tull, input ^ tull);
		auto blockres = DESblock(input, subkeys);
		char buffer[100] = {0};
		sprintf(buffer, "%016llx", blockres);
		tull = 0;
		for (int i = 0; i < 64; i ++ )
			tull = tull * 2 + !!(blockres & (1ULL << i));
		//printf("%s %016llx\n", buffer, tull);
		res += buffer;
	}
	return res;
}

std::string DESCBC_Dec(std::string plainstring, std::string keystring, std::string IVstring){
	std::bitset<64> key;
	unsigned long long tull, IV;
	sscanf(keystring.c_str(), "%llx", &tull);
	key = tull;
	for (int j = 15; j >= 0; j -- )
		tull = (tull << 4) + char2numrev(IVstring[j]);
	sscanf(IVstring.c_str(), "%llx", &IV);
	tull = IV;
	auto subkeys = getsubkey(key);
	for (int i = 0; i < ROUND / 2; i ++ ){
		auto t = subkeys[i];
		subkeys[i] = subkeys[ROUND - i - 1];
		subkeys[ROUND - i - 1] = t;
	}
	std::string res = "";
	for (int i = 0; i < plainstring.size(); i += 16){
		unsigned long long input = 0;
		for (int j = 15; j >= 0; j -- )
			input = (input << 4) + char2numrev(plainstring[i + j]);
		auto blockres = DESblock(input, subkeys);
		//printf("|%016llx||%016llx|%s\n", blockres, tull, IVstring.c_str());
		blockres ^= tull;
		char buffer[100] = {0};
		sprintf(buffer, "%016llx", blockres);
		tull = 0;
		for (int i = 0; i < 64; i ++ )
			tull = tull * 2 + !!(input & (1ULL << i));
		res += buffer;
	}
	int tint = res[res.size() - 1] - '0';
	//printf("%d\n", tint);
	res = res.substr(0, res.size() - tint * 2);
	return res;
}

void Encmain(std::string inputfilename, std::string key, std::string IV, std::string outputfilename){
	std::string plain;
	FILE *in = fopen(inputfilename.c_str(), "rb");
	for (; ; ){
		int ch = fgetc(in);
		if (ch == EOF) break;
		plain += num2charmap[ch / 16];
		plain += num2charmap[ch % 16];
	}
	auto res = DESCBC_Enc(plain, key, IV);
	FILE *out = fopen(outputfilename.c_str(), "wb");
	for (int i = 0; i < res.size(); i += 2){
		unsigned char ch = char2nummap[res[i]] * 16 + char2nummap[res[i + 1]];
		fwrite(&ch, 1, 1, out);
	}
	fclose(out);
}
void Decmain(std::string inputfilename, std::string key, std::string IV, std::string outputfilename){
	std::string input;
	FILE *in = fopen(inputfilename.c_str(), "rb");
	for (; ; ){
		int ch = fgetc(in);
		if (ch == EOF) break;
		input += num2charmap[ch / 16];
		input += num2charmap[ch % 16];
	}
	auto res = DESCBC_Dec(input, key, IV);
	FILE *out = fopen(outputfilename.c_str(), "wb");
	for (int i = 0; i < res.size(); i += 2){
		unsigned char ch = char2nummap[res[i]] * 16 + char2nummap[res[i + 1]];
		fwrite(&ch, 1, 1, out);
	}
	fclose(out);
}
void Init(){
	num2charmap[0] = '0';
	num2charmap[1] = '1';
	num2charmap[2] = '2';
	num2charmap[3] = '3';
	num2charmap[4] = '4';
	num2charmap[5] = '5';
	num2charmap[6] = '6';
	num2charmap[7] = '7';
	num2charmap[8] = '8';
	num2charmap[9] = '9';
	num2charmap[10] = 'A';
	num2charmap[11] = 'B';
	num2charmap[12] = 'C';
	num2charmap[13] = 'D';
	num2charmap[14] = 'E';
	num2charmap[15] = 'F';
	char2nummap['0'] = 0;
	char2nummap['1'] = 1;
	char2nummap['2'] = 2;
	char2nummap['3'] = 3;
	char2nummap['4'] = 4;
	char2nummap['5'] = 5;
	char2nummap['6'] = 6;
	char2nummap['7'] = 7;
	char2nummap['8'] = 8;
	char2nummap['9'] = 9;
	char2nummap['a'] = 10;
	char2nummap['b'] = 11;
	char2nummap['c'] = 12;
	char2nummap['d'] = 13;
	char2nummap['e'] = 14;
	char2nummap['f'] = 15;
	char2nummap['A'] = 10;
	char2nummap['B'] = 11;
	char2nummap['C'] = 12;
	char2nummap['D'] = 13;
	char2nummap['E'] = 14;
	char2nummap['F'] = 15;
}
int main(){
	Init();
	for (;;){
		printf("input mode number\n1:file encryption\n2:file decryption\n3:block encryption\n4:block decryption\n0:exit\n");
		int tint = 0;
		scanf("%d", &tint);
		if (tint == 0) return 0;
		if (tint < 1 || tint > 4) continue;
		std::string inputfilename, key, iv, outputfilename;
		printf("input %s\n", tint < 3 ? "file name" : "block in hex, length = 16");
		std::cin >> inputfilename;
		printf("key in hex, length = 16\n");
		std::cin >> key;
		if (tint < 3){
			printf("iv in hex, length = 16\n");
			std::cin >> iv;
			printf("output file name\n");
			std::cin >> outputfilename;
		}
		
		if (tint == 1) Encmain(inputfilename, key, iv, outputfilename);
		else if (tint == 2) Decmain(inputfilename, key, iv, outputfilename);
		else if (tint == 3) printf("encryption result:	%s\n", DESECB_Enc(inputfilename, key).c_str());
		else printf("decryption result:	%s\n", DESECB_Dec(inputfilename, key).c_str());
		printf("%scryption over.\n----------\n", tint == 1 || tint == 3 ? "en" : "de");
	}
}
