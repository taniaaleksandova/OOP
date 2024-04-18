#include <iostream>
#include <fstream>
#include "InstaPost.h"
#include "InstaProfile.h"

int main()
{
    InstaPost post = { "Photos pt.1", 20, "photo.txt" };
    post.like();
    std::cout << post;

    InstaProfile profile = { "tanita", {post}, 1 };
}