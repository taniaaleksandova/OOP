#include <fstream>
#include <iostream>
#include "InstaPost.h"

InstaPost::InstaPost(){
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->description[i] = '\0';
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->photoPath[i] = '\0';
	}
	this->likes = 0;
}

InstaPost::InstaPost(const char* description, int likes, const char* photoPath){
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->description[i] = description[i];
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->photoPath[i] = photoPath[i];
	}
	this->likes = likes;
}

InstaPost::InstaPost(InstaPost const& other){
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->description[i] = other.description[i];
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->photoPath[i] = other.photoPath[i];
	}
	this->likes = other.likes;
}

void InstaPost::printPhoto(std::ostream& os) const {
	std::ifstream file(this->photoPath, std::ios::in);
	if (!file.is_open()) {
		std::cout << "Error";
	}
	char chr;
	while (!file.eof()) {
		file.get( chr);
		os << chr;
	}
}

void InstaPost::like(){
	this->likes++;
}

InstaPost& InstaPost::operator=(const InstaPost& other)
{
	if (this != &other) {
		strcpy_s(this->description, (strlen(other.description) + 1), other.description);
		strcpy_s(this->photoPath, (strlen(other.photoPath) + 1), other.photoPath);
		this->likes = other.likes;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const InstaPost& post) {
	post.printPhoto(os);
	os << std:: endl << "'" << post.description << "' - " << post.likes << " likes" << std::endl;
	return os;
}
