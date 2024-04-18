#ifndef INSTAPROFILE_H
#define INSTAPROFILE_H
#include "InstaPost.h"


class InstaProfile {
private:
	static const unsigned SIZE = 10;
	char* userName;
	InstaPost** posts;
	int capacityPosts;

public:
	InstaProfile();
	InstaProfile(const char* userName, InstaPost** posts, int capacityPosts);
	InstaProfile(const char* userName, const char* postPath, int capacityPosts);
	InstaProfile(InstaProfile const& other);
	InstaProfile(InstaProfile&& other);
	~InstaProfile();

	InstaProfile& operator=(const InstaProfile& other);
	InstaProfile& operator=(InstaProfile&& other);

	void operator+=(InstaPost& post);
	InstaPost& operator[](int index);
	bool isEmpty(int index);
	void resize();



};
#endif
