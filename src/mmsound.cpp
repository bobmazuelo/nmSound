#include <mmsound.h>
#include <unistd.h>

using namespace std;

int	main(int argc, char **argv)
{
	string line;

	// ./mmsound file.mm
	if (argc == 2)
	{

		string file_str(argv[1]);
		string ext = file_str.substr(file_str.find('.') + 1);

		if (!ext.compare("mm"))
		{
			ifstream file(argv[1]);

			if (file.bad())
			{
				cerr << "[ERROR]: bad file" << endl;
				exit(1);
			}

			try
			{
				while (getline(file, line))
					parser_mmline(line);
			}
			catch (const std::runtime_error& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
			}

			file.close();
		}
	}
	else if (argc == 1)	// Pipe or heredoc
	{
		if (!isatty(fileno(stdin)))
		{
			try
			{
				while (getline(cin, line))
					parser_mmline(line);
			}
			catch (const std::runtime_error& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
		else
		{
			cerr << "Usage: " << argv[0] << " [mm file]\n";

			return (1);
		}
	}
	else
	{
		cerr << "Usage: " << argv[0] << " [mm file]\n";

		return (1);
	}

	return (0);
}
