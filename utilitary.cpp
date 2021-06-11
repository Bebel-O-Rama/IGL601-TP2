#include "utilitary.h"

// Clear the intermediate files
void clearIntermediateFile()
{
    // Delete the folder "intermediate" with its content
    // Create a empty folder called "intermediate" at the same place
    // Add a empty file called "index"
}


void addToIntermediateFile(std::string path)


// https://pragmaticjoe.blogspot.com/2015/02/how-to-generate-sha1-hash-in-c.html
std::string getSHA(std::string &inputStr)
{
	using boost::uuids::detail::sha1;
	using std::ifstream;

	sha1 sha;

	sha.process_bytes(inputStr.c_str(), inputStr.length());

	unsigned int hash[5];
	sha.get_digest(hash);
	
	std::stringstream stream;

	for (int i = 0; i < 5; ++i) {
		stream << std::hex << hash[i]; 
	}

	inputStr = stream.str();

	return inputStr;
}

// Output the content of a file (at the designed path) in a string 
std::string readFile(std::string &filePath)
{
    using std::ifstream;
	using std::string;

	// Verifies if the path gives a file, if no, return a empty string
    if (!pathExists(filePath))
    {
        return "";
    }

    // Read the file and copy its content in a string
	ifstream file(filePath);
	string content{	std::istreambuf_iterator<char>(file),
					std::istreambuf_iterator<char>() };

    return content;
}

// Retourne si le path pointe vers un directory qui existe
bool pathExists(std::string &path) 
{
    boost::system::error_code ec; // Pour eviter les exceptions

    return boost::filesystem::is_directory(path, ec);
}

// Verifie si un fichier existe a l'adresse du path
bool fileExists(std::string &filePath) 
{
    boost::system::error_code ec; // Pour eviter les exceptions

    return boost::filesystem::exists(filePath, ec);
}