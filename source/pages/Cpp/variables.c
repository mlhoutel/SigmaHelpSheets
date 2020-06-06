int main() {

	// Variable declaration and Operators
	int value = 10;

	value += 5; // 10+5 = 15
	value -= 3; // 15-3 = 12
	value *= 2; // 12*2 = 24
	value /= 4; // 24/4 = 6

	value++; // 6+1 = 7
	++value; // 7+1 = 8

	value--; // 8-1 = 7
	--value; // 7-1 = 6

	// Binary Operators
	int binA = 60, binB = 6;

	binA & binB // 60 AND 6 = 4
	// 0011 1100 (60)
	// 0000 0110 (6)
	// ---------------
	// 0000 0100 (4)
	
	binA | binB // 60 OR 6 = 62
	// 0011 1100 (60)
	// 0000 0110 (6)
	// ---------------
	// 0011 1110 (62)

	binA ^ binB // 60 XOR 6 = 58
	// 0011 1100 (60)
	// 0000 0110 (6)
	// ---------------
	// 0011 1010 (58)

	~binB // NOT 6 = -9
	// (0) 0110 (6)
	// ---------------
	// (1) 1001 (-9)
	
	binB <<= 3 // 6 LEFT-SHIFTED BY 3 = 48
	// 0000 0110 (6)
	// ---------------
	// 0011 0000 (48)

	binA = binA >> 2 // 60 RIGHT-SHIFTED BY 2 = 15
	// 0011 1100 (60)
	// ---------------
	// 0000 1111 (15)

	// Tests
	bool A = true; // A=true=1
	bool B = !A; // B=false=0

	if (A) { /* (IS) TRUE */ }
	if (!A) { /* (IS NOT) FALSE */ }

	if (A && B) { /* (AND) FALSE */ }
	if (A || B) { /* (OR) TRUE */ }
	if(!A != !B) { /* (XOR) TRUE */ }

	if (A==1) { /* (EQUAL) TRUE */ }
	if (A!=42) { /* (NOT EQUAL) TRUE */ }
	if (A>1) { /* (GREATER THAN) FALSE */ }
	if (A>=1) { /* (GREATER OR EQUAL) TRUE*/ }
	if (A<-2) { /* (LOWER THAN) FALSE*/ }
	if (A<=B) { /* (LOWER OR EQUAL) FALSE*/ }
}