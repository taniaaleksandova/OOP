#ifndef INSTAPOST_H
#define INSTAPOST_H
#include <fstream>

class InstaPost {

private:
	static const unsigned MAX_SIZE = 1024;
	static const unsigned PATH_SIZE = 1024;
	char description[MAX_SIZE + 1];
	unsigned likes;
	char photoPath[PATH_SIZE];

	void printPhoto(std::ostream& os) const;

public:
	InstaPost();
	InstaPost(const char* description, int likes, const char* photoPath);
	InstaPost(InstaPost const& other);
	void like();
	InstaPost& operator=(const InstaPost& other);
	friend std::ostream& operator<<(std::ostream& is, const InstaPost& post);
};

#endif
