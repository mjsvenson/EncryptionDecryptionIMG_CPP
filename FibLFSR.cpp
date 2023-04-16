#include "FibLFSR.h"

FibLFSR::FibLFSR (string seed)
{
 for (int i = 0; i < 16; i++)
 {
	if (seed.at(i) == '1')
	 FibSeed[i] = 1;
	else
	 FibSeed[i] = 0;
 }
}

string FibLFSR::print()
{
string result;

for (int i = 0; i < 16; i++)
{
if (FibSeed[i] == 1)
result += '1';
else
result += '0';
}

return result;
}

ostream& operator<<(ostream& os, FibLFSR& output)
{
os << output.print();
return os;
}

int FibLFSR::step()
{

int right = ((FibSeed[0] ^ FibSeed[2]) ^ FibSeed[3]) ^ FibSeed[5];

for (int i = 1; i < 17; i++)
{
	FibSeed[i-2] = FibSeed[i-1];
}

FibSeed[15] = right;

return right;
}

int FibLFSR::generate(int k)
{
int sum = 0;
for (int i = 0; i < k; i++)
{
 if (step() == 1)
	sum = (sum*2 + 1);
 else
	sum *= 2;
}

return sum;

}
