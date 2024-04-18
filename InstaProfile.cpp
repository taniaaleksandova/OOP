#include "InstaProfile.h"
#include <iostream>

InstaProfile::InstaProfile() {
	this->capacityPosts = 1;
	this->userName = new char[this->capacityPosts];
	this->posts = new InstaPost * [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		posts[i] = nullptr;
	}
}

InstaProfile::InstaProfile(const char* userName, InstaPost** posts, int capacityPosts) {
	this->userName = new char[strlen(userName) + 1];
	strcpy_s(this->userName, strlen(userName), userName);
	this->posts = new InstaPost * [capacityPosts];
	for (int i = 0; i < capacityPosts; i++)
	{
		this->posts[i] = posts[i];
	}
	this->capacityPosts = capacityPosts;
}

InstaProfile::InstaProfile(const char* userName, const char* postPath, int capacityPosts){
	this->capacityPosts = capacityPosts;
	this->userName = new char[strlen(userName) + 1];
	strcpy_s(this->userName, strlen(userName), userName);

	this->posts = new InstaPost * [capacityPosts];
	std::ifstream file(postPath, std::ios::in || std::ios::binary);
	file.seekg(0);
	for (int i = 0; i < capacityPosts; i++)
	{
		file.read((char*)&posts[i], sizeof(InstaPost));
	}
	if (!file.eof()) {
		std::cout << "Not enoght space for all the posts.";
	}
}

InstaProfile::InstaProfile(InstaProfile const& other){
	this->capacityPosts = other.capacityPosts;
	this->userName = new char[strlen(other.userName) + 1];
	strcpy_s(this->userName, strlen(other.userName), other.userName);

	this->posts = new InstaPost * [other.capacityPosts];
	for (int i = 0; i < other.capacityPosts; i++)
	{
		this->posts[i] = other.posts[i];
	}
}

InstaProfile::InstaProfile(InstaProfile&& other){
		this->capacityPosts = other.capacityPosts;
		this->userName = other.userName;
		this->posts = other.posts;

		other.capacityPosts = 0;
		other.userName = nullptr;
		other.posts = nullptr;
}

InstaProfile::~InstaProfile(){
	delete[] this->userName;

	for (int i = 0; i < this->capacityPosts; i++)
	{
		delete this->posts[i];
	}
	delete[] this->posts;
}

InstaProfile& InstaProfile::operator=(const InstaProfile& other){
	if (this != &other) {

		delete[] this->userName;
		for (int i = 0; i < this->capacityPosts; i++)
		{
			delete posts[i];
		}
		delete[] posts;

		this->userName = new char[strlen(other.userName) + 1];
		this->capacityPosts = other.capacityPosts;
		this->posts = new InstaPost * [capacityPosts];

		strcpy_s(this->userName, strlen(other.userName), other.userName);
		for (int i = 0; i < this->capacityPosts; i++)
		{
			posts[i] = other.posts[i];
		}
		this->posts = other.posts;
	}
	return *this;
}

InstaProfile& InstaProfile::operator=(InstaProfile&& other){
	if (this != &other) {

		this->capacityPosts = other.capacityPosts;
		this->userName = other.userName;
		for (int  i = 0; i < this->capacityPosts; i++)
		{
			posts[i] = other.posts[i];
		}
		this->posts = other.posts;

		other.capacityPosts = 0;
		other.userName = nullptr;
		for (int i = 0; i < this->capacityPosts; i++)
		{
			other.posts[i] = nullptr;
		}
		other.posts = nullptr;
	}
	return *this;
}

void InstaProfile::operator+=(InstaPost& post){
	int isCompleted = false;
	for (size_t i = 0; i < this->capacityPosts; i++)
	{
		if (this->posts[i] == nullptr) {
			posts[i] = &post;
			isCompleted = true;
			break;
		}
	}
	if (!isCompleted) {
		resize();
		posts[this->capacityPosts - 1] = &post;
	}
}

InstaPost& InstaProfile::operator[](int index){
	InstaPost post = *posts[index];
	return post;
	
}

bool InstaProfile::isEmpty(int index){
	return posts[index] == nullptr;
}

void InstaProfile::resize(){
	InstaPost** posts = new InstaPost*[capacityPosts + 1];
	for (int i = 0; i < this->capacityPosts; i++)
	{
		posts[i] = this->posts[i];
	}
	this->posts = posts;
	this->capacityPosts++;
	for (int i = 0; i < capacityPosts + 1; i++) {
		posts[i] = nullptr;
	}
	posts = nullptr;
}
