#include <iostream>

using namespace std;

int arr[25];
int tarr[25];

int Check()
{
	if (tarr[1] == tarr[2] && tarr[1] == tarr[3] && tarr[1] == tarr[4])
	{

	}
	else
	{
		return 0;
	}


	if (tarr[5] == tarr[6] && tarr[5] == tarr[7] && tarr[5] == tarr[8])
	{

	}
	else
	{
		return 0;
	}

	if (tarr[13] == tarr[14] && tarr[13] == tarr[15] && tarr[13] == tarr[16])
	{

	}
	else
	{
		return 0;
	}

	if (tarr[9] == tarr[10] && tarr[9] == tarr[11] && tarr[9] == tarr[12])
	{

	}
	else
	{
		return 0;
	}
	
	if (tarr[17] == tarr[18] && tarr[17] == tarr[19] && tarr[17] == tarr[20])
	{

	}
	else
	{
		return 0;
	}

	if (tarr[21] == tarr[22] && tarr[21] == tarr[23] && tarr[21] == tarr[24])
	{

	}
	else
	{
		return 0;
	}

	return 1;
}

void One()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}

	tarr[2] = arr[6];
	tarr[4] = arr[8];

	tarr[6] = arr[10];
	tarr[8] = arr[12];

	tarr[10] = arr[23];
	tarr[12] = arr[21];

	tarr[21] = arr[4];
	tarr[23] = arr[2];
}

void Two()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}

	tarr[10] = arr[6];
	tarr[12] = arr[8];

	tarr[6] = arr[2];
	tarr[8] = arr[4];

	tarr[2] = arr[23];
	tarr[4] = arr[21];

	tarr[23] = arr[10];
	tarr[21] = arr[12];
}

void Three()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[1] = arr[5];
	tarr[3] = arr[7];

	tarr[5] = arr[9];
	tarr[7] = arr[11];

	tarr[9] = arr[23];
	tarr[11] = arr[21];

	tarr[21] = arr[3];
	tarr[23] = arr[1];
}

void Four()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[5] = arr[1];
	tarr[7] = arr[3];

	tarr[9] = arr[5];
	tarr[11] = arr[7];

	tarr[21] = arr[11];
	tarr[23] = arr[9];

	tarr[1] = arr[23];
	tarr[3] = arr[21];
}

void Five()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[22] = arr[18];
	tarr[21] = arr[17];

	tarr[18] = arr[6];
	tarr[17] = arr[5];

	tarr[6] = arr[14];
	tarr[5] = arr[13];

	tarr[14] = arr[22];
	tarr[13] = arr[21];
}

void Six()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[13] = arr[5];
	tarr[14] = arr[6];

	tarr[5] = arr[17];
	tarr[6] = arr[18];

	tarr[17] = arr[21];
	tarr[18] = arr[22];

	tarr[21] = arr[13];
	tarr[22] = arr[14];
}

void Seven()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}

	tarr[15] = arr[7];
	tarr[16] = arr[8];

	tarr[7] = arr[19];
	tarr[8] = arr[20];

	tarr[19] = arr[23];
	tarr[20] = arr[24];

	tarr[23] = arr[15];
	tarr[24] = arr[16];
}

void Eight()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[24] = arr[20];
	tarr[23] = arr[19];

	tarr[20] = arr[8];
	tarr[19] = arr[7];

	tarr[8] = arr[16];
	tarr[7] = arr[15];

	tarr[16] = arr[24];
	tarr[15] = arr[23];
}

void Nine()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[4] = arr[14];
	tarr[3] = arr[16];

	tarr[14] = arr[9];
	tarr[16] = arr[10];

	tarr[9] = arr[19];
	tarr[10] = arr[17];
	
	tarr[19] = arr[4];
	tarr[17] = arr[3];
}

void Ten()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[3] = arr[17];
	tarr[4] = arr[19];

	tarr[17] = arr[10];
	tarr[19] = arr[9];

	tarr[10] = arr[16];
	tarr[9] = arr[14];

	tarr[16] = arr[3];
	tarr[14] = arr[4];
}

void Eleven()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[1] = arr[18];
	tarr[2] = arr[20];

	tarr[18] = arr[12];
	tarr[20] = arr[11];

	tarr[12] = arr[15];
	tarr[11] = arr[13];

	tarr[15] = arr[1];
	tarr[13] = arr[2];
}

void Twelve()
{
	for (int i = 1; i < 25; i++)
	{
		tarr[i] = arr[i];
	}
	tarr[2] = arr[13];
	tarr[1] = arr[15];

	tarr[13] = arr[11];
	tarr[15] = arr[12];

	tarr[11] = arr[20];
	tarr[12] = arr[18];

	tarr[20] = arr[2];
	tarr[18] = arr[1];
}



int main()
{
	for (int i = 1; i < 25; i++)
	{
		scanf("%d", &arr[i]);
	}

	One();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Two();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Three();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Four();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Five();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Six();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Seven();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Eight();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Nine();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Ten();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Eleven();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	Twelve();
	if (Check() == 1)
	{
		printf("1");
		return 0;
	}

	printf("0\n");
	return 0;
}
