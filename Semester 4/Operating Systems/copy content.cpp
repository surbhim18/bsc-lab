#include<iostream>
#include<cstdlib>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		cout << "Invalid number of arguments supplied!!\n";
		exit(1);
	}

	int file_descriptor1 = open(argv[1], O_RDONLY);

	if(file_descriptor1 == -1)
	{
		cout << "Error in opening file. Please try again\n";
		exit(1);
	}

	int file_descriptor2 = open(argv[2], O_RDWR|O_CREAT, S_IRWXU);

	//int file_descriptor2 = creat(argv[2], 0666);

	if(file_descriptor2 == -1)
	{
		cout << "Error in creating the file.\n";
		exit(1);
	}

	char buf[1024];
	int count;

	while(count = read(file_descriptor1, buf, sizeof(buf)))
	{
		//write(file_descriptor2, buf, count);
	
		if(count)
		{
			if(write(file_descriptor2, buf, count)!=count)
			{
				cout << "Writing to the file failed\n";
				exit(1);
			}
		}

		else
		{
			cout << "Reading from file failed\n";
			exit(1);
		}
	}

	cout << "Copying content to the file was successful!!\n";

	close(file_descriptor1);
	close(file_descriptor2);

return 0;
}
